#ifndef _CELECTRIC_H_
#define _CELECTRIC_H_

#include "CMonster.h"

class CElectric:public CMonster
{
protected:
	std::vector<std::string> m_force = { "Water" }; //vecteur des types de victimes à privilégier
	float m_paralysis; //probabilité de se faire paralyser

	bool paralyze(); //booléen de test paralysie

public:
	CElectric();
	CElectric(int id, std::string type, std::string nom, int HP, int vit, int att, int def, float paralysis=0.0f);
	~CElectric();

	float getParalysis();

	void setParalysis(float paralysis);

	bool attaquer(int num_att, CMonster* cible);
};

#endif