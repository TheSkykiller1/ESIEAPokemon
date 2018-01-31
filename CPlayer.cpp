#include "CPlayer.h"
/*Public*/
	//==================Methodes======================
	//---------Constructeurs / Destructeur-------

CPlayer::CPlayer() {}
CPlayer::CPlayer(int id, std::string name, int posX, int posY, int fight_count, int fight_win)
{
	id_player = id; s_pseudo = name; s_posx = posX; s_posy = posY; s_nb_fight = fight_count; s_nb_win = fight_win;
	
}
CPlayer::~CPlayer() { Pokeballs.clear(); }

		//---------Getters-----
int CPlayer::get_id() { return id_player; }
std::string CPlayer::pseudo() { return s_pseudo; }

int CPlayer::fight_count() { return s_nb_fight; }
int CPlayer::fight_win() { return s_nb_win; }

void CPlayer::list_pokemon()
{
	std::cout << "Liste des pokemons: \n";
	for (int index = 0; index < Pokeballs.size(); index++)
	{
		std::cout << "-" << index << ") ID: " << Pokeballs[index]->getId() << " Nom: " << Pokeballs[index]->getNom() << " et de type : " << Pokeballs[index]->getType() << "\n"\
			<< "\t possede: " << Pokeballs[index]->getHP() << " HP et : " << Pokeballs[index]->getAttaque() << " Degats et " << Pokeballs[index]->getDefense() << " de defense.\n";
	}
}

CPlayer* CPlayer::target() { return s_target; }
int CPlayer::positionX() { return s_posx; }
int CPlayer::positionY() { return s_posy; }

CTerrain* CPlayer::type_terrain() { return s_cases; }

		//---------Setters-----
//add 1 match to the counter, and 1 to win if match is won, exp gain are handled by this function
void CPlayer::match_fini(bool win)
{
	if (win) {
		s_nb_fight += 1;
		s_nb_win += 1;
	}
	else
	{
		s_nb_fight += 1;
	}
}  

//remet au stade initial le joueur et ses pokemons
void CPlayer::match_reset()
{
	nb_objects = nb_objects_base;
	for (int o = 0;o < Pokeballs.size();o++)
	{
		Pokeballs[o]->reset();
	}
}		

void CPlayer::set_object(std::vector<CObject*> listeobject)
{
	objects_player = listeobject;
	for (int i = 0;i < listeobject.size();i++)//init nb of object
	{
		nb_objects_base.push_back(0);
		nb_objects.push_back(0);
	}
}

void CPlayer::set_nb_oject(int id, int nb)
{
	nb_objects_base[id] = nb;
	nb_objects[id] = nb;
}

void CPlayer::add_pokemon(CMonster* pokemon)
{
	Pokeballs.push_back(pokemon);
}

void CPlayer::move(int X, int Y) { s_posx = X;s_posy = Y; }
void CPlayer::move(int X, int Y, CTerrain* terrain, CPlayer* cible) 
{ s_posx = X;s_posy = Y; s_cases = terrain; s_target = cible; }

void CPlayer::set_target(CPlayer* cible) { s_target = cible; }
void CPlayer::set_terrain(CTerrain* terrain) { s_cases = terrain; }

void CPlayer::attaquer()
{
	system("CLS");
	std::cout << "Joueur " << s_pseudo << " , c'est votre tour! Que voulez-vous faire ? \n\
\t 1) Utiliser un object \n\
\t 2) Attaquer le pokemon adverse " << s_target->Pokeballs[s_target->id_actif]->getNom() << " de type: " << s_target->Pokeballs[s_target->id_actif]->getType() << "\n";
	int choix;
	std::cin >> choix;
	if (choix == 1)
	{
		use_object();
	}
	else if (choix == 2)
	{
		CMonster* Pukatchika = Pokeballs[id_actif];
		Pukatchika->tour(s_target->Pokeballs[s_target->id_actif], s_cases);
	}
}
void CPlayer::use_object()
{
	std::cout << "Quel objet voulez-vous utiliser ? \n";
	for (int i = 0; i < objects_player.size();i++)
	{
		if (nb_objects[i] > 0)
		{
			std::cout << "\t -" << i << ") " << objects_player[i]->getNom() << " peut etre utiliser sur votre pokemon \n \t";
			std::cout << "Genre: ";
			if (objects_player[i]->getGenre() == "Potion")
			{
				std::cout << objects_player[i]->getGenre() << "\n \t";
				std::cout << "Statistiques: " << objects_player[i]->getAtt() << " Attack " << objects_player[i]->getDef() <<\
					" Def " << objects_player[i]->getHP() << " HP " << objects_player[i]->getVit() << " Speed \n";
			}
			if (objects_player[i]->getGenre() == "Drug")
			{
				std::cout << objects_player[i]->getGenre() << "\n \t";
				std::cout << "Statistiques: " << objects_player[i]->getEtat() << " etat \n";
			}
		}
	}
	int choix;
	std::cin >> choix;
	Pokeballs[id_actif]->useObject(objects_player[choix]);
	nb_objects[choix]--;
}
bool CPlayer::check()
{
	if (Pokeballs[id_actif]->getHPAct() <= 0)
	{
		id_actif++;
		if(id_actif == maxpokeballs) { id_actif=0; return false; }
		else { return true; }
	}
	else
	{
		return true;//toujours au moins 1 pokemon en vie
	}
}

 ///========================================================================