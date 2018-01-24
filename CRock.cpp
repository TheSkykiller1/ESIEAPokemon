#include "CRock.h"

CRock::CRock()
{
	CMonster();
}

CRock::CRock(int id, short type, std::string nom, short HP, short vit, short att, short def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CRock::~CRock()
{

}

//GETTERS

//SETTERS