// https://leetcode.com/problems/set-matrix-zeroes/description/
#include <algorithm>
#include <iostream>
#include <vector>

void set_zero_col(std::vector<std::vector<int>>& matrix, const int col)
{
    for(auto& row : matrix)
    {
        row.at(col) = 0;
    }
}

void set_zero_row(std::vector<std::vector<int>>& matrix, const int row)
{
    int id = 0;

    while(1)
    {
        if (id == row)
        {
            auto& xrow = matrix.at(id);

            for(auto& rr : xrow)
            {
                rr = 0;
            }

            break;
        }

        ++id;
    }
}

void setZeroes(std::vector<std::vector<int>>& matrix)
{
    std::vector<std::pair<int,int>> zero_cells;
    int row_id = 0;
    int col_id = 0;

    for(const auto& row : matrix)
    {
        col_id = 0;

        for(const auto& r : row)
        {
            if (r == 0)
            {
                zero_cells.push_back(std::make_pair(row_id, col_id));
            }

            ++col_id;
        }

        ++row_id;
    }

    for(const auto& cell : zero_cells)
    {
        const auto &[r,c] = cell;

        set_zero_row(matrix, r);
        set_zero_col(matrix, c);
    }
}

inline void print_matrix(std::vector<std::vector<int>>& matx)
{
    for(const auto& row : matx)
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
    std::vector<std::vector<int>> matx {
        {1,1,1},
        {0,1,1},
        {1,1,1},
    };

    setZeroes(matx);

    print_matrix(matx);

    return 0;
}
