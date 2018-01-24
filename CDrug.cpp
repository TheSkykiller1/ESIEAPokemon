#include "CDrug.h"

CDrug::CDrug()
{

}

CDrug::CDrug(int id, std::string nom, std::vector<short> type, short vit, short att, short def, short HP)
{
	CObject(id, nom, type, vit, att, def, HP);
}

CDrug::~CDrug()
{

}