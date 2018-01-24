#ifndef _CDRUG_H_
#define _CDRUG_H_

#include "CObject.h"

class CDrug :public CObject
{
public:
	CDrug();
	CDrug(int id, std::string nom, std::vector<short> type, short vit, short att, short def, short HP);
	~CDrug();
};

#endif