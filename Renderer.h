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

class LevelRenderer;
class Exit;

class Key;
class KeyBlock;
class JewelBlue;

class Player;
class Enemy;

class UI;

class Renderer
{
public:
	Renderer();
	~Renderer();
	//void SetBackgroundColour();
	void Update();
	void CollisionChecks(Player* player);
	void ClearAndPresent();
	void StaticObjectUpdate();
	void Pause(float delay);
	void Destroy();

	void ConstructLevelObjects();

	void ConstructLevel01Objects();
	void ConstructLevel02Objects();
	void ConstructLevel03Objects();
	void ConstructLevel04Objects();

	void DestructLevelObjects();
private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
	SDL_Texture* m_texture{ nullptr };

	LevelRenderer* m_level{ nullptr };
	Exit* m_exit{ nullptr };

	Key* m_key{ nullptr };
	KeyBlock* m_keyBlock{ nullptr };
	JewelBlue* m_jewelBlue{ nullptr };

	Player* m_player{ nullptr };
	int m_startX, m_startY{ 0 };
	Enemy* m_enemy{ nullptr };

	UI* m_UI{ nullptr };

	std::vector<JewelBlue*> m_listOfJewelBlue;
	std::vector<Enemy*> m_listOfEnemy;

	bool m_updateStaticObject{ true };

	int m_currentLevel{ 0 };
};

