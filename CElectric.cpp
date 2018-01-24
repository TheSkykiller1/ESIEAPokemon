#include "CElectric.h"

CElectric::CElectric()
{
	CMonster();
}

CElectric::CElectric(float paralysis)
{
	CMonster();
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