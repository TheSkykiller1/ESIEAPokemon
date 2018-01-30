#include "CPotion.h"

CPotion::CPotion() { CObject();}
CPotion::CPotion(int id, std::string genre, std::string nom, \
	std::vector<std::string> type, int vit, int att, int def, int HP) : \
	CObject(id, genre, nom, type), m_vit(vit), m_att(att), m_def(def), m_HP(HP)
{
}
CPotion::~CPotion(){}

// GETTERS
int CPotion::getVit(){return m_vit;}
int CPotion::getAtt(){return m_att;}
int CPotion::getDef(){return m_def;}
int CPotion::getHP(){return m_HP;}

// SETTERS
void CPotion::setVit(int vit){m_vit = vit;}
void CPotion::setAtt(int att){m_att = att;}
void CPotion::setDef(int def){m_def = def;}
void CPotion::setHP(int HP){m_HP = HP;}