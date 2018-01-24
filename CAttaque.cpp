#include "CAttaque.h"

//GETTERS

std::string CAttaque::getNom()
{
	return m_nom;
}

short CAttaque::getType()
{
	return m_type;
}

short CAttaque::getNU()
{
	return m_nu;
}

short CAttaque::getPA()
{
	return m_pAttaque;
}

float CAttaque::getPE()
{
	return m_pEchec;
}

bool CAttaque::getCS()
{
	return m_cs;
}

//SETTERS

void CAttaque::setNom(std::string nom)
{
	m_nom = nom;
}

void CAttaque::setType(short type)
{
	m_type = type;
}

void CAttaque::setNU(short nu)
{
	m_nu = nu;
}

void CAttaque::setPA(short pa)
{
	m_pAttaque = pa;
}

void CAttaque::setPE(float pe)
{
	m_pEchec = pe;
}

void CAttaque::setCS(bool cs)
{
	m_cs = cs;
}

//METHODES

/*short CAttaque::degat(CMonster* att, CMonster* def)
{
	short attaque = att->getAttaque;
	short defense = def->getDefense;
	float coeff = (float)(0.85+(rand() % 15) / 100);
	float avantage = 1;
	float base_type_att = att->getType;
	float base_type_def = def->getType;
	for (int i = 0; i < att->getForce.size(); i++)
	{
		if (att->getForce[i + att->getForce.begin()] == base_type_def)
		{
			avantage = 2;
		}
	}
	for (int i = 0; i < def->getForce.size(); i++)
	{
		if (def->getForce[i + def->getForce.begin()] == base_type_att)
		{
			avantage = 0.5;
		}
	}
	short degat = ((11 * attaque*m_pAttaque) / (25 * defense) + 2)*avantage*coeff;
	return degat;
}*/