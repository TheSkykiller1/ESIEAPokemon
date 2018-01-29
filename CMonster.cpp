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

int CMonster::updateEtat() //todo etat a finir
{
	short etat = getEtat();
	if (etat == 1) //pok�mon brul�
	{
		if (m_etat_tours < 3)
		{
			m_attaque_act -= m_attaque / 10;
			m_etat_tours += 1;
		}
		else
		{
			etat = 0; //�tat normal
			m_attaque_act = m_attaque;
		}
	}
	if (etat == 2) //pok�mon empoisonn�
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
	if (etat == 3) //pok�mon paralys�
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

int CMonster::degat(int num_att, CMonster &def)
{
	int attaque = m_attaque_act;
	int defense = def.getDefense();
	float coeff = (float)((85 + (rand() % 16)) / 100);
	float avantage = 1;
	if (num_att != -1)
	{

		std::string base_type_att = m_type;
		std::string base_type_def = def.getType();
		if (def.getType() == "Rock") //si type terre
		{
			if (def.getCache() == 1)
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
			for (int i = 0; i < def.getForce().size(); i++)
			{
				if (def.getForce()[i] == base_type_att)
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

bool CMonster::init_combat(CMonster &monstre1, CMonster &monstre2)
{
	int HP1 = monstre1.getHPAct();
	int HP2 = monstre2.getHPAct();
	if (HP1*HP2 == 0)
	{
		return 1;
	}
	return 0;
}

bool CMonster::analyse_speed(CMonster &monstre1, CMonster &monstre2)
{
	if (monstre1.getVitesseAct() < monstre2.getVitesseAct())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool CMonster::tour(CMonster &monstre1, CMonster &monstre2, int num_att1, int num_att2, CObject &objet1, CObject &objet2, CWorld &world)
{
	if (init_combat(monstre1, monstre2))
	{
		//TOUR IMPOSSIBLE, plus de HP sur l'un des monstres
		return 1;
	}
	if (&objet1 != NULL)
	{
		monstre1.setAttaqueAct(monstre1.getAttaqueAct() + objet1.getAtt());
		monstre1.setDefenseAct(monstre1.getDefenseAct() + objet1.getDef());
		monstre1.setHPAct(monstre1.getHPAct() + objet1.getHP());
		monstre1.setVitesseAct(monstre1.getVitesseAct() + objet1.getVit());
		monstre1.setEtat(objet1.getEtat());
	}
	if (&objet2 != NULL)
	{
		monstre2.setAttaqueAct(monstre2.getAttaqueAct() + objet2.getAtt());
		monstre2.setDefenseAct(monstre2.getDefenseAct() + objet2.getDef());
		monstre2.setHPAct(monstre2.getHPAct() + objet2.getHP());
		monstre2.setVitesseAct(monstre2.getVitesseAct() + objet2.getVit());
		monstre2.setEtat(objet2.getEtat());
	}
	if (analyse_speed(monstre1, monstre2))
	{
		//monstre2 commence
		monstre2.attaquer(num_att2, monstre1);
		if (monstre1.getHPAct() != 0)
		{
			monstre1.attaquer(num_att1, monstre2);
		}
	}
	else
	{
		//monstre1 commence
		monstre1.attaquer(num_att1, monstre2);
		if (monstre2.getHPAct() != 0)
		{
			monstre2.attaquer(num_att2, monstre1);
		}
	}
}