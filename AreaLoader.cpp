#include "AreaLoader.h"
#include "LevelRenderer.h"

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

//// void AreaLoader::LoadArea(Areas areaToLoad, std::vector<std::string>& layout)
//void AreaLoader::LoadArea(Areas area, std::vector<std::string> *layout)
//{
//	std::string line;
//	std::ifstream file(m_areas[area].c_str());
//	while (file >> line)
//	{
//		layout.push_back(line);
//	}
//	file.close();
//}

void AreaLoader::ChangeArea() // ChangeArea(Area area, std::vector<std::string>& layout);
{
	//LoadArea();
}

bool AreaLoader::IsChangingArea(int x, int y)
{
	return false;
}
