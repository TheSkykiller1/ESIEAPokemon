#ifndef _CATTAQUE_H_
#define _CATTAQUE_H_

#include <iostream>
#include "CMonster.h"

class CAttaque
{
protected:
	std::string m_nom;
	std::string m_type;
	int m_nu; //nombre d'utilisation de l'attaque
	int m_pAttaque; //puissance d'attaque
	float m_pEchec; //probabilité d'échec

public:
	CAttaque();
	CAttaque(std::string nom, std::string type, int nu, int pa, float pe);
	~CAttaque();

	std::string getNom();
	std::string getType();
	int getNU();
	int getPA();
	float getPE();

	void setNom(std::string nom);
	void setType(std::string type);
	void setNU(int nu);
	void setPA(int pa);
	void setPE(float pe);
};

#endif
