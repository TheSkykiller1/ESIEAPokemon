#ifndef _CINSECT_H_
#define _CINSECT_H_

#include "CGrass.h"

class CInsect :public CGrass
{
public:
	CInsect();
	CInsect(int id, short type, std::string nom, short HP, short vit, short att, short def);
	~CInsect();

	void poison(CMonster* monstre);
};

#endif