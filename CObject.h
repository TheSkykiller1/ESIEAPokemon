#ifndef _COBJECT_H_
#define _COBJECT_H_

#include <iostream>
#include <vector>

class CObject
{
protected:
	int m_id;
	std::string m_nom;
	std::vector<short> m_type;
	//modification relative (+:augmentation)
	short m_vit;
	short m_att;
	short m_def;
	short m_HP;
	//
	short m_etat; //-1 si aucun for�age sinon prend la valeur de l'�tat forc� � l'utilisation
public:
	CObject();
	CObject(int id, std::string nom, std::vector<short> type, short vit, short att, short def, short HP);
	~CObject();
	short getId();
	std::string getNom();
	std::vector<short> getType();
	short getVit();
	short getAtt();
	short getDef();
	short getHP();
	short getEtat();

	void setId(short id);
	void setNom(std::string nom);
	void setType(std::vector<short> type);
	void setVit(short vit);
	void setAtt(short att);
	void setDef(short def);
	void setHP(short HP);
	void setEtat(short etat);
};

#endif