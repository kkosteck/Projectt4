#include "../include/Meat.hpp"
#include <iostream>

int Meat::meat_quantity = 0;

Meat::Meat(std::istream& is, std::ostream& os)
{
  meat_quantity++;
  std::string str;
  float flt;
  os << "Podaj nazwę mięsa:  "; is >> str;  name = str;
  os << "Podaj producenta mięsa:  "; is >> str;  producer = str;
  os << "Podaj cenę za opakowanie mięsa: (float) "; is >> flt;  price_per_mass = flt;
  os << "Podaj ilość (kg) mięsa: (float) "; is>>flt; mass = flt;
}

Meat::~Meat()
{
  meat_quantity--;
}
int Meat::get_meat_quantity() {return meat_quantity;}

std::string Meat::get_name() {return name;}
std::string Meat::get_producer() {return producer;}
float Meat::get_price_per_mass() {return price_per_mass;}
float Meat::get_mass() {return mass;}
