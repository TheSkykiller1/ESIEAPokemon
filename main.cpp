#include <iostream>
#include "CMonster.h"
#include "CPlayer.h"
#include "CWorld.h"

int main()
{
	CWorld Monde;
	std::cout << "\t\t\t Bienvenue dans PokeLeague \n\
Que voulez-vous faire : \n\
\t 1) Lancer une partie \n\
\t 2) Quitter\n";
	int choix = 0;
	std::cin >> choix;
	switch (choix) {
	case 1:
		system("CLS");
		std::cout << "\t\t\t Creation du monde \n\
\t Choisir la taille du monde: format:\"x y\" :\n";
		int tailleX, tailleY;
		std::cin >> tailleX;
		std::cin >> tailleY;
		std::cout << "Taille choisie: X: " << tailleX << " Y: " << tailleY << "\n";
		Monde.set_dimension(tailleX, tailleY);
		Monde.generate_terrain();
		Monde.map_view_terrain();

		break;
	case 2:
		// Code
		break;
	default:
		// Code
		break;
	}
	/*CPlayer Sacha("Sacha", true, 0, 0);
	Sacha.add_pokemon(FEU, "Salameche", 10, 50, 254, 5);
	Sacha.add_pokemon(FEU, "salo", 10, 50, 254, 5);
	Sacha.add_pokemon(FEU, "sali", 11, 51, 25, 5);
	Sacha.add_pokemon(FEU, "salut", 12, 52, 15, 5);
	Sacha.add_pokemon(FEU, "salto", 13, 53, 45, 5);
	Sacha.add_pokemon(FEU, "saloute", 14, 54, 65, 5);
	Sacha.add_pokemon(FEU, "sallumer", 15, 55, 84, 5);
	Sacha.add_pokemon(FEU, "salouminer", 16, 56, 45, 5);
	Sacha.delete_pokemon();*/
	//CPlayer Sacha("Sacha", true, 0, 0);
	system("pause");

}