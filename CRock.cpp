#include "CRock.h"

CRock::CRock()
{
	CMonster();
}

CRock::CRock(int id, short type, std::string nom, short HP, short vit, short att, short def, bool cache)
{
	CMonster(id, type, nom, HP, vit, att, def);
	m_cache = cache;
}

CRock::~CRock()
{

}

//GETTERS

bool CRock::getCache()
{
	return m_cache;
}

//SETTERS

void CRock::setCache(bool cache)
{
	m_cache = cache;
}