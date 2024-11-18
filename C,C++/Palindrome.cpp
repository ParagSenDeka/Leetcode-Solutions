#include <iostream>
using namespace std;
string a = "adabbada";
int maxLength = a.length();

string maximum;

bool checkPalindrome(int start, int end)
{
    while (start >= 0 && end < maxLength)
    {

        if (a[start] != a[end])
        {
            return false;
        }
        start--;
        end++;
    }
    return true;
}
string checkFirstAndEnd(int start, int end)
{
    int newEnd=end;
    while (start >= 0)
    {
        while (end < maxLength)
        {
            if (a[start] == a[end])
            {
                if(checkPalindrome(start, end))
                    if (end-start+1 > maximum.length()) {
                        // update the maximum with the longer palindrome
                        maximum=a.substr(start,end-start+1);
                    }
                }
                else{
                    maximum="Not palindrome";
                }
            }
            end++;
        }
        start--;
        end=newEnd;
    }
    return maximum;
}

int main()
{
    int start,end;
    if (a.length() % 2 == 0)
    {
        start = (a.length() / 2)-1;
        end = (a.length() / 2);
    }
    else
    {
        start=end=a.length()/2;
    }
    // print a newline after the output
    cout<<checkFirstAndEnd(start, end) << endl;
}
