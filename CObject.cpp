#include "CObject.h"

CObject::CObject()
{

}

CObject::CObject(int id, std::string nom, std::vector<std::string> type)
{
	m_id = id;
	m_nom = nom;
	m_type = type;
}

CObject::~CObject()
{

}

//GETTERS

int CObject::getId()
{
	return m_id;
}

std::string CObject::getNom()
{
	return m_nom;
}

std::vector<std::string> CObject::getType()
{
	return m_type;
}

int CObject::getVit()
{
	return 0;
}

int CObject::getAtt()
{
	return 0;
}

int CObject::getDef()
{
	return 0;
}

int CObject::getHP()
{
	return 0;
}

int CObject::getEtat()
{
	return 0;
}

//SETTERS

void CObject::setId(int id)
{
	m_id = id;
}

void CObject::setNom(std::string nom)
{
	m_nom = nom;
}

void CObject::setType(std::vector<std::string> type)
{
	m_type = type;
}