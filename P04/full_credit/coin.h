#ifndef COIN_H
#define COIN_H

#include <iostream>
#include <string>
/*when your class allocates memory from the
heap, keeping a pointer to its address
● To copy the object, you also need to “deep copy” the allocated
heap memory to another heap memory area
● To assign the object, you need to deallocate the existing heap
memory before doing the “deep copy” to allocate the new heap
memory
● To delete the object, you also need to delete the heap memory
*/


enum class Coin_size {PENNY, NICKEL, DIME, QUARTER};

class Coin {
  public:

  Coin(Coin_size _size, Year year); //constructor

  std::string Coin(const Coin& rhs) const;

  Coin& Coin::operator = (const Coin& rhs) { //copy assignment
    if (this != &rhs) _value = new int{*(rhs._value)};
    return *this;
  }

  ~Coin(); //destructor

  std::string add_note() const;
  friend std::ostream& operator<<(std::ostream& ost, const Coin& coin);
  friend std::istream& operator>>(std::istream& ist, Coin& coin);

  private:
  Coin_size _size;
  Year _year;
  std::string* _notes;
};

#endif
