#include "CAttaque.h"

CAttaque::CAttaque()
{
}
CAttaque::CAttaque(std::string nom, std::string type, int nu, int pa, float pe):\
m_nom(nom),m_type(type),m_nu(nu),m_power(pa),m_fail(pe)
{
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

int CAttaque::get_NbUse()
{
	return m_nu;
}

int CAttaque::get_Power()
{
	return m_power;
}

float CAttaque::get_Fail()
{
	return m_fail;
}
