#include <iostream>
#include "barchartanimate.h"
#include <assert.h>
#include <gtest/gtest.h>
#include <map>

using namespace std;

bool testBarDefaultConstructor() {
  Bar b;
  if (b.getName() != "") {
    cout << "testBarDefaultConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 0) {
    cout << "testBarDefaultConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "") {
    cout << "testBarDefaultConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarDefaultConstructor: all passed!" << endl;
  return true;
}

bool testBarParamConstructor() {
  Bar b("Chicago", 9234324, "US");
  if (b.getName() != "Chicago") {
    cout << "testBarParamConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 9234324) {
    cout << "testBarParamConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "US") {
    cout << "testBarParamConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarParamConstructor: all passed!" << endl;
  return true;
}

bool testBarlessthanop_1() {
  Bar A("Chicago", 9922124, "US");
  Bar B("Texas", 9922134, "US");
  assert(A.getName() == "Chicago");
  assert(B.getName() == "Texas");
  assert(A.getValue() == 9922124);
  assert(B.getValue() == 9922134);
  assert(A.getCategory() == "US");
  assert(B.getCategory() == "US");
  assert(A < B);

  cout << "testBarlessthanop_1: all passed!" << endl;
  return true;
}

bool testBarlessthanop_2() {
  Bar A("Mumbai", -123124, "India");
  Bar B("Texas", -997451, "US");
  assert(A.getName() == "Mumbai");
  assert(B.getName() == "Texas");
  assert(A.getValue() == -123124);
  assert(B.getValue() == -997451);
  assert(A.getCategory() == "India");
  assert(B.getCategory() == "US");
  assert(B < A);

  cout << "testBarlessthanop_2: all passed!" << endl;
  return true;
}

bool testBarlessthanequalop_1() {
  Bar A("Chicago", 9922124, "US");
  Bar B("Texas", 9922134, "US");
  assert(A.getName() == "Chicago");
  assert(B.getName() == "Texas");
  assert(A.getValue() == 9922124);
  assert(B.getValue() == 9922134);
  assert(A.getCategory() == "US");
  assert(B.getCategory() == "US");
  assert(A <= B);

  Bar C("Mumbai", 9922124, "India");
  assert(C.getName() == "Mumbai");
  assert(C.getValue() == 9922124);
  assert(C.getCategory() == "India");
  assert(A <= C);
  assert(C <= A);

  cout << "testBarlessthanequalop_1: all passed!" << endl;
  return true;
}

bool testBarlessthanequalop_2() {
  Bar A("Chicago", -723571, "US");
  Bar B("Texas", -3464711, "US");
  assert(A.getName() == "Chicago");
  assert(B.getName() == "Texas");
  assert(A.getValue() == -723571);
  assert(B.getValue() == -3464711);
  assert(A.getCategory() == "US");
  assert(B.getCategory() == "US");
  assert(B <= A);

  Bar C("Mumbai", -723571, "India");
  assert(C.getName() == "Mumbai");
  assert(C.getValue() == -723571);
  assert(C.getCategory() == "India");
  assert(A <= C);
  assert(C <= A);

  cout << "testBarlessthanequalop_2: all passed!" << endl;
  return true;
}

bool testBargreaterthanop_1() {
  Bar A("Chicago", 9922124, "US");
  Bar B("Texas", 9922134, "US");
  assert(A.getName() == "Chicago");
  assert(B.getName() == "Texas");
  assert(A.getValue() == 9922124);
  assert(B.getValue() == 9922134);
  assert(A.getCategory() == "US");
  assert(B.getCategory() == "US");
  assert(B > A);

  cout << "testBargreaterthanop_1: all passed!" << endl;
  return true;
}

bool testBargreaterthanop_2() {
  Bar A("Chicago", -87878, "US");
  Bar B("Texas", -564333, "US");
  assert(A.getName() == "Chicago");
  assert(B.getName() == "Texas");
  assert(A.getValue() == -87878);
  assert(B.getValue() == -564333);
  assert(A.getCategory() == "US");
  assert(B.getCategory() == "US");
  assert(A > B);

  cout << "testBargreaterthanop_2: all passed!" << endl;
  return true;
}

bool testBargreaterthanequalop_1() {
  Bar A("Chicago", 9922124, "US");
  Bar B("Texas", 9922134, "US");
  assert(A.getName() == "Chicago");
  assert(B.getName() == "Texas");
  assert(A.getValue() == 9922124);
  assert(B.getValue() == 9922134);
  assert(A.getCategory() == "US");
  assert(B.getCategory() == "US");
  assert(B >= A);

  Bar C("Mumbai", 9922124, "India");
  assert(C.getName() == "Mumbai");
  assert(C.getValue() == 9922124);
  assert(C.getCategory() == "India");
  assert(C >= A);
  assert(A >= C);

  cout << "testBargreaterthanequalop_1: all passed!" << endl;
  return true;
}

bool testBargreaterthanequalop_2() {
  Bar A("Chicago", -3224, "US");
  Bar B("Texas", -2432, "US");
  assert(A.getName() == "Chicago");
  assert(B.getName() == "Texas");
  assert(A.getValue() == -3224);
  assert(B.getValue() == -2432);
  assert(A.getCategory() == "US");
  assert(B.getCategory() == "US");
  assert(B >= A);

  Bar C("Mumbai", -3224, "India");
  assert(C.getName() == "Mumbai");
  assert(C.getValue() == -3224);
  assert(C.getCategory() == "India");
  assert(C >= A);
  assert(A >= C);

  cout << "testBargreaterthanequalop_2: all passed!" << endl;
  return true;
}

void testBarChartgraph() {
  cout << "Testing Barchart graph" << endl;

  BarChart S(5);

  S.addBar("Mumbai", 100, "India");
  S.addBar("Chicago", 60, "USA");

  S.addBar("Miami", 90, "USA");
  S.addBar("LA", 78, "USA");
  S.addBar("Rome", 85, "Itlay");

  map<string, string> colorMap;

  colorMap["USA"] = RED;
  colorMap["India"] = BLUE;
  colorMap["Itlay"] = GREEN;

  S.graph(cout, colorMap, 5);

  colorMap.clear();
  cout << endl;
}

void testBarChartgraph1() {
  cout << "testing BarChart graph with copy constructor" << endl;

  BarChart S(5);

  S.addBar("Mumbai", 100, "India");
  S.addBar("Chicago", 60, "USA");

  S.addBar("Miami", 90, "USA");
  S.addBar("LA", 78, "USA");
  S.addBar("Rome", 85, "Itlay");

  map<string, string> colorMap;

  colorMap["USA"] = RED;
  colorMap["India"] = BLUE;
  colorMap["Itlay"] = GREEN;

  S.graph(cout, colorMap, 5);

  BarChart copy = S;

  S.graph(cout, colorMap, 5);

  colorMap.clear();

  cout << endl;
}

//  This tests all the public functions of barchartanimate
//  other than opertor[]
void barchartanimatetest1() {
  string filename = "mytest.txt";
  ifstream inFile(filename);
  string title;
  getline(inFile, title);
  string xlabel;
  getline(inFile, xlabel);
  string source;
  getline(inFile, source);

  BarChartAnimate A(title, xlabel, source);
  assert(A.getSize() == 0);

  while (!inFile.eof()) {
    A.addFrame(inFile);
  }

  A.animate(cout, 12, 4);
  assert(A.getSize() == 9);

  cout << "barchartanimatetest1 all tests passed" << endl;
}

//  This tests all the public functions of barchartanimate
//  other than opertor[]
void barchartanimatetest2() {
  string filename = "mytest.txt";
  ifstream inFile(filename);
  string title;
  getline(inFile, title);
  string xlabel;
  getline(inFile, xlabel);
  string source;
  getline(inFile, source);

  BarChartAnimate A(title, xlabel, source);
  assert(A.getSize() == 0);

  while (!inFile.eof()) {
    A.addFrame(inFile);
  }
  A.animate(cout, 12, -1);
  assert(A.getSize() == 9);

  cout << "barchartanimatetest1 all tests passed" << endl;
}

void barchartanimateoper1() {
  string filename = "mytest.txt";
  ifstream inFile(filename);
  string title;
  getline(inFile, title);
  string xlabel;
  getline(inFile, xlabel);
  string source;
  getline(inFile, source);

  BarChartAnimate A(title, xlabel, source);
  assert(A.getSize() == 0);

  while (!inFile.eof()) {
    A.addFrame(inFile);
  }

  map<string, string> colorMap;

  colorMap["South Asia"] = RED;
  colorMap["East Asia"] = BLUE;
  colorMap["Middle East"] = GREEN;

  A[0].graph(cout, colorMap, 12);
  assert(A.getSize() == 9);

  cout << "barchartanimateoper1 all tests passed" << endl;
}

void barchartanimateoper2() {
  string filename = "mytest.txt";
  ifstream inFile(filename);
  string title;
  getline(inFile, title);
  string xlabel;
  getline(inFile, xlabel);
  string source;
  getline(inFile, source);

  BarChartAnimate A(title, xlabel, source);
  assert(A.getSize() == 0);

  while (!inFile.eof()) {
    A.addFrame(inFile);
  }

  map<string, string> colorMap;

  colorMap["South Asia"] = RED;
  colorMap["East Asia"] = BLUE;
  colorMap["Middle East"] = GREEN;

  A[A.getSize() - 1].graph(cout, colorMap, 12);
  assert(A.getSize() == 9);
  cout << "barchartanimateoper2 all tests passed" << endl;
}

int main() {
  //  Testing these first because animate pushes everything very up
  cout << "Testing barchartanimate.h " << endl;
  barchartanimatetest1();
  barchartanimatetest2();

  barchartanimateoper1();
  barchartanimateoper2();

  cout << endl;
  cout << "Testing bar.h" << endl;
  testBarDefaultConstructor();
  testBarParamConstructor();
  testBarlessthanop_1();
  testBarlessthanop_2();
  testBarlessthanequalop_1();
  testBarlessthanequalop_2();
  testBargreaterthanop_1();
  testBargreaterthanop_2();
  testBargreaterthanequalop_1();
  testBargreaterthanequalop_2();

  cout << endl;
  cout << "Testing barchart.h graph function" << endl;
  testBarChartgraph();
  testBarChartgraph1();

  return 0;
}
