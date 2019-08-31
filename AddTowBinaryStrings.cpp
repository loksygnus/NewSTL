#include <iostream>

using namespace std;

string AddBinaryString(string a, string b)
{
        int alen = a.length() - 1;
        int blen = b.length() - 1;
        int reslen = alen;

        char ta, tb, carry, tcarry;

        if (blen > alen)
        {
            return AddBinaryString(b, a);
        }

        carry = '0';
        char tempcarry = '0';
        do
        {        
            while (blen >= 0)
            {
                ta = a[alen];
                tb = b[blen];

                if (ta == tb)
                {
                    a[alen] = '0';

                    if (ta == '1')
                    {
                        tempcarry = '1';
                    }
                    else
                    {
                        tempcarry = '0';
                    }                
                }
                else
                {
                    a[alen] = '1';
                    tempcarry = '0';
                }

                ta = a[alen];

                if (carry == '1')
                {
                    if (ta == carry)
                    {
                        a[alen] = '0';

                        if (ta == '1')
                        {
                            tempcarry = '1';
                        }   
                    }
                    else
                    {
                        a[alen] = '1';
                    }
                }

                carry = tempcarry;

                alen--;
                blen--;
            }

            if (alen < 0)
            {
                break;
            }
            
            ta = a[alen];

            if (carry == '1')
            {
                if (ta == carry)
                {
                    a[alen] = '0';

                    if (ta == '1')
                    {
                        tempcarry = '1';
                    }   
                }
                else
                {
                    a[alen] = '1';
                    tempcarry = '0';
                }

            }

            carry = tempcarry;

            alen--;        

            /* code */
        } while (alen >= 0);

        if (carry == '1')
        {
            string result = "1";
            result.append(a);

            return result;
        }   

 
        return a;
}



int main()
{
    string str = AddBinaryString("100100001101100010011100010110000001001111110111010111110100",
     "111100011011010001100011011000111001011010111101111111010000");

    cout<<"Final output: "<<str<<endl;
    return 0;
}