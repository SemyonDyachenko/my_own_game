//
// Created by semyon on 03.12.2019.
//

#include "SFMLRendererAPI.h"
#include "../../include/Engine/Core/Window.h"


SFMLRendererAPI::SFMLRendererAPI() {

}


void SFMLRendererAPI::Init() {

}

void SFMLRendererAPI::Clear(Engine::Window &window) {
window.Clear(Engine::Math::Color3<float>(0,0,0,100));
}

void SFMLRendererAPI::Draw(Engine::VertexArray *vertexArray) {

}

void SFMLRendererAPI::Clear(Engine::Math::Color3<float> &color) {

}

