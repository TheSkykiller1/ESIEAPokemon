#ifndef _CDRUG_H_
#define _CDRUG_H_

#include "CObject.h"

class CDrug :public CObject
{
protected:
	int m_etat;
public:
	CDrug();
	CDrug(int id, std::string nom, std::vector<std::string> type,int etat);
	~CDrug();

	int getEtat();

	void setEtat(int etat);
};

#endif