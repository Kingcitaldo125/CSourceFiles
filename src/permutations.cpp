#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

template <class T>
inline std::vector<T> catvec(const T& first, const std::vector<T>& second)
{
    std::vector<T> out {first};
    std::copy_if(
        second.begin(),
        second.end(),
        std::back_inserter(out),
        [&first](const T& t){ return t != first; }
    );

    return out;
}

void perm_help(std::vector<std::vector<int>>& outmatx, std::vector<int>& input, const int isize, const int idx)
{
    if (isize < 2) return;
    if (idx >= isize) return;

    for(int i = idx; i < isize; ++i)
    {
        perm_help(outmatx, input, isize, idx + 1);

        outmatx.push_back(catvec(input.at(i), input));
        int previdx = idx - 1;
        previdx = previdx < 0 ? 0 : previdx;
        std::iter_swap(input.begin() + previdx, input.begin() + idx);
    }
}

std::vector<std::vector<int>> perm(const int N)
{
    std::vector<std::vector<int>> matx;
    std::vector<std::vector<int>> outmatx;
    std::vector<int> input;

    const auto stringify = [](const std::vector<int>& ip)
    {
        std::string out("");

        for(const auto& i : ip)
        {
            out += std::to_string(i);
            out += ' ';
        }

        return out;
    };

    const auto filter = [&matx, &outmatx, &stringify]
    {
        std::unordered_set<std::string> outset;
        for(const auto& itm : matx)
        {
            const auto [_,inserted] = outset.insert(stringify(itm));
            if (!inserted) continue;
            outmatx.push_back(std::move(itm));
        }
    };

    const auto sorted = [&outmatx, &stringify]
    {
        std::sort(outmatx.begin(), outmatx.end(), [](const auto& a, const auto& b)
        {
            const int xsize = static_cast<int>(a.size());
            for(int i = 0; i < xsize; ++i)
            {
                if (a.at(i) == b.at(i)) continue;
                return a.at(i) < b.at(i);
            }
            return a.at(0) < b.at(0);
        });
    };

    for(int i = 0; i < N; ++i) input.push_back(i);

    perm_help(matx, input, static_cast<int>(input.size()), 0);

    filter();
    sorted();

    return outmatx;
}

int main()
{
    for(const auto& itm : perm(3))
    {
        for(const auto& i : itm)
        {
            std::cout << i << " ";
        }
        puts("");
    }

    return 0;
}
