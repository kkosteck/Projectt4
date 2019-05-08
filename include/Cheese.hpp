#ifndef CHEESE_HPP
#define CHEESE_HPP

#include <iostream>
#include <vector>

class Cheese
{
	private:
		std::string name;				//nazwa sera
		std::string producer;		//nazwa producenta
		float price_per_pckg;		//cena za paczke
		std::string exp_date;			//data przydatnosci do spozycia
		std::vector <char> c_name;
		static int cheese_quantity; //licznik obiektow klasy

	public:
		Cheese(); //prosi uzytkownika o podanie danych i tworzy obiekt
		//zakladam ze uzytkownik poda poprawne dane
		~Cheese();
		std::string get_name(); //zwraca nazwe
		void print_name();
		std::string get_producer(); //zwraca producenta
		float get_price_per_pckg();	//zwraca cene
		std::string get_exp_date(); //zwraca date przydatnosci do sporzycia
		static int get_cheese_quantity(); //licznik obiektow klasy
};

#endif
