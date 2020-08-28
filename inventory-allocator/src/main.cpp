#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> stock(string);


int main(int argc, char *argv[]) {
  string input = "";
  //take user's order

  //take warehouse information reading first line then storing map into vector
  //until a match is found
  //only store items from warehouse that are wanted to save space
  
  vector<string> name;
  vector<map<string, int>> warehouse;
  int space = input.find(" ");
  name.push_back(input.substr(0, space));
  string list = input.substr(space);
  //cout << name << endl << list <<endl;
  //warehouse.push_back(stock(list));

  //if no single warehouse can complete order
  //then use vector of maps to piece together order

  return 0;
}