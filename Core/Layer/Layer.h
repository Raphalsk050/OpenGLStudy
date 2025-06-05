#pragma once
#include <iostream>
#include <string>
#include "Core/TimeStep.h"
#include "Core/Events/Event.h"


namespace GLStudy
{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach()
        {
            std::cout << "Layer " << debug_name_ <<" attached" << std::endl;
        }

        virtual void OnDetach()
        {
        }

        virtual void OnUpdate(Timestep ts)
        {
            std::cout << "Layer " << debug_name_ <<" updated" << std::endl;
        }

        virtual void OnImGuiRender()
        {
        }

        virtual void OnEvent(Event&)
        {
        }

        const std::string& GetName() const { return debug_name_; }

    protected:
        std::string debug_name_;
    };
} // GLStudy
