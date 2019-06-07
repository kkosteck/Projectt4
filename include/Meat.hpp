#ifndef MEAT_HPP
#define MEAT_HPP

#include <iostream>

class Meat
{
	private:
		std::string name;			//nazwa
		std::string producer;		//producent
		float price_per_mass;		//cena za jed masy
		float mass;					//ilosc miesa w jed masy
		static int meat_quantity; 	//licznik elementow klasy

	public:	//funkcje analogicznie jak w Cheese.hpp
		Meat(std::istream& is = std::cin, std::ostream& os = std::cout); //Argumenty i/o potrzebne do ominięcie podawania danych w testach
		~Meat();
		std::string get_name();
		std::string get_producer();
		float get_price_per_mass();
		float get_mass();
		static int get_meat_quantity();
};

#endif
