#ifndef _CINSECT_H_
#define _CINSECT_H_

#include "CGrass.h"

class CInsect :public CGrass
{
public:
	CInsect();
	~CInsect();

	void poison(CMonster* monstre);
};

#endif