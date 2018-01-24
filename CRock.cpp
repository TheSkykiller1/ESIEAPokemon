#include "CRock.h"

CRock::CRock()
{
	CMonster();
}

CRock::CRock(bool cache)
{
	CMonster();
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