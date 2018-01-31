#include <iostream>
#include "CMonster.h"
#include "CPlayer.h"
#include "CWorld.h"


//Save les types de pokemons pour les "construire"
struct TypePokemon {
	std::string type, name;
	int id, HP_min, HP_max, VIT_min, VIT_max, \
		ATT_min, ATT_max, DEF_min, DEF_max;

	float flood, fall, paralysis, poison, burn, heal;
};

int nb_joueurs = 0;
std::vector<CPlayer> Joueurs;

std::vector<CMonster*> ListePokemon;
std::vector<TypePokemon> ListeTypePokemon;

std::vector<CObject*> ListeObject;

CWorld Monde;

//===================PARSER==========================
template<typename Out>
void split(const std::string &s, char delim, Out result)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) { *(result++) = item; }
}
std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}
//====================================================

void read_config_pokemon()
{
	std::string row;
	std::ifstream File("monsters.pkmn", std::ios::in);
	int id = 0;
	if (File.is_open())
	{
		while (getline(File, row))
		{
			if (row == "Monster")//Debut du bloc
			{
				TypePokemon pokemon;
				pokemon.id = id++;
				while (row != "EndMonster")//Tant que l'on est dans le bloc
				{
					getline(File, row);
					if (row == "EndMonster") { break; }//Si on a fini le bloc on quitte
					std::vector<std::string> token = split(row, '\t\t');
					std::vector<std::string> element;
					for (int i = 0;i < token.size();i++)//On clear les elements vides
					{
						if (token[i] != "") { element.push_back(token[i]); }
					}

					//Analyse des resultats
					if (element[0] == "Name") { pokemon.name = element[1]; }
					else if (element[0] == "Type") { pokemon.type = element[1]; }
					else if (element[0] == "HP")
					{
						pokemon.HP_min = std::stoi(element[1]);
						pokemon.HP_max = std::stoi(element[2]);
					}
					else if (element[0] == "Speed")
					{
						pokemon.VIT_min = std::stoi(element[1]);
						pokemon.VIT_max = std::stoi(element[2]);
					}
					else if (element[0] == "Attack")
					{
						pokemon.ATT_min = std::stoi(element[1]);
						pokemon.ATT_max = std::stoi(element[2]);
					}
					else if (element[0] == "Defense")
					{
						pokemon.DEF_min = std::stoi(element[1]);
						pokemon.DEF_max = std::stoi(element[2]);
					}
					else if (element[0] == "Paralysis")
					{
						pokemon.paralysis = stof(element[1]);
					}
					else if (element[0] == "Flood")
					{
						pokemon.flood = stof(element[1]);
					}
					else if (element[0] == "Fall")
					{
						pokemon.fall = stof(element[1]);
					}
					else if (element[0] == "Poison")
					{
						pokemon.poison = stof(element[1]);
					}
					else if (element[0] == "Burn")
					{
						pokemon.burn = stof(element[1]);
					}
					else if (element[0] == "Heal")
					{
						pokemon.heal = stof(element[1]);
					}
				}
				ListeTypePokemon.push_back(pokemon);
			}
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier \n";
	}
}
void read_config_object()
{
	std::string row;
	std::ifstream File("object.pkmn", std::ios::in);
	if (File.is_open())
	{
		while (getline(File, row))
		{
			if (row == "object")//Debut du bloc
			{
				std::string name, genre, etat;
				int id;
				int attack = 0, defense = 0, hp = 0, speed = 0;
				std::vector<std::string> type;

				while (row != "Endobject")//Tant que l'on est dans le bloc
				{
					getline(File, row);
					if (row == "Endobject") { break; }//Si on a fini le bloc on quitte
					std::vector<std::string> token = split(row, '\t\t');
					std::vector<std::string> element;
					for (int i = 0;i < token.size();i++)//On clear les elements vides
					{
						if (token[i] != "") { element.push_back(token[i]); }
					}

					if (element[0] == "Name") { name = element[1]; }
					else if (element[0] == "Id")
					{
						id = stoi(element[1]);
					}
					else if (element[0] == "Genre")
					{
						genre = element[1];
					}
					else if (element[0] == "Type")
					{
						for (int b = 1;b < element.size();b++)
						{
							type.push_back(element[b]);
							//std::cout << "TYPE : " << element[b] << " -" << b << ") \t";
						}
						std::cout << "\n";
					}
					else if (element[0] == "Heal")
					{
						hp = stoi(element[1]);
					}
					else if (element[0] == "Speed")
					{
						speed = stoi(element[1]);
					}
					else if (element[0] == "Attack")
					{
						attack = stoi(element[1]);
					}
					else if (element[0] == "Defense")
					{
						defense = stoi(element[1]);
					}
					else if (element[0] == "State")
					{
						etat = element[1];
					}
				}
				//std::cout << "Info id: " << id << " genre:" << genre << " name:" << name << " speed:" << speed << " attack:" << attack << " defense:" << defense << " hp:" << hp << "\n";
				if (genre == "Potion")
				{
					CPotion *potion;
					potion = new CPotion(id, genre, name, type, speed, attack, defense, hp);
					ListeObject.push_back(potion);
					int pos = std::find(ListeObject.begin(), ListeObject.end(), potion) - ListeObject.begin();
					Monde.ListeObjets.push_back(ListeObject[pos]);
					//std::cout << "Potion id: " << potion.getId() << " genre:" << potion.getGenre() << " name:" << potion.getNom() << " speed:" << potion.getVit() << " attack:" << potion.getAtt() << " defense:" << potion.getDef() << " hp:" << potion.getHP() << "\n\n";
				}
				if (genre == "Drug")
				{
					CDrug *drug;
					drug = new CDrug(id, genre, name, type, etat);
					ListeObject.push_back(drug);
					int pos = std::find(ListeObject.begin(), ListeObject.end(), drug) - ListeObject.begin();
					Monde.ListeObjets.push_back(ListeObject[pos]);
				}
			}
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier \n";
	}
}

void afficher_objets()
{
	std::cout << "Tous les objets disponibles: \n";
	for (int i = 0;i < ListeObject.size();i++)
	{
		CObject* objets = ListeObject[i];

		std::cout << "\t -" << objets->getId() << ") Nom : \"" << objets->getNom() << "\"\t | Genre : \"" << \
			objets->getGenre() << "\"\t | Attack : " << objets->getAtt() << "\t | Defense : " << \
			objets->getDef() << "\t | Vitesse : " << objets->getVit() << "\t | HP : " << \
			objets->getHP() << "\t | etat : " << objets->getEtat() << "\n";
	}
}


void jouer()
{
	system("cls");
	std::cout << "Creation de deux joueurs:\n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Speudo joueur " << i + 1 << ": ";
		std::string pseudo;
		std::cin >> pseudo;
		CPlayer joueur(nb_joueurs++, pseudo);
		Joueurs.push_back(joueur);
	}
	for (int i = 0; i < 2; i++)
	{
		system("cls");
		std::cout << "Creation des pokemons pour chaque joueurs:\n";
		for (int u = 0;u < ListeTypePokemon.size();u++)
		{
			TypePokemon pk = ListeTypePokemon[u];
			std::cout << "\t-" << pk.id << ") " << pk.name << " type: " << pk.type << \
				" HP (min/max): " << pk.HP_min << "/" << pk.HP_max << " Attack (min/max): " << pk.ATT_min << "/" << pk.ATT_max << \
				" Defense (min/max): " << pk.DEF_min << "/" << pk.DEF_max << " Speed (min/max): " << pk.VIT_min << "/" << pk.VIT_max << \
				"\n";
		}
		std::cout << "Choisir 3 pokemons (ID) \n";
		int nbchoix = 0;
		while (nbchoix < 3)
		{
			std::cout << "Choix " << nbchoix + 1 << "/3 \n";
			int choix;
			std::cin >> choix;
			for (int u = 0;u < ListeTypePokemon.size();u++) //on recherche l'id
			{
				if (choix == ListeTypePokemon[u].id)
				{
					TypePokemon pokemon_choisi = ListeTypePokemon[u];

					int hp = rand() % (pokemon_choisi.HP_max - pokemon_choisi.HP_min) + pokemon_choisi.HP_min, \
						att = rand() % (pokemon_choisi.ATT_max - pokemon_choisi.ATT_min) + pokemon_choisi.ATT_min, \
						def = rand() % (pokemon_choisi.DEF_max - pokemon_choisi.DEF_min) + pokemon_choisi.DEF_min, \
						vit = rand() % (pokemon_choisi.VIT_max - pokemon_choisi.VIT_min) + pokemon_choisi.VIT_min;

					if (pokemon_choisi.type == "Electric")
					{
						CElectric *poke;
						poke = new CElectric(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def, pokemon_choisi.paralysis);
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Water")
					{
						CWater *poke;
						poke = new CWater(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Rock")
					{
						CRock *poke;
						poke = new CRock(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Fire")
					{
						CFire *poke;
						poke = new CFire(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Insect")
					{
						CInsect *poke;
						poke = new CInsect(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Plant")
					{
						CPlant *poke;
						poke = new CPlant(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Joueurs[i].add_pokemon(ListePokemon[pos]);
					}
					nbchoix++;
					break;
				}
			}
		}
		std::cout << "Votre joueur possede : ";
		Joueurs[i].list_pokemon();
		std::cout << "Choisir vos objets: MAIN\n";
		afficher_objets();


		system("pause");
		Monde.list_player();
		system("pause");
		//float flood, fall, paralysis, poison, burn, heal;
	}

}


/*Fonction regroupant tout le jeu*/

/*
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
		if ((tailleX > 0) && (tailleX <= 20) && (tailleY > 0) && (tailleY <= 20)) { invalid = false; }
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
			int s_max = 0;
			for (int i = 0; i < Monde.ListeTerrain.size(); i++)
			{
				if (Monde.ListeTerrain[i].Title().size() > s_max)
				{
					s_max = Monde.ListeTerrain[i].Title().size();
				}
			}
			for (int i2 = 0; i2 < Monde.ListePokemon.size(); i2++)
			{
				int att = rand() % (Monde.ListePokemon[i2].ATT_max - Monde.ListePokemon[i2].ATT_min) + Monde.ListePokemon[i2].ATT_min;
				int def = rand() % (Monde.ListePokemon[i2].DEF_max - Monde.ListePokemon[i2].DEF_min) + Monde.ListePokemon[i2].DEF_min;
				int vit = rand() % (Monde.ListePokemon[i2].VIT_max - Monde.ListePokemon[i2].VIT_min) + Monde.ListePokemon[i2].VIT_min;
				int HP = rand() % (Monde.ListePokemon[i2].HP_max - Monde.ListePokemon[i2].HP_min) + Monde.ListePokemon[i2].HP_min;
				std::cout << "\t -" << i2 << ")" << Monde.ListePokemon[i2].name;
				int i = Monde.ListePokemon[i2].name.size();
				while (i < s_max)
				{
					std::cout << " ";
					i++;
				}
				std::cout << " \t\t| Att: " << att << " \t| Def: " << def << " \t| Vit : " << vit << " \t| HP  :" << HP << "\n";
			}
			std::cout << "\nChoix des monstres : " << nb+1 << "/3\n";
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
				}
			}
			if (test == 0)
			{
				std::cout << "Nom introuvable\n";
				system("pause");
			}
			test = 0;
		}
	}
}*/

int main()
{
	read_config_object();
	read_config_pokemon();

	Monde.set_liste_objet(ListeObject);

	jouer();
	system("pause");
}