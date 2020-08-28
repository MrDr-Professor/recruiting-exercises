#include <iostream>
//#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<string, int> stock(string);


int main(int argc, char *argv[]) {
  //ifstream order(argv[1]);
  //ifstream warehouses(argv[2]);
  string input = "house apple 1 orange 2 corn 5";
  int num = 0;
  //take user's order

  //take warehouse information reading first line then storing map into vector
  //until a match is found
  //only store items from warehouse that are wanted to save space
  
  vector<string> name;
  vector<map<string, int>> warehouse;
  int space = input.find(" ");
  name.push_back(input.substr(0, space));
  string list = input.substr(space+1);
  warehouse.push_back(stock(list));

  cout << warehouse[0]["apple"] << endl;
  cout << warehouse[0]["bannana"] << endl;

  //if no single warehouse can complete order
  //then use vector of maps to piece together order

  return 0;
}

map<string, int> stock(string line){
  map<string, int> inv;
  string temp;
  stringstream ss;
  string count;
  ss << line;
  while(ss >> temp){
      ss >> count;
      inv[temp] = stoi(count);
  }
  return inv;
}