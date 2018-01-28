#ifndef _CTERRAIN_H
#define _CTERRAIN_H
#include <iostream>

class CTerrain
{
public:
	CTerrain();
	CTerrain(std::string name,int id, float fire, float electric, float water, float rock, float grass);
	~CTerrain();
	
	//Getters
	std::string Title();
	int id();
	float fire_bonus();
	float electric_bonus();
	float water_bonus();
	float rock_bonus();
	float grass_bonus();
	void set_title(std::string debugtitle);

protected:
	std::string s_name_terrain;
	int s_id_terrain;
	float s_fire;
	float s_electric;
	float s_water;
	float s_rock;
	float s_grass;
	
};
#endif

