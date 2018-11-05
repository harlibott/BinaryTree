#include <iostream>
#include <cstdlib>
#include "ItemType.h"

using namespace std;

ItemType:: ItemType(int value){
  this->value = value;
}// dataType constructor

ItemType:: ItemType(){
  this->value = 0;
}

ItemType:: Comparison ItemType:: compareTo(ItemType &item){
  // handles the comparator function
  if (getValue() == item.getValue()){
    return ItemType:: EQUAL;
  }
  else if (getValue() < item.getValue()) {
    return ItemType:: LESS;
  }
  else {
    return ItemType:: GREATER;
  }
}// Comparison

int ItemType:: getValue() const{
  return this->value;
}// getValue

void ItemType:: printValue(){
  cout << "value: " << getValue() << endl;
}
