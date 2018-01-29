#include "CPlant.h"

CPlant::CPlant()
{
	CMonster();
}

CPlant::CPlant(int id, std::string type, std::string nom, int HP, int vit, int att, int def, float heal)
{
	CGrass(id, type, nom, HP, vit, att, def);
	m_heal = heal;
}

CPlant::~CPlant()
{

}

// GETTERS

float CPlant::getHeal()
{
	return m_heal;
}

//SETTERS

void CPlant::setHeal(float heal)
{
	m_heal = heal;
}

//METHODES

bool CPlant::heal()
{
	short val = m_heal + rand() / RAND_MAX;
	if (val)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool CPlant::attaquer(int num_att, CMonster* cible)
{
	if (m_etat == 3) //paralysie
	{
		if (rand() % 4 == 0) //proba de 25% de ne pas pouvoir attaquer
		{
			return 1;
		}
	}
	if (echec(num_att) == 0 && m_nu[num_att] > 0)
	{
		int val_degat = degat(num_att, cible);
		cible->recevoirDegat(val_degat);
		m_nu[num_att]--;
		if (heal() && m_type_attaque[num_att] != "Normal")
		{
			m_HP_act = m_HP;
		}
		return 0;
	}
	else
	{
		return 1;
	}
}