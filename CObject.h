#ifndef _COBJECT_H_
#define _COBJECT_H_

#include <iostream>
#include <vector>

class CObject
{
protected:
	int m_id;
	std::string m_nom;
	std::vector<std::string> m_type;
public:
	CObject();
	CObject(int id, std::string nom, std::vector<std::string> type);
	~CObject();
	short getId();
	std::string getNom();
	std::vector<std::string> getType();

	void setId(short id);
	void setNom(std::string nom);
	void setType(std::vector<short> type);
};

#endif