   
#include <iostream>

using namespace std;
   
    int myAtoi(string str) {
        
        int i = 0, sign = 1;
        int break_out = 0;
        int stream = 0;
        
        while(str[i] != '\0')
        {
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '-'))
            {
                if (str[i] == '-')
                {
                    if (stream == 1)
                    {
                        break_out = 1;
                    }
                    else if ((str[i + 1] >= '0') && (str[i + 1] <= '9'))
                    {
                        sign = -1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    temp = temp * 10 + (str[i] - '0');
                    stream = 1;
                }                
            }
            else if (stream == 1)
            {
                break_out = 1;
            }
            else if ((str[i] == ' ') || (str[i] == '+'))
            {
                if (str[i] == '+')
                {
                    if ((str[i + 1] >= '0') && (str[i + 1] <= '9'))
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        return 0;
                    }
                }
                
                i++;
                continue;
            }
            else
            {
                if (i == 0)
                {
                    /*First Charater in string is non-digit: Hence return zero*/
                    return 0;
                }
                else
                {
                    break_out = 1;
                }
            }
            
            if (sign == -1)
            {
                if ((temp * sign) <= INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else
            {
                if (temp >= INT_MAX)
                {
                    return INT_MAX;
                }
            }
            
            if (break_out == 1)
            {
                return (int) (temp * sign);
            }
            
            i++;
        }
        
        return (int) (temp * sign);        
    
    }

    int main()
    {
        cout<<"Program to convert string to integer with sign and also validates such that returned integer will be with in the range INT_MIN & INT_MAX"<<endl;

        int val = myAtoi("   -42");

        cout<<val<<endl;

        return 0;
    }