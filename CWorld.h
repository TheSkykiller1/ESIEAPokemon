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
#include "CMonster.h"
#include "CElectric.h"
#include "CFire.h"
#include "CGrass.h"
#include "CInsect.h"
#include "CPlant.h"
#include "CRock.h"
#include "CWater.h"


class CWorld
{
protected:
	//Utile pour split les chaines de string avec un delimiter
	template<typename Out>
	void split(const std::string &s, char delim, Out result);

	std::vector<std::string> split(const std::string &s, char delim);

public:
	int dimensionX;
	int dimensionY;
	int nb_joueur;
	std::vector<CPlayer> joueurs; //Le joueur connait sa position
	std::vector<CMonster> liste_pokemon;
	//CTerrain* Cases; //Defini la grille de jeu et le terrain de la case en question
	CWorld();
	//CWorld(int X, int Y);
	~CWorld();

	//void generate_terrain(int X, int Y);
	//void print_players();
	//void print_map();
	//CTerrain terrain(int posX, int posY);
	//std::vector<CPlayer> Player(int posX, int posY); //Donne la liste des joueurs sur cette case, si > 2 alors un match est déclaré.

	std::vector<CMonster> read_config_pokemon();
};
#endif // !_CWORLD_H
