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

std::vector<std::string> CMonster::getNAttaques()
{
	return m_nom_attaque;
}

std::vector<std::string> CMonster::getTAttaques()
{
	return m_type_attaque;
}

std::vector<int> CMonster::getNU()
{
	return m_nu;
}

std::vector<int> CMonster::getPAtt()
{
	return m_pAttaques;
}

std::vector<float> CMonster::getPEchec()
{
	return m_pEchec;
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
	if (etat == 1) //pokémon brulé
	{
		if (m_etat_tours < 3)
		{
			m_attaque_act -= m_attaque / 10;
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
	this->attaquer(num_att, monstre);
	/*std::cout << monstre->getNom()<< " :\n"; //J'ai modif ça aussi ^^'
	std::cout << "Choix de l'attaque :\n";
	std::cout << "0) Coup de griffes\n";
	std::cout << "1) "<< monstre->getNAttaques[0]<< "\n";
	std::cout << "2) "<< monstre->getNAttaques[1]<< "\n";
	std::cout << "3) "<< monstre->getNAttaques[2]<< "\n";
	std::cout << "4) "<< monstre->getNAttaques[3]<< "\n";
	int num_att2;
	std::cin >> num_att2;
	if (init_combat(*this, monstre))
	{
		//TOUR IMPOSSIBLE, plus de HP sur l'un des monstres
		return 1;
	}*/

	/*
	if (&objet1 != NULL)
	{
		this->setAttaqueAct(this->getAttaqueAct() + objet1.getAtt());
		this->setDefenseAct(this->getDefenseAct() + objet1.getDef());
		this->setHPAct(this->getHPAct() + objet1.getHP());
		this->setVitesseAct(this->getVitesseAct() + objet1.getVit());
		this->setEtat(objet1.getEtat());
	}
	if (&objet2 != NULL)
	{
		monstre.setAttaqueAct(monstre.getAttaqueAct() + objet2.getAtt());
		monstre.setDefenseAct(monstre.getDefenseAct() + objet2.getDef());
		monstre.setHPAct(monstre.getHPAct() + objet2.getHP());
		monstre.setVitesseAct(monstre.getVitesseAct() + objet2.getVit());
		monstre.setEtat(objet2.getEtat());
	}
	*/
	/*
	if (analyse_speed(*this, monstre))
	{
		//monstre2 commence
		monstre.attaquer(num_att2, monstre);
		if (this->getHPAct() != 0)
		{
			this->attaquer(num_att1, monstre);
		}
	}
	else
	{
		//monstre1 commence
		this->attaquer(num_att1, monstre);
		if (monstre.getHPAct() != 0)
		{
			monstre.attaquer(num_att2, *this);
		}
	}*/
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