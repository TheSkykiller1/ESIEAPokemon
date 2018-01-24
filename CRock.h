#ifndef _CROCK_H_
#define _CROCK_H_

#include "CMonster.h"

class CRock:public CMonster
{
protected:
	std::vector<short> m_force = { 4 };
	bool m_cache;

public:
	CRock();
	CRock(bool cache);
	~CRock();

	bool getCache();

	void setCache(bool cache);
};

#endif
