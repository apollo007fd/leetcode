#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int length = nums.size(), num_occurrence=0;
		if(length==0 || nums[length-1] < target || nums[0] > target)
			return 0;
		int beg=0, end=nums.size()-1, mid=-1;
		while(beg <= end)
		{
			mid = beg + (end - beg) / 2;
			if (nums[mid] < target)
				beg = mid + 1;
			else if (target < nums[mid])
				end = mid - 1;
			else
				break;
		}
		if(beg <= end)
		{
			for(int i=mid; i>=0 && nums[i]==target; --i)
				++num_occurrence;
			for(int i=mid+1; i<length && nums[i]==target; ++i)
				++num_occurrence;
		}
		return num_occurrence;
    }
};


int main()
{
	vector<int> ints = {5,7,7,8,8,10};
	int target = 7;
	Solution solution;
	cout << solution.search(ints, target) << endl;
}
