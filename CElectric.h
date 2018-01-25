#ifndef _CELECTRIC_H_
#define _CELECTRIC_H_

#include "CMonster.h"

class CElectric:public CMonster
{
protected:
	std::vector<std::string> m_force = { "Water" };
	float m_paralysis;

	bool paralyze();

public:
	CElectric();
	CElectric(int id, std::string type, std::string nom, int HP, int vit, int att, int def, float paralysis=0.0f);
	~CElectric();

	float getParalysis();

	void setParalysis(float paralysis);

	bool attaquer(int num_att, CMonster &cible);
};

#endif