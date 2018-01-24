#ifndef _CWATER_H_
#define _CWATER_H_

#include "CMonster.h"

class CWater :public CMonster
{
protected:
	std::vector<short> m_force = { 1 };
	float m_flood;
	float m_fall;

public:
	float getFlood();
	float getFall();

	void setFlood(float flood);
	void setFall(float fall);

	bool flood();
};

#endif