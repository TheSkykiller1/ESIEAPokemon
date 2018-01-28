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
#include "CElectric.h"
#include "CFire.h"
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
	void read_config_pokemon();
	void read_config_terrain();
	int nb_joueur;
	int dimensionX;
	int dimensionY;

public:
	
	std::vector<CPlayer> joueurs; //Le joueur connait sa position
	///config
	std::vector<CMonster> ListePokemon;
	std::vector<CTerrain> ListeTerrain;
	///config

	CWorld();
	CWorld(int X, int Y);
	~CWorld();
	
	//setter
	void add_player(CPlayer &player);//On ajoute le joeuur au monde et on lui donne les pointeurs du monde (pour acceder au config et aux autres joueurs) //todo ameliorer cela
	void set_dimension(int x, int y);
	//getter
	std::vector<CPlayer> Player(int posX, int posY); //Donne la liste des joueurs sur cette case, si > 2 alors un match est déclaré.
	int dimension(bool xy);//false=x, y=true;
	int connected_player();
	void list_player();
	void detail_list_player();
	//void print_map();
	//CTerrain terrain(int posX, int posY);
	

	
};
#endif // !_CWORLD_H
