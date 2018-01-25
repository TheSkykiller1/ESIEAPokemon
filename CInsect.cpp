#include "CInsect.h"

CInsect::CInsect()
{
	CMonster();
}

CInsect::CInsect(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	CGrass(id, type, nom, HP, vit, att, def);
}

CInsect::~CInsect()
{

}

void poison(CMonster &monstre)
{
	//monstre->setEtat(2);
}