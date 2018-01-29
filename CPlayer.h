#ifndef _CPlayer_H
#define _CPlayer_H
#include <iostream>
#include <fstream>//ifstream
#include <string>//getline
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "CTerrain.h"
#include "CMonster.h"
//#include "CObject.h"
class CPlayer
{
protected:
	int id_pokemon = 0;
	std::string s_pseudo;
	short s_level;
	int s_exp;//exp du level
	int s_exp_up; //exp necessaire pour level up
	int s_nb_fight;
	int s_nb_win;
	int maxpokeballs = 3;
	int maxobjects = 5;
	int s_posx;
	int s_posy;
	int id_actif = 0;
	CPlayer* s_target; //Pointer of the target player (Given by GameManager)
	CTerrain* s_cases; //Pointer of the cases where is the player (Given by CWorld)
	//CWorld* s_world; // Pointer of the world (Given by CWorld) Warning Only for view data (Can destroy itself with it ! recurvise targeter)
	void level_refresh(); //refresh player level

public:
	void read_level_requirement();//read level and xp needed from config
	CPlayer();
	CPlayer(std::string name, int posX, int posY, int fight_count = 0, int fight_win = 0, short level=0, int xp = 0);
	CPlayer(std::string name, int posX, int posY, std::vector<CMonster> Pokeball, int fight_count = 0, int fight_win = 0,short level=0, int xp = 0);
	~CPlayer();
	///temp
	std::vector<int> Liste_level;
	std::vector<CMonster> Pokeballs;
	std::vector<CObject> objects;
	std::vector<int> nb_objects_base;//Au depart des combats
	std::vector<int> nb_objects;//utiliser pendant les combats pour savoir combien il reste d'utilisation des objets
	///temp

	void use_object();


	//getter
	std::string pseudo();
	short level();
	int xp();
	int xp_up();
	int fight_count();
	int fight_win();
	void list_pokemon();//Affiche les pokemon et leur stats de base (base_damage, etc)
	void tableau_level();
	CPlayer* target();
	CTerrain* type_terrain();
	int positionX();
	int positionY();
	int id_pokemon_actif();

	//setter
	void set_pseudo(std::string pseudo);
	void change_level(short s_level); //debug only! level_refresh is called for reset xp and xp_up to correct value and assign bonus if any
	void set_exp(int exp);
	void give_exp(int exp);
	void match_fini(bool win,int exp=0); //add 1 match to the counter, and 1 to win if match is won, exp gain are handled by this function
	void set_object(std::vector<CObject> listeobject);//set object list
	void set_nb_oject(int id, int nb);
	
	bool add_pokemon(std::string type, std::string nom, int hpe, int vitesse, int attaque, int defense);
	bool add_pokemon(CMonster pokemon);
	void delete_pokemon(int id_pokemon);//Delete directement le pokemon
	void delete_pokemon();//Affiche les pokemon et demande lequel supprimer

	void set_target(CPlayer* cible); //debug only
	void set_terrain(CTerrain* terrain); //debug only

	void attaquer();
	bool check();//false: perdu, true: encore des pokemon en vie;
	




	void move(int X, int Y, CTerrain* terrain, CPlayer* cible); //cible = NULL if no enemy on same cases

	 //Utile pour split les chaines de string avec un delimiter
	template<typename Out>
	void split(const std::string &s, char delim, Out result);

	std::vector<std::string> split(const std::string &s, char delim);
};
#endif

