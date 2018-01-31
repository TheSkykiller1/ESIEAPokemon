void printAllAttack()
{
	int i;
	std::string separateur = "\t";
	std::cout << "|Num:" << separateur << "Nom:" << separateur << "Type:" << separateur << "Power:" << separateur << "NbUse:" << separateur << "Fail:\n|";
	for (i = 0; i < ListeAttaques.size(); i++)
	{
		std::cout << "(" << i << ")" << separateur;
		std::cout << ListeAttaques[i]->getNom() << separateur << ListeAttaques[i]->getType << separateur \
			<< ListeAttaques[i]->get_Power() << separateur << ListeAttaques[i]->get_NbUse() << separateur \
			<< ListeAttaques[i]->get_Fail() << "|\n";
	}
}

void printAttack(std::string type)
{
	int i;
	std::string separateur = "\t";
	std::cout << "|Num:" << separateur << "Nom:" << separateur << "Type:" << separateur << "Power:" << separateur << "NbUse:" << separateur << "Fail:\n|";
	for (i = 0; i < ListeAttaques.size(); i++)
	{
		if (type == ListeAttaques[i].getType())
		{
			std::cout << "(" << i << ")" << separateur;
			std::cout << ListeAttaques[i]->getNom() << separateur << ListeAttaques[i]->getType() << separateur \
				<< ListeAttaques[i]->get_Power() << separateur << ListeAttaques[i]->get_NbUse() << separateur \
				<< ListeAttaques[i]->get_Fail() << "|\n";
		}
	}
}

void print(std::string type)
{
	std::string separateur = "\t";
	std::cout << "|Num:" << separateur << "Nom:" << separateur << "Type:" << separateur << "Power:" << separateur << "NbUse:" << separateur << "Fail:\n|";
	for (int i = 0; i < Attaques_list.size; i++)
	{
		if (type == Attaques_list[i].getType())
		std::cout << "(" << i << ")" << separateur;
		std::cout << Attaques_list[i]->getNom() << separateur << Attaques_list[i]->getType() << separateur \
			<< Attaques_list[i]->get_Power() << separateur << attaques_utilisation[i]->get_NbUse() << separateur \
			<< Attaques_list[i]->get_Fail() << "|\n";
	}
}