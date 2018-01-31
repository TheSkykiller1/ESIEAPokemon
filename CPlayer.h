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
#include "CFire.h"
#include "CRock.h"
#include "CWater.h"
#include "CElectric.h"
#include "CPlant.h"
#include "CInsect.h"
#include "CObject.h"
#include "CPotion.h"
#include "CDrug.h"

class CPlayer
{
///========================================================================
protected:
	//===================Variables=====================

	int id_player;
	std::string s_pseudo="Unknow";

	int s_nb_fight=0;
	int s_nb_win=0;

	CTerrain* s_cases; //Pointer of the cases where is the player (Given by CWorld)
	int s_posx=0;
	int s_posy=0;

	CPlayer* s_target; //Pointer of the target player (Given by GameManager)
	int id_pokemon = 0;
	int maxpokeballs = 3;
	int maxobjects = 5;

///========================================================================
public:
	//===================Variables=====================

	int id_actif = 0;	//Quel pokemon est actif en ce moment dans le vector<CMonster*> Pokeballs

	//==================Methodes======================
	//---------Constructeurs / Destructeur-------

	CPlayer();
	CPlayer(int id, std::string name, int posX=0, int posY=0, int fight_count = 0, int fight_win = 0);
	~CPlayer();

	//---------Variables discretes----//Temporairement public

	std::vector<CMonster*> Pokeballs;

	std::vector<CObject*> objects_player;
	std::vector<int> nb_objects_base;		//combien on a selectionner chaque objets
	std::vector<int> nb_objects;			//combien il reste d'utilisation des objets

	//---------Methodes--------------------------

	//---------Getters-----
	int get_id();
	std::string pseudo();

	int fight_count();
	int fight_win();

	void list_pokemon();			//Affiche les pokemon et leur stats de base (base_damage, etc)

	CPlayer* target();

	int positionX();
	int positionY();

	CTerrain* type_terrain();
	
	//---------Setters-----

	void match_fini(bool win);	 //add 1 match to the counter, and 1 to win if match is won, exp gain are handled by this function
	void match_reset();		//remet au stade initial le joueur et ses pokemons

	void set_object(std::vector<CObject*> listeobject);	//set object list (copy from CWorld)
	void set_nb_oject(int id, int nb);

	void add_pokemon(CMonster* pokemon);

	void move(int X, int Y);
	void move(int X, int Y, CTerrain* terrain, CPlayer* cible);
	void set_target(CPlayer* cible);
	void set_terrain(CTerrain* terrain);

	void attaquer();
	bool check();//false: perdu, true: encore des pokemon en vie;


///========================================================================
};
#endif

