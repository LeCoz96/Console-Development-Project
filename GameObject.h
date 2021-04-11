#pragma once
#include<SDL.h>
#include<vector>
#include<string>

class Map;

class GameObject
{
public:
	GameObject(int x, int y, SDL_Renderer* renderer, Map* map);
	GameObject() = default;
	~GameObject() = default;

	void SetX(int value);
	void SetY(int value);
	int GetX();
	int GetY();

	virtual void Render();

	bool Collision(GameObject* object);
	virtual void Update();

	virtual void Animate();

protected:
	SDL_Renderer* m_renderer{ nullptr };
	SDL_Texture* m_texture{ nullptr };

	Map* m_map{ nullptr };
	int m_xPos, m_yPos;
	int m_blockSize;

	SDL_Rect m_sourceRect{}, m_destRect{};

	int m_currentFrame;
	int m_animationSpeed;
	int m_imageSize;
	std::vector<SDL_Texture*> m_listOfTextures;
	std::vector<std::pair<SDL_Rect, int>> m_imageDictionary;

};
