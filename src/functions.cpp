#include "functions.hpp"
#include "Products.hpp"
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
			std::cout << *tmp[i] << std::endl;
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
	std::vector<AllDrinks *> dr = prod.get_drinks();
	if(dr.size() == 0)
		std::cout << "Brak napojow" << std::endl<<std::endl;
	else
		for(unsigned int i=0; i<dr.size(); i++)
			dr[i]->get_drink();
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
void display(std::vector<AllDrinks *> dr)
{
	if(dr.size() == 0)
		std::cout << "Brak napojow" << std::endl<<std::endl;
	else
		for(unsigned int i=0; i<dr.size(); i++)
		{
			std::cout <<"Element: "<< i << std::endl;
			dr[i]->get_drink();
		}
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
