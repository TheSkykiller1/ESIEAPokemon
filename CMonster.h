#ifndef _CMONSTER_H_
#define _CMONSTER_H_

#include "CAttaque.h"

#include <iostream>
#include <vector>

class CMonster
{
protected:
	int m_id;
	std::string m_type;
	std::string m_nom;
	int m_HP;
	int m_vitesse;
	int m_attaque;
	int m_attaque_act;
	//std::vector<CAttaque> m_attaques;
	int m_defense;
	int m_etat;
	int m_etat_tours;
	std::vector<std::string> m_force;
	//std::vector<CAttaque*> m_CS;
	bool m_cache;

	std::vector<std::string> m_nom_attaques;
	std::vector<int> m_nu;
	std::vector<int> m_pAttaques;
	std::vector<float> m_pEchec;
public:
	CMonster();
	CMonster(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CMonster();

	int getId();
	std::string getType();
	std::string getNom();
	int getHP();
	int getVitesse();
	int getAttaque();
	int getAttaqueAct();
	int getDefense();
	int getEtat();
	int getEtatTours();
	std::vector<std::string> getForce();
	//std::vector<CAttaque> getCS();
	bool getCache();

	void setId(int id);
	void setType(std::string type);
	void setNom(std::string nom);
	void setHP(int HP);
	void setVitesse(int vitesse);
	void setAttaque(int attaque);
	void setAttaqueAct(int attaqueAct);
	void setDefense(int defense);
	void setEtat(int etat);
	void setEtatTours(int tours);
	void setCache(bool cache);
	
	short updateEtat();
	virtual bool attaquer(int num_att, CMonster &cible);
	short degat(int num_att, CMonster &def);
};

#endif

