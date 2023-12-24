#include<string>
#include<map>
#include<utility>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
				map<char,char> mapa, mapa2;
				pair<char,char> p;
				map<char,char>::iterator it, its;
				for(int i = 0; i< s.size(); i++){
					it = mapa.find(s.at(i));
					its = mapa2.find(t.at(i));
					if(it != mapa.end()){
						if(it->second != t.at(i))
							return false;
						continue;
					}
					if(its != mapa2.end()){
						if(its->second != s.at(i))
							return false;
						continue;
					}
					mapa.insert({s.at(i), t.at(i)});
					mapa2.insert({t.at(i), s.at(i)});
				}
			return true;
    }
};
