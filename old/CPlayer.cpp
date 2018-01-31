#include "CPlayer.h"
/*Public*/
//---------Constructeurs / Destructeur-------

CPlayer::CPlayer() {}
CPlayer::CPlayer(int id, std::string name)
{
	id_player = id;
	s_pseudo = name;
}
CPlayer::~CPlayer() { }

void CPlayer::add_pokemon(CMonster* pokemon) { Pokemons.push_back(pokemon); }

void CPlayer::attaquer()
{
	/*system("CLS");
	std::cout << "Joueur " << s_pseudo << " , c'est votre tour! Que voulez-vous faire ? \n\
\t 1) Utiliser un object \n\
\t 2) Attaquer le pokemon adverse " << s_target->Pokeballs[s_target->id_pokemon_actif()].getNom() << " de type: " << s_target->Pokeballs[s_target->id_pokemon_actif()].getType() << "\n";
	int choix;
	std::cin >> choix;
	if (choix == 1)
	{
		use_object();
	}
	else if (choix == 2)
	{
		std::string type = Pokeballs[id_actif].getType();
		if (type == "Fire")
		{
			CFire& mob = dynamic_cast<CFire&>(Pokeballs[id_actif]);
			mob.tour(&s_target->Pokeballs[s_target->id_pokemon_actif()], s_cases);
		}
		else if (type == "Rock")
		{
			CRock& mob = dynamic_cast<CRock&>(Pokeballs[id_actif]);
			mob.tour(&s_target->Pokeballs[s_target->id_pokemon_actif()], s_cases);
		}
		else if (type == "Water")
		{
			CWater& mob = dynamic_cast<CWater&>(Pokeballs[id_actif]);
			mob.tour(&s_target->Pokeballs[s_target->id_pokemon_actif()], s_cases);
		}
		else if (type == "Plant")
		{
			CPlant& mob = dynamic_cast<CPlant&>(Pokeballs[id_actif]);
			mob.tour(&s_target->Pokeballs[s_target->id_pokemon_actif()], s_cases);
		}
		else if (type == "Insect")
		{
			CInsect& mob = dynamic_cast<CInsect&>(Pokeballs[id_actif]);
			mob.tour(&s_target->Pokeballs[s_target->id_pokemon_actif()], s_cases);
		}
		else if (type == "Electric")
		{
			CElectric& mob = dynamic_cast<CElectric&>(Pokeballs[id_actif]);
			mob.tour(&s_target->Pokeballs[s_target->id_pokemon_actif()], s_cases);
		}
	}*/
}
void CPlayer::use_object()
{
	/*std::cout << "Quel objet voulez-vous utiliser ? \n";
	for (int i = 0; i < Liste_object_player.size();i++)
	{
		if (nb_objects[i] > 0)
		{
			std::cout << "\t -" << i << ") " << Liste_object_player[i]->getNom() << " peut etre utiliser sur votre pokemon \n \t";
			std::cout << "Genre: ";
			if (Liste_object_player[i]->getGenre() == "Potion")
			{
				CPotion* boisson = dynamic_cast<CPotion*>(Liste_object_player[i]);
				std::cout << boisson->getGenre() << "\n \t";
				std::cout << "Statistiques: " << boisson->getAtt() << " Attack " << boisson->getDef() << " Def " << boisson->getHP() << " HP " << boisson->getVit() << " Speed \n";
			}
			if (Liste_object_player[i]->getGenre() == "Drug")
			{
				CDrug* drugs = dynamic_cast<CDrug*>(Liste_object_player[i]);
				std::cout << drugs->getGenre() << "\n \t";
				std::cout << "Statistiques: " << drugs->getEtat() << " etat \n";
			}

		}
	}
	int choix;
	std::cin >> choix;
	//Pokeballs[id_actif].useObject(Liste_object_player[choix]);
	nb_objects[choix]--;*/
}
bool CPlayer::check()
{
	/*if (Pokeballs[id_actif].getHPAct() <= 0)
	{
		id_actif++;
		if(id_actif == maxpokeballs) { id_actif=0; return false; }
		else { return true; }
	}
	else
	{
		return true;//toujours au moins 1 pokemon en vie
	}*/
}

 ///========================================================================