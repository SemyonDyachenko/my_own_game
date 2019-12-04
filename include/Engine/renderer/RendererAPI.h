//
// Created by semyon on 02.12.2019.
//

#ifndef MY_OWN_GAME_RENDERERAPI_H
#define MY_OWN_GAME_RENDERERAPI_H

#include <iostream>

namespace Engine {

    class RendererAPI {
    public:
        enum class API {
            NONE = 0,
            OPENGL = 0,
            SFML = 1,
            VULKAN = 0,
            DIRECTX = 0
        };

    private:
        static API m_API;
    public:


        virtual void Init() = 0;

        virtual void Clear() = 0;


        inline static API getAPI();

       //static std::shared_ptr<RendererAPI> Create();


    };


}


#endif //MY_OWN_GAME_RENDERERAPI_H
