#include "CWorld.h"

CWorld::CWorld()
{
	read_config_pokemon();
	read_config_terrain();
	debug_afficher_pokemon();
	debug_afficher_terrain();
}

CWorld::~CWorld()
{
}

void CWorld::debug_afficher_pokemon()
{
	std::cout << "Tous les pokemons lu dans la config: \n";
	for (int i = 0;i < ListePokemon.size();i++)
	{
		TypePokemon pokedex = ListePokemon[i]; //optimisation memoire d'appel
		std::cout << " \t Pokemon : " << pokedex.id << " nom: " << pokedex.name << " type: " << pokedex.type \
			<<"\n";
	}
}

void CWorld::debug_afficher_terrain()
{
	std::cout << "Tous les terrains lu dans la config: \n";
	for (int i = 0;i < ListeTerrain.size();i++)
	{
		CTerrain terrain = ListeTerrain[i]; //optimisation memoire d'appel
		std::cout << " \t Terrain : " << terrain.id() << " nom: " << terrain.Title() << " type: "<< "\n";
	}
}


void CWorld::set_dimension(size_t x, size_t y)
{
	dimensionX = x;
	dimensionY = y;
}

void CWorld::generate_terrain()
{
	srand(time(NULL));//Init random generator
	size_t row = 3, col = 3; //debug dimension
	for (int x = 0; x < row; x++) //generate grid and terrain for each cases
	{
		for (int y = 0; y < col; y++)
		{
			std::vector<CTerrain> colVector;
			cases.push_back(colVector);
			int choix_terrain = rand() % ListeTerrain.size();//random choice of terrain
			cases.at(x).push_back(ListeTerrain[choix_terrain]);
		}
	}
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

void CWorld::map_view_terrain()
{
	std::cout << "\t\t\t Map: \n\n";
	//cases.at(2).at(1).set_title("debugname");     //cases.at(columns).at(rows) = value

	for (int x = 0; x < dimensionX; x++)
	{
		std::cout << "\t";
		for (int y = 0; y < dimensionY; y++)
		{
			std::cout << cases[x][y].Title() << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";
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
			{
				TypePokemon pokemon;
				pokemon.id = id++;
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
					if (element[0] == "Name") { pokemon.name = element[1]; }
					else if (element[0] == "Type") { pokemon.type = element[1]; }
					else if (element[0] == "HP")
					{
						pokemon.HP_min = std::stoi(element[1]);
						pokemon.HP_max = std::stoi(element[2]);
					}
					else if (element[0] == "Speed")
					{
						pokemon.VIT_min = std::stoi(element[1]);
						pokemon.VIT_max = std::stoi(element[2]);
					}
					else if (element[0] == "Attack")
					{
						pokemon.ATT_min = std::stoi(element[1]);
						pokemon.ATT_max = std::stoi(element[2]);
					}
					else if (element[0] == "Defense")
					{
						pokemon.DEF_min = std::stoi(element[1]);
						pokemon.DEF_max = std::stoi(element[2]);
					}
					else if (element[0] == "Paralysis")
					{
						pokemon.paralysis=stof(element[1]);
					}
					else if (element[0] == "Flood")
					{
						pokemon.flood=stof(element[1]);
					}
					else if (element[0] == "Fall")
					{
						pokemon.fall = stof(element[1]);
					}
					else if (element[0] == "Poison")
					{
						pokemon.poison = stof(element[1]);
					}
					else if (element[0] == "Burn")
					{
						pokemon.burn = stof(element[1]);
					}
					else if (element[0] == "Heal")
					{
						pokemon.heal = stof(element[1]);
					}
				}
				ListePokemon.push_back(pokemon);
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