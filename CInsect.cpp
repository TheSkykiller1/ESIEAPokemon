#include "CInsect.h"

CInsect::CInsect()
{
	CMonster();
}

CInsect::CInsect(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	CGrass(id, type, nom, HP, vit, att, def);
}

CInsect::~CInsect()
{

}

//METHODES

void poison(CMonster &monstre)
{
	//monstre->setEtat(2);
}

bool CInsect::attaquer(int num_att, CMonster &cible)
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
		return 0;
	}
	else
	{
		return 1;
	}
}