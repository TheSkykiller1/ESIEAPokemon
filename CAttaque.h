#ifndef _CATTAQUE_H_
#define _CATTAQUE_H_

#include <iostream>
#include "CMonster.h"

class CAttaque
{
protected:
	std::string m_nom;
	short m_type;
	short m_nu; //nombre d'utilisation de l'attaque
	short m_pAttaque; //puissance d'attaque
	float m_pEchec; //probabilité d'échec
	bool m_cs;//s'agit t'il d'une capacité spéciale ?

public:
	std::string getNom();
	short getType();
	short getNU();
	short getPA();
	float getPE();
	bool getCS();

	void setNom(std::string nom);
	void setType(short type);
	void setNU(short nu);
	void setPA(short pa);
	void setPE(float pe);
	void setCS(bool cs);

	//short degat(CMonster * att, CMonster * def);
};

#endif
