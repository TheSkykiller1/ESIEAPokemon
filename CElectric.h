#ifndef _CELECTRIC_H_
#define _CELECTRIC_H_

#include "CMonster.h"

class CElectric:public CMonster
{
protected:
	std::vector<short> m_force = { 0 };
	float m_paralysis;

	bool paralyze();

public:
	CElectric();
	CElectric(float paralysis);
	~CElectric();

	float getParalysis();

	void setParalysis(float paralysis);
};

#endif