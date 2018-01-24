#ifndef _CPlayer_H
#define _CPlayer_H
#include <iostream>
#include <vector>
#include <fstream>//ifstream
#include <string>//getline
#include "CMonster.h"
class CPlayer
{
protected:
	static int id;
	int self_id;
	std::string s_pseudo;
	bool isPlayable;//Si c'est une IA ou un vrai joueur
	short s_level;
	int s_exp;//exp du level
	int s_exp_up; //exp necessaire pour level up
	int s_nb_fight;
	int s_nb_win;

	int s_posx;
	int s_posy;

	void read_level_requirement();//read level and xp needed from config
	void level_refresh(); //refresh player level

public:
	CPlayer();
	CPlayer(std::string name, bool isPlayer, int posX, int posY, int fight_count = 0, int fight_win = 0, short level=0, int xp = 0);
	CPlayer(std::string name, bool isPlayer, int posX, int posY, std::vector<CMonster> Pokeball, int fight_count = 0, int fight_win = 0,short level=0, int xp = 0);
	~CPlayer();
	///temp
	std::vector<int> s_tablevel;
	std::vector<CMonster> Pokeballs;
	///temp

	//getter
	std::string pseudo();
	short level();
	int xp();
	int xp_up();
	int fight_count();
	int fight_win();
	void list_pokemon();//Affiche les pokemon et leur stats de base (base_damage, etc)

	//setter
	void set_pseudo(std::string pseudo);
	void change_level(short s_level); //debug only! level_refresh is called for reset xp and xp_up to correct value and assign bonus if any
	void set_exp(int exp);
	void give_exp(int exp);
	void match_fini(bool win,int exp=0); //add 1 match to the counter, and 1 to win if match is won, exp gain are handled by this function
	void add_pokemon(const CMonster& pokemon);
	void delete_pokemon(int id_pokemon);

};
#endif

