//  bar.h
//
//  Sharva Thakur
//  Project 3
//
//  This is bar.h file. Here there is a class where there are 3 private
//  members, string Name which stores name string category which stores
//  category and Value which stores the value.category
//  There are 9 public functions
//  default constructor:
//  a second constructor:
//  destructor:
//  getName:
//  getValue:
//  getCategory:
//  opertor<
//  opertor<=
//  opertor>
//  opertor>=
//
//  NOTE: this is tested in tests.cpp with normal assert.
//

#include <iostream>
#include <string>
#include "myrandom.h"  //  used in autograder, do not remove
using namespace std;

//
//  Bar
//
class Bar {
 private:
  //  Private member variables for a Bar object
  string Name;      //  Stores the name of object
  string Category;  //  Stores the category of object
  int Value;        //  Stores the value of the oobject

 public:
  //  default constructor:
  Bar() {
    Name = "";
    Category = "";
    Value = 0;
  }

  //
  //  a second constructor:
  //
  //  Parameter passed in constructor Bar object.
  //
  //  This function sets the bar values to the values in the Parameter.
  //
  Bar(string name, int value, string category) {
    Name = name;
    Category = category;
    Value = value;
  }

  //  destructor:
  virtual ~Bar() {}

  //
  //  getName:
  //
  //  This function returns the private member name of the object.
  //
  string getName() {
    return Name;  //  returns name
  }

  //
  //  getValue:
  //
  //  This function returns the private member value of the object.
  //
  int getValue() {
    return Value;  //  returns value
  }

  //
  //  getCategory:
  //
  //  This function returns the private member category of the object.
  //
  string getCategory() {
    return Category;  //  returns category
  }

  //  operators

  //
  //  opertor<
  //
  //  returns true if value is less than other's value
  //
  bool operator<(const Bar &other) const {
    if (this->Value < other.Value) {
      return true;
    }

    return false;
  }

  //
  //  opertor<=
  //
  //  returns true if value is less than or equal to other's value
  //
  bool operator<=(const Bar &other) const {
    if (this->Value <= other.Value) {
      return true;
    }

    return false;
  }

  //
  //  opertor>
  //
  //  returns true if value is greater than other's value
  //
  bool operator>(const Bar &other) const {
    if (this->Value > other.Value) {
      return true;
    }
    return false;
  }

  //
  //  opertor>=
  //
  //  returns true if value is greater than or equal to other's value
  //
  bool operator>=(const Bar &other) const {
    if (this->Value >= other.Value) {
      return true;
    }

    return false;
  }
};
