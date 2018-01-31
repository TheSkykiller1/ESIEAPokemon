#ifndef _CMONSTER_H_
#define _CMONSTER_H_
#include <iostream>
#include <vector>
#include <string>

#include "CAttaque.h"
#include "CObject.h"
#include "CTerrain.h"

#include <iostream>

class CMonster
{
protected:
	int m_id; //id du monstre
	std::string m_type; //type du monstre
	std::string m_nom; //nom du monstre
	int m_HP; //points de vie totaux du monstre
	int m_HP_act; //points de vie actuels du monstre
	int m_vitesse; //vitesse total du monstre
	int m_vitesse_act; //vitesse actuelle du monstre
	int m_attaque; //attaque du monstre
	int m_attaque_act; //attaque actuelle du monstre
	int m_defense; //defense totale du monstre
	int m_defense_act; //defense actuelle du monstre
	std::string m_etat; //etat du monstre
	int m_etat_tours; //nombre de tours dans un �tat non normal
	std::vector<std::string> m_force; //liste des types de monstres �tant des cibles plus faciles
	bool m_cache; //etat du cachage des monstres Rock

	std::vector<std::string> m_nom_attaque; //vecteur des noms d'attaque
	std::vector<std::string> m_type_attaque; //vecteur des types d'attaque
	std::vector<int> m_nu; //vecteur des nombres d'utilisations restantes
	std::vector<int> m_pAttaques; //vecteur des puissances d'attaques
	std::vector<float> m_pEchec; //vecteur des probabilit�s d'echecs
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
	std::string getEtat();
	int getEtatTours();
	virtual std::vector<std::string> getForce();
	bool getCache();
	virtual float getFall();
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
	void setEtat(std::string etat);
	void setEtatTours(int tours);
	void setCache(bool cache);
	void reset();
	
	std::string updateEtat(); //mise � jour des �tats des monstres (� chaque tour)
	virtual bool attaquer(int num_att, CMonster* cible); //attaque d'un monstre vers un autre avec une attaque determin�e
	int degat(int num_att, CMonster* def); //calcul des d�g�ts d'une attaque
	bool echec(int num_att); //bool�en de test de l'echec de l'attaque
	bool init_combat(CMonster* monstre); //v�rification de l'�tat initial des monstres
	bool analyse_speed(CMonster* monster); //d�termination de l'ordre d'attaque
	bool tour(CMonster* monstre, CTerrain* terrain); //demande de l'attaque et ex�cution de cette derni�re
	void useObject(CObject* objet); //utilisation des objets
	void recevoirDegat(int degat); //reception des d�g�ts
	virtual void checkHP(CTerrain* terrain); //v�rification des HP du monstre, pour ex�cution d'actions sp�cifiques
	virtual bool verifTerrain(int num_att, CMonster* monstre, CTerrain* terrain); //v�rification de l'�tat du terrain
};

#endif

