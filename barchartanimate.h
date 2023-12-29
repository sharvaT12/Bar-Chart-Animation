//  barchartanimate.h
//  Sharva Thakur
//  Project 3
//
//  This is barchartanimate. Here there is class BarChartAnimate.There are
//  7 private member which are array of BarChart called barcharts int size,
//  int capacity, map<string,string> colorMap, string title, string xlabel
//  and string source.
//  There are 3 private helper functions
//  s_color
//  takeinput
//  takeinput
//  There are 6 public functions
//  a parameterized constructor:
//  destructor:
//  addFrame:
//  animate:
//  getSize:
//  operator[]:
//
//  NOTE: This function is tested in tests.cpp using normal test
//  use make build_tests and make run_tests from my make file
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h"  // used in autograder, do not remove
#include "barchart.h"

using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
  //
  // Private member variables for the abstraction.
  // This implementation uses a low-level C array, bars, to store a list of
  // BarCharts.  As a result, you must also keep track of the number of
  // elements stored (size) and the capacity of the array (capacity).
  // This IS dynamic array, so it must expand automatically, as needed.
  //
  BarChart* barcharts;  // pointer to a C-style array
  int size;
  int capacity;
  map<string, string> colorMap;
  string title;
  string xlabel;
  string source;

  //
  //  s_color
  //
  //  This helper function takes a string as parameter
  //
  //  This helper function checks if the category exists in the map
  //  if not then it assigns a color to the category
  //
  void s_color(string& category) {
    if (colorMap.count(category) == 0) {
      int color_index = colorMap.size();

      if (color_index >= usleep(COLORS.size())) {
        color_index = color_index % COLORS.size();
        colorMap[category] = COLORS[color_index];
      }
    }
  }

  //
  //  takeinput
  //
  //  This helper function has parameter 1 stringstream 4 strings and
  //  1 int
  //
  //  This function takes all the input
  //
  void takeinput(stringstream& parser, string& name_t, string& year_t,
                 string& country_t, string& category, int& value_t) {
    string value_temp;
    getline(parser, year_t, ',');

    getline(parser, name_t, ',');
    getline(parser, country_t, ',');
    getline(parser, value_temp, ',');
    value_t = stoi(value_temp);
    getline(parser, category, '\n');
  }

  //
  //  increase_capacity
  //
  //  This helper function increases the size of barchart to double.
  //
  void increase_capacity() {
    BarChart* temp = new BarChart[capacity * 2];
    this->capacity = this->capacity * 2;
    for (int i = 0; i < size; i++) {
      temp[i] = this->barcharts[i];
    }
    delete[] barcharts;

    barcharts = temp;
  }

 public:
  // a parameterized constructor:
  // Like the ourvector, the barcharts C-array should be constructed here
  // with a capacity of 4.
  BarChartAnimate(string title, string xlabel, string source) {
    this->barcharts = new BarChart[4];
    this->size = 0;
    this->capacity = 4;
    this->title = title;
    this->xlabel = xlabel;
    this->source = source;
  }

  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated
  // by BarChartAnimate.
  //
  virtual ~BarChartAnimate() {
    if (barcharts != nullptr) {
      for (int i = 0; i < size; i++) {
        barcharts[i].clear();
      }

      delete[] barcharts;
    }
  }

  // addFrame:
  // adds a new BarChart to the BarChartAnimate object from the file stream.
  // if the barcharts has run out of space, double the capacity (see
  // ourvector.h for how to double the capacity).
  // See application.cpp and handout for pre and post conditions.
  void addFrame(ifstream& file) {
    int filesize = 0;
    if (this->capacity <= this->size) {  //  if the array is full
      increase_capacity();               //  private helper function
    }

    file >> filesize;  // takes the size of file

    int value_t = 0;
    string name_t, country_t, category, line, year_t;
    BarChart A(filesize);
    for (int i = 0; i <= filesize; i++) {
      getline(file, line);

      if (!line.empty()) {  //  checks if line is empty

        stringstream parser;
        parser.str(line);

        //  private helper function
        takeinput(parser, name_t, year_t, country_t, category, value_t);
        A.addBar(name_t, value_t, category);

        //  private helper function
        s_color(category);

        if (i == filesize) {
          A.setFrame(year_t);
          barcharts[size] = A;
          size++;
        }
      }
    }
  }

  // animate:
  // this function plays each frame stored in barcharts.  In order to see the
  // animation in the terminal, you must pause between each frame.  To do so,
  // type:  usleep(3 * microsecond);
  // Additionally, in order for each frame to print in the same spot in the
  // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
  // in between each frame.
  void animate(ostream& output, int top, int endIter) {
    unsigned int microsecond = 50000;

    if (endIter == -1) {
      endIter = size;  //  if user puts -1
    }

    for (int i = 0; i < endIter; i++) {
      usleep(3 * microsecond);

      output << CLEARCONSOLE;
      output << BLACK << title << endl;
      output << BLACK << source << endl;

      barcharts[i].graph(output, colorMap, top);

      output << BLACK << xlabel << endl;
      output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    }
  }

  //
  //  creative component
  //
  //  uses the color sceme as the user wants.
  void animate(ostream& output, int top, int endIter,
               vector<string>& Colorscheme) {
    unsigned int microsecond = 50000;

    if (endIter == -1) {
      endIter = size;  //  if user puts -1
    }

    for (int i = 0; i < endIter; i++) {
      usleep(3 * microsecond);

      output << CLEARCONSOLE;
      output << BLACK << title << endl;
      output << BLACK << source << endl;

      map<string, string> A;

      auto itr1 = colorMap.begin();

      while (itr1 !=
             colorMap.end()) {  //  creating a map of colorscheme user wants

        A[itr1->first] = Colorscheme[0];
        itr1++;
        A[itr1->first] = Colorscheme[1];
        itr1++;
      }

      barcharts[i].graph(output, A, top);

      output << BLACK << xlabel << endl;
      output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    }
  }

  //
  // Public member function.
  //
  // getSize
  //
  // Returns the size of the BarChartAnimate object.
  //
  int getSize() { return this->size; }

  //
  // operator[]
  //
  // Public member function.
  // Returns BarChart element in BarChartAnimate.
  // This gives public access to BarChart stored in the BarChartAnimate.
  // If i is out of bounds, throw an out_of_range error message:
  // "BarChartAnimate: i out of bounds"
  //
  BarChart& operator[](int i) {
    if (i >= size || i < 0) {  //  if i is less than 0 or greater than size
      throw out_of_range("i out of bounds");
    }

    return this->barcharts[i];
  }
};
