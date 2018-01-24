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
	return false; //todo paralyser
}

void CElectric::attaquer(short num_att, CMonster &cible)
{
	if (m_nu[num_att] > 0)
	{
		short val_degat = degat(num_att, cible);
		short HP1 = cible.getHP();
		short HP2 = HP1 - val_degat;
		cible.setHP(HP2);
		m_nu[num_att]--;
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