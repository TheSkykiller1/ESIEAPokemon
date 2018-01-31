#ifndef _CFIRE_H_
#define _CFIRE_H_

#include "CMonster.h"

class CFire :public CMonster
{
protected:
	std::vector<std::string> m_force = { "Insect", "Plant" };
	float m_burn; //probabilité de faire bruler l'ennemi

public:
	CFire();
	CFire(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CFire();
	
	bool burn(); //booléen de test brulure
	bool attaquer(int m_num, CMonster* cible);
};

#endif
