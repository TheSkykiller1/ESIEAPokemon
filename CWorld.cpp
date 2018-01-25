#include "CWorld.h"
#include <iostream>
#include <fstream>//ifstream
#include <string>//getline
#include <sstream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
CWorld::CWorld()
{
}


CWorld::~CWorld()
{
}

std::vector<CMonster> CWorld::read_config_pokemon()
{
	std::string row;std::string MESSAGE = "";
	std::ifstream File("monsters.pkmn", std::ios::in);
	srand(time(NULL));//Init random generator
	std::vector<CMonster> ListePokemon;
	if (File.is_open())
	{
		while (getline(File, row))
		{
			if (row == "Monster")//Debut du bloc
			{	//Value only!
				std::string name, type;
				int hp, speed, attack, defense;

				while (row!="EndMonster")//Tant que l'on est dans le bloc
				{	
					getline(File, row);
					if (row == "EndMonster") { break; }//Si on a fini le bloc on quitte
					std::vector<std::string> token = split(row, '\t\t');
					std::vector<std::string> element;
					for (int i = 0;i < token.size();i++)//On clear les elements vides
					{
						if (token[i] != "") { element.push_back(token[i]); }
					}

					//Analyse des resultats
					if (element[0] == "Name") { name = element[1]; }
					else if (element[0] == "Type") { type = element[1]; }
					else if (element[0] == "HP")
					{
						int min = std::stoi(element[1]);
						int max = std::stoi(element[2]);
						hp = rand() % (max - min) + min;
					}
					else if (element[0] == "Speed")
					{
						int min = std::stoi(element[1]);
						int max = std::stoi(element[2]);
						speed = rand() % (max - min) + min;
					}
					else if (element[0] == "Attack")
					{
						int min = std::stoi(element[1]);
						int max = std::stoi(element[2]);
						attack = rand() % (max - min) + min;
					}
					else if (element[0] == "Defense")
					{
						int min = std::stoi(element[1]);
						int max = std::stoi(element[2]);
						defense = rand() % (max - min) + min;
					}
				}
				if (type == "Electric")
				{
					
				}
				else if (type == "Fire")
				{

				}
				else if (type == "Rock")
				{

				}
				else if (type == "Plant")
				{

				}
				else if (type == "Insect")
				{

				}
				else if (type == "Water")
				{

				}
			}
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier \n";
	}
}

//La function template pour parser les donnees

template<typename Out>
void CWorld::split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

//La fonction permetant de l'utiliser

std::vector<std::string> CWorld::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}