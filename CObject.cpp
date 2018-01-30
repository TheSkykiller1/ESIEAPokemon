#include "CObject.h"

CObject::CObject(){}
CObject::CObject(int id,std::string genre, std::string nom, std::vector<std::string> type)
{
	m_id = id;
	m_nom = nom;
	m_genre = genre;
	m_type = type;
}
CObject::~CObject(){}

//GETTERS
int CObject::getId(){return m_id;}
std::string CObject::getNom(){return m_nom;}
std::string CObject::getGenre(){return m_genre;}
std::vector<std::string> CObject::getType(){return m_type;}
int CObject::getVit(){return 0;}
int CObject::getAtt(){return 0;}
int CObject::getDef(){return 0;}
int CObject::getHP(){return 0;}
std::string CObject::getEtat(){return "";}

//SETTERS
void CObject::setId(int id){m_id = id;}
void CObject::setNom(std::string nom){m_nom = nom;}
void CObject::setGenre(std::string genre){m_genre = genre;}
void CObject::setType(std::vector<std::string> type){m_type = type;}