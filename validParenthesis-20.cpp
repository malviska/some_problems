#include<stack>
#include<string>
#include<map>
#include<utility>
#include<iostream>
using namespace std;

class Solution{
  public:
  stack<char> values;
  map<char,char> m = {{'{','}'},{'(',')'}, {'[',']'}};
  bool isValid(string s){
    for(unsigned int i = 0; i<s.size();i++){
      if(values.empty()){
        values.push(s.at(i));
        continue;
      }
      if(m[values.top()] == s.at(i)){
        values.pop();
        continue;
      }
      values.push(s.at(i));
      }
      return values.empty();
    }
  };

int main() {
  Solution sl;
  cout<<sl.isValid("[()")<<endl;
  return 0;
}



