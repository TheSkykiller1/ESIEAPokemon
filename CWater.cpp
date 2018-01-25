#include "CWater.h"

CWater::CWater()
{
	CMonster();
}

CWater::CWater(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CWater::~CWater()
{

}

//GETTERS

float CWater::getFlood()
{
	return m_flood;
}

float CWater::getFall()
{
	return m_fall;
}

//SETTERS

void CWater::setFlood(float flood)
{
	m_flood = flood;
}

void CWater::setFall(float fall)
{
	m_fall = fall;
}

//METHODES

bool CWater::flood()
{
	short val = m_flood + rand() / RAND_MAX;
	if (val)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}