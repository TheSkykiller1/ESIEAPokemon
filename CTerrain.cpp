#include "CTerrain.h"

CTerrain::CTerrain()
{
	s_name_terrain = "Unamed";
	s_id_terrain = 0;
	s_fire = 0.0f;
	s_electric = 0.0f;
	s_water = 0.0f;
	s_rock = 0.0f;
	s_grass = 0.0f;
}
CTerrain::CTerrain(std::string name,int id, float fire, float electric, float water, float rock, float grass)
{
	s_name_terrain = name;
	s_id_terrain = id;
	s_fire = fire;
	s_electric = electric;
	s_water = water;
	s_rock = rock;
	s_grass = grass;
}

CTerrain::~CTerrain()
{
}
void CTerrain::set_title(std::string debugtitle)
{
	s_name_terrain = debugtitle;
}
std::string CTerrain::Title() { return s_name_terrain; }
int CTerrain::id() { return s_id_terrain; }
float CTerrain::fire_bonus() { return s_fire; }
float CTerrain::electric_bonus() { return s_electric; }
float CTerrain::water_bonus() { return s_water; }
float CTerrain::rock_bonus() { return s_rock; }
float CTerrain::grass_bonus() { return s_grass; }