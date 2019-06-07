#ifndef DRINKS_HPP
#define DRINKS_HPP

#include <iostream>
class AllDrinks //klasa bazowa umożliwiająca zapisywanie różnych wariantów szablonu klasy Drinks do jednego kontenera
{
	private:
		int type; // typ napoju (zwykly [1], ekskluzywny [0])
	public: 
		virtual ~AllDrinks() {};
		int get_type() {return type;}
		void set_type(int choice){type = choice;}
};

template <typename T>
class Drinks : public AllDrinks		//soki, mleko etc...tanie,		trunki drogie
{
	private: //analogicznie jak w Cheese.hpp tylko cena stanowi element szablonu ktorym roznia sie konkretne klasy
		std::string name;
		std::string producer;
		T price_per_bottle;
		std::string exp_date;

	public:
		//szablon klasy musi miec ciala funkcji w tym samym pliku
		//funkcje sa analogiczne do Cheese.hpp (zwracanie konkretnych wartosci, wyswietlanie przez przeciazenie)
		Drinks()
		{
			T choice; std::string str;
			std::cout << "nazwa napoju: "; std::cin >> str; name=str;
			std::cout << "nazwa producenta: "; std::cin >> str; producer=str;
			std::cout << "cena za butelkę: "; std::cin >> choice; price_per_bottle = choice;
			std::cout << "data ważnośći napoju: "; std::cin >> str; exp_date=str;
		}
		std::string get_name() {return name;}
		std::string get_producer() {return producer;}
		std::string get_exp_date() {return exp_date;}
		
		T get_price_per_bottle(){return price_per_bottle;}

		friend std::ostream& operator<< (std::ostream& end, Drinks<T>& dr)
		{
		  return end << "Napoj: " << dr.get_name() << "  Producent: " << dr.get_producer() << std::endl
		  << "Cena: " << dr.get_price_per_bottle() << "  Ilość: " << dr.get_exp_date();		
		}
};

#endif
