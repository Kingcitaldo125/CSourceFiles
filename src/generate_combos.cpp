// C++ version of Python's combinations_with_replacement
// https://docs.python.org/3/library/itertools.html#itertools.combinations_with_replacement

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using set_t = std::unordered_set<std::string>;

inline bool sum_filter(const std::vector<int> &vec, const int sum)
{
    int xsum = 0;
    for (const auto &v : vec)
        xsum += v;
    return xsum == sum;
}

inline void print_vector(const std::vector<int> &vec)
{
    for (const auto &v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

inline std::string stringify(const std::vector<int> &reference)
{
    std::string refstr("");

    for (const auto &r : reference)
    {
        refstr += std::to_string(r);
        refstr += ',';
    }

    if (refstr.size() > 0)
    {
        return std::string(refstr.begin(), refstr.end() - 1);
    }
    return "";
}

void combos(std::vector<std::vector<int>> &coins, set_t &xset, const std::vector<int> &reference,
            std::vector<int> &current, const std::size_t magnitude, const int idx)
{
    if (idx >= static_cast<int>(reference.size()))
    {
        const auto &c_size = current.size();

        if (c_size == 0 || c_size != magnitude)
            return;

        std::sort(current.begin(), current.end());

        auto cur_str = stringify(current);
        // std::cout << "cur_str: " << cur_str << "\n";
        if (xset.find(cur_str) != xset.end())
            return;

        coins.push_back(current);
        xset.insert(cur_str);
        return;
    }

    combos(coins, xset, reference, current, magnitude, idx + 1);

    current.push_back(reference.at(idx));

    combos(coins, xset, reference, current, magnitude, idx + 1);

    current.erase(current.begin());
}

void generate_combos_help(std::vector<std::vector<int>> &t_coins, std::vector<int> holder,
                          set_t &xset, const std::size_t magnitude)
{
    for (int i = 0; i < static_cast<int>(holder.size()); ++i)
    {
        std::vector<std::vector<int>> coins;
        std::vector<int> current;

        combos(coins, xset, holder, current, magnitude, 0);

        auto f = holder.front();

        holder.erase(holder.begin());
        holder.push_back(f);

        for (const auto &c : coins)
        {
            t_coins.push_back(c);
            generate_combos_help(t_coins, c, xset, magnitude);
        }
    }
}

std::vector<std::vector<int>> generate_combos(std::vector<int> holder, const std::size_t magnitude)
{
    std::vector<std::vector<int>> t_coins;
    set_t xset;

    if (holder.size() == magnitude)
    {
        t_coins.push_back(holder);
    }

    std::unordered_set<int> hset;
    std::copy(holder.begin(), holder.end(), std::inserter(hset, hset.begin()));
    for (const auto &h : hset)
    {
        holder.push_back(h);
    }

    generate_combos_help(t_coins, holder, xset, magnitude);

    return t_coins;
}

int main()
{
    auto xcombos = generate_combos({1, 2, 3}, 4);

    for (const auto &c : xcombos)
    {
        print_vector(c);
    }

    return 0;
}
