
#ifndef TNT_FILAMENT_FG_DETAILS_DEPENDENCYGRAPH_H
#define TNT_FILAMENT_FG_DETAILS_DEPENDENCYGRAPH_H

#include "third_party/filament/libs/utils/include/utils/ostream.h"
#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"

#include <vector>

namespace filament {

class DependencyGraph {
public:
    DependencyGraph() noexcept;
    ~DependencyGraph() noexcept;
    DependencyGraph(const DependencyGraph&) noexcept = delete;
    DependencyGraph& operator=(const DependencyGraph&) noexcept = delete;

    using NodeID = uint32_t;

    class Node;

    struct Edge {
        // An Edge can't be modified after it's created (e.g. by copying into it)
        const NodeID from;
        const NodeID to;

        Edge(DependencyGraph& graph, Node* from, Node* to);

        // Edge can't be copied or moved, this is to allow subclassing safely.
        // Subclasses can hold their own data.
        Edge(Edge const& rhs) noexcept = delete;
        Edge& operator=(Edge const& rhs) noexcept = delete;
    };

    class Node {
    public:
        explicit Node(DependencyGraph& graph) noexcept;

        // Nodes can't be copied
        Node(Node const&) noexcept = delete;
        Node& operator=(Node const&) noexcept = delete;

        //! Nodes can be moved
        Node(Node&&) noexcept = default;

        virtual ~Node() noexcept = default;

        //! returns a unique id for this node
        NodeID getId() const noexcept { return mId; }

        bool isTarget() const noexcept { return mRefCount >= TARGET; }

        bool isCulled() const noexcept { return mRefCount == 0; }

        uint32_t getRefCount() const noexcept;

    public:
        //! return the name of this node
        virtual char const* getName() const noexcept;

        //! output itself as a graphviz string
        virtual utils::CString graphvizify() const noexcept;

        //! output a graphviz color string for an Edge from this node
        virtual utils::CString graphvizifyEdgeColor() const noexcept;

    private:
        // nodes that read from us: i.e. we have a reference to them
        friend class DependencyGraph;
        static const constexpr uint32_t TARGET = 0x80000000u;
        uint32_t mRefCount = 0;     // how many references to us
        const NodeID mId;           // unique id
    };

    using EdgeContainer = utils::FixedCapacityVector<Edge*, std::allocator<Edge*>, false>;
    using NodeContainer = utils::FixedCapacityVector<Node*, std::allocator<Node*>, false>;

    void clear() noexcept;

    NodeContainer const& getNodes() const noexcept;

    EdgeContainer getIncomingEdges(Node const* node) const noexcept;

    EdgeContainer getOutgoingEdges(Node const* node) const noexcept;

    Node const* getNode(NodeID id) const noexcept;

    Node* getNode(NodeID id) noexcept;

    //! cull unreferenced nodes. Links ARE NOT removed, only reference counts are updated.
    void cull() noexcept;

    bool isEdgeValid(Edge const* edge) const noexcept;

    //! export a graphviz view of the graph
    void export_graphviz(utils::io::ostream& out, const char* name = nullptr);

    bool isAcyclic() const noexcept;

private:
    // id must be the node key in the NodeContainer
    uint32_t generateNodeId() noexcept;
    void registerNode(Node* node, NodeID id) noexcept;
    void link(Edge* edge) noexcept;
    static bool isAcyclicInternal(DependencyGraph& graph) noexcept;
    NodeContainer mNodes;
    EdgeContainer mEdges;
};

inline DependencyGraph::Edge::Edge(DependencyGraph& graph,
        DependencyGraph::Node* from, DependencyGraph::Node* to)
        : from(from->getId()), to(to->getId()) {
    assert_invariant(graph.mNodes[this->from] == from);
    assert_invariant(graph.mNodes[this->to] == to);
    graph.link(this);
}

} // namespace filament

#endif // TNT_FILAMENT_FG_DETAILS_DEPENDENCYGRAPH_H
