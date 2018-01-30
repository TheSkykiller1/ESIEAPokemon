#include <iostream>
#include "CMonster.h"
#include "CPlayer.h"
#include "CWorld.h"

int main()
{
	int id = 0;
	CWorld Monde;
	std::cout << "\n\n\t\t\t Bienvenue dans PokeLeague \n\
Que voulez-vous faire : \n\
\t 1) Lancer une partie \n\
\t 2) Quitter\n";
	int choix = 0;
	int tailleX = -1, tailleY = -1;
	int i1 = 1;
	CMonster pokemon;
	std::cin >> choix;
	switch (choix) {
	case 1:
		system("CLS");
		std::cout << "\t\t\t Creation du monde \n\
\t Choisir la taille du monde: format:\"x puis y\" :\n";
		while ((tailleX > 20) || (tailleX < 0) || (tailleY > 20) || (tailleY < 0))
		{
			std::cout << "X:";
			std::cin >> tailleX;
			std::cout << "Y:";
			std::cin >> tailleY;
		}
		std::cout << "Taille choisie: X: " << tailleX << " Y: " << tailleY << "\n";
		Monde.set_dimension(tailleX, tailleY);
		Monde.generate_terrain();
		Monde.map_view_terrain();
		system("pause");
		system("cls");

		std::cout << "\t\t\t Creation des personnages \n\
\t Choisir le nombre de personnages: ";
		int nb;
		std::cin >> nb;
		std::cout << "\t Veuillez renseigner les différents champs: \n";
		for (int i = 0;i < nb;i++)
		{
			std::string name; int posX, posY;
			std::cout << "Joueur " << i+1 << " Nom: ";
			std::cin >> name;
			std::cout << "\nJoueur " << i+1 << " " << name << " X: ";
			std::cin >> posX;
			std::cout << "Joueur " << i+1 << " " << name << " Y: ";
			std::cin >> posY;
			CPlayer joueur(id++,name, posX, posY);
			Monde.add_player(joueur);
			while (i1 <= 3)
			{
				system("CLS");
				std::cout << "Joueur " << i << " " << name << " position X: " << posX << " Y:" << posY << "\n";
				for (int i2 = 0; i2 < Monde.ListePokemon.size(); i2++)
				{
					int att = Monde.ListePokemon[i2].ATT_min + rand()*(Monde.ListePokemon[i2].ATT_max - Monde.ListePokemon[i2].ATT_min) / RAND_MAX;
					int def = Monde.ListePokemon[i2].DEF_min + rand()*(Monde.ListePokemon[i2].DEF_max - Monde.ListePokemon[i2].DEF_min) / RAND_MAX;
					int vit = Monde.ListePokemon[i2].VIT_min + rand()*(Monde.ListePokemon[i2].VIT_max - Monde.ListePokemon[i2].VIT_min) / RAND_MAX;
					int HP = Monde.ListePokemon[i2].HP_min + rand()*(Monde.ListePokemon[i2].HP_max - Monde.ListePokemon[i2].HP_min) / RAND_MAX;
					std::cout << Monde.ListePokemon[i2].name << " Att: " << att << " Def: " << def << " Vit : " << vit << " HP  :" << HP << "\n";
				}
				std::cout << "\nChoix des monstres : " << i1 << "/3\n";
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
						i1++;
					}
				}
				if (test == 0)
				{
					std::cout << "Nom introuvable\n";
					system("pause");
				}
				test = 0;
			}
			i1 = 1;
		}
		system("CLS");
		for (int i = 0; i < nb; i++)
		{
			system("cls");
			std::cout << "\t\tChoix des objets :\n";
			int i1 = 0;
			while (i1< Monde.ListeObject.size())
			{
				std::cout << "Nom : " << Monde.ListeObject[i1].getNom() << " Genre :" << Monde.ListeObject[i1].getGenre() << " Att : " << Monde.ListeObject[i1].getAtt() << " Def : " << Monde.ListeObject[i1].getDef() << " Vit : " << Monde.ListeObject[i1].getVit() << " HP : " << Monde.ListeObject[i1].getHP() << "\n";
				i1++;
			}
			system("pause");
		}
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