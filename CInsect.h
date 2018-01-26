#ifndef _CINSECT_H_
#define _CINSECT_H_

#include "CGrass.h"

class CInsect :public CGrass
{
public:
	CInsect();
	CInsect(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CInsect();

	void poison(CMonster &monstre);
	bool attaquer(int m_num, CMonster &cible);
};

#endif