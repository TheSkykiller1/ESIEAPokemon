#ifndef _CGRASS_H_
#define _CGRASS_H_

#include "CMonster.h"

class CGrass :public CMonster
{
protected:
	std::vector<std::string> m_force = { "Rock" };

public:
	CGrass();
	CGrass(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CGrass();
};

#endif