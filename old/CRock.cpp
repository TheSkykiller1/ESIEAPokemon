#include "CRock.h"

CRock::CRock()
{
	CMonster();
}

CRock::CRock(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CRock::~CRock()
{

}

//GETTERS

//SETTERS

//METHODES
bool CRock::attaquer(int num_att, CMonster* cible)
{
	if (m_etat == "Paralyzed") //paralysie
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
		return 0;
	}
	else
	{
		return 1;
	}
}