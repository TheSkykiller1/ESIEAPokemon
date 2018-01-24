#include "CWater.h"

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