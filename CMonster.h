#ifndef _CMONSTER_H_
#define _CMONSTER_H_
#include <iostream>
#include <vector>
#include <string>

#include "CAttaque.h"
#include "CObject.h"

class CMonster
{
protected:
	int m_id;
	std::string m_type;
	std::string m_nom;
	int m_HP;
	int m_HP_act;
	int m_vitesse;
	int m_vitesse_act;
	int m_attaque;
	int m_attaque_act;
	//std::vector<CAttaque> m_attaques;
	int m_defense;
	int m_defense_act;
	int m_etat;
	int m_etat_tours;
	std::vector<std::string> m_force;
	//std::vector<CAttaque*> m_CS;
	bool m_cache;

	std::vector<std::string> m_nom_attaque;
	std::vector<std::string> m_type_attaque;
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
	int getHPAct();
	int getVitesse();
	int getVitesseAct();
	int getAttaque();
	int getAttaqueAct();
	int getDefense();
	int getDefenseAct();
	int getEtat();
	int getEtatTours();
	std::vector<std::string> getForce();
	//std::vector<CAttaque> getCS();
	bool getCache();
	std::vector<std::string> getNAttaques();
	std::vector<std::string> getTAttaques();
	std::vector<int> getNU();
	std::vector<int> getPAtt();
	std::vector<float> getPEchec();

	void setId(int id);
	void setType(std::string type);
	void setNom(std::string nom);
	void setHP(int HP);
	void setHPAct(int HP_act);
	void setVitesse(int vitesse);
	void setVitesseAct(int vitesse_act);
	void setAttaque(int attaque);
	void setAttaqueAct(int attaque_act);
	void setDefense(int defense);
	void setDefenseAct(int defense_act);
	void setEtat(int etat);
	void setEtatTours(int tours);
	void setCache(bool cache);
	
	int updateEtat();
	virtual bool attaquer(int num_att, CMonster &cible);
	int degat(int num_att, CMonster &def);
	bool echec(int num_att);
	bool init_combat(CMonster &monstre1, CMonster &monstre2);
	bool analyse_speed(CMonster &monstre1, CMonster &monster2);
	bool tour(CMonster* monstre/*, CObject &objet1, CObject &objet2*//*, CWorld &terrain*/);
	void useObject(CObject &objet);
};

#endif

