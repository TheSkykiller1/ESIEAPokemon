#ifndef _CPOTION_H_
#define _CPOTION_H_

#include "CObject.h"

class CPotion :public CObject
{
public:
	CPotion();
	CPotion(int id, std::string nom, std::vector<short> type, short vit, short att, short def, short HP);
	~CPotion();
};

#endif