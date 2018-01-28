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
protected:
	//Utile pour split les chaines de string avec un delimiter
	template<typename Out>
	void split(const std::string &s, char delim, Out result);
	std::vector<std::string> split(const std::string &s, char delim);
	void read_config_pokemon();
	void read_config_terrain();
	void debug_afficher_pokemon();
	void debug_afficher_terrain();

	int nb_joueur;
	int dimensionX;
	int dimensionY;

	struct TypePokemon {
		std::string type, name;
		int id, HP_min, HP_max, VIT_min, VIT_max, ATT_min, ATT_max, DEF_min, DEF_max;
		float flood, fall, paralysis, poison, burn, heal;
	};

public:
	std::vector<CPlayer> joueurs; //Le joueur connait sa position
	std::vector <std::vector <CTerrain> > cases; //our vector of cases
	//config
	std::vector<TypePokemon> ListePokemon;//utiliser pour créer des pokemons pour les joueurs
	std::vector<CTerrain> ListeTerrain;

	CWorld();
	~CWorld();
	
	//setter
	void add_player(CPlayer player);//On ajoute le joueur au monde et on lui donne les pointeurs du monde (pour acceder au config et aux autres joueurs) //todo ameliorer cela
	void set_dimension(int x, int y);
	void generate_terrain();
	void move_player(int id, int x, int y);
	//getter
	std::vector<CPlayer> Player(int posX, int posY); //Donne la liste des joueurs sur cette case, si > 2 alors un match est déclaré.
	int dimension(bool xy);//false=x, y=true;
	int connected_player();
	void list_player();
	void detail_list_player();
	void map_view_terrain();
	//void print_map();
	//CTerrain terrain(int posX, int posY);
	

	
};
#endif // !_CWORLD_H
