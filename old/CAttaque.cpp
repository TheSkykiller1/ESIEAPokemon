#include "CAttaque.h"

CAttaque::CAttaque()
{

}

CAttaque::CAttaque(std::string nom, std::string type, int nu, int pa, float pe)
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

std::string CAttaque::getType()
{
	return m_type;
}

int CAttaque::getNU()
{
	return m_nu;
}

int CAttaque::getPA()
{
	return m_pAttaque;
}

float CAttaque::getPE()
{
	return m_pEchec;
}

//SETTERS

void CAttaque::setNom(std::string nom)
{
	m_nom = nom;
}

void CAttaque::setType(std::string type)
{
	m_type = type;
}

void CAttaque::setNU(int nu)
{
	m_nu = nu;
}

void CAttaque::setPA(int pa)
{
	m_pAttaque = pa;
}

void CAttaque::setPE(float pe)
{
	m_pEchec = pe;
}

//METHODES