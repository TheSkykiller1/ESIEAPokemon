#include "CWater.h"

CWater::CWater()
{
	CMonster();
}

CWater::CWater(int id, short type, std::string nom, short HP, short vit, short att, short def)
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
	return false; //todo a modifier flood
}