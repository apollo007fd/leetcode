#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	long res = 0, i = 0;
		bool negative = false;
		while(i < str.size() && str[i] == ' ') ++i;
		if (!isdigit(str[i]))
		{
			if(str[i] == '+')
				negative = false;
			else if (str[i] == '-')
				negative = true;
			else
				return 0;
			++i;
		}
		while(isdigit(str[i]))
		{
			res = res * 10 + str[i] - '0';
			if (!negative && res >= INT_MAX)
				return INT_MAX;
			else if (negative && -res <= INT_MIN)
				return INT_MIN;
			++i;
		}
		return negative ? -res : res;
    }
};


int main()
{
	//string str= "   -123333334532323232";
	string str= "42";
	Solution *solution = new Solution();
	cout << solution->myAtoi(str) << endl;
}
