#include <iostream>
#include "CMonster.h"
#include "CPlayer.h"
#include "CWorld.h"

/*Fonction regroupant tout le jeu*/
void jeux()
{
	//====================Etape 1: Creation du monde==========================

	int tailleX, tailleY;
	bool invalid = true;
	while (invalid)
	{
		system("CLS");
		std::cout << "\t\t\t Creation du monde \n\
\t Choisir la taille du monde (max 20*20):\n X:";
		std::cin >> tailleX;
		std::cout << "Y:";
		std::cin >> tailleY;
		if ((tailleX > 0) && (tailleX < 20) && (tailleY > 0) && (tailleY < 20)) { invalid = false; }
	}
	std::cout << "Taille choisie: X: " << tailleX << " Y: " << tailleY << "\n";
	CWorld Monde;
	Monde.set_dimension(tailleX, tailleY);
	Monde.generate_terrain();
	Monde.map_view_terrain();

	//====================Etape 2: Creation des joueurs==========================

	int id = 0;
	int nb_player = 0;
	int nb = 0;
	while (true)
	{
		std::cout << "\t\t\t Creation des personnages \n\
\t Choisir le nombre de personnages (max:2) :";
		std::cin >> nb_player;
		if ((nb_player > 0) && (nb_player < 3)) { break; }
	}

	std::cout << "\n \t Veuillez renseigner les différents champs: \n";
	for (int i = 0;i < nb_player;i++)
	{
		std::string name; int posX, posY;
		std::cout << "Joueur " << i + 1 << " Nom: ";
		std::cin >> name;
		std::cout << "Joueur " << i + 1 << " " << name << " X: ";
		std::cin >> posX;
		std::cout << "Joueur " << i + 1 << " " << name << " Y: ";
		std::cin >> posY;

		CPlayer joueur(id++, name, posX, posY);
		Monde.add_player(joueur);//On l'ajoute au monde
		Monde.joueurs[i].set_terrain(&Monde.cases[posX][posY]);//On assigne le terrain de la case au joueur
		std::cout << "Joueur " << i + 1 << " " << name << " X: " << posX << " Y: " << posY << " est sur le terrain: " << Monde.cases[posX][posY].Title() << "\n";
		system("pause");

		//====================Etape 3: Assignation de pokemon pour les joueurs==========================
		while (nb < 3)
		{
			system("CLS");
			std::cout << "\t\tChoix des pokemons pour le joueur " << i + 1 << " " << name << " position X: " << posX << " Y:" << posY << "\n\n\n";
			//Affichage de toutes les statistiques de chaque pokemon

			for (int i2 = 0; i2 < Monde.ListePokemon.size(); i2++)
			{
				int att = rand() % (Monde.ListePokemon[i2].ATT_max - Monde.ListePokemon[i2].ATT_min) + Monde.ListePokemon[i2].ATT_min;
				int def = rand() % (Monde.ListePokemon[i2].DEF_max - Monde.ListePokemon[i2].DEF_min) + Monde.ListePokemon[i2].DEF_min;
				int vit = rand() % (Monde.ListePokemon[i2].VIT_max - Monde.ListePokemon[i2].VIT_min) + Monde.ListePokemon[i2].VIT_min;
				int HP = rand() % (Monde.ListePokemon[i2].HP_max - Monde.ListePokemon[i2].HP_min) + Monde.ListePokemon[i2].HP_min;
				std::cout << "\t -" << i2 << ")" << Monde.ListePokemon[i2].name << " \t\t| Att: " << att << " \t| Def: " << def << " \t| Vit : " << vit << " \t| HP  :" << HP << "\n";
			}
			std::cout << "\nChoix des monstres : " << nb << "/3\n";
			std::cout << "Sélectionner le nom du monstre voulu : \t";
			std::string nom;
			bool test = 0;
			std::cin >> nom;
			for (int j = 0; j < Monde.ListePokemon.size(); j++)
			{
				if (Monde.ListePokemon[j].name == nom && test == 0)
				{
					CMonster pokemon;
					Monde.joueurs[i].add_pokemon(pokemon);
					test = 1;
					nb++;
				}
			}
			if (test == 0)
			{
				std::cout << "Nom introuvable\n";
				system("pause");
			}
			test = 0;
		}
		nb = 0;

		//====================Etape 4: Assignation des objets pour les joueurs==========================

		int object_nb = 0;
		Monde.joueurs[i].set_object(Monde.ListeObject);//On donne au joueur la liste des objets
		while (object_nb < 5)
		{
			system("cls");
			std::cout << "Choix des objets :\n";
			for (int i2 = 0; i2 < Monde.ListeObject.size(); i2++)
			{
				std::cout << "\t -" << Monde.ListeObject[i2].getId() << ") Nom : \"" << Monde.ListeObject[i2].getNom() << "\"\t | Genre : \"" << Monde.ListeObject[i2].getGenre() << "\"\t | Attack : " << Monde.ListeObject[i2].getAtt() << "\t | Defense : " << Monde.ListeObject[i2].getDef() << "\t | Vitesse : " << Monde.ListeObject[i2].getVit() << "\t | HP : " << Monde.ListeObject[i2].getHP() << "\n";
			}
			std::cout << "\nChoix des objets : " << object_nb << "/5\n";
			std::cout << "Valeur du tableau des objets dans joueurs: " << Monde.joueurs[i].objects.size() << "\n";
			std::cout << "Sélectionner l'id de l'objet voulu : \n";
			int choix_id;
			bool test = 0;
			std::cin >> choix_id;
			for (int j = 0; j < Monde.joueurs[i].objects.size();j++)
			{
				if ((Monde.joueurs[i].objects[j].getId() == choix_id) && (test == 0))
				{
					std::cout << "Monde objet id: " << Monde.joueurs[i].objects[j].getId() << " et l'id choisi est: " << choix_id << " Objet: " << object_nb << "\n";
					test = 1;
					object_nb++;
					system("pause");
				}
				/*if ((Monde.joueurs[i].objects[j].getId() == choix_id) && (test == 0))
				{
				test = 1;
				int obj = Monde.joueurs[i].nb_objects_base[j];
				Monde.joueurs[i].set_nb_oject(j, obj++);
				std::cout<<"Vous avez ajouter: "<< Monde.joueurs[i].objects[j].getNom()<<", le total de cet objet est de: "<< Monde.joueurs[i].nb_objects_base[j]<<"\n";
				object_nb++;
				system("pause");
				}*/
			}
			if (test == 0)
			{
				std::cout << "Nom introuvable\n";
				system("pause");
			}
			test = 0;
		}
	}
}

/*Menu de control du jeu*/

void menu()
{
	while (1)
	{
		system("CLS");
		std::cout << "\t\t\t Bienvenue dans PokeLeague \n\
Que voulez-vous faire : \n\
\t 1) Lancer une partie \n\
\t 2) Quitter\n";
		int choix = 0;
		std::cin >> choix;
		switch (choix) {
		case 1:
			jeux();
			break;
		case 2:
			exit(0);
			break;
		default:
			std::cout << "Aucune commande associe a l'entree! \n";
			break;
		}
		system("pause");
	}
}

int main()
{
	menu();

	/*CPlayer Sacha("Sacha", true, 0, 0);
	Sacha.add_pokemon(FEU, "Salameche", 10, 50, 254, 5);
	Sacha.add_pokemon(FEU, "salo", 10, 50, 254, 5);
	Sacha.add_pokemon(FEU, "sali", 11, 51, 25, 5);g
	Sacha.add_pokemon(FEU, "salut", 12, 52, 15, 5);
	Sacha.add_pokemon(FEU, "salto", 13, 53, 45, 5);
	Sacha.add_pokemon(FEU, "saloute", 14, 54, 65, 5);
	Sacha.add_pokemon(FEU, "sallumer", 15, 55, 84, 5);
	Sacha.add_pokemon(FEU, "salouminer", 16, 56, 45, 5);
	Sacha.delete_pokemon();*/
	//CPlayer Sacha("Sacha", true, 0, 0);
	system("pause");

}