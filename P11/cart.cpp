#include "cart.h"
#include "item.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>

Cart::Cart(std::string customer): _customer{customer}{};

Cart::~Cart(){};

Cart::Cart(const Cart& cart): _customer(cart._customer), _items(cart._items){}


std::vector<Item*> ::iterator Cart::begin(){ return _items.begin();}

std::vector<Item*> ::iterator Cart::end(){return _items.end();}

double Cart::cost(){
int j;
double totalcost;
for(std::vector<Item*>::iterator p = _items.begin(); p!=_items.end(); ++p){
totalcost+= _items[j]->cost();
j++;}
return totalcost;}

Cart& Cart::operator=(const Cart& cart){
_customer = cart._customer;
for(Item* i : cart._items) _items.push_back(new Item{*i});
return *this;
if(this == &cart) return *this;}; //do nothing

void Cart::add_item(Item& item){_items.push_back(new Item{item});}



