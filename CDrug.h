#ifndef _CDRUG_H_
#define _CDRUG_H_

#include "CObject.h"

#include <iostream>

class CDrug :public CObject
{
protected:
	std::string m_etat;
public:
	CDrug();
	CDrug(int id, std::string nom, std::vector<std::string> type, int etat);
	~CDrug();

	std::string getEtat();

	void setEtat(std::string etat);
};

#endif