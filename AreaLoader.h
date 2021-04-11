#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

enum Areas
{
	Area01,
	Area02,
	Area03,
	Area04
};

class AreaLoader
{
public:
	AreaLoader();
	~AreaLoader();

	std::vector<std::string> LoadArea(Areas area);

	void ChangeArea();

	bool IsChangingArea(int x, int y);

	std::vector<std::string> m_areas;
};

