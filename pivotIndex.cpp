#include<vector>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums){
		int sum = 0;
		int inferiorSum = 0;
		for (long int j = nums.size()-1; j >= 0; j--){
			sum += nums[j];
		}
		for(long int i = 0; i< nums.size(); i++){
			sum -= nums[i];
			if(inferiorSum == sum){
				return i;
			}
			inferiorSum += nums[i];
		}
	return -1;
	}
}
