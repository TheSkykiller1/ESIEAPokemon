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

	//==================Methodes======================
	//---------Parser----------------

	template<typename Out>
	void split(const std::string &s, char delim, Out result);
	std::vector<std::string> split(const std::string &s, char delim);

	//---------Methodes discretes----

	void read_config_terrain();

///========================================================================
public:
	//===================Variables=====================

	std::vector<CPlayer> Joueurs;

	std::vector <std::vector <CTerrain> > cases;


	 //-------config----------------------------

	std::vector<CTerrain> ListeTerrain;

	//==================Methodes======================
	//---------Constructeurs / Destructeur-------

	CWorld();
	~CWorld();

	//---------Methodes discretes----

	void afficher_terrain();

	//---------Methodes--------------------------

		//---------Getters-----
	int dimension(bool xy);// 0=x et 1=y
	void map_view_terrain();

	void list_player();

	//---------Setters-----

	void set_dimension(int x, int y);
	void generate_terrain();

	void add_player(CPlayer player);
	void move_player(int id, int x, int y);

	///========================================================================
};
#endif // !_CWORLD_H
