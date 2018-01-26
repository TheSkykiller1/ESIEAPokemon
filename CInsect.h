#ifndef _CINSECT_H_
#define _CINSECT_H_

#include "CGrass.h"

class CInsect :public CGrass
{
protected:
	float m_poison;
public:
	CInsect();
	CInsect(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CInsect();

	bool poison();
	bool attaquer(int m_num, CMonster &cible);
};

#endif