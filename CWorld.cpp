#include "CWorld.h"
#include <iostream>
#include <fstream>//ifstream
#include <string>//getline
#include <sstream>

CWorld::CWorld()
{
}


CWorld::~CWorld()
{
}

void CWorld::read_config_pokemon()
{
	std::string row;std::string MESSAGE = "";
	std::ifstream File("monsters.pkmn", std::ios::in);
	if (File.is_open())
	{
		int i = 0;
		while (getline(File, row))
		{
			if (row == "Monster") 
			{
				int typeof_Pokemon;
				getline(File, row);
				row.erase(0, 1);

				std::istringstream ss(row);
				std::string element;
				while (getline(ss, element, '\t')) {
					std::cout << "Arguments: " << element << '\n';
					MESSAGE += (element + "\n");
				}
			}
			
			i++;
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier \n";
	}
	system("pause");
}