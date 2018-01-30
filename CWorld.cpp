//COMMENTAIRE DE TEST

#include "CWorld.h"

///========================================================================
/*Private*/
	//==================Methodes======================
	//---------Parser----------------

	template<typename Out>
	void CWorld::split(const std::string &s, char delim, Out result) 
	{
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) { *(result++) = item; }
	}
	std::vector<std::string> CWorld::split(const std::string &s, char delim) 
	{
		std::vector<std::string> elems;
		split(s, delim, std::back_inserter(elems));
		return elems;
	}

	//---------Methodes discretes----

	void CWorld::read_config_object()
	{
		std::string row;
		std::ifstream File("object.pkmn", std::ios::in);
		if (File.is_open())
		{
			while (getline(File, row))
			{
				if (row == "object")//Debut du bloc
				{	//Value only!
					std::string name, genre, etat;
					int id;
					int attack=0, defense=0, hp=0, speed=0;
					std::vector<std::string> type;

					while (row != "Endobject")//Tant que l'on est dans le bloc
					{
						getline(File, row);
						if (row == "Endobject") { break; }//Si on a fini le bloc on quitte
						std::vector<std::string> token = split(row, '\t\t');
						std::vector<std::string> element;
						for (int i = 0;i < token.size();i++)//On clear les elements vides
						{
							if (token[i] != "") { element.push_back(token[i]); }
						}

						if (element[0] == "Name") { name = element[1]; }
						else if (element[0] == "Id")
						{
							id = stoi(element[1]);
						}
						else if (element[0] == "Genre")
						{
							genre = element[1];
						}
						else if (element[0] == "Type")
						{
							for (int b = 1;b < element.size();b++)
							{
								type.push_back(element[b]);
								//std::cout << "TYPE : " << element[b] << " -" << b << ") \t";
							}
							std::cout << "\n";
						}
						else if (element[0] == "Heal")
						{
							hp = stoi(element[1]);
						}
						else if (element[0] == "Speed")
						{
							speed = stoi(element[1]);
						}
						else if (element[0] == "Attack")
						{
							attack = stoi(element[1]);
						}
						else if (element[0] == "Defense")
						{
							defense = stoi(element[1]);
						}
						else if (element[0] == "State")
						{
							etat = element[1];
						}
					}
					//std::cout << "Info id: " << id << " genre:" << genre << " name:" << name << " speed:" << speed << " attack:" << attack << " defense:" << defense << " hp:" << hp << "\n";
					if (genre == "Potion")
					{
						CPotion potion(id, genre, name, type, speed, attack, defense, hp);
						//std::cout << "Potion id: " << potion.getId() << " genre:" << potion.getGenre() << " name:" << potion.getNom() << " speed:" << potion.getVit() << " attack:" << potion.getAtt() << " defense:" << potion.getDef() << " hp:" << potion.getHP() << "\n\n";
						ListeObject.push_back(potion);
					}
					if (genre == "Drug")
					{
						CDrug drug(id, genre, name, type, etat);
						ListeObject.push_back(drug);
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
	void CWorld::read_config_terrain()
	{
		std::string row;
		std::ifstream File("terrain.pkmn", std::ios::in);
		if (File.is_open())
		{
			while (getline(File, row))
			{
				if (row == "terrain")//Debut du bloc
				{	//Value only!
					std::string name;
					int id;
					float water, rock, electric, fire, grass;

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
						if (element[0] == "Name")
						{
							name = element[1];
						}
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
		int id = 0;
		if (File.is_open())
		{
			while (getline(File, row))
			{
				if (row == "Monster")//Debut du bloc
				{
					TypePokemon pokemon;
					pokemon.id = id++;
					while (row != "EndMonster")//Tant que l'on est dans le bloc
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
							pokemon.paralysis = stof(element[1]);
						}
						else if (element[0] == "Flood")
						{
							pokemon.flood = stof(element[1]);
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


///========================================================================
/*Public*/
	//==================Methodes======================
	//---------Constructeurs / Destructeur-------

	CWorld::CWorld()//todo affichage par le menu non pas à la creation
	{
		read_config_object();
		read_config_pokemon();
		read_config_terrain();
		afficher_pokemon();
		afficher_terrain();
		afficher_objets();
	}
	CWorld::~CWorld(){}

	//---------Methodes discretes----

	void CWorld::afficher_pokemon()//todo afficher plus d'infos
	{
		std::cout << "Tous les pokemons lu dans la config: \n";
		for (int i = 0;i < ListePokemon.size();i++)
		{
			TypePokemon pokedex = ListePokemon[i];
			std::cout << " \t Pokemon : " << pokedex.id << " nom: " << pokedex.name << " type: " << pokedex.type << "\n";
		}
	}
	void CWorld::afficher_terrain()//todo afficher mieux le terrain
	{
		std::cout << "Tous les terrains lu dans la config: \n";
		for (int i = 0;i < ListeTerrain.size();i++)
		{
			CTerrain terrain = ListeTerrain[i];
			std::cout << " \t Terrain : " << terrain.id() << " nom: " << terrain.Title() << " type: " << "\n";
		}
	}
	void CWorld::afficher_objets()
	{
		std::cout << "Tous les objets lu dans la config: \n";
		for (int i = 0;i < ListeObject.size();i++)
		{
			CObject objets = ListeObject[i];
			std::cout << " \t Terrain : " << objets.getId() << " nom: " << objets.getNom() << " type: " << objets.getGenre() << "\n";
		}
	}
	//---------Methodes--------------------------

	//---------Getters-----
	int CWorld::dimension(bool xy)
	{
		if (xy) { return dimensionY; }
		else { return dimensionX; }
	}
	void CWorld::map_view_terrain()
	{
		std::cout << "\t\t\t Map: \n\n";
		int s_max = 0;
		for (int i = 0; i < this->ListeTerrain.size(); i++)
		{
			if (this->ListeTerrain[i].Title().size() > s_max)
			{
				s_max = this->ListeTerrain[i].Title().size();
			}
		}
		for (int x = 0; x < dimensionX; x++)
		{
			std::cout << "\t|";
			for (int y = 0; y < dimensionY; y++)
			{
				std::cout << cases[x][y].Title();
				int i = cases[x][y].Title().size();
				while (i < s_max)
				{
					std::cout << " ";
					i++;
				}
				std::cout << "|";
			}
			std::cout << std::endl;
		}
		std::cout << "\n\n";
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

	//---------Setters-----

	void CWorld::set_dimension(int x, int y)
	{
		dimensionX = x;
		dimensionY = y;
	}
	void CWorld::generate_terrain()
	{
		srand(time(NULL));//Init random generator
		for (int x = 0; x < dimensionX; x++) //generate grid and terrain for each cases
		{
			for (int y = 0; y < dimensionY; y++)
			{
				std::vector<CTerrain> colVector;
				cases.push_back(colVector);
				int choix_terrain = rand() % ListeTerrain.size();//random choice of terrain
				cases.at(x).push_back(ListeTerrain[choix_terrain]);
			}
		}
	}

	void CWorld::add_player(CPlayer player)
	{
		joueurs.push_back(player);
	}
	void CWorld::move_player(int id, int x, int y)
	{
		for (int i = 0;i < joueurs.size();i++)
		{
			if (((joueurs[i].positionX() == x) && (joueurs[i].positionY() == y)) && joueurs[i].get_id() != joueurs[id].get_id())
			{
				joueurs[id].move(x, y, &cases[x][y], &joueurs[i]);
				joueurs[id].match_reset();
				joueurs[i].match_reset();
				bool player_win = 0;
				while (true)
				{
					joueurs[id].attaquer();//Joueur 1
					if (joueurs[i].check() == false) //Si joueur 2 perd
					{
						joueurs[id].match_fini(true, 50);
						joueurs[i].match_fini(false, 10);
						break;
					}
					joueurs[i].attaquer(); //Joueur 2
					if (joueurs[id].check() == false)//Si joueur 1 perd
					{
						joueurs[i].match_fini(true, 50);
						joueurs[id].match_fini(false, 10);
						break;
					}
				}
			}
			else
			{
				joueurs[id].move(x, y);
			}
		}
	}

///========================================================================