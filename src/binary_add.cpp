#include <iostream>

int add(int a, int b)
{
    int res = 0;
    int x = 1;
    int carry = 0;

    while(x <= 512)
    {
        bool bit1 = ((a & x) > 0 ? true : false);
        bool bit2 = ((b & x) > 0 ? true : false);

        if (bit1 && bit2)
        {
            if (carry)
            {
                res = res | x; // toggle on the bit
            }
            else
            {
                res = res ^ (res & x); // toggle off the bit
            }

            carry = 1;
        }
        else if (bit1 || bit2)
        {
            if (carry)
            {
                res = res ^ (res & x);
                carry = 1;
            }
            else
            {
                res = res | x;
            }
        }
        else
        {
            if (carry)
            {
                res = res | x;
                carry = 0;
            }
        }
        x = x << 1;
    }

    if (carry)
    {
        res = res | ( 1 << x ); // move a set bit into the current x place
        carry = 0;
    }

    return res;
}

int main()
{
    std::cout << add(2, 3) << "\n";
    return 0;
}
