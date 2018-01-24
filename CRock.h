#ifndef _CROCK_H_
#define _CROCK_H_

#include "CMonster.h"

class CRock:public CMonster
{
protected:
	std::vector<short> m_force = { 4 };

public:
	CRock();
	CRock(int id, short type, std::string nom, short HP, short vit, short att, short def);
	~CRock();
};

#endif
