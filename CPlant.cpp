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