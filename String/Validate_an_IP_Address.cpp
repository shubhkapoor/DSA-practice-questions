/*      Validate an IP Address

Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, 
each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers 
only from 0 to 255 and any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string s as its only argument .

Example 1:

Input:
ip = 222.111.111.111
Output: 1


Example 2:

Input:
ip = 5555..555
Output: 0
Explanation: 5555..555 is not a valid
ip address, as the middle two portions
are missing.

*/

class Solution
{
public:
    int isValid(string s)
    {
        int dot=0;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='.')
            {
                dot++;
            }
        }

        if(dot != 3)
        {
            return 0;
        }

        vector<pair<int,string>> v;
        int i=0;

        while(i<s.length())
        {
            bool found = false;
            string tmp = "";
            int num = 0;

            while(i<s.length() && s[i]>='0' && s[i]<='9')
            {
                found = true;
                num = num*10 + (s[i]-'0');
                tmp.push_back(s[i]);

                if(num>255)
                {
                    return 0;
                }
                i++;
            }

            dot++;

            if(found)
            {
                v.push_back({num,tmp});
            }

            i++;
        }

        if(v.size()!=4)
        {
            return 0;
        }

        for(int i=0; i<v.size(); i++)
        {
            if(v[i].first>255)
            {
                return 0;
            }
            else if(v[i].first==0 && v[i].second.length()>1)
            {
                return 0;
            }
            else if(v[i].first!=0 && v[i].second[0]=='0')
            {
                return 0;
            }
        }

        return 1;
    }
};
