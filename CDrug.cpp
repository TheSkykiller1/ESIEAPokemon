#include "CDrug.h"

CDrug::CDrug()
{
	CObject();
}

CDrug::CDrug(int id, std::string nom, std::vector<std::string> type, int etat)
{
	CObject(id, nom, type);
	m_etat = etat;
}

CDrug::~CDrug()
{

}

std::string CDrug::getEtat()
{
	return m_etat;
}

void CDrug::setEtat(std::string etat)
{
	m_etat = etat;
}