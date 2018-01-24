#include "CObject.h"

CObject::CObject()
{

}

CObject::CObject(int id, std::string nom, std::vector<short> type, short vit, short att, short def, short HP)
{
	m_id = id;
	m_nom = nom;
	m_type = type;
	m_vit = vit;
	m_att = att;
	m_def = def;
	m_HP = HP;
}

CObject::~CObject()
{

}

//GETTERS

short CObject::getId()
{
	return m_id;
}

std::string CObject::getNom()
{
	return m_nom;
}

std::vector<short> CObject::getType()
{
	return m_type;
}

short CObject::getVit()
{
	return m_vit;
}

short CObject::getAtt()
{
	return m_att;
}

short CObject::getDef()
{
	return m_def;
}

short CObject::getHP()
{
	return m_HP;
}

short CObject::getEtat()
{
	return m_etat;
}

//SETTERS

void CObject::setId(short id)
{
	m_id = id;
}

void CObject::setNom(std::string nom)
{
	m_nom = nom;
}

void CObject::setType(std::vector<short> type)
{
	m_type = type;
}

void CObject::setVit(short vit)
{
	m_vit = vit;
}

void CObject::setAtt(short att)
{
	m_att = att;
}

void CObject::setDef(short def)
{
	m_def = def;
}

void CObject::setHP(short HP)
{
	m_HP = HP;
}

void CObject::setEtat(short etat)
{
	m_etat = etat;
}