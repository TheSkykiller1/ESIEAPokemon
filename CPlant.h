#ifndef _CPLANT_H_
#define _CPLANT_H_

#include "CGrass.h"

class CPlant :public CGrass
{
public:
	CPlant();
	CPlant(int id, short type, std::string nom, short HP, short vit, short att, short def);
	~CPlant();
};

#endif