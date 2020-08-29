#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<string, int> stock(string);
void out(map<string, int>);


int main(int argc, char *argv[]) {
  ifstream order(argv[1]);
  ifstream ware(argv[2]);
  string input = "";
  int num = 0;

  //take user's order
  map<string, int> want;
  getline(order, input);
  order.close();
  want = stock(input);

  //take warehouse information reading first line then storing map into vector
  //until a match is found
  //only store items from warehouse that are wanted to save space
  vector<string> name;
  vector<map<string, int>> warehouse;
  bool found = false;
  while(found == false && getline(ware, input)){
    int space = input.find(" ");

    name.push_back(input.substr(0, space));

    string list = input.substr(space+1);
    warehouse.push_back(stock(list));

    for (pair<string, int> item : want) {
      string obj = item.first;
      int count = item.second;
      if(count <= warehouse[num][obj]){
        if(obj == want.rbegin()->first){
          cout << name[num]  << ":" << endl;
          out(want);
          found = true;
        }
      }else{
        break;
      }
    }
    num++;
  }
  ware.close();

  //if no single warehouse can complete order
  //then use vector of maps to piece together order

  map<string, map<string, int>> solution;
  if(found == false){
    for (pair<string, int> item : want) {
      bool complete = false;
      for(int i = 0; i < num; i++){
        if(warehouse[i][item.first] > 0){
          if(warehouse[i][item.first] <= item.second){
            solution[name[i]][item.first] = warehouse[i][item.first];
            item.second -= warehouse[i][item.first];
          }else{
            solution[name[i]][item.first] = item.second;
            item.second = 0;
          }
        }
        if(item.second == 0){
          complete = true;
          break;
        }
      }
      if(complete == false){
        break;
      }else if(item.first == want.rbegin()->first){
        found = true;
      }
    }

    if(found == true){
      for (pair<string, map<string, int>> house : solution) {
        cout << house.first << ":" << endl;
        out(house.second);
        cout << endl;
      }
    }else{
      cout << "Order could not be completed." << endl;
    }
  }

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

void out(map<string, int> stock){
  for (pair<string, int> item : stock) {
    cout << item.first << " " << item.second << endl;
  }
}