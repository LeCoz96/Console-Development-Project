#include "AreaLoader.h"

AreaLoader::AreaLoader()
{
	m_areas.push_back("Assets/Map/Map01.txt");
	m_areas.push_back("Assets/Map/Map02.txt");
	m_areas.push_back("Assets/Map/Map03.txt");
}

AreaLoader::~AreaLoader()
{
	m_areas.clear();
}

std::vector<std::string> AreaLoader::LoadArea(Areas area) // store all the data recived into the vector layout and return ready for the renderer
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
