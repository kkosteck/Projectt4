#include "functions.hpp"
#include "Products.hpp"
#include "Cheese.hpp"
#include <iostream>

void display(class Products prod)
{
	std::cout << "\033[2J\033[1;1H";
	if(Cheese::get_cheese_quantity()==0)
		std::cout << "Brak sera" << std::endl<<std::endl;
	else
	{
		Cheese **tmp;
		tmp = prod.get_cheese();
		for (int i=0; i<Cheese::get_cheese_quantity(); i++)
		{
			std::cout << "Vector name: ";
			tmp[i]->print_name();
			std::cout << *tmp[i] << std::endl;
		}
	}
	if(Meat::get_meat_quantity()==0)
		std::cout << "Brak miesa" << std::endl<<std::endl;
	else
	{
		Meat **tmp;
		tmp = prod.get_meat();
		for (int i=0; i<Meat::get_meat_quantity(); i++)
			std::cout << *tmp[i] << std::endl;
	}
	if(Drinks<float>::get_drinks_quantity()==0)
		std::cout << "Brak tanich napoi (float)" << std::endl<<std::endl;
	else
	{
		Drinks<float> **tmp;
		tmp = prod.get_f_drinks();
		for (int i=0; i<Drinks<float>::get_drinks_quantity(); i++)
			std::cout << *tmp[i] << std::endl;
	}
	if(prod.get_d_drinks()==NULL)
		std::cout << "Brak ekskluzywnych napoi (double)" << std::endl<<std::endl;
	else
	{
		std::cout << "wyswietlanie ekskluzywnych napoi (double)" << std::endl;
		Drinks<double> **tmp;
		tmp = prod.get_d_drinks();
		for (int i=0; i<Drinks<double>::get_drinks_quantity(); i++)
			std::cout << *tmp[i] << std::endl;
	}

}

void display(class Cheese **ch)
{
	if(ch==NULL)
		std::cout << "Brak sera" << std::endl<<std::endl;
	else
		for (int i=0; i<Cheese::get_cheese_quantity(); i++)
			std::cout <<"Element: "<< i <<std::endl<< *ch[i] <<std::endl;
}
void display(class Meat **me)
{
	if(me==NULL)
		std::cout << "Brak miesa" << std::endl<<std::endl;
	else
		for (int i=0; i<Meat::get_meat_quantity(); i++)
			std::cout <<"Element: "<< i <<std::endl<< *me[i] <<std::endl;
}

std::ostream & operator<< (std::ostream &end, Cheese &ch)
{
  return end << "Ser: " << ch.get_name() << "  Wyprodukowany przez: " << ch.get_producer() << std::endl
  << "Cena: " << ch.get_price_per_pckg() << "  Ważny do: " << ch.get_exp_date() << std::endl;
}

std::ostream & operator<< (std::ostream &end, Meat &mt)
{
  return end << "Mięso: " << mt.get_name() << "  Producent: " << mt.get_producer() << std::endl
  << "Cena: " << mt.get_price_per_mass() << "  Ilość: " << mt.get_mass() << std::endl;
}
