#pragma once
#include <vector>
#include <string>
#include <iostream>
class LevelLoader
{
public:
	LevelLoader();
	~LevelLoader();

private:
	bool IsWall(int x, int y);

	void LoadMap(std::string fileName);

	std::vector<std::string> m_mapLayout;

};

