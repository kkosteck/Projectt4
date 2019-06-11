#include "Products.hpp"
#include "functions.hpp"
#include <stdexcept>

Products::Products()
{
	cheese = NULL;
	meat = NULL;
}
Products::~Products() {}

Cheese **Products::get_cheese() 	{return cheese;}
void 		 Products::add_cheese()
{
	if(Cheese::get_cheese_quantity()==0)
	{
		cheese = new Cheese *[1];
		cheese[0] = new Cheese ();
	}
	else
	{
		int quant = Cheese::get_cheese_quantity();
		Cheese **tmp = new Cheese *[quant]; //tymczasowy wsk
		for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
			tmp[i] = cheese[i];
		delete cheese;
		cheese = new Cheese *[quant+1];	//alokacja na nowo, z jednym miejscem wiecej
		for(int i=0; i < quant; i++)		//przepisanie z powrotem
			cheese[i] = tmp[i];
		delete tmp;
		cheese[quant] = new Cheese();		//konstruowanie nowego elementu

	}
}
void Products::rm_cheese()
{
	if(Cheese::get_cheese_quantity()<1)
		throw std::logic_error( "Nie można usunąć elementów których nie ma");

	int choice;
	std::cout<< "usuwanie elementu z listy serow, dostępne elementy: " << std::endl;
	display(get_cheese());
	std::cin.clear();
	std::cin.ignore(20000, '\n');
	std::cout << "Podaj poprawny nr: "<< std::endl;
	std::cin >> choice;
	if(choice > Cheese::get_cheese_quantity() - 1 || choice<0)
		throw std::logic_error( "Element o tym numerze nie istnieje!");
		
	cheese[choice]->~Cheese();
	for(int i=choice; i<Cheese::get_cheese_quantity() ;i++)
			cheese[i]=cheese[i+1];
	int quant = Cheese::get_cheese_quantity();
	Cheese **tmp = new Cheese *[quant]; //tymczasowy wsk
	for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
		tmp[i] = cheese[i];
	delete cheese;
	cheese = new Cheese *[quant];	//alokacja na nowo, z jednym miejscem wiecej
	for(int i=0; i < quant; i++)		//przepisanie z powrotem
		cheese[i] = tmp[i];
	delete tmp;
}

Meat **Products::get_meat()		{return meat;}
void Products::add_meat()
{
	if(Meat::get_meat_quantity()==0)//get_cheese_quantity()==0)
	{
		meat = new Meat *[1];
		meat[0] = new Meat ();
	}
	else
	{
		int quant = Meat::get_meat_quantity();
		Meat **tmp = new Meat *[quant]; //tymczasowy wsk
		for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
			tmp[i] = meat[i];
		delete meat;
		meat = new Meat *[quant+1];	//alokacja na nowo, z jednym miejscem wiecej
		for(int i=0; i < quant; i++)		//przepisanie z powrotem
			meat[i] = tmp[i];
		delete tmp;
		meat[quant] = new Meat();		//konstruowanie nowego elementu
	}
}
void Products::rm_meat()
{
	if(Meat::get_meat_quantity()<1)
		throw std::logic_error( "Nie można usunąć elementów których nie ma!");

	int choice;
	std::cout<< "usuwanie elementu z listy mięs, dostępne elementy: " << std::endl;
	display(get_meat());
	std::cin.clear();
	std::cin.ignore(20000, '\n');
	std::cout << "Podaj poprawny nr: "<< std::endl;
	std::cin >> choice;
	if(choice > Meat::get_meat_quantity()-1 || choice<0)
		throw std::logic_error( "Element o tym numerze nie istnieje!");
	
	meat[choice]->~Meat();
	for(int i=choice; i<Meat::get_meat_quantity() ;i++)
			meat[i]=meat[i+1];
	int quant = Meat::get_meat_quantity();
	Meat **tmp = new Meat *[quant]; //tymczasowy wsk
	for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
		tmp[i] = meat[i];
	delete meat;
	meat = new Meat *[quant+1];	//alokacja na nowo, z jednym miejscem wiecej
	for(int i=0; i < quant; i++)		//przepisanie z powrotem
		meat[i] = tmp[i];
	delete tmp;
}

std::vector<AllDrinks *> Products::get_drinks()	{return drinks;}
void Products::add_drinks()
{
	int choice;
	std::cout << "Klasa napoju, 1-zwykły  2-ekskluzywny" << std::endl;
	std::cin >> choice;
	if(choice==1)
	{
		AllDrinks *drink = new Drinks<float>(choice);
		drinks.push_back(drink);
	}
	else if(choice == 2)
	{
		AllDrinks *drink = new Drinks<double>(choice);
		drinks.push_back(drink);
	}
	else
		throw std::logic_error( "Klasa napoju o tym numerze nie istnieje!");
}

void Products::rm_drinks()
{
	if(drinks.size() < 1)
		throw std::logic_error( "Nie można usunąć elementów których nie ma!");
		
	unsigned int choice;
	std::cout<< "usuwanie elementu z listy, dostępne elementy: " << std::endl;
	display(drinks);
	std::cin.clear();
	std::cin.ignore(20000, '\n');
	std::cout << "Podaj poprawny nr: "<< std::endl;
	std::cin >> choice;
	if(choice > drinks.size() - 1)
		throw std::logic_error( "Element o tym numerze nie istnieje!");
		
	delete drinks[choice];
	drinks.erase(drinks.begin() + choice);
}

void Products::clean()
{
	int tmp = Cheese::get_cheese_quantity();
	for(int i=0; i<tmp; i++)
		cheese[i]->~Cheese();
	delete [] cheese;
	tmp = Meat::get_meat_quantity();
	for(int i=0; i<tmp; i++)
		meat[i]->~Meat();
	delete [] meat;
	std::vector<AllDrinks *>().swap(drinks);
}
