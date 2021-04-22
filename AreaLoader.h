#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

enum Areas
{
	Area01,
	Area02,
	Area03
};


class AreaLoader
{
public:
	AreaLoader();
	~AreaLoader();

	std::vector<std::string> LoadArea(Areas area);

	std::vector<std::string> m_areas;
};

