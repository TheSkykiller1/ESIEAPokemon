#include "CInsect.h"

CInsect::CInsect()
{
	CMonster();
}

CInsect::~CInsect()
{

}

void poison(CMonster* monstre)
{
	monstre->setEtat(2);
}