#ifndef _CTERRAIN_H
#define _CTERRAIN_H
#include <iostream>

class CTerrain
{
public:
	CTerrain();
	~CTerrain();
	
	//Getters
	std::string Title();

protected:
	std::string s_name_terrain;
	short s_id_terrain;
	float s_fire;
	float s_electric;
	float s_water;
	float s_rock;
	float s_grass;
	
};
#endif

