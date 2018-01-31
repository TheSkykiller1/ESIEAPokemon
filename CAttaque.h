#ifndef _CATTAQUE_H_
#define _CATTAQUE_H_

#include <iostream>
#include "CMonster.h"

class CAttaque
{
protected:
	std::string m_nom; //nom de l'attaque
	std::string m_type; //type de l'attaque
	int m_nu; //nombre d'utilisation de l'attaque
	int m_power; //puissance d'attaque
	float m_fail; //probabilité d'échec

public:
	CAttaque();
	CAttaque(std::string nom, std::string type, int nu, int pa, float pe);
	~CAttaque();

	std::string getNom();
	std::string getType();
	int get_NbUse();
	int get_Power();
	float get_Fail();
};

#endif
