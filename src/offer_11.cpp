#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        int start=0, end=length-1;
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[end] > nums[mid])
                end = mid;
            else if (nums[end] < nums[mid])
                start = mid+1;
            else
                --end;
        }
        return nums[start];
    }
};

int main()
{
	Solution* solution = new Solution();
	vector<int> input_arr = {3,1,3};
	//vector<int> input_arr = {2,2,2,0,1};
	//vector<int> input_arr = {1,2,2,3,4,5,5,6};
	int ans = solution->findMin(input_arr);
	cout << ans << endl;
}
