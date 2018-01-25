#include "CRock.h"

CRock::CRock()
{
	CMonster();
}

CRock::CRock(int id, std::string type, std::string nom, int HP, int vit, int att, int def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CRock::~CRock()
{

}

//GETTERS

//SETTERS