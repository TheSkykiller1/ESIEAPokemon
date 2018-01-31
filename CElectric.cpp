#include "CElectric.h"

CElectric::CElectric() : CMonster()
{
}

CElectric::CElectric(int id, std::string type, std::string nom, int HP, int vit, int att, int def, float paralysis) : CMonster(id, type, nom, HP, vit, att, def), m_paralysis(paralysis), m_force ( 0 )
{
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

bool CElectric::attaquer(int num_att, CMonster* cible)
{
	if (m_etat == "Paralyzed") //paralysie
	{
		if (rand() % 4 == 0) //proba de 25% de ne pas pouvoir attaquer
		{
			return 1;
		}
	}
	if (echec(num_att)==0 && m_nu[num_att] > 0)
	{
		int val_degat = degat(num_att, cible);
		cible->recevoirDegat(val_degat);
		m_nu[num_att]--;
		if (paralyze() && m_type_attaque[num_att]!="Normal") //si l'ennemi doit être paralysé
		{
			if (cible->getEtat() == "Normal") //si l'ennemi est dans un etat normal
			{
				cible->setEtat("Paralyzed"); //paralysie
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