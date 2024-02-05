#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define MAX_INF 999999999

using node_t = std::pair<std::string,int>;
using graph_t = std::unordered_map<std::string, std::vector<node_t>>;

std::unordered_map<std::string,int> dyjkstras(graph_t& mgraph, const std::string& start)
{
    std::unordered_set<std::string> visited;
    std::queue<node_t> mq;
    std::unordered_map<std::string,int> costs;

    for(const auto& pair : mgraph)
    {
        const auto &[i,j] = pair;
        costs[i] = MAX_INF;
    }

    costs[start] = 0;

    mq.push(std::make_pair(start, 0));

    while(!mq.empty())
    {
        const auto item = mq.front();
        mq.pop();

        const auto &[id, weight] = item;

        visited.insert(id);

        std::cout << "Visited: '" << id << "'\n";

        int l_cost = MAX_INF;
        std::string l_neighbor = id;
        for(const auto& neighbor : mgraph[id])
        {
            const auto &[nid, nweight] = neighbor;

            costs[nid] = std::min(costs[nid], weight + nweight);

            if (costs[nid] < l_cost)
            {
                l_cost = costs[nid];
                l_neighbor = nid;
            }
        }

        if (visited.find(l_neighbor) == visited.end())
        {
            mq.push(std::make_pair(l_neighbor, l_cost));
        }
    }

    return costs;
}

int main()
{
    graph_t graph{{"D",{}}};

    graph["A"].push_back(std::make_pair("B", 4));
    graph["A"].push_back(std::make_pair("C", 2));

    graph["B"].push_back(std::make_pair("C", 3));
    graph["B"].push_back(std::make_pair("D", 2));
    graph["B"].push_back(std::make_pair("E", 3));

    graph["C"].push_back(std::make_pair("B", 1));
    graph["C"].push_back(std::make_pair("D", 4));
    graph["C"].push_back(std::make_pair("E", 5));

    graph["E"].push_back(std::make_pair("D", 1));

    const auto costs = dyjkstras(graph, "A");

    puts("Costs:");
    for(const auto& cp : costs)
    {
        const auto &[i,j] = cp;
        std::cout << i << "," << j << "\n";
    }

    return 0;
}
