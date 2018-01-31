#include "CGrass.h"

CGrass::CGrass() : CMonster()
{
}

CGrass::CGrass(int id, std::string type, std::string nom, int HP, int vit, int att, int def) : CMonster(id, type, nom, HP, vit, att, def)
{
}

CGrass::~CGrass()
{
}