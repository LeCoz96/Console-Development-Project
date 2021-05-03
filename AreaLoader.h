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
	TotalAreas
};


class AreaLoader
{
public:
	AreaLoader();
	~AreaLoader();
	std::vector<std::string> LoadArea(Areas area);

private:

	std::vector<std::string> m_areas;
};

