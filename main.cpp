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
	int tailleX = -1, tailleY = -1;
	int i = 1;
	CMonster pokemon;
	std::cin >> choix;
	switch (choix) {
	case 1:
		system("CLS");
		std::cout << "\t\t\t Creation du monde \n\
\t Choisir la taille du monde: format:\"x y\" :\n";
		while ((tailleX > 20) || (tailleX < 0) || (tailleY > 20) || (tailleY < 0))
		{
			std::cin >> tailleX;
			std::cin >> tailleY;
		}
		std::cout << "Taille choisie: X: " << tailleX << " Y: " << tailleY << "\n";
		Monde.set_dimension(tailleX, tailleY);
		Monde.generate_terrain();
		Monde.map_view_terrain();

		std::cout << "\t\t\t Creation des personnages \n\
\t Choisir le nombre de personnages: \n";
		int nb;
		std::cin >> nb;
		std::cout << "\t Veuillez renseigner les différents champs: \n";
		for (int i = 0;i < nb;i++)
		{
			std::string name; int posX, posY;
			std::cout << "Joueur " << i << " Nom: ";
			std::cin >> name;
			std::cout << "Joueur " << i << " " << name << " X: ";
			std::cin >> posX;
			std::cout << "Joueur " << i << " " << name << " Y: ";
			std::cin >> posY;
			CPlayer joueur(name, posX, posY);
			Monde.add_player(joueur);
			std::cout << "Joueur " << i << " " << name << " position X: " << posX << " Y:" << posY << "\n";
			while (i <= 3)
			{
				std::cout << "Choix des monstres : " << i << "/3\n";
				std::cout << "Sélectionner le nom du monstre voulu :\n";
				std::string nom;
				bool test = 0;
				std::cin >> nom;
				for (int j=0; j < Monde.ListePokemon.size(); j++)
				{
					if (Monde.ListePokemon[j].name == nom && test==0)
					{
						joueur.add_pokemon(pokemon);
						test = 1;
						i++;
					}
				}
				if (test == 0)
				{
					std::cout << "Nom introuvable\n";
				}
				test = 0;
			}
		}
		Monde.list_player();

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