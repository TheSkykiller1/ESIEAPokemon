#ifndef _CMONSTER_H_
#define _CMONSTER_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>//ifstream
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "CAttaque.h"
#include "CObject.h"
#include "CTerrain.h"

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
	int m_etat_tours; //nombre de tours dans un état non normal
	std::vector<std::string> m_force; //liste des types de monstres étant des cibles plus faciles
	bool m_cache; //etat du cachage des monstres Rock


	template<typename Out>
	void split(const std::string &s, char delim, Out result);
	std::vector<std::string> split(const std::string &s, char delim);

public:
	CMonster();
	CMonster(int id, std::string type, std::string nom, int HP, int vit, int att, int def);
	~CMonster();

	std::vector<CAttaque*> Attaques_list;

	std::vector<bool> Attaques_actives;
	std::vector<int> Attaques_utilisation;

	void set_attaques_disp(std::vector<CAttaque*> Attac);

#pragma region GETSET
	virtual int getId();
	virtual std::string getType();
	virtual std::string getNom();
	virtual int getHP();
	virtual int getHPAct();
	virtual int getVitesse();
	virtual int getVitesseAct();
	virtual int getAttaque();
	virtual int getAttaqueAct();
	virtual int getDefense();
	virtual int getDefenseAct();
	virtual std::string getEtat();
	virtual int getEtatTours();
	virtual std::vector<std::string> getForce();
	virtual bool getCache();
	virtual float getFall();

	virtual void setId(int id);
	virtual void setType(std::string type);
	virtual void setNom(std::string nom);
	virtual void setHP(int HP);
	virtual void setHPAct(int HP_act);
	virtual void setVitesse(int vitesse);
	virtual void setVitesseAct(int vitesse_act);
	virtual void setAttaque(int attaque);
	virtual void setAttaqueAct(int attaque_act);
	virtual void setDefense(int defense);
	virtual void setDefenseAct(int defense_act);
	virtual void setForce(std::vector<std::string> force);
	virtual void setEtat(std::string etat);
	virtual void setEtatTours(int tours);
	virtual void setCache(bool cache);
	virtual void reset();
	
#pragma endregion

	std::string updateEtat(); //mise à jour des états des monstres (à chaque tour)
	virtual bool attaquer(int num_att, CMonster* cible); //attaque d'un monstre vers un autre avec une attaque determinée
	int degat(int num_att, CMonster* def); //calcul des dégâts d'une attaque
	bool echec(int num_att); //booléen de test de l'echec de l'attaque
	bool init_combat(CMonster* monstre); //vérification de l'état initial des monstres
	bool analyse_speed(CMonster* monster); //détermination de l'ordre d'attaque
	bool tour(CMonster* monstre, CTerrain* terrain); //demande de l'attaque et exécution de cette dernière
	void useObject(CObject* objet); //utilisation des objets
	void recevoirDegat(int degat); //reception des dégâts
	virtual void checkHP(CTerrain* terrain); //vérification des HP du monstre, pour exécution d'actions spécifiques
	virtual bool verifTerrain(int num_att, CMonster* monstre, CTerrain* terrain); //vérification de l'état du terrain
};

#endif

