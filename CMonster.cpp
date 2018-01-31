#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	m_id = id;
	m_type = type;
	m_nom = nom;
	m_HP = HP;
	m_HP_act = HP;
	m_vitesse = vit;
	m_vitesse_act = vit;
	m_attaque = att;
	m_attaque_act = att;
	m_defense = def;
	m_defense_act = def;
	m_etat = "Normal";
	m_etat_tours = 0;
	m_cache = 0;
}

CMonster::~CMonster()
{

}

//GETTERS
void CMonster::set_attaques_disp(std::vector<CAttaque*> Attac)
{
	Attaques_list = Attac;
	for (int i = 0;i < Attaques_list.size();i++)
	{
		Attaques_actives.push_back(false);
		Attaques_utilisation.push_back(0);
	}
}

int CMonster::getId()
{
	return m_id;
}

std::string CMonster::getType()
{
	return m_type;
}

std::string CMonster::getNom()
{
	return m_nom;
}

int CMonster::getHP()
{
	return m_HP;
}

int CMonster::getHPAct()
{
	return m_HP_act;
}

int CMonster::getVitesse()
{
	return m_vitesse;
}

int CMonster::getVitesseAct()
{
	return m_vitesse_act;
}

int CMonster::getAttaque()
{
	return m_attaque;
}

int CMonster::getAttaqueAct()
{
	return m_attaque_act;
}

int CMonster::getDefense()
{
	return m_defense;
}

int CMonster::getDefenseAct()
{
	return m_defense_act;
}

std::string CMonster::getEtat()
{
	return m_etat;
}

int CMonster::getEtatTours()
{
	return m_etat_tours;
}

std::vector<std::string> CMonster::getForce()
{
	return m_force;
}

bool CMonster::getCache()
{
	return m_cache;
}

float CMonster::getFall()
{
	return 0.0f;
}

//SETTERS

void CMonster::setId(int id)
{
	m_id = id;
}

void CMonster::setType(std::string type)
{
	m_type = type;
}

void CMonster::setNom(std::string nom)
{
	m_nom = nom;
}

void CMonster::setHP(int HP)
{
	m_HP = HP;
}

void CMonster::setHPAct(int HP_act)
{
	m_HP_act = HP_act;
}

void CMonster::setVitesse(int vitesse)
{
	m_vitesse = vitesse;
}

void CMonster::setVitesseAct(int vitesse_act)
{
	m_vitesse_act = vitesse_act;
}

void CMonster::setAttaque(int attaque)
{
	m_attaque = attaque;
}

void CMonster::setAttaqueAct(int attaque_act)
{
	m_attaque_act = attaque_act;
}

void CMonster::setDefense(int defense)
{
	m_defense = defense;
}

void CMonster::setDefenseAct(int defense_act)
{
	m_defense_act = defense_act;
}

void CMonster::setForce(std::vector<std::string> force)
{
	m_force = force;
}

void CMonster::setEtat(std::string etat)
{
	m_etat = etat;
}

void CMonster::setEtatTours(int tours)
{
	m_etat_tours = tours;
}

void CMonster::setCache(bool cache)
{
	m_cache = cache;
}

void CMonster::reset()
{
	m_HP_act = m_HP;
	m_vitesse_act = m_vitesse;
	m_attaque_act = m_attaque;
	m_defense_act = m_defense;
	m_etat = "Normal";
	m_etat_tours = 0;
	m_cache = false;
	//TO DO : RETIRER L'INNONDATION SI LE MONSTRE EN A DECLENCHE UNE 
}


std::string CMonster::updateEtat() //todo etat a finir
{
	std::string etat = getEtat();
	if (etat == "Burnt") //pok�mon brul�
	{
		if (m_etat_tours < 3)
		{
			m_attaque_act -= m_attaque / 10;
			m_etat_tours += 1;
		}
		else
		{
			etat = "Normal"; //�tat normal
			m_attaque_act = m_attaque;
		}
	}
	if (etat == "Poisonned") //pok�mon empoisonn�
	{
		if (m_etat_tours < 3)
		{
			m_HP -= m_attaque / 10;
		}
		else
		{
			etat = "Normal";
		}
	}
	if (etat == "Paralyzed") //pok�mon paralys�
	{
		if (rand() % 6 <= m_etat_tours)
		{
			etat = "Normal";
		}
	}
	return etat;//todo a modifier temporaire
}

bool CMonster::attaquer(int num_att, CMonster* cible)
{
	return 0;
}

int CMonster::degat(int num_att, CMonster* def)
{
	int attaque = m_attaque_act;
	int defense = def->getDefense();
	float coeff = (float)((85 + (rand() % 16)) / 100);
	float avantage = 1;
	if (num_att != -1)
	{

		std::string base_type_att = m_type;
		std::string base_type_def = def->getType();
		if (def->getType() == "Rock") //si type terre
		{
			if (def->getCache() == 1)
			{
				defense *= 2;
			}
		}
		if (m_type_attaque[num_att] != "Normal")
		{
			for (int i = 0; i < m_force.size(); i++)
			{
				if (m_force[i] == base_type_def)
				{
					avantage = 2;
				}
			}
			for (int i = 0; i < def->getForce().size(); i++)
			{
				if (def->getForce()[i] == base_type_att)
				{
					avantage = 0.5;
				}
			}
		}
		int degat = ((11 * attaque*(m_pAttaques[num_att])) / (25 * defense) + 2)*avantage*coeff;
		return degat;
	}
	else
	{
		int degat = (attaque * coeff) / defense;
	}
}

bool CMonster::echec(int num_att)
{
	short val = m_pEchec[num_att]+rand()/RAND_MAX;
	if (val)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool CMonster::init_combat(CMonster* monstre)
{
	int HP1 = this->getHPAct();
	int HP2 = monstre->getHPAct();
	if (HP1*HP2 == 0)
	{
		return 1;
	}
	return 0;
}

bool CMonster::analyse_speed(CMonster* monstre)
{
	if (this->getVitesseAct() < monstre->getVitesseAct())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool CMonster::verifTerrain(int num_att, CMonster* cible, CTerrain* terrain)
{
	if (terrain->isflooded() && m_type != "Water")
	{
		short val = cible->getFall() + rand() / RAND_MAX;
		if (val)
		{
			int val_degat = degat(num_att, cible);
			this->recevoirDegat(val_degat/4);
			return 0;
		}
	}
	return 1;
}

bool CMonster::tour(CMonster* monstre, CTerrain* terrain)
{
	std::cout << m_nom << " :\n";
	std::cout << "Choix de l'attaque :\n";
	std::cout << "0) Coup de griffes\n";
	std::cout << "1) " << m_nom_attaque[0] << "\n";
	std::cout << "2) " << m_nom_attaque[1] << "\n";
	std::cout << "3) " << m_nom_attaque[2] << "\n";
	std::cout << "4) " << m_nom_attaque[3] << "\n";
	int num_att;
	std::cin >> num_att;
	if (verifTerrain(num_att, monstre, terrain))
	{
		this->attaquer(num_att, monstre);
	}
	return 0;
}

void CMonster::useObject(CObject* objet)
{
	this->setAttaqueAct(this->getAttaqueAct() + objet->getAtt());
	this->setDefenseAct(this->getDefenseAct() + objet->getDef());
	this->setHPAct(this->getHPAct() + objet->getHP());
	this->setVitesseAct(this->getVitesseAct() + objet->getVit());
	this->setEtat(objet->getEtat());
}

void CMonster::recevoirDegat(int degat)
{
	this->setHPAct(this->getHPAct() - degat);
}

void CMonster::checkHP(CTerrain* terrain)
{
	if ((this->getHPAct()) <= 0)
	{
		this->setHPAct(0);
	}
}