#ifndef _CATTAQUE_H_
#define _CATTAQUE_H_

#include <iostream>
#include "CMonster.h"

class CAttaque
{
protected:
	std::string m_nom;
	int m_type;
	int m_nu; //nombre d'utilisation de l'attaque
	int m_pAttaque; //puissance d'attaque
	float m_pEchec; //probabilité d'échec
	bool m_cs;//s'agit t'il d'une capacité spéciale ?

public:
	CAttaque();
	CAttaque(std::string nom, int type, int nu, int pa, float pe);
	~CAttaque();

	std::string getNom();
	int getType();
	int getNU();
	int getPA();
	float getPE();
	bool getCS();

	void setNom(std::string nom);
	void setType(int type);
	void setNU(int nu);
	void setPA(int pa);
	void setPE(float pe);
	void setCS(bool cs);
};

#endif
