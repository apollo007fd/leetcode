#include<iostream>
using namespace std;

//青蛙跳台阶问题,剑指offer 10-2  
//https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

class Solution {
public:
    int numWays(int n) {
		if(n<0 || n > 100)
			return 0;
		int num_solutions[101] = {1, 1, 2};
		for(int i=3; i<=100; i++)
		{
			int sum = num_solutions[i-1] + num_solutions[i-2];
			if (sum > 1000000007)
				sum -= 1000000007;
			num_solutions[i] = sum;
			if(i>=n)
				break;
		}
		return num_solutions[n];
    }
};

int main()
{
	Solution solu;
	int ans = solu.numWays(7);
	cout << ans;
}
