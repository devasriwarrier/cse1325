#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer {
  public:

  Customer(std::string Name, std::string Phone, std::string Email);

  friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);

  Customer(std::istream& ist);   // Open

  void save(std::ostream& ost);  // Save

private:
  std::string _name; 
  std::string _phone; 
  std::string _email; 
};

#endif
