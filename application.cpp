// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;

//  void files
//
//  prints all the filenames
//
void files() {
  cout << "cities.txt" << endl;
  cout << "baby_names.txt" << endl;
  cout << "brands.txt" << endl;
  cout << "cities_usa.txt" << endl;
  cout << "countries.txt" << endl;
  cout << "endgame.txt" << endl;
  cout << "football.txt" << endl;
  cout << "games-of-thrones.txt" << endl;
  cout << "infinity-war.txt" << endl;
}

//
//  print_colorscheme
//
//  prints color options
//
void print_colorscheme() {
  cout << endl;
  cout << "Choose from the following colorscheme" << endl;

  cout << "1. Red/Blue" << endl;
  cout << "2. Red/Gold" << endl;
  cout << "3. Gold/Blue" << endl;
  cout << "4. Cyan/Purple" << endl;
  cout << "5. Cyan/Gold" << endl;
  cout << "6. Red/Purple" << endl;

  cout << "Type in the digit of colorscheme" << endl;
}

//
//  choose_colorscheme
//
//  this function chooses the colorscheme (according to mimir)
//
void choose_colorscheme(vector<string>& Colorscheme, BarChartAnimate& bca) {
  int num = 0;
  int j = 1;
  cin >> num;
  if (num == 1) {
    Colorscheme = {RED, BLUE};
  } else if (num == 2) {
    Colorscheme = {RED, GOLD};
  } else if (num == 3) {
    Colorscheme = {GOLD, BLUE};
  } else if (num == 4) {
    Colorscheme = {CYAN, PURPLE};
  } else if (num == 5) {
    Colorscheme = {CYAN, GOLD};
  } else if (num == 6) {
    Colorscheme = {RED, PURPLE};
  } else {
    j = 0;
    cout << "Does not exist using default colorscheme" << endl;
    bca.animate(cout, 12, -1);
  }

  if (j == 1) {
    bca.animate(cout, 12, -1, Colorscheme);
  }
}

//
//  creative component
//
//  this function asks user if he wants a custom colorscheme
//  if the user wants the custom colorscheme
//  then this uses the sceme
//  if user says no or gives incorrect option then this uses
//  default colorscheme
//
void animate_user(BarChartAnimate& bca, string& ans) {
  if (ans == "y") {
    vector<string> Colorscheme;
    print_colorscheme();

    choose_colorscheme(Colorscheme, bca);
  } else {
    bca.animate(cout, 12, -1);
  }
}

//
//  main
//
int main() {
  string filename;

  files();
  cout << endl;
  cout << "Choose from the list of files" << endl;

  cin >> filename;

  ifstream inFile(filename);

  if (!inFile.good()) {  //  if file not good
    cout << "Error: unable to open " << filename << endl;
    return 0;
  }

  string title;
  getline(inFile, title);
  string xlabel;
  getline(inFile, xlabel);
  string source;
  getline(inFile, source);

  BarChartAnimate bca(title, xlabel, source);
  cout << endl;
  cout << "Do you want custom colorscheme?(y/n)" << endl;
  string ans;
  cin >> ans;

  while (!inFile.eof()) {
    bca.addFrame(inFile);
  }
  animate_user(bca, ans);

  return 0;
}
