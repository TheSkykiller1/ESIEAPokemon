#include "CGrass.h"

CGrass::CGrass()
{
	CMonster();
}

CGrass::CGrass(int id, short type, std::string nom, short HP, short vit, short att, short def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CGrass::~CGrass()
{
	CMonster();
}