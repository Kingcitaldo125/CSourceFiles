#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using graph_t = std::unordered_map<std::string, std::vector<std::string>>;
using parent_graph_t = std::unordered_map<std::string, std::string>;
using visited_t = std::unordered_set<std::string>;

void fd_help(graph_t &graph, visited_t &visited, std::string &output, std::string cur)
{
    visited.insert(cur);

    for (const auto &n : graph[cur])
    {
        if (visited.find(n) != visited.end())
            continue;
        fd_help(graph, visited, output, n);
    }

    output += cur;
}

std::string ufind_find(parent_graph_t &parent, const std::string &cur)
{
    if (parent[cur] == cur)
        return cur;
    return ufind_find(parent, parent[cur]);
}

void ufind_union(graph_t &graph, parent_graph_t &parent, const std::string &first,
                 const std::string &second)
{
    const auto p1 = ufind_find(parent, first);
    const auto p2 = ufind_find(parent, second);

    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";

    parent[p1] = p2;

    if (p1 == p2)
        return;

    graph.erase(graph.find(p2));
    graph[p1].push_back(p2);
}

std::string foreignDictionary(const std::vector<std::string> &words)
{
    if (words.empty())
        return "";

    graph_t graph;
    parent_graph_t parent;
    std::string output("");
    std::string start("");

    for (const auto &w : words)
    {
        if (w.empty())
            continue;
        const auto cur_start = std::string(1, w.front());
        if (start == "")
            start = cur_start;

        bool newroot = parent.find(cur_start) == parent.end();
        for (auto it = w.begin(); it < w.end() - 1; ++it)
        {
            const auto key = std::string(1, *it);
            const auto val = std::string(1, *(it + 1));

            graph[key].push_back(val);
            parent[key] = key;
        }

        if (newroot)
        {
            std::cout << "joining roots..\n";
            ufind_union(graph, parent, start, cur_start);
            std::cout << "done\n";
        }

        visited_t visited;
        output = "";
        fd_help(graph, visited, output, start);
        std::reverse(output.begin(), output.end());

        std::unordered_map<std::string, int> keymap;
        int ctr = 0;
        for (const auto &o : output)
        {
            keymap[std::string(1, o)] = ctr;
            ++ctr;
        }

        std::vector<int> w_ordering;
        for (const auto &ww : w)
        {
            w_ordering.push_back(keymap[std::string(1, ww)]);
        }

        if (!std::is_sorted(w_ordering.begin(), w_ordering.end()))
        {
            std::cout << "out of order: " << w << "\n";
            return "";
        }
    }

    return output;
}

int main()
{
    std::cout << foreignDictionary({"hrn", "hrf", "er", "enn", "rfnn"}) << "\n";
    return 0;
}
