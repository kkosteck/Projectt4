#include "Cheese.hpp"
#include <iostream>
#include <vector>

int Cheese::cheese_quantity = 0;

Cheese::Cheese()
{
  std::string str;
  float flt;
  cheese_quantity++;
  std::cout << "Podaj nazwę sera:  "; std::cin >> str;  name = str;
  std::cout << "Podaj producenta sera:  "; std::cin >> str;  producer = str;
  std::cout << "Podaj cenę za opakowanie sera: (float) "; std::cin >> flt;  price_per_pckg = flt;
  std::cout << "Podaj datę ważności sera:  "; std::cin >> str;  exp_date = str;

  for(int i=0; i<(int)name.size(); ++i)
    c_name.push_back(std::toupper(name[i]));
}
Cheese::~Cheese()
{
  cheese_quantity--;
}
int Cheese::get_cheese_quantity() {return cheese_quantity;}

std::string Cheese::get_name() {return name;}

void Cheese::print_name()
{
  for(std::vector<char>::iterator it = c_name.begin(); it != c_name.end(); ++it)
    std::cout << *it;
  std::cout << std::endl;
}

std::string Cheese::get_producer() {return producer;}
float Cheese::get_price_per_pckg() {return price_per_pckg;}
std::string Cheese::get_exp_date() {return exp_date;}
