#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> runningSum(vector<int>& nums){
		vector<int> result;
		result.push_back(nums[0]);
		for(int i = 1; i < nums.size(); i++){
			result.push_back(nums[i]+result[i-1]);
		}
		return result;
	}
};

int main (){
	vector<int> hi;
	char value;
	while(cin>>value){
		hi.push_back(value);
	}
	Solution sol;
	vector<int> result = sol.runningSum(hi);
	for(int j = 0; j<result.size(); j++){
		cout<<result[j]<<" ";
	}
	cout<<"\n";
	return 0;
}
