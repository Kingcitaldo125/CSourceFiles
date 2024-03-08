// https://leetcode.com/problems/pacific-atlantic-water-flow/description/
#include <iostream>
#include <list>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using grid = std::vector<std::vector<int>>;
using visited_t = std::unordered_map<std::string, std::pair<int,int>>;

static std::regex cell_str_rgx("\\[(\\d+),(\\d+)\\]");

inline std::string cell_to_string(const int x, const int y)
{
    return std::string("[") + std::to_string(x) + std::string(",") + std::to_string(y) + std::string("]");
}

inline std::pair<int,int> string_to_cell(std::string mstr)
{
    std::smatch sm;

    const auto res = std::regex_match(mstr, sm, cell_str_rgx);

    return std::make_pair(res ? std::stoi(sm[1]) : -1, res ? std::stoi(sm[2]) : -1);
}

std::vector<std::pair<int,int>> get_neighbors(const grid& heights, const int x, const int y)
{
    std::vector<std::pair<int,int>> neighs;
    const auto height_size = static_cast<int>(heights.size());
    const auto cur_cell = heights.at(y).at(x);

    for(int i = x - 1; i < x + 2; ++i)
    {
        if (i < 0 || i >= height_size || i == x)
        {
            continue;
        }

        const auto local_cell = heights.at(y).at(i);

        if (local_cell > cur_cell)
        {
            continue;
        }

        neighs.push_back(std::make_pair(i, y));
    }

    for(int j = y - 1; j < y + 2; ++j)
    {
        if (j < 0 || j >= height_size || j == y)
        {
            continue;
        }

        const auto local_cell = heights.at(j).at(x);

        if (local_cell > cur_cell)
        {
            continue;
        }

        neighs.push_back(std::make_pair(x, j));
    }

    return neighs;
}

void bfs(const grid& heights, visited_t& visited_cells, std::pair<int,int> start_cell)
{
    std::list<std::pair<int,int>> mq;
    std::unordered_set<std::string> visited;

    mq.push_back(start_cell);

    // Breadth-first search going outwards from the current cell
    // to all of the neighboring cells.
    while(mq.size() > 0)
    {
        auto cell = mq.front();
        const auto &[cell_x, cell_y] = cell;
        mq.pop_front();

        visited.insert(cell_to_string(cell_x, cell_y));

        // Only get neighbors that have a value equal to or less than
        // the value of the current cell.
        for(const auto& pair : get_neighbors(heights, cell_x, cell_y))
        {
            const auto &[neighbor_x, neighbor_y] = pair;

            if (visited.find(cell_to_string(neighbor_x, neighbor_y)) == visited.end())
            {
                mq.push_back(std::make_pair(neighbor_x, neighbor_y));
            }
        }
    }

    const int heights_size = static_cast<int>(heights.size());
    const auto &[sx, sy] = start_cell;
    const auto s_str = cell_to_string(sx, sy);

    // Set the current cell's visited parameters based
    // on the relative locations to both oceans.
    for(const auto& v_cell : visited)
    {
        const auto [cx, cy] = string_to_cell(v_cell);

        const bool visit_pac = (cx == 0 || cy == 0);
        const bool visit_atl = (cx == (heights_size - 1) || cy == (heights_size - 1));

        // Set the visited parameters of the current cell
        auto &[pac,atl] = visited_cells[s_str];

        if (visit_pac) pac = 1;
        if (visit_atl) atl = 1;
    }
}

grid pacific_atlantic(const grid& heights)
{
    grid res_grid;
    visited_t visited_cells;

    // Go through all cells in the grid.
    for(int x = 0; x < static_cast<int>(heights.size()); ++x)
    {
        for(int y = 0; y < static_cast<int>(heights.size()); ++y)
        {
            // See if we can get to both oceans from the current cell.
            bfs(heights, visited_cells, std::make_pair(x, y));
        }
    }

    // Collect cells that we've visited twice.
    for(const auto& item_pair : visited_cells)
    {
        const auto &[cell_param, visit_pair] = item_pair;
        const auto &[pac, atl] = visit_pair;

        if (atl == 1 && pac == 1)
        {
            const auto [x,y] = string_to_cell(cell_param);
            std::vector<int> mints;

            //std::cout << "Target cell: " << x << " " << y << std::endl;

            mints.push_back(x);
            mints.push_back(y);

            res_grid.push_back(std::move(mints));
        }
    }

    return res_grid;
}

inline void print_res_grid(const grid& grid)
{
    for(const auto& row : grid)
    {
        for(const auto& r : row)
        {
            std::cout << r << " ";
        }

        std::cout << "\n";
    }
}

int main()
{
    grid heights
    {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4},
    };

    print_res_grid(pacific_atlantic(heights));

    return 0;
}
