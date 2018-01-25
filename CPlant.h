#ifndef _CPLANT_H_
#define _CPLANT_H_

#include "CGrass.h"

class CPlant :public CGrass
{
public:
	CPlant();
	CPlant(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CPlant();
};

#endif