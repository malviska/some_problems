#include<map>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int result = 0;
    map<char,int> roman { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},{'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(string s) {
      int val1, val2;
        for(int i = 0; i < s.size(); i++){
          val1 = roman[s.at(i)];
          val2 = 0;
          if(i+1 < s.size()){
            val2 = roman[s.at(i+1)];

          }
          if(val2 > val1){
            result -= val1;
            continue;
          }
          result += val1;
        }
    }
};

int main() {
  string value; cin >> value;
  Solution mak;
  mak.romanToInt(value);
  cout<< mak.result <<endl;
  return 0;
}