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
	m_vitesse = vit;
	m_attaque = att;
	m_attaque_act = att;
	//m_attaques = attaques;
	m_defense = def;
	m_etat = 0;
	m_etat_tours = 0;
	m_cache = 0;
}

CMonster::~CMonster()
{

}

//GETTERS

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

int CMonster::getVitesse()
{
	return m_vitesse;
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

int CMonster::getEtat()
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

void CMonster::setVitesse(int vitesse)
{
	m_vitesse = vitesse;
}

void CMonster::setAttaque(int attaque)
{
	m_attaque = attaque;
}

void CMonster::setAttaqueAct(int attaqueAct)
{
	m_attaque_act = attaqueAct;
}

void CMonster::setDefense(int defense)
{
	m_defense = defense;
}

void CMonster::setEtat(int etat)
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

//METHODES

short CMonster::updateEtat() //todo etat a finir
{
	short etat = getEtat();
	if (etat == 1) //pokémon brulé
	{
		if (m_etat_tours < 3)
		{
			m_attaque_act -= m_attaque/10;
			m_etat_tours += 1;
		}
		else
		{
			etat = 0; //état normal
			m_attaque_act = m_attaque;
		}
	}
	if (etat == 2) //pokémon empoisonné
	{
		if (m_etat_tours < 3)
		{
			m_HP -= m_attaque / 10;
		}
		else
		{
			etat = 0;
		}
	}
	if (etat == 3) //pokémon paralysé
	{
		if (rand() % 6 <= m_etat_tours)
		{
			etat = 0;
		}
	}
	return etat;//todo a modifier temporaire
}

bool CMonster::attaquer(int num_att, CMonster &cible)
{
	return 0;
}

short CMonster::degat(int num_att, CMonster &def)
{
	/*short attaque = m_attaque_act;
	short defense = def.getDefense();
	float coeff = (float)(0.85 + (rand() % 15) / 100);
	float avantage = 1;
	std::string base_type_att = m_type;
	std::string base_type_def = def.getType();
	if (def.getType() == 3) //si type terre
	{
		if (def.getCache() == 1)
		{
			defense *= 2;
		}
	}
	for (unsigned short i = 0; i < m_force.size(); i++)
	{
		if (m_force[i+*m_force.begin()] == base_type_def)
		{
			avantage = 2;
		}
	}
	for (std::vector<short>::iterator it = def.getForce().begin(); it != def.getForce().end(); ++it)
	{
		if (*it == base_type_att)
		{
			avantage = 0.5;
		}
	}
	short degat = ((11 * attaque*(m_pAttaques[num_att])) / (25 * defense) + 2)*avantage*coeff;
	return degat;
	*/
	return 0; //DEBUG
}
