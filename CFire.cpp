#include "CFire.h"

CFire::CFire()
{
	CMonster();
}

CFire::CFire(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CFire::~CFire()
{

}

void CFire::burn(CMonster* monstre)
{
	monstre->setEtat(1);
}