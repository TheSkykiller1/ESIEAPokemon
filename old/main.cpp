#include <iostream>
#include "CMonster.h"
#include "CPlayer.h"
#include "CTerrain.h"

//Save les types de pokemons pour les "construire"
struct TypePokemon {
	std::string type, name;
	int id, HP_min, HP_max, VIT_min, VIT_max, \
		ATT_min, ATT_max, DEF_min, DEF_max;

	float flood, fall, paralysis, poison, burn, heal;
};

int nb_joueurs = 0;
std::vector<CPlayer> Joueurs;


std::vector<CMonster> ListePokemon;
std::vector<TypePokemon> ListeTypePokemon;


//===================PARSER==========================
template<typename Out>
void split(const std::string &s, char delim, Out result)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) { *(result++) = item; }
}
std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}
//====================================================

void read_config_pokemon()
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
				ListeTypePokemon.push_back(pokemon);
			}
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier \n";
	}
}
//Todo corriger


void jouer()
{
	std::cout << "Creation de deux joueurs:";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Speudo joueur " << i + 1 <<":";
		std::string pseudo;
		std::cin >> pseudo;
		CPlayer joueur(nb_joueurs++, pseudo);
		Joueurs.push_back(joueur);
	}
	std::cout << "Creation des pokemons pour chaque joueurs:";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Joueur " << i + 1 << ":";
		std::string pseudo;
		std::cin >> pseudo;
		CPlayer joueur(nb_joueurs++, pseudo);
		Joueurs.push_back(joueur);
	}
}

int main()
{
	std::cout << "Bienvenue dans PokeLeague \n\
-1) Jouer \n\
- 2) Quitter \n";
	int choix;
	std::cin >> choix;
	switch (choix)
	{
	case 1:
	{
		jouer();
		break;
	}
	case 2:
		break;
	default:
		break;
	}

	system("pause");
}