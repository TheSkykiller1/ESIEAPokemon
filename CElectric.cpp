#include "CElectric.h"

CElectric::CElectric()
{
	CMonster();
}

CElectric::CElectric(int id, short type, std::string nom, short HP, short vit, short att, short def, float paralysis)
{
	CMonster(id, type, nom, HP, vit, att, def);
	m_paralysis = paralysis;
	m_force = { 0 };
}

CElectric::~CElectric()
{

}

//METHODES

bool CElectric::paralyze()
{
	short val = m_paralysis + rand() / RAND_MAX;
	if (val)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool CElectric::attaquer(short num_att, CMonster &cible)
{
	if (m_etat == 3) //paralysie
	{
		if (rand() % 4 == 0) //proba de 25% de ne pas pouvoir attaquer
		{
			return 1;
		}
	}
	if (m_nu[num_att] > 0)
	{
		short val_degat = degat(num_att, cible);
		short HP1 = cible.getHP();
		short HP2 = HP1 - val_degat;
		cible.setHP(HP2);
		m_nu[num_att]--;
		if (paralyze()) //si l'ennemi doit être paralysé
		{
			if (cible.getEtat() == 0) //si l'ennemi est dans un etat normal
			{
				cible.setEtat(3); //paralysie
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

//GETTERS

float CElectric::getParalysis()
{
	return m_paralysis;
}

//SETTERS

void CElectric::setParalysis(float paralysis)
{
	m_paralysis = paralysis;
}