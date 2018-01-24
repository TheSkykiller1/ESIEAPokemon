#include "CPotion.h"

CPotion::CPotion()
{
	CObject();
}

CPotion::CPotion(int id, std::string nom, std::vector<short> type, short vit, short att, short def, short HP)
{
	CObject(id, nom, type, vit, att, def, HP);
}

CPotion::~CPotion()
{

}