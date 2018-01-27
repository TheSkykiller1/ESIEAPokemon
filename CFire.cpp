#include "CFire.h"

CFire::CFire()
{
	CMonster();
}

CFire::CFire(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CFire::~CFire()
{

}

bool CFire::burn()
{
	short val = m_burn + rand() / RAND_MAX;
	if (val)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool CFire::attaquer(int num_att, CMonster &cible)
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
		short HP1 = cible.getHPAct();
		short HP2 = HP1 - val_degat;
		cible.setHP(HP2);
		m_nu[num_att]--;
		if (burn())
		{
			if (cible.getEtat() == 0)
			{
				cible.setEtat(1);
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}