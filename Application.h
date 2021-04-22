#pragma once

class Renderer;
class Input;
class Audio;
class Player;

class Application
{
public:
	Application();
	~Application();
	void Run();
	void Destroy();

private:
	Renderer* mp_renderer{ nullptr };
	Input* mp_controllers{ nullptr };
	Audio* mp_sounds{ nullptr };
	Player* m_player{ nullptr };

};

