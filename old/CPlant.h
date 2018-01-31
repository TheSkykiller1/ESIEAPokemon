#ifndef _CPLANT_H_
#define _CPLANT_H_

#include "CGrass.h"

class CPlant :public CGrass
{
protected:
	float m_heal;
public:
	CPlant();
	CPlant(int id, std::string type, std::string nom, int HP, int vit, int att, int def, float heal = 0.0f);
	~CPlant();

	bool heal();

	float getHeal();

	void setHeal(float heal);

	bool attaquer(int m_num, CMonster* cible);
};

#endif