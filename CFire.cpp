#include "CFire.h"

CFire::CFire()
{
	CMonster();
}

void CFire::burn(CMonster* monstre)
{
	monstre->setEtat(1);
}