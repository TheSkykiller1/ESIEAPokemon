#include "CDrug.h"

CDrug::CDrug()
{
	CObject();
}

CDrug::CDrug(int id, std::string nom, std::string type, int etat)
{
	CObject(id, nom, type);
	m_etat = etat;
}

CDrug::~CDrug()
{

}

int CDrug::getEtat()
{
	return m_etat;
}

void CDrug::setEtat(int etat)
{
	m_etat = etat;
}