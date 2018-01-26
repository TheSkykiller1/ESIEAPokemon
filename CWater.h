#ifndef _CWATER_H_
#define _CWATER_H_

#include "CMonster.h"

class CWater :public CMonster
{
protected:
	std::vector<std::string> m_force = { "Fire" };
	float m_flood;
	float m_fall;

public:
	CWater();
	CWater(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CWater();

	float getFlood();
	float getFall();

	void setFlood(float flood);
	void setFall(float fall);

	bool flood();
	bool attaquer(int num_att, CMonster &cible);
};

#endif