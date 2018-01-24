#pragma once

#include <thread>
#include <iostream>
#include <string>
#include <Windows.h>

class CJeux
{
public:
	CJeux();
	~CJeux();
	
	int etat;

	void show_menu();//Le menu s'affiche au depart
	void start_game();//Option 1
	void settings();//Option 2
	void quit();//Option 3


	void SetColour(int ForgC);
	void Navigation();
	void Switch(int index);
	void UpdateMenu();

	const int IAIM = 4;
	const int IAIM_SMOOTH = 3;
	const int IWAL = 2;
	const int ITRI = 1;
	const int IRAD = 0;

	int Difficulty = 1;
	int M_Index = 0;
	int Changes = 0;

	bool New_world = false;
	bool RandomPokemon = false;
	bool Settings = false;
	bool disconnect = false;
	bool updated = false;

	std::string bools[2] = { "[OFF]", "[ON]" };
	
};

