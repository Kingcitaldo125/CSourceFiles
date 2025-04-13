#include <iostream>
#include <vector>

using std::cout;
using std::endl;

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>> &matx)
{
    // check to make sure there are no differing row sizes
    {
        auto n_size = -1;
        for (auto &i : matx)
        {
            if (n_size != -1 && n_size != i.size())
                throw "Row sizes alternate; Cannot transpose";
            n_size = i.size();
        }
    }

    std::vector<std::vector<int>> new_matx;
    auto row_size = matx[0].size();

    for (auto i = 0; i < row_size; ++i)
    {
        std::vector<int> n_row(matx.size(), 0);
        new_matx.push_back(n_row);
    }

    for (auto i = 0; i < row_size; ++i)
    {
        for (auto j = 0; j < matx.size(); ++j)
        {
            new_matx[i][j] = matx[j][i];
        }
    }
    return new_matx;
}

int main()
{
    std::vector<std::vector<int>> mints;

    mints.push_back({1, 2});
    mints.push_back({3, 4});
    mints.push_back({5, 6});

    std::vector<std::vector<int>> t_matx;
    try
    {
        t_matx = transpose(mints);
    }
    catch (...)
    {
        cout << "Exception occurred\n";
    }

    for (auto &row : t_matx)
    {
        for (auto &i : row)
        {
            cout << i << ",";
        }
        cout << endl;
    }

    cout << "Hello World" << endl;

    return 0;
}
