#include "CWorld.h"

CWorld::CWorld()
{
	read_config_pokemon();
}


CWorld::~CWorld()
{
}

void CWorld::add_player(CPlayer &player)
{
		joueurs.push_back(player);
}

int CWorld::dimension(bool xy)
{
	if (xy) { return dimensionY; }
	else { return dimensionX; }
}

int CWorld::connected_player() { return (joueurs.size() - 1); }

void CWorld::list_player()
{
	for (int i = 0;i < joueurs.size();i++)
	{
		std::cout << "Joueur n°" << i << " : " << joueurs[i].pseudo() << " lvl: " << joueurs[i].level() << " xp: " << joueurs[i].xp() << "/" << joueurs[i].xp_up() << "\n";
	}
}
void CWorld::detail_list_player()
{
	for (int i = 0;i < joueurs.size();i++)
	{
		std::cout << "Joueur n°" << i << " : " << joueurs[i].pseudo() << " lvl: " << joueurs[i].level() << " xp: " << joueurs[i].xp() << "/" << joueurs[i].xp_up() << \
			"\n a comme pokemon: \n \t";
		for (int o = 0; o < joueurs[i].Pokeballs.size();o++)
		{
			std::cout << joueurs[i].Pokeballs[o].getNom() << " de type " << joueurs[i].Pokeballs[o].getType() << "\n \t";
		}
	}
}

void CWorld::read_config_terrain()
{
	std::string row;
	std::ifstream File("terrain.pkmn", std::ios::in);
	srand(time(NULL));//Init random generator
	if (File.is_open())
	{
		while (getline(File, row))
		{
			if (row == "terrain")//Debut du bloc
			{	//Value only!
				std::string name;
				int id;
				float water,rock,electric,fire,grass;

				while (row != "Endterrain")//Tant que l'on est dans le bloc
				{
					getline(File, row);
					if (row == "Endterrain") { break; }//Si on a fini le bloc on quitte
					std::vector<std::string> token = split(row, '\t\t');
					std::vector<std::string> element;
					for (int i = 0;i < token.size();i++)//On clear les elements vides
					{
						if (token[i] != "") { element.push_back(token[i]); }
					}

					//Analyse des resultats
					if (element[0] == "Name") { name = element[1]; }
					else if (element[0] == "Id")
					{
						id = stoi(element[1]);
					}
					else if (element[0] == "Water")
					{
						water = stof(element[1]);
					}
					else if (element[0] == "Rock")
					{
						rock = stof(element[1]);
					}
					else if (element[0] == "Electric")
					{
						electric = stof(element[1]);
					}
					else if (element[0] == "Fire")
					{
						fire = stof(element[1]);
					}
					else if (element[0] == "Grass")
					{
						grass = stof(element[1]);
					}
				}
				CTerrain terrain(name, id, fire, electric, water, rock, grass);
				ListeTerrain.push_back(terrain);
			}
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier \n";
	}
}
void CWorld::read_config_pokemon()
{
	std::string row;
	std::ifstream File("monsters.pkmn", std::ios::in);
	srand(time(NULL));//Init random generator
	int id = 0;
	if (File.is_open())
	{
		while (getline(File, row))
		{
			if (row == "Monster")//Debut du bloc
			{	//Value only!
				std::string name, type;
				int hp, speed, attack, defense;
				float paralyze, poison, fall, flood, burn;

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
					else if (element[0] == "Paralysis")
					{
						paralyze=stof(element[1]);
					}
					else if (element[0] == "Flood")
					{
						flood=stof(element[1]);
					}
					else if (element[0] == "Fall")
					{
						fall = stof(element[1]);
					}
					else if (element[0] == "Poison")
					{
						poison = stof(element[1]);
					}
					else if (element[0] == "Burn")
					{
						burn = stof(element[1]);
					}
				}
				if (type == "Electric")
				{
					CElectric pokemon(id++, type, name, hp, speed, attack, defense);
					ListePokemon.push_back(pokemon);
				}
				else if (type == "Fire")
				{
					CFire pokemon(id++, type, name, hp, speed, attack, defense);
					ListePokemon.push_back(pokemon);
				}
				else if (type == "Rock")
				{
					CRock pokemon(id++, type, name, hp, speed, attack, defense);
					ListePokemon.push_back(pokemon);
				}
				else if (type == "Plant")
				{
					CPlant pokemon(id++, type, name, hp, speed, attack, defense);
					ListePokemon.push_back(pokemon);
				}
				else if (type == "Insect")
				{
					CInsect pokemon(id++, type, name, hp, speed, attack, defense);
					ListePokemon.push_back(pokemon);
				}
				else if (type == "Water")
				{
					CWater pokemon(id++, type, name, hp, speed, attack, defense);
					ListePokemon.push_back(pokemon);
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