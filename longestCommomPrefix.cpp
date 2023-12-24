#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string finder(vector<string> strs){
      if(strs[0].size() == 0) return "";
      if(strs[1].find(strs[0]) != string::npos && strs[2].find(strs[0]) != string::npos) return strs[0];
      int dogus = strs[0].size();
      int bogus = dogus/2;
      string val1 = strs[0].substr(0, bogus);
      string val2 = strs[0].substr(bogus, dogus -1);
      string x1 = finder({val1, strs[1], strs[2]});
      string x2 = finder({val2, strs[1], strs[2]});
      string x3 =  x1+x2;
      if(strs[1].find(x3) != string::npos && strs[2].find(x3) != string::npos) return x3;
      if(x1.size() > x2.size()) return x1;
      return x2;
    }
    string longestCommonPrefix(vector<string>& strs) {
      string minor;
      if(strs[0].size() < strs[1].size()  && strs[0].size() < strs[2].size()){
        minor = strs[0];
      }else if(strs[1].size() < strs[0].size() && strs[1].size()< strs[2].size()){
        minor = strs[1];
        strs[1] =  strs[0];
        strs[0] = minor;
      }else {
        minor = strs[2];
        strs[2] = strs[0];
        strs[0] = minor;
      }
      return finder(strs);
    }
};

int main() {
  vector<string> hi {"pepinodenovoornitorrinco", "denovoornito", "denokvoornito"};
  Solution sol;
  cout<< sol.longestCommonPrefix(hi)<<endl;
  return 0;
}