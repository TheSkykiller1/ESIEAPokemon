#include "CPlant.h"

CPlant::CPlant()
{
	CMonster();
}

CPlant::CPlant(int id, short type, std::string nom, short HP, short vit, short att, short def)
{
	CMonster(id, type, nom, HP, vit, att, def);
}

CPlant::~CPlant()
{

}