#include "CJeux.h"



CJeux::CJeux()
{
}


CJeux::~CJeux()
{
}

void CJeux::start_game()
{

}
void CJeux::settings()
{

}
void CJeux::quit()
{

}



void CJeux::SetColour(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void CJeux::Navigation()
{
	for (int i = 2; i < 180; i++)
	{
		if (GetAsyncKeyState(i) & 0x8000)
		{
			switch (i)
			{
			case 38: // HAUT
				if (M_Index < 4)
					M_Index++;
				Changes++;
				updated = true;
				break;
			case 40: // BAS
				if (M_Index > 0)
					M_Index--;
				Changes++;
				updated = true;
				break;
			case 37: // GAUCHE
				Switch(M_Index);
				Changes++;
				updated = true;
				break;
			case 39: // DROIT
				Switch(M_Index);
				Changes++;
				updated = true;
				break;
			case 13: //enter
				std::cout << "VALIDER\n";
				Changes++;
				updated = true;
				break;
			}
			Sleep(100);
		}
	}
}

void CJeux::Switch(int index)
{
	if (index == 4)
	{
		New_world = !New_world;
	}
	if (index == 3)
	{
		if (GetAsyncKeyState(37))
		{
			if (Difficulty > 1)
			{
				Difficulty--;
			}
		}
		else if (GetAsyncKeyState(39))
		{
			if (Difficulty < 5)
			{
				Difficulty++;
			}
		}
	}
	if (index == 2)
	{
		RandomPokemon = !RandomPokemon;
	}
	if (index == 1)
	{
		Settings = !Settings;
	}
	if (index == 0)
	{
		disconnect = !disconnect;
	}

}

void CJeux::UpdateMenu()
{
	int temp = -1;
	if (temp != Changes)
	{
		temp = Changes;
		system("CLS");
		SetColour(15);
		std::cout << "________________________________________________________________" << std::endl << std::endl;
		std::cout << "                        >>  Menu <<" << std::endl;
		std::cout << "________________________________________________________________" << std::endl << std::endl;

		if (M_Index == 4)
		{
			SetColour(10);
			std::cout << " Nouveau monde\t\t\t\t=\t\t" << bools[New_world] << std::endl;
		}
		else
		{
			SetColour(15);
			std::cout << " Nouveau monde\t\t\t\t=\t\t" << bools[New_world] << std::endl;
		}

		//--------------

		if (M_Index == 3)
		{
			SetColour(10);
			std::cout << " Difficulte\t\t\t\t=\t\t[" << Difficulty << " ] " << std::endl;
		}
		else
		{
			SetColour(15);
			std::cout << " Difficulte\t\t\t\t=\t\t[" << Difficulty << " ] " << std::endl;
		}

		//--------------

		if (M_Index == 2)
		{
			SetColour(10);
			std::cout << " Utiliser des pokemons aleatoires\t=\t\t" << bools[RandomPokemon] << std::endl;
		}
		else
		{
			SetColour(15);
			std::cout << " Utiliser des pokemons aleatoires\t=\t\t" << bools[RandomPokemon] << std::endl;
		}

		//--------------

		if (M_Index == 1)
		{
			SetColour(10);
			std::cout << " Editer les parametres\t\t\t=\t\t" << bools[Settings] << std::endl;
		}
		else
		{
			SetColour(15);
			std::cout << " Editer les parametres\t\t\t=\t\t" << bools[Settings] << std::endl;
		}

		//--------------

		if (M_Index == 0)
		{
			SetColour(10);
			std::cout << " Quitter\t\t\t\t=\t\t" << bools[disconnect] << std::endl;
		}
		else
		{
			SetColour(15);
			std::cout << " Quitter\t\t\t\t=\t\t" << bools[disconnect] << std::endl;
		}
	}
	//}
}

void CJeux::show_menu()
{
	UpdateMenu();
	for (;;) {
		Navigation();
		if (updated == true)
		{
			updated = false;
			UpdateMenu();
		}
		Sleep(50);
	}

	system("PAUSE");
}