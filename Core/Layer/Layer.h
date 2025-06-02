#pragma once
#include <string>
#include "Core/TimeStep.h"


namespace GLStudy
{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach()
        {
        }

        virtual void OnDetach()
        {
        }

        virtual void OnUpdate(Timestep ts)
        {
        }

        virtual void OnImGuiRender()
        {
        }

        const std::string& GetName() const { return debug_name_; }

    protected:
        std::string debug_name_;
    };
} // GLStudy
