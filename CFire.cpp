#include "CFire.h"

CFire::CFire()
{
	CMonster();
}

CFire::CFire(int id, short type, std::string nom, short HP, short vit, short att, short def)
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