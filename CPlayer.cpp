#include "CPlayer.h"

void CPlayer::level_refresh()
{

}//Refresh stats of the player if level change

CPlayer::CPlayer()
{
	s_pseudo = "NoName"; s_posx = 0; s_posy = 0; s_nb_fight = 0; s_nb_win = 0; s_level = 0; s_exp = 0;
}
CPlayer::CPlayer(std::string name, int posX, int posY, int fight_count, int fight_win, short level, int exp)
{
	s_pseudo = name; s_posx = posX; s_posy = posY; s_nb_fight = fight_count; s_nb_win = fight_win; s_level = level; s_exp = exp;
}
CPlayer::CPlayer(std::string name, int posX, int posY, std::vector<CMonster> Pokeball, int fight_count, int fight_win, short level, int exp)
{
	s_pseudo = name;  s_posx = posX; s_posy = posY; Pokeballs = Pokeball; s_nb_fight = fight_count; s_nb_win = fight_win; s_level = level; s_exp = exp;
}
CPlayer::~CPlayer() { Pokeballs.clear(); Liste_level.clear(); }

//getter
std::string CPlayer::pseudo() { return s_pseudo; }
short CPlayer::level() { return s_level; }
int CPlayer::xp() { return s_exp; }
int CPlayer::xp_up() { return s_exp_up; }
int CPlayer::fight_count() { return s_nb_fight; }
int CPlayer::fight_win() { return s_nb_win; }
void CPlayer::list_pokemon()
{
	int nb_Pokeball = Pokeballs.size();
	if (nb_Pokeball < 1)
	{
		std::cout << "Vous n'avez pas de pokemon!\n";
	}
	else
	{
		std::cout << "Liste des pokemons:  " << nb_Pokeball << " Pokemons!\n";
		for (int pokemon = 0; pokemon < nb_Pokeball; ++pokemon)
		{
			std::cout << "-" << pokemon << ") ID: " << Pokeballs[pokemon].getId() << " Nom: " << Pokeballs[pokemon].getNom() << " et de type : " << Pokeballs[pokemon].getType() << "\n"\
				<< "\t possede: " << Pokeballs[pokemon].getHP() << " HP et : " << Pokeballs[pokemon].getAttaque() << " Degats et " << Pokeballs[pokemon].getDefense() << " de defense.\n";
		}
	}
}//Affiche les pokemon et leur stats de base (base_damage, etc)
CPlayer* CPlayer::target() { return s_target; }
int CPlayer::positionX() { return s_posx; }
int CPlayer::positionY() { return s_posy; }
CTerrain* CPlayer::type_terrain() { return s_cases; }

//setter
void CPlayer::set_pseudo(std::string pseudo) { s_pseudo = pseudo; }
void CPlayer::change_level(short level) { s_level = level; }//debug only! level_refresh is called for reset xp and xp_up to correct value and assign bonus if any
void CPlayer::set_exp(int exp) { s_exp = exp; }
void CPlayer::give_exp(int exp) { s_exp += exp; }
void CPlayer::match_fini(bool win, int exp)//add 1 match to the counter, and 1 to win if match is won, exp gain are handled by this function  TODO
{
	if (win) {
		s_nb_fight += 1;
		s_nb_win += 1;
	}
	else
	{
		s_nb_fight += 1;
	}
	s_exp += exp;
	if (s_exp >= s_exp_up)
	{
		s_level += 1;
		s_exp -= s_exp_up;
		level_refresh();
	}
}

void CPlayer::set_object(std::vector<CObject> listeobject)
{
	objects = listeobject;
	for (int i = 0;i < listeobject.size();i++)//init nb of object
	{
		nb_objects.push_back(0);
	}
}
void CPlayer::set_nb_oject(int id, int nb)
{
	nb_objects_base[id] = nb;
	nb_objects = nb_objects_base;
}

bool CPlayer::add_pokemon(CMonster pokemon)//todo add pokemon
{
	if (Pokeballs.size() < maxpokeballs)//max 3
	{
		pokemon.setId(id_pokemon++);
		Pokeballs.push_back(pokemon);
		return true;
	}
	return false;
}
bool CPlayer::add_pokemon(std::string type, std::string nom, int hpe, int vitesse, int attaque, int defense)
{
	if (Pokeballs.size() < maxpokeballs)//max 3
	{
		CMonster pokemon(id_pokemon++, type, nom, hpe, vitesse, attaque, defense);
		pokemon.setId(id_pokemon++);
		Pokeballs.push_back(pokemon);
		return true;
	}
	return false;

}//todo add pokemon2
void CPlayer::delete_pokemon()
{
	if (Pokeballs.size() < 1) { std::cout << "Vous n'avez pas de pokemon donc vous ne pouvez pas en relacher!\n"; return; }
	list_pokemon();
	std::cout << "Quel Pokemon voulez-vous supprimer ? (ID)\n";
	int choix;
	std::cin >> choix;
	delete_pokemon(choix);

}
void CPlayer::delete_pokemon(int id_pokemon)
{
	for (std::vector<CMonster>::iterator it = Pokeballs.begin(); it != Pokeballs.end(); ++it)
	{
		if (id_pokemon == it->getId())
		{
			Pokeballs.erase(it);
		}
	}
}

void CPlayer::tableau_level()
{
	std::cout << "Tableau des levels \n";
	for (int i = 0;i < Liste_level.size();i++)//On clear les elements vides
	{
		std::cout << "Level: " << i + 1 << " exp a avoir: " << Liste_level[i] << "\n";
	}
}
void CPlayer::move(int X, int Y, CTerrain* terrain, CPlayer* cible) {
	s_posx = X;s_posy = Y; s_cases = terrain; s_target = cible;}

void CPlayer::set_target(CPlayer* cible) { s_target = cible; }
void CPlayer::set_terrain(CTerrain* terrain) { s_cases = terrain; }

int CPlayer::id_pokemon_actif() { return id_actif; }

void CPlayer::use_object()
{
	std::cout << "Quel objet voulez-vous utiliser ? \n";
	for (int i = 0; i < objects.size();i++)
	{
		if (nb_objects[i] > 0)
		{
			std::cout << "\t -"<<i<<") " << objects[i].getNom() << " utilisation: " << objects[i].getType() << "\n";
		}
	}
	int choix;
	std::cin >> choix;
	Pokeballs[id_actif].useObject(&objects[choix]);
	nb_objects[choix]--;
}

void CPlayer::attaquer() 
{
	system("CLS");
	std::cout << "Joueur " << s_pseudo << " , c'est votre tour! Que voulez-vous faire ? \n\
\t 1) Utiliser un object \n\
\t 2) Attaquer le pokemon adverse " << s_target->Pokeballs[s_target->id_pokemon_actif()].getNom()<<" de type: "<< s_target->Pokeballs[s_target->id_pokemon_actif()].getType() << "\n";
	int choix;
	std::cin >> choix;
	if (choix == 1)
	{
		use_object();
	}
	else if(choix==2)
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
	}
}

bool CPlayer::check()
{
	if (Pokeballs[id_actif].getHPAct() <= 0)
	{
		id_actif++;if (id_actif == maxpokeballs) { id_actif--; return false; }
	}
	else
	{
		return true;//toujours au moins 1 pokemon en vie
	}
}


//Lit le fichier de config de player pour obtenir ses levels
void CPlayer::read_level_requirement()
{
	std::string row;;
	std::ifstream File("player.pkmn", std::ios::in);
	srand(time(NULL));//Init random generator
	if (File.is_open())
	{
		while (getline(File, row))
		{
			if (row == "level")//Debut du bloc
			{
				while (row != "Endlevel")//Tant que l'on est dans le bloc
				{
					getline(File, row);
					if (row == "Endlevel") { break; }//Si on a fini le bloc on quitte
					std::vector<std::string> token = split(row, '\t\t');
					std::vector<std::string> element;
					for (int i = 0;i < token.size();i++)//On clear les elements vides
					{
						if (token[i] != "") { element.push_back(token[i]); }
					}
					//Analyse des resultats
					if (element[0] == "experience") {
						int EXPERIENCE = stoi(element[1]);
						Liste_level.push_back(stoi(element[1]));
					}
				}
			}
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d’ouvrir le fichier player \n";
	}
}

//La function template pour parser les donnees
template<typename Out>
void CPlayer::split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

//La fonction permetant de l'utiliser
std::vector<std::string> CPlayer::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}