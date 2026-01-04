#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <unordered_map>
#include <unordered_set>

// #define PRINT_GRAPH

using graph_t = std::unordered_map<std::string, std::vector<std::string>>;
using visited_t = std::unordered_set<std::string>;

inline int rand_int(std::mt19937 &twister, const int low, const int high)
{
    return (twister() % (high - low)) + low;
}

graph_t make_graph(const std::vector<std::string> &words)
{
    graph_t graph;
    visited_t pairings;
    const auto insert_pairing =
        [&graph, &pairings](const std::string &string1, const std::string &string2)
    {
        const auto [_, inserted] = pairings.insert(string1 + ',' + string2);
        if (!inserted)
            return;
#ifdef PRINT_GRAPH
        std::cout << string1 << " -> " << string2 << ";\n";
#endif
        graph[string1].push_back(std::move(string2));
    };

    for (auto it = words.cbegin(); it < words.cend(); ++it)
    {
        const auto word = *it;
        for (auto jt = word.cbegin(); jt < word.cend() - 1; ++jt)
        {
            auto string1 = std::string(1, *jt);
            auto string2 = std::string(1, *(jt + 1));
            if (string1 == string2)
                continue;
            insert_pairing(string1, string2);
        }

        for (auto jt = it + 1; jt < words.cend(); ++jt)
        {
            const auto word1 = *it;
            const auto word2 = *jt;
            std::size_t minlen = std::min(word1.size(), word2.size());
            for (std::size_t i = 0; i < minlen; ++i)
            {
                for (std::size_t j = i; j < minlen; ++j)
                {
                    auto string1 = std::string(1, word1[i]);
                    auto string2 = std::string(1, word2[j]);
                    if (string1 == string2)
                        continue;
                    insert_pairing(string1, string2);
                }
            }
        }
    }
    return graph;
}

void top_sort(graph_t &graph, std::mt19937 &twister, const std::string &current, std::string &mstr)
{
    const int num_neighbors = static_cast<int>(graph[current].size());

    if (0 == num_neighbors)
    {
        mstr += current;
        return;
    }

    const int next = rand_int(twister, 0, num_neighbors);
    top_sort(graph, twister, graph[current][next], mstr);
    mstr += current;
}

std::string foreignDictionary(std::mt19937 &twister, const std::vector<std::string> &words)
{
    if (words.empty())
        return "";

    if (words.front().empty())
        return "";

    auto graph = make_graph(words);
    std::string mstr = "";
    top_sort(graph, twister, std::string(1, words.front().front()), mstr);
    return std::string(mstr.rbegin(), mstr.rend());
}

int main()
{
    const auto words = std::vector<std::string>{"hrn", "hrf", "er", "en", "rf"};
    std::mt19937 twister(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0; i < 5; ++i)
    {
        std::cout << foreignDictionary(twister, words) << "\n";
    }
    return 0;
}
