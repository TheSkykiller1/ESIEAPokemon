#include "CInsect.h"

CInsect::CInsect() : C()
{
}

CInsect::CInsect(int id, std::string type, std::string nom, int HP, int vit, int att, int def) : CGrass(id, type, nom, HP, vit, att, def)
{
}

CInsect::~CInsect()
{

}

//METHODES

bool CInsect::poison()
{
	short val = m_poison + rand() / RAND_MAX;
	if (val)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool CInsect::attaquer(int num_att, CMonster* cible)
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
		if (poison() && m_type_attaque[num_att] != "Normal")
		{
			if (cible->getEtat() == "Normal")
			{
				cible->setEtat("Poisonned");
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}