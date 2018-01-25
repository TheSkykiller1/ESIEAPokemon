#include "CMonster.h"
#include "CElectric.h"
#include "CWater.h"
#include "CRock.h"
#include "CFire.h"
#include "CGrass.h"
#include <iostream>
#include "CPlayer.h"
#include "CWorld.h"

#define EAU 0
#define FEU 1
#define HERBE 2
#define TERRE 3
#define FOUDRE 4

int main()
{
	/*CPlayer Sacha("Sacha", true, 0, 0);
	Sacha.add_pokemon(FEU, "Salameche", 10, 50, 254, 5);
	Sacha.add_pokemon(FEU, "salo", 10, 50, 254, 5);
	Sacha.add_pokemon(FEU, "sali", 11, 51, 25, 5);
	Sacha.add_pokemon(FEU, "salut", 12, 52, 15, 5);
	Sacha.add_pokemon(FEU, "salto", 13, 53, 45, 5);
	Sacha.add_pokemon(FEU, "saloute", 14, 54, 65, 5);
	Sacha.add_pokemon(FEU, "sallumer", 15, 55, 84, 5);
	Sacha.add_pokemon(FEU, "salouminer", 16, 56, 45, 5);
	Sacha.delete_pokemon();*/
	CWorld MONDE;
	MONDE.read_config_pokemon();
	

	system("pause");

}