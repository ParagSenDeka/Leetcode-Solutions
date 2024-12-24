#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while ((i >= 0 || j >= 0) || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            res += carry % 2 + '0';
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution obj;
    string a = "1010", b = "1011";
    cout << obj.addBinary(a, b) << endl;
    return 0;
}