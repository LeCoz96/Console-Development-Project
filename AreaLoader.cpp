#include "AreaLoader.h"

AreaLoader::AreaLoader()
{
	m_areas.push_back("Assets/Map/Map01.txt");
	m_areas.push_back("Assets/Map/Map02.txt");
	m_areas.push_back("Assets/Map/Map03.txt");
	m_areas.push_back("Assets/Map/Map04.txt");
}

AreaLoader::~AreaLoader()
{
	m_areas.clear();
}

std::vector<std::string> AreaLoader::LoadArea(Areas area)
{
	std::vector<std::string> layout;
	std::string line;
	std::ifstream file(m_areas[area].c_str());
	while (file >> line)
	{
		layout.push_back(line);
	}
	file.close();
	return layout;
}
