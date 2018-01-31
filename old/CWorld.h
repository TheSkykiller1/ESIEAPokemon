#ifndef _CWORLD_H
#define _CWORLD_H

#include <iostream>
#include <fstream>//ifstream
#include <string>//getline
#include <sstream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "CPlayer.h"
#include "CTerrain.h"

class CWorld
{
///========================================================================
protected:
	//===================Variables=====================

	int nb_joueur;
	int dimensionX;
	int dimensionY;

	//Save les types de pokemons pour les "construire"
	struct TypePokemon {
		std::string type, name;
		int id, HP_min, HP_max, VIT_min, VIT_max, \
			ATT_min, ATT_max, DEF_min, DEF_max;

		float flood, fall, paralysis, poison, burn, heal;
	};

	//==================Methodes======================
	//---------Parser----------------

	template<typename Out>
	void split(const std::string &s, char delim, Out result);
	std::vector<std::string> split(const std::string &s, char delim);

	//---------Methodes discretes----

	void read_config_pokemon();
	void read_config_terrain();
	void read_config_object();

///========================================================================
public:
	//===================Variables=====================

	std::vector<CPlayer> joueurs;
	std::vector <std::vector <CTerrain> > cases;

	 //-------config----------------------------

	std::vector<TypePokemon> ListePokemon;
	std::vector<CTerrain> ListeTerrain;

	std::vector<CPotion> Potions; //STOCKAGE DES POTIONS
	std::vector<CDrug> Drugs; //STOCKAGE DES DRUG
	std::vector<CObject*> ListeObject; //STOCKAGE ACCES

	//==================Methodes======================
	//---------Constructeurs / Destructeur-------

	CWorld();
	~CWorld();

	//---------Methodes discretes----

	void afficher_pokemon();
	void afficher_terrain();
	void afficher_objets();

	//---------Methodes--------------------------

		//---------Getters-----
	int dimension(bool xy);// 0=x et 1=y
	void map_view_terrain();

	int connected_player();
	void list_player();
	void detail_list_player();

	//---------Setters-----

	void set_dimension(int x, int y);
	void generate_terrain();

	void add_player(CPlayer player);
	void move_player(int id, int x, int y);

	///========================================================================
};
#endif // !_CWORLD_H
