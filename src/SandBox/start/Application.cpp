//
// Created by semyon on 01.12.2019.
//


#include "../../../include/SandBox/start/Application.h"
#include "../../../include/Engine/Physics/Collision.h"
#include "../../../include/Engine/Entity/Components/MovementComponent.h"


namespace Engine {
	
}

void Application::InitGraphics()
{
	Renderer2D::Init();
	RenderCommand::Init();
}

Application::Application() {
	
    this->window = Window::Create(1280,720,"Faton Engine");
	this->InitGraphics();

	event = nullptr;

	component = new MovementComponent(*sprite,0.5,0.25);
	
	
	
	std::shared_ptr<Texture2D> texture = Texture2D::Create("assets/images/pusheen.png");
	sprite = new Sprite(1, 1, texture);

	entity = new Entity::Entity();
	
	entity->AddSprite(sprite);

	entity->AddMovementComponent(component);

	entity->AddBoxColliderComponent();
	
	entity->OnGravity(false);
	
	camera = new Camera2D(window->GetWidth() / window->GetHeight());
	

	
	sprite2 = new Sprite(5,5,texture);	



}

Application::~Application() {
    this->window->Close();
}


void Application::OnUpdate() {

	
}



void Application::OnRender() {

	
	
	//sprite->OnRender(*camera);


	
	sprite2->OnRender(*camera);
}

void Application::Run() {
    event = new WindowCloseEvent();
    while (window->isOpen()) {

		sf::Clock clock;
		float time = (float)glfwGetTime();
		Time deltaTime = float(time - lastFrameTime) / 1000;
		lastFrameTime = time;

    	
		clock.restart();
		time = time / 800;

		camera->Update(time);
        window->PollEvent(*event);
		window->Clear({ 34, 38, 35,1 });
		OnUpdate();
        OnRender();

		BoxCollider2D collider(sprite2->GetBounds());

    	if (Collision::Intersects(entity->GetCollider2D(), collider))
		{
			float push = std::min(std::max(1.0f, 0.0f), 1.0f);
			if (entity->GetMovementComponent().GetVelocity().x > 0)
			{
				sprite->Move(-0.1f*push, 0.0f);
			}
			else if(entity->GetMovementComponent().GetVelocity().x < 0)
			{
				sprite->Move(0.1f*push, 0.0f);
			}
			else if(entity->GetMovementComponent().GetVelocity().y > 0)
			{
				sprite->Move(0.0f, -0.1f*push);
			}
			else if(entity->GetMovementComponent().GetVelocity().y < 0)
			{
				sprite->Move(0.0f, 0.1f*push);
			}
		}

		//entity->Update(time);

		entity->OnRender(*camera);

		std::cout << "Delta Time: " << deltaTime.AsMicroseconds() << std::endl;
    	

		if(Input::IsKeyPressed(FATON_KEY_T))
    	{
			entity->Move(0.0f, 0.1f, deltaTime.AsMicroseconds());
    	}
		else if(Input::IsKeyPressed(FATON_KEY_G))
		{
			entity->Move(0.0f, -0.1f, deltaTime.AsMicroseconds());
		}
		else if(Input::IsKeyPressed(FATON_KEY_F))
		{
			entity->Move(-0.1f, 0.0f, deltaTime.AsMicroseconds());
		}
		else if(Input::IsKeyPressed(FATON_KEY_H))
    	{
			entity->Move(0.1f, 0.0f, deltaTime.AsMicroseconds());
    	}
    	
        window->Show();

    }
}




