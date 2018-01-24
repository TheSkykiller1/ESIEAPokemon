#include "CPlayer.h"

void CPlayer::read_level_requirement()
{
	std::string row;
	std::ifstream File("player.pkmn", std::ios::in);
	if (File.is_open())
	{
		while (getline(File, row))
		{
			std::string delimiter = "\t";
			std::size_t pos = 0;
			std::string token;
			while ((pos = row.find(delimiter)) != std::string::npos)
			{
				token = row.substr(0, pos);
				std::cout << "Arguments: " << token << std::endl;
				row.erase(0, pos + delimiter.length());
			}
			std::cout << row << std::endl;
		}
		File.close();
	}
	else
	{
		std::cout << "Impossible d�ouvrir le fichier \n";
	}
} //Read from config?

void CPlayer::level_refresh()
{

}//Refresh stats of the player if level change

CPlayer::CPlayer()
{
	//NO USE!
}
CPlayer::CPlayer(std::string name, bool isPlayer, int posX, int posY, int fight_count, int fight_win, short level, int exp)
{
	s_pseudo = name; isPlayable = isPlayer; s_posx = posX; s_posy = posY; s_nb_fight = fight_count; s_nb_win = fight_win; s_level = level; s_exp = exp;
}
CPlayer::CPlayer(std::string name, bool isPlayer, int posX, int posY, std::vector<CMonster> Pokeball, int fight_count, int fight_win, short level, int exp)
{
	s_pseudo = name; isPlayable = isPlayer; s_posx = posX; s_posy = posY; Pokeballs = Pokeball; s_nb_fight = fight_count; s_nb_win = fight_win; s_level = level; s_exp = exp;
}
CPlayer::~CPlayer() { Pokeballs.clear(); s_tablevel.clear(); }

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
		std::cout << "Liste des pokemons:  "<<nb_Pokeball<<" Pokemons!\n";
		for (int pokemon = 0; pokemon < nb_Pokeball; ++pokemon)
		{
			std::cout << "-" << pokemon << ") ID: " << Pokeballs[pokemon].getId() << " Nom: " << Pokeballs[pokemon].getNom() << " et de type : " << Pokeballs[pokemon].getType() << "\n"\
				<< "\t possede: " << Pokeballs[pokemon].getHP() << " HP et : " << Pokeballs[pokemon].getAttaque() << " Degats et " << Pokeballs[pokemon].getDefense() << " de defense.\n";
		}
	}
}//Affiche les pokemon et leur stats de base (base_damage, etc)

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
void CPlayer::add_pokemon(CMonster pokemon)
{
	pokemon.setId(id_pokemon++);
	Pokeballs.push_back(pokemon);
}
void CPlayer::add_pokemon(short type, std::string nom, short hpe, short vitesse, short attaque, short defense)
{
	CMonster pokemon(id_pokemon++, type, nom, hpe, vitesse, attaque, defense);
	Pokeballs.push_back(pokemon);
}
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