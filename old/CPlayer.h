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
protected:
public:

	int id_player;
	std::string s_pseudo = "Unknow";

	CTerrain* s_cases; //Pointer du terrain

	CPlayer* s_target; //Pointer of the target player

	int id_pokemon_actif = 0;
	int max_pokemon = 3;
	int max_objects = 5;

	std::vector<CMonster*> Pokemons;
	
	std::vector<CDrug> Drugs;
	std::vector<CPotion> Potions;

	CPlayer();
	CPlayer(int id, std::string name);
	~CPlayer();

	void add_pokemon(CMonster* pokemon);
	void attaquer();
	void use_object();
	bool check();



};
#endif

