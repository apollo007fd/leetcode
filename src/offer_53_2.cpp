#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size() + 1;
		if (nums[n-2]==n-2)
			return n-1;
		int beg=0, end=n-2, mid;
		while(beg < end)
		{
			mid = beg + (end - beg) / 2;
			if(nums[mid] == mid)
				beg = mid + 1;
			else
				end = mid;
		}
		return beg;
    }
};

int main()
{
	//vector<int> vints = {0, 1, 3};	
	//vector<int> vints = {0, 1, 2};	
	vector<int> vints = {1, 2, 3};	
	Solution solution;
	cout << solution.missingNumber(vints) << endl;
}
