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
	
	void set_liste_objet(std::vector<CObject*> obj);
///========================================================================
/*Public*/
	//==================Methodes======================
	//---------Constructeurs / Destructeur-------

	CWorld::CWorld()//todo affichage par le menu non pas à la creation
	{
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
			std::cout << " \t Terrain : " << terrain.id() << " nom: " << terrain.Title() << "\n";
		}
	}
	void CWorld::afficher_objets()
	{
		std::cout << "Tous les objets lu dans la config: \n";
		for (int i = 0;i < ListeObject.size();i++)
		{
			CObject objets = ListeObject[i];

			std::cout << "\t -" << ListeObject[i].getId() << ") Nom : \"" << ListeObject[i].getNom() << "\"\t | Genre : \"" <<\
				ListeObject[i].getGenre() << "\"\t | Attack : " << ListeObject[i].getAtt() << "\t | Defense : " <<\
				ListeObject[i].getDef() << "\t | Vitesse : " << ListeObject[i].getVit() << "\t | HP : " <<\
				ListeObject[i].getHP() << "\t | etat : " << ListeObject[i].getEtat() << "\n";


			//std::cout << " \t Objet id: " << objets.getId() << " nom: \"" << objets.getNom() << "\" type: " << objets.getGenre() << "\n";
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
		Joueurs.push_back(player);
	}
	void CWorld::move_player(int id, int x, int y)
	{
		for (int i = 0;i < Joueurs.size();i++)
		{
			if (((Joueurs[i].positionX() == x) && (Joueurs[i].positionY() == y)) && Joueurs[i].get_id() != Joueurs[id].get_id())
			{
				Joueurs[id].move(x, y, &cases[x][y], &Joueurs[i]);
				Joueurs[id].match_reset();
				Joueurs[i].match_reset();
				bool player_win = 0;
				while (true)
				{
					Joueurs[id].attaquer();//Joueur 1
					if (Joueurs[i].check() == false) //Si joueur 2 perd
					{
						Joueurs[id].match_fini(true);
						Joueurs[i].match_fini(false);
						break;
					}
					Joueurs[i].attaquer(); //Joueur 2
					if (Joueurs[id].check() == false)//Si joueur 1 perd
					{
						Joueurs[i].match_fini(true);
						Joueurs[id].match_fini(false);
						break;
					}
				}
			}
			else
			{
				Joueurs[id].move(x, y);
			}
		}
	}

///========================================================================