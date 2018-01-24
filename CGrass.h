#ifndef _CGRASS_H_
#define _CGRASS_H_

#include "CMonster.h"

class CGrass :public CMonster
{
protected:
	std::vector<short> m_force = { 3 };

public:
	CGrass();
	~CGrass();
};

#endif