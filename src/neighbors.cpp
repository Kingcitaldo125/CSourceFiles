#include <iostream>
// #include <string>
#include <unordered_set>
#include <vector>

using cell_t = std::pair<int, int>;
using visited_t = std::unordered_set<std::string>;
using graph_t = std::vector<std::string>;

inline std::string cell_to_string(cell_t mc)
{
    const auto [x, y] = mc;
    return "[" + std::to_string(x) + "," + std::to_string(y) + "]";
}

inline cell_t string_to_cell(std::string mc)
{
    return std::make_pair(std::stoi(mc.substr(1, mc.find(","))),
                          std::stoi(mc.substr(mc.find(",") + 1, mc.find("]"))));
}

inline void print_neighbors(std::vector<std::vector<int>> &neighbors)
{
    for (const auto &row : neighbors)
    {
        for (const auto &r : row)
        {
            std::cout << r << " ";
        }

        std::cout << "\n";
    }
}

std::vector<std::vector<int>> get_neighbors(graph_t &graph, const int x, const int y)
{
    std::vector<std::vector<int>> neighbors;

    // std::cout << "Current cell: " << x << "," << y << "\n";

    for (int yy = y - 1; yy < y + 2; ++yy)
    {
        std::cout << "CB (Y): " << x << "," << yy << "\n";

        if (yy == y || yy < 0 || yy >= graph.size())
        {
            continue;
        }

        if (graph.at(yy).at(x) != '1')
        {
            continue;
        }

        std::cout << "Pushing Back (Y): " << x << "," << yy << "\n";

        neighbors.push_back(std::vector<int>{x, yy});
    }

    for (int xx = x - 1; xx < x + 2; ++xx)
    {
        std::cout << "CB (X): " << xx << "," << y << "\n";

        if (xx == x || xx < 0 || xx >= graph.at(0).size())
        {
            std::cout << "Cell not in bounds: " << xx << "," << y << "\n";
            continue;
        }

        if (graph.at(y).at(xx) != '1')
        {
            std::cout << "Cell not 1: " << graph.at(y).at(xx) << " : " << xx << "\n";
            std::cout << "Cell not 1: " << xx << "," << y << "\n";
            continue;
        }

        std::cout << "Pushing Back (X): " << xx << "," << y << "\n";

        neighbors.push_back(std::vector<int>{xx, y});
    }

    neighbors.push_back(std::vector<int>{0, 0});

    // print_neighbors(neighbors);

    return neighbors;
}

bool is_island(graph_t &graph, visited_t &visited, const int x, const int y)
{
    visited.insert(cell_to_string(std::make_pair(x, y)));

    std::cout << "Visited: " << x << "," << y << "\n";

    if (x == 0 || x == static_cast<int>(graph.at(0).size()) - 1)
    {
        // std::cout << "X false: " << x << "\n";
        return false;
    }

    if (y == 0 || y == static_cast<int>(graph.size()) - 1)
    {
        // std::cout << "Y false: " << y << "\n";
        return false;
    }

    auto neighbors = get_neighbors(graph, x, y);
    std::cout << "Neighbors:\n";
    for (const auto &neighbor : neighbors)
    {
        const int nx = neighbor.at(0);
        const int ny = neighbor.at(1);

        std::cout << "nx: " << nx << " ny: " << ny << "\n";

        const auto n_pair = std::make_pair(nx, ny);
        const auto n_string = cell_to_string(n_pair);

        std::cout << "n_string: " << n_string << "\n";

        if (visited.find(n_string) == visited.end())
        {
            return is_island(graph, visited, nx, ny);
        }
    }

    return true;
}

void remove_islands(graph_t &graph)
{
    visited_t global_visited;
    const auto rows = static_cast<int>(graph.size());
    const auto cols = static_cast<int>(graph.at(0).size());

    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < cols; ++x)
        {
            if (graph.at(y).at(x) == '1')
            {
                const auto csz = cell_to_string(std::make_pair(x, y));

                if (global_visited.find(csz) != global_visited.end())
                {
                    continue;
                }

                visited_t visited;

                const bool is_is = is_island(graph, visited, x, y);

                for (const auto &v : visited)
                    global_visited.insert(v);

                if (is_is)
                {
                    for (const auto &v : visited)
                    {
                        const auto [vx, vy] = string_to_cell(v);
                        graph.at(vy).at(vx) = '@';
                    }
                }
            }
        }
    }
}

inline void print_graph(graph_t &graph)
{
    for (const auto &row : graph)
    {
        std::cout << row << "\n";
    }
}

int main()
{
    graph_t mgraph{
        "00000", "00010", "00010", "00111", "00000",
    };

    remove_islands(mgraph);
    print_graph(mgraph);

    return 0;
}
