#ifndef _CROCK_H_
#define _CROCK_H_

#include "CMonster.h"

class CRock:public CMonster
{
protected:
	std::vector<std::string> m_force = { "Electric" };

public:
	CRock();
	CRock(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CRock();

	bool attaquer(int m_num, CMonster &cible);
};

#endif
