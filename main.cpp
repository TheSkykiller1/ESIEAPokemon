#include <iostream>
#include "CMonster.h"
#include "CPlayer.h"
#include "CWorld.h"

/*Informations
*L'utilisation de \x82"" est pour affiché le caractère é dans la console windows
ü : \x81
â : \x83
ä : \x84
à : \x85
ç : \x87
ê : \x88
ë : \x89
è : \x8A
ï : \x8B
î : \x8C
*/

//Save les types de pokemons pour les "construire"
struct TypePokemon {
	std::string type, name;
	int id, HP_min, HP_max, VIT_min, VIT_max, \
		ATT_min, ATT_max, DEF_min, DEF_max;

	float flood, fall, paralysis, poison, burn, heal;
};

int nb_joueurs = 0;

std::vector<CMonster*> ListePokemon;
std::vector<TypePokemon> ListeTypePokemon;
std::vector<CAttaque*> ListeAttaques;
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


void read_config_attaque()
{
	std::string row;
	std::ifstream File("attacks.pkmn", std::ios::in);
	if (File.is_open())
	{
		while (getline(File, row))
		{
			if (row == "Attack")//Debut du bloc
			{	//Value only!
				std::string name, type;
				int power = 0, nbuse = 0;
				float fail = 0.0f;
				while (row != "EndAttack")//Tant que l'on est dans le bloc
				{
					getline(File, row);
					if (row == "EndAttack") { break; }//Si on a fini le bloc on quitte
					std::vector<std::string> token = split(row, '\t\t');
					std::vector<std::string> element;
					for (int i = 0;i < token.size();i++)//On clear les elements vides
					{
						if (token[i] != "") { element.push_back(token[i]); }
					}

					//Analyse des resultats
					if (element[0] == "Name")
					{
						name = element[1];
					}
					else if (element[0] == "Type")
					{
						type = element[1];
					}
					else if (element[0] == "Power")
					{
						power = stoi(element[1]);
					}
					else if (element[0] == "NbUse")
					{
						nbuse = stoi(element[1]);
					}
					else if (element[0] == "Fail")
					{
						fail = stof(element[1]);
					}
				}
				CAttaque *attac;
				attac = new CAttaque(name, type, power, nbuse, fail);
				ListeAttaques.push_back(attac);
			}
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier attacks.pkmn \n";
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
					//std::cout << "Potion id: " << potion.getId() << " genre:" << potion.getGenre() << " name:" << potion.getNom() << " speed:" << potion.getVit() << " attack:" << potion.getAtt() << " defense:" << potion.getDef() << " hp:" << potion.getHP() << "\n\n";
				}
				if (genre == "Drug")
				{
					CDrug *drug;
					drug = new CDrug(id, genre, name, type, etat);
					ListeObject.push_back(drug);
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
void afficher_objets_joueur(int id)
{
	std::cout << "Vos objets: \n";
	for (int idn = 1;idn < Monde.Joueurs[id].nb_objects_base.size() + 1;idn++)
	{
		std::cout << "\tNom: " << Monde.Joueurs[id].objects_player[idn - 1]->getNom() << " Quantite: " << Monde.Joueurs[id].nb_objects_base[idn - 1] << "\n";
	}
}


void jouer()
{
	system("cls");
	int dimX=-1, dimY=-1;
	while ((dimX < 0) || (dimX > 20) || (dimY < 0) || (dimY > 20))
	{
		std::cout << "\t\t\tCreation du monde: \n";
		std::cout << "Choisir les dimensions: \nX:";
		std::cin >> dimX;
		std::cout << "Y:";
		std::cin >> dimY;
	}
	Monde.set_dimension(dimX, dimY);
	Monde.generate_terrain();
	Monde.map_view_terrain();

	std::cout << "\t\t\tCreation de deux joueurs:\n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Pseudo joueur " << i + 1 << ": ";
		std::string pseudo;
		std::cin >> pseudo;
		int x = -1, y = -1;
		while ((x < 0) || (x > dimX-1) || (y < 0) || (y > dimY-1))
		{
			std::cout << "\t Position du joueur: (A partir du haut a gauche [case 0/0] :\n";
			std::cout << "X:";
			std::cin >> x;
			std::cout << "Y:";
			std::cin >> y;
		}
		
		CPlayer joueur(nb_joueurs++, pseudo,x,y);
		joueur.set_object(ListeObject);
		Monde.Joueurs.push_back(joueur);
		Monde.set_terrain_player(i, x, y); // pour donner le type de terrain au joueur (init seulement après par la commande move)
	}
	for (int i = 0; i < 2; i++)
	{
		system("cls");
		std::cout << "\n\t\t\tCreation des pokemons pour chaque joueurs:\n";
		for (int u = 0;u < ListeTypePokemon.size();u++)
		{
			TypePokemon pk = ListeTypePokemon[u];
			std::cout << "\n\n";
			std::cout << "-" << pk.id << ") " << pk.name << " type: " << pk.type << std::endl;
			std::cout << "\t\t| HP (min/max): " << pk.HP_min << "/" << pk.HP_max;
			std::cout << "\t| Attack (min/max): " << pk.ATT_min << "/" << pk.ATT_max;
			std::cout << "\t| Defense (min/max): " << pk.DEF_min << "/" << pk.DEF_max;
			std::cout << "\t| Speed(min / max) : " << pk.VIT_min << " / " << pk.VIT_max;
			std::cout << std::flush;
		}
		std::cout << "\n Choisir 3 pokemons (ID) \n";
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
						poke->set_attaques_disp(ListeAttaques);

						std::cout << "Choisir 4 Attaques (ID) \n"; //todo Afficher attaque creation
						//afficher_attaques();
						nbchoix = 0;
						while (nbchoix < 4)
						{
							std::cout << "Choix " << nbchoix + 1 << "/4 \n";
							int choix;
							std::cin >> choix;
							if ((choix < ListeAttaques.size()) && (poke->getType() == ListeAttaques[choix]->getType()) && (poke->Attaques_actives[choix] == false))
							{
								poke->Attaques_actives[choix] = true;
								std::cout << "Attaque choisie : " << poke->Attaques_list[choix]->getNom() << "\n";
								nbchoix++;
							}
							else if ((choix < ListeAttaques.size()) &&  (poke->getType() != ListeAttaques[choix]->getType()))
							{
								std::cout << "Choix hors plage, ou attaque invalide sur ce pokemon\n";
							}
							else
							{
								std::cout << "Choix hors plage, ou attaque deja active sur ce pokemon\n";
							}
						}
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Monde.Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Water")
					{
						CWater *poke;
						poke = new CWater(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						poke->set_attaques_disp(ListeAttaques);

						std::cout << "Choisir 4 Attaques (ID) \n"; //todo Afficher attaque creation
																   //afficher_attaques();
						nbchoix = 0;
						while (nbchoix < 4)
						{
							std::cout << "Choix " << nbchoix + 1 << "/4 \n";
							int choix;
							std::cin >> choix;
							if ((choix < ListeAttaques.size()) && (poke->getType() == ListeAttaques[choix]->getType()) && (poke->Attaques_actives[choix] == false))
							{
								poke->Attaques_actives[choix] = true;
								std::cout << "Attaque choisie : " << poke->Attaques_list[choix]->getNom() << "\n";
								nbchoix++;
							}
							else if ((choix < ListeAttaques.size()) && (poke->getType() != ListeAttaques[choix]->getType()))
							{
								std::cout << "Choix hors plage, ou attaque invalide sur ce pokemon\n";
							}
							else
							{
								std::cout << "Choix hors plage, ou attaque deja active sur ce pokemon\n";
							}
						}
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Monde.Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Rock")
					{
						CRock *poke;
						poke = new CRock(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						poke->set_attaques_disp(ListeAttaques);

						std::cout << "Choisir 4 Attaques (ID) \n"; //todo Afficher attaque creation
																   //afficher_attaques();
						nbchoix = 0;
						while (nbchoix < 4)
						{
							std::cout << "Choix " << nbchoix + 1 << "/4 \n";
							int choix;
							std::cin >> choix;
							if ((choix < ListeAttaques.size()) && (poke->getType() == ListeAttaques[choix]->getType()) && (poke->Attaques_actives[choix] == false))
							{
								poke->Attaques_actives[choix] = true;
								std::cout << "Attaque choisie : " << poke->Attaques_list[choix]->getNom() << "\n";
								nbchoix++;
							}
							else if ((choix < ListeAttaques.size()) && (poke->getType() != ListeAttaques[choix]->getType()))
							{
								std::cout << "Choix hors plage, ou attaque invalide sur ce pokemon\n";
							}
							else
							{
								std::cout << "Choix hors plage, ou attaque deja active sur ce pokemon\n";
							}
						}
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Monde.Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Fire")
					{
						CFire *poke;
						poke = new CFire(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						poke->set_attaques_disp(ListeAttaques);
						std::cout << "Choisir 4 Attaques (ID) \n"; //todo Afficher attaque creation
																   //afficher_attaques();
						nbchoix = 0;
						while (nbchoix < 4)
						{
							std::cout << "Choix " << nbchoix + 1 << "/4 \n";
							int choix;
							std::cin >> choix;
							if ((choix < ListeAttaques.size()) && (poke->getType() == ListeAttaques[choix]->getType()) && (poke->Attaques_actives[choix] == false))
							{
								poke->Attaques_actives[choix] = true;
								std::cout << "Attaque choisie : " << poke->Attaques_list[choix]->getNom() << "\n";
								nbchoix++;
							}
							else if ((choix < ListeAttaques.size()) && (poke->getType() != ListeAttaques[choix]->getType()))
							{
								std::cout << "Choix hors plage, ou attaque invalide sur ce pokemon\n";
							}
							else
							{
								std::cout << "Choix hors plage, ou attaque deja active sur ce pokemon\n";
							}
						}
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Monde.Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Insect")
					{
						CInsect *poke;
						poke = new CInsect(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						poke->set_attaques_disp(ListeAttaques);
						std::cout << "Choisir 4 Attaques (ID) \n"; //todo Afficher attaque creation
																   //afficher_attaques();
						nbchoix = 0;
						while (nbchoix < 4)
						{
							std::cout << "Choix " << nbchoix + 1 << "/4 \n";
							int choix;
							std::cin >> choix;
							if ((choix < ListeAttaques.size()) && (poke->getType() == ListeAttaques[choix]->getType()) && (poke->Attaques_actives[choix] == false))
							{
								poke->Attaques_actives[choix] = true;
								std::cout << "Attaque choisie : " << poke->Attaques_list[choix]->getNom() << "\n";
								nbchoix++;
							}
							else if ((choix < ListeAttaques.size()) && (poke->getType() != ListeAttaques[choix]->getType()))
							{
								std::cout << "Choix hors plage, ou attaque invalide sur ce pokemon\n";
							}
							else
							{
								std::cout << "Choix hors plage, ou attaque deja active sur ce pokemon\n";
							}
						}
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Monde.Joueurs[i].add_pokemon(ListePokemon[pos]);
						std::cout << "Ajout d'un pokemon " << pokemon_choisi.type << "\n";
					}
					else if (pokemon_choisi.type == "Plant")
					{
						CPlant *poke;
						poke = new CPlant(pokemon_choisi.id, pokemon_choisi.type, pokemon_choisi.name, hp, vit, att, def);
						poke->set_attaques_disp(ListeAttaques);
						std::cout << "Choisir 4 Attaques (ID) \n"; //todo Afficher attaque creation
																   //afficher_attaques();
						nbchoix = 0;
						while (nbchoix < 4)
						{
							std::cout << "Choix " << nbchoix + 1 << "/4 \n";
							int choix;
							std::cin >> choix;
							if ((choix < ListeAttaques.size()) && (poke->getType() == ListeAttaques[choix]->getType()) && (poke->Attaques_actives[choix] == false))
							{
								poke->Attaques_actives[choix] = true;
								std::cout << "Attaque choisie : " << poke->Attaques_list[choix]->getNom() << "\n";
								nbchoix++;
							}
							else if ((choix < ListeAttaques.size()) && (poke->getType() != ListeAttaques[choix]->getType()))
							{
								std::cout << "Choix hors plage, ou attaque invalide sur ce pokemon\n";
							}
							else
							{
								std::cout << "Choix hors plage, ou attaque deja active sur ce pokemon\n";
							}
						}
						ListePokemon.push_back(poke);
						int pos = std::find(ListePokemon.begin(), ListePokemon.end(), poke) - ListePokemon.begin();
						Monde.Joueurs[i].add_pokemon(ListePokemon[pos]);
					}
					nbchoix++;
					break;
				}
			}
		}
		std::cout << "Votre joueur possede : ";
		Monde.Joueurs[i].list_pokemon();
		system("pause");


		system("cls");
		std::cout << "Choisir 5 objets (ID) \n";
		afficher_objets();
		nbchoix = 0;
		while (nbchoix < 5)
		{
			std::cout << "Choix " << nbchoix + 1 << "/5 \n";
			int choix;
			std::cin >> choix;
			if (choix-1 < Monde.Joueurs[i].nb_objects_base.size())
			{
				int value = Monde.Joueurs[i].nb_objects_base[choix - 1];
				Monde.Joueurs[i].set_nb_oject(choix - 1, ++value);
				std::cout << "Ojet choisi : " << Monde.Joueurs[i].objects_player[choix - 1]->getNom() << " et la quantite: " << Monde.Joueurs[i].nb_objects_base[choix - 1] << "\n";
				nbchoix++;
			}
		}
		afficher_objets_joueur(i);
		Monde.list_player();
		system("pause");
		//float flood, fall, paralysis, poison, burn, heal;
	}
	std::cout<<"\t\t\tCommencement du jeu Pokeleague! \n";
	int nb_tour_max = 100; //nb de deplacement avant la fin
	int nb_tour = 0;
	int joueur = 0;

	while (nb_tour < nb_tour_max)
	{
		
		//Monde.map_view_terrain();
		int choix = 0, tour_joueur = 1;
		while (tour_joueur)
		{
			int posX = Monde.Joueurs[0].positionX(), posY = Monde.Joueurs[0].positionY();
			Monde.map_view_terrain();
			std::cout << "Le joueur 1 " << " joue! \t Position actuelle X: " << posX << " Y: " << posY << " TYPE: "<< Monde.Joueurs[0].type_terrain()->Title() << "\n";
			std::cout << "Choix du deplacement: \n\
\t\t    1)Haut\n\
\t 2) Gauche \t\t 3) Droite\n\
\t\t    4) Bas\n";
			std::cin >> choix;
			std::string test = "Joueur1";
			if (choix == 1)
			{
				posX--;
				if (posX >= 0)
				{
					Monde.move_player(0, posX, posY);
					tour_joueur = 0;
				}
			}
			else if (choix == 2)
			{
				posY--;
				if (posY >= 0)
				{
					Monde.move_player(0, posX, posY);
					tour_joueur = 0;
				}
			}
			else if (choix == 3)
			{
				posY++;
				if (posY < dimY)
				{
					Monde.move_player(0, posX, posY);
					tour_joueur = 0;
				}
			}
			else if (choix == 4)
			{
				posX++;
				if (posX < dimX)
				{
					Monde.move_player(0, posX, posY);
					tour_joueur = 0;
				}
			}
			else
			{
				std::cout << "Mauvaise valeure! \n";
			}
		}

		Monde.map_view_terrain();
		choix = 0; tour_joueur = 1;
		while (tour_joueur)
		{
			int posX = Monde.Joueurs[1].positionX(), posY = Monde.Joueurs[1].positionY();
			Monde.map_view_terrain();
			std::cout << "Le joueur 2 " << " joue! \t Position actuelle X: " << posX << " Y: " << posY << " TYPE: " << Monde.Joueurs[1].type_terrain()->Title() << "\n";
			std::cout << "Choix du deplacement: \n\
\t\t    1)Haut\n\
\t 2) Gauche \t\t 3) Droite\n\
\t\t    4) Bas\n";
			std::cin >> choix;
			std::string test = "Joueur2";
			if (choix == 1)
			{
				posX--;
				if (posX >= 0)
				{
					Monde.move_player(1, posX, posY);
					tour_joueur = 0;
				}
			}
			else if (choix == 2)
			{
				posY--;
				if (posY >= 0)
				{
					Monde.move_player(1, posX, posY);
					tour_joueur = 0;
				}
			}
			else if (choix == 3)
			{
				posY++;
				if (posY < dimY)
				{
					Monde.move_player(1, posX, posY);
					tour_joueur = 0;
				}
			}
			else if (choix == 4)
			{
				posX++;
				if (posX < dimX)
				{
					Monde.move_player(1, posX, posY);
					tour_joueur = 0;
				}
			}
			else
			{
				std::cout << "Mauvaise valeure! \n";
			}
		}
		nb_tour++;
	}
}
		

int main()
{
	read_config_object();
	read_config_pokemon();

	jouer();
	system("pause");
}