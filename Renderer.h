#pragma once
#include<SDL.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<vector>

#if _DEBUG

#define DBG_HALT {__debugbreak();}
#define DBG_ASSERT_MSG(f,s,m) {if(!(f)) {printf((s),(m)); DBG_HALT;}}

#endif

class Map;
class Exit;

class Key;
class KeyBlock;
class JewelBlue;
class JewelBlueBlock;
class JewelRed;
class JewelRedBlock;

class Player;
class Enemy;

class UI;

class Renderer
{
public:
	Renderer();
	~Renderer();
	void RenderGameObjects();
	void SetBackgroundColour();
	void Update();
	void ClearAndPresent();
	void Pause(float delay);
	void Destroy();

private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
	SDL_Texture* m_texture{ nullptr };

	Map* m_map{ nullptr };
	Exit* m_exit{ nullptr };

	Key* m_key{ nullptr };
	KeyBlock* m_keyBlock{ nullptr };
	JewelBlue* m_jewelBlue{ nullptr };
	JewelBlueBlock* m_jewelBlueBlock{ nullptr };
	JewelRed* m_jewelRed{ nullptr };
	JewelRedBlock* m_jewelRedBlock{ nullptr };

	Player* m_player{ nullptr };
	Enemy* m_enemy{ nullptr };

	UI* m_UI{ nullptr };

	std::vector<Key*> m_listOfKey;
	std::vector<JewelBlue*> m_listOfJewelBlue;
	std::vector<JewelRed*> m_listOfJewelRed;
	std::vector<Enemy*> m_listOfEnemy;
};

