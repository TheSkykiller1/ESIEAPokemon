#include "CAttaque.h"

CAttaque::CAttaque()
{

}

CAttaque::CAttaque(std::string nom, short type, short nu, short pa, float pe)
{
	m_nom = nom;
	m_type = type;
	m_nu = nu;
	m_pAttaque = pa;
	m_pEchec = pe;
}

CAttaque::~CAttaque()
{

}

//GETTERS

std::string CAttaque::getNom()
{
	return m_nom;
}

short CAttaque::getType()
{
	return m_type;
}

short CAttaque::getNU()
{
	return m_nu;
}

short CAttaque::getPA()
{
	return m_pAttaque;
}

float CAttaque::getPE()
{
	return m_pEchec;
}

bool CAttaque::getCS()
{
	return m_cs;
}

//SETTERS

void CAttaque::setNom(std::string nom)
{
	m_nom = nom;
}

void CAttaque::setType(short type)
{
	m_type = type;
}

void CAttaque::setNU(short nu)
{
	m_nu = nu;
}

void CAttaque::setPA(short pa)
{
	m_pAttaque = pa;
}

void CAttaque::setPE(float pe)
{
	m_pEchec = pe;
}

void CAttaque::setCS(bool cs)
{
	m_cs = cs;
}

//METHODES