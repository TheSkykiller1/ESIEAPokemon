#include "CDrug.h"

CDrug::CDrug() { CObject(); }
CDrug::CDrug(int id,std::string genre, std::string nom, std::vector<std::string> type, std::string etat)
{
	CObject(id, genre, nom, type);
	m_etat = etat;
}
CDrug::~CDrug(){}

//Methodes
std::string CDrug::getEtat() { return m_etat; }
void CDrug::setEtat(std::string etat) { m_etat = etat; }