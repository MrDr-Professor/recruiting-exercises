#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<string, int> stock(string);


int main(int argc, char *argv[]) {
  ifstream order(argv[1]);
  ifstream ware(argv[2]);
  string input = "";
  int num = 0;

  //take user's order
  map<string, int> want;
  getline(order, input);
  want = stock(input);
  cout << "order-" << endl;
  cout << "apple: " << want["apple"] << endl;
  cout << "bannana: " << want["bananna"] << endl;

  //take warehouse information reading first line then storing map into vector
  //until a match is found
  //only store items from warehouse that are wanted to save space
  getline(ware, input);
  cout << input << endl;
  vector<string> name;
  vector<map<string, int>> warehouse;
  int space = input.find(" ");
  name.push_back(input.substr(0, space));
  string list = input.substr(space+1);
  warehouse.push_back(stock(list));

  cout << "warehouse-" << endl;
  cout << "apple: " << warehouse[0]["apple"] << endl;
  cout << "bannana: " << warehouse[0]["bannana"] << endl;

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