#include "CFire.h"

CFire::CFire() : CMonster()
{
}

CFire::CFire(int id, std::string type, std::string nom, int HP, int vit, int att, int def) : CMonster(id, type, nom, HP, vit, att, def), m_force({"Insect", "Plant"})
{
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

bool CFire::attaquer(int num_att, CMonster* cible, CTerrain* terrain)
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
		cible->checkHP(terrain);
		if (burn() && m_type_attaque[num_att] != "Normal")
		{
			if (cible->getEtat() == "Normal")
			{
				cible->setEtat("Burnt");
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}