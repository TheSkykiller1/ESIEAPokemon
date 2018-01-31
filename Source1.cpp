void CMonster::print(std::string type)
{
	std::string separateur = "\t";
	std::cout << "|Num:" << separateur << "Nom:" << separateur << "Type:" << separateur << "Power:" << separateur << "NbUse:" << separateur << "Fail:\n|";
	for (int i = 0; i < Attaques_actives.size; i++)
	{
		if (type == Attaques_list[i]->getType())
			std::cout << "(" << i << ")" << separateur;
		std::cout << Attaques_list[i]->getNom() << separateur << Attaques_list[i]->getType() << separateur \
			<< Attaques_list[i]->get_Power() << separateur << Attaques_utilisation[i] << separateur \
			<< Attaques_list[i]->get_Fail() << "|\n";
	}
}

void CMonster::printAttack(std::string type)
{
	int i;
	std::string separateur = "\t";
	std::cout << "|Num:" << separateur << "Nom:" << separateur << "Type:" << separateur << "Power:" << separateur << "NbUse:" << separateur << "Fail:\n|";
	for (i = 0; i < Attaques_list.size(); i++)
	{
		if (type == Attaques_list[i]->getType())
		{
			std::cout << "(" << i << ")" << separateur;
			std::cout << Attaques_list[i]->getNom() << separateur << Attaques_list[i]->getType() << separateur \
				<< Attaques_list[i]->get_Power() << separateur << Attaques_list[i]->get_NbUse() << separateur \
				<< Attaques_list[i]->get_Fail() << "|\n";
		}
	}
}

void CMonster::printAllAttack()
{
	int i;
	std::string separateur = "\t";
	std::cout << "|Num:" << separateur << "Nom:" << separateur << "Type:" << separateur << "Power:" << separateur << "NbUse:" << separateur << "Fail:\n|";
	for (i = 0; i < Attaques_list.size(); i++)
	{
		std::cout << "(" << i << ")" << separateur;
		std::cout << Attaques_list[i]->getNom() << separateur << Attaques_list[i]->getType << separateur \
			<< Attaques_list[i]->get_Power() << separateur << Attaques_list[i]->get_NbUse() << separateur \
			<< Attaques_list[i]->get_Fail() << "|\n";
	}
}
