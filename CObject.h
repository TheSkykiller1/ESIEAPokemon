#ifndef _COBJECT_H_
#define _COBJECT_H_

#include <iostream>
#include <vector>

class CObject
{
protected:
	int m_id; //id de l'objet
	std::string m_nom; //nom de l'objet
	std::vector<std::string> m_type; //type de monstre autorisé
public:
	CObject();
	CObject(int id, std::string nom, std::vector<std::string> type);
	~CObject();

	int getId();
	std::string getNom();
	std::vector<std::string> getType();
	virtual int getVit();
	virtual int getAtt();
	virtual int getDef();
	virtual int getHP();
	virtual std::string getEtat();

	void setId(int id);
	void setNom(std::string nom);
	void setType(std::vector<std::string> type);
};

#endif