#include "Meat.hpp"
#include "Drinks.hpp"
#include "Cheese.hpp"
#include "Products.hpp"
#include "functions.hpp"

Products::Products()
{
	cheese = NULL;
	meat = NULL;
	f_drinks = NULL;
	d_drinks = NULL;
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
	int choice;
	std::cout<< "usuwanie elementu z listy serow, dostępne elementy: " << std::endl;
	display(get_cheese());
	if(Cheese::get_cheese_quantity()<1)
		std::cout << "Nie można usunąć elementów których nie ma" << std::endl;
	else
	{
		do
		{
			std::cin.clear();
			std::cin.ignore(20000, '\n');
			std::cout << "Podaj poprawny nr: "<< std::endl;
			std::cin >> choice;
		} while (choice > Cheese::get_cheese_quantity() || choice<0);
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
	int choice;
	std::cout<< "usuwanie elementu z listy mięs, dostępne elementy: " << std::endl;
	display(get_meat());
	if(Meat::get_meat_quantity()<1)
		std::cout << "Nie można usunąć elementów których nie ma" << std::endl;
	else
	{
		do
		{
			std::cin.clear();
			std::cin.ignore(20000, '\n');
			std::cout << "Podaj poprawny nr: "<< std::endl;
			std::cin >> choice;
		} while (choice > Meat::get_meat_quantity()-1 || choice<0);
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
}

Drinks<float>	**Products::get_f_drinks()	{return f_drinks;}
Drinks<double>	**Products::get_d_drinks()	{return d_drinks;}

void Products::add_drink()
{
	int choice;
	std::cout << "Klasa napoju, 1-zwykły  2-ekskluzywny" << std::endl;
	std::cin >> choice;
	if(choice==1)
	{
		if(Drinks<float>::get_drinks_quantity()==0)
		{
			f_drinks = new Drinks<float> *[1];
			f_drinks[0] = new Drinks<float> ();
		}
		else
		{
			int quant = Drinks<float>::get_drinks_quantity();
			Drinks<float> **tmp = new Drinks<float> *[quant]; //tymczasowy wsk
			for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
				tmp[i] = f_drinks[i];
			delete f_drinks;
			f_drinks = new Drinks<float> *[quant+1];	//alokacja na nowo, z jednym miejscem wiecej
			for(int i=0; i < quant; i++)		//przepisanie z powrotem
				f_drinks[i] = tmp[i];
			delete tmp;
			f_drinks[quant] = new Drinks<float>();		//konstruowanie nowego elementu
		}
	}
	else
	{
		if(Drinks<double>::get_drinks_quantity()==0)
		{
			d_drinks = new Drinks<double> *[1];
			d_drinks[0] = new Drinks<double> ();
		}
		else
		{
			int quant = Drinks<double>::get_drinks_quantity();
			Drinks<double> **tmp = new Drinks<double> *[quant]; //tymczasowy wsk
			for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
				tmp[i] = d_drinks[i];
			delete d_drinks;
			d_drinks = new Drinks<double> *[quant+1];	//alokacja na nowo, z jednym miejscem wiecej
			for(int i=0; i < quant; i++)		//przepisanie z powrotem
				d_drinks[i] = tmp[i];
			delete tmp;
			d_drinks[quant] = new Drinks<double>();		//konstruowanie nowego elementu
		}
	}
}
void Products::rm_drink()
{
	int choice, choice2;
	std::cout<< "Jakiej klasy napój będzie usuwany? (1-tanie, 2-ekskluzywne)";
	std::cin >> choice;
	std::cout<< "usuwanie elementu z listy, dostępne elementy: " << std::endl;
	if (choice == 2)
		{
			display(get_d_drinks());
			if(Drinks<double>::get_drinks_quantity()<1)
			{
				std::cout << "Nie można usunąć elementów których nie ma" << std::endl;
				return;
			}
		}
	else
		{
			display(get_f_drinks());
			if(Drinks<float>::get_drinks_quantity()<1)
			{
				std::cout << "Nie można usunąć elementów których nie ma" << std::endl;
				return;
			}
		}
	if (choice == 2)
	{
		do
		{
			std::cin.clear();
			std::cin.ignore(20000, '\n');
			std::cout << "Podaj poprawny nr: "<< std::endl;
			std::cin >> choice2;
		} while (choice2 > Drinks<float>::get_drinks_quantity() || choice2<0);
		d_drinks[choice]->~Drinks();
		for(int i=choice; i<Drinks<double>::get_drinks_quantity() ;i++)
			d_drinks[i]=d_drinks[i+1];
		int quant = Drinks<double>::get_drinks_quantity();
		Drinks<double> **tmp = new Drinks<double> *[quant]; //tymczasowy wsk
		for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
			tmp[i] = d_drinks[i];
		delete d_drinks;
		d_drinks = new Drinks<double> *[quant];	//alokacja na nowo, z jednym miejscem wiecej
		for(int i=0; i < quant; i++)		//przepisanie z powrotem
			d_drinks[i] = tmp[i];
		delete tmp;
	}
	else
	{
		do
		{
			std::cin.clear();
			std::cin.ignore(20000, '\n');
			std::cout << "Podaj poprawny nr: "<< std::endl;
			std::cin >> choice2;
		} while (choice2 > Drinks<double>::get_drinks_quantity() || choice2<0);
		f_drinks[choice]->~Drinks();
		for(int i=choice; i<Drinks<float>::get_drinks_quantity(); i++)
			f_drinks[i]=f_drinks[i+1];
		int quant = Drinks<float>::get_drinks_quantity();
		Drinks<float> **tmp = new Drinks<float> *[quant]; //tymczasowy wsk
		for(int i=0; i < quant; i++)			//przepisanie do tymczasowego wsk
			tmp[i] = f_drinks[i];
		delete f_drinks;
		f_drinks = new Drinks<float> *[quant];	//alokacja na nowo, z jednym miejscem wiecej
		for(int i=0; i < quant; i++)		//przepisanie z powrotem
			f_drinks[i] = tmp[i];
		delete tmp;
	}
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
	tmp = Drinks<float>::get_drinks_quantity();
	for(int i=0; i<tmp; i++)
		f_drinks[i]->~Drinks();
	delete [] f_drinks;
	tmp = Drinks<double>::get_drinks_quantity();
	for(int i=0; i<tmp; i++)
		d_drinks[i]->~Drinks();
	delete [] d_drinks;
}
