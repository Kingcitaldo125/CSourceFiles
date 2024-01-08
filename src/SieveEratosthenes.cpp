#include <cmath>

#include <array>
#include <algorithm>
#include <iostream>
#include <vector>

template <size_t N>
std::vector<unsigned int> sieve()
{
    if (N <= 0)
        return std::vector<unsigned int>();

    std::array<unsigned int, N> mints;

    for(auto i = 2; i < N; ++i)
        mints.at(i) = i;
    mints.at(0) = 0;
    mints.at(1) = 0;

    const auto sqrt_N = static_cast<unsigned int>(sqrt(static_cast<double>(N)));

    for(auto i = 2; i < sqrt_N; ++i)
    {
        if (mints.at(i) != 0)
        {
            unsigned int j = i * i;

            while(1)
            {
                if (j >= N)
                    break;

                mints.at(j) = 0;
                j += i;
            }

            std::cout << "\n";
        }
    }

    std::vector<unsigned int> vals;

    std::copy_if(mints.begin(), mints.end(), std::back_inserter(vals), [](const unsigned int i){ return i != 0; });

    return vals;
}

int main()
{
    const auto vals = sieve<16>();

    for(const auto& i : vals)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
