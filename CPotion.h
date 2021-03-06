#ifndef _CPOTION_H_
#define _CPOTION_H_

#include "CObject.h"

class CPotion :public CObject
{
protected:
	//modification relative (+:augmentation)
	short m_vit;
	short m_att;
	short m_def;
	short m_HP;
	//
public:
	CPotion();
	CPotion(int id,std::string genre, std::string nom, std::vector<std::string> type, int vit, int att, int def, int HP);
	~CPotion();

	//getters
	int getVit();
	int getAtt();
	int getDef();
	int getHP();
	//setters
	void setVit(int vit);
	void setAtt(int att);
	void setDef(int def);
	void setHP(int HP);
};

#endif