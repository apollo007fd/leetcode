#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
		long res = 0, i=0; bool neg = false;
		while(i<str.size() && str[i]==' ') ++i;
		if(!isdigit(str[i]))
		{
			if (str[i]!='+' && str[i]!='-')
				return 0;
			else if (str[i] == '-')
				neg = true;
			else
				neg = false;
			++i;
		}
		while(isdigit(str[i]))
		{
			res = res * 10 + str[i] - '0';
			if( !neg && res >= INT_MAX)
				return INT_MAX;
			else if (neg && -res <= INT_MIN)
				return INT_MIN;
			++i;
		}
		if(neg)
			res *= -1;
		return res;
    }
};


int main()
{
	//string str= "   -123333334532323232";
	string str= "42";
	Solution *solution = new Solution();
	cout << solution->strToInt(str) << endl;
}
