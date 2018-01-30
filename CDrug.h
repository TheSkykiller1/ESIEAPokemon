#ifndef _CDRUG_H_
#define _CDRUG_H_

#include "CObject.h"

class CDrug :public CObject
{
protected:
	std::string m_etat;
public:
	CDrug();
	CDrug(int id, std::string genre, std::string nom, std::vector<std::string> type, std::string etat);
	~CDrug();

	std::string getEtat();

	void setEtat(std::string etat);
};

#endif