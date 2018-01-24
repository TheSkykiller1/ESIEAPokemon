#include "CInsect.h"

CInsect::CInsect()
{
	CMonster();
}

CInsect::CInsect(int id, short type, std::string nom, short HP, short vit, short att, short def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CInsect::~CInsect()
{

}

void poison(CMonster* monstre)
{
	monstre->setEtat(2);
}