#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using board_t = std::vector<std::string>;
using combos_t = std::vector<board_t>;

inline void print_board(const board_t &board)
{
    for (const auto &row : board)
    {
        std::cout << row << "\n";
    }
    puts("");
}

inline void print_combos(const combos_t &combos)
{
    for (const auto &board : combos)
    {
        print_board(board);
    }
}

board_t gen_qstr(const int n)
{
    board_t qvec;

    for (int i = 0; i < n; ++i)
    {
        std::string xstr("");
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                xstr += 'Q';
                continue;
            }
            xstr += '.';
        }
        qvec.push_back(std::move(xstr));
    }

    return qvec;
}

bool is_row_valid(const board_t &board)
{
    int cnt = 0;
    int xrow = 1;
    for (const auto &row : board)
    {
        cnt = 0;
        for (const auto &r : row)
        {
            if (r == 'Q')
                ++cnt;
        }

        if (cnt > 1)
        {
            return false;
        }

        ++xrow;
    }

    return cnt < 2;
}

bool is_col_valid(const board_t &board)
{
    for (int j = 0; j < static_cast<int>(board.size()); ++j)
    {
        int cnt = 0;
        for (int i = 0; i < static_cast<int>(board.size()); ++i)
        {
            if (board.at(i).at(j) == 'Q')
                ++cnt;
        }

        if (cnt > 1)
        {
            return false;
        }
    }
    return true;
}

bool is_diag_valid(const board_t &board)
{
    const int board_size = static_cast<int>(board.size());
    int i = board_size - 1;
    int j = 0;

    while (1)
    {
        if (i < 0)
            break;

        int cnt = 0;
        for (int idx = 0; idx < board_size; ++idx)
        {
            if (j + idx >= board_size)
                break;
            if (i + idx >= board_size)
                break;
            if (board[j + idx][i + idx] == 'Q')
                ++cnt;
            if (cnt > 1)
            {
                // puts("downwards upper echelon invalid");
                return false;
            }
        }
        --i;
    }

    i = 0;
    j = 1;
    while (1)
    {
        if (j >= board_size)
            break;

        int cnt = 0;
        for (int idx = 0; idx < board_size; ++idx)
        {
            if (j + idx >= board_size)
                break;
            if (i + idx >= board_size)
                break;
            if (board[j + idx][i + idx] == 'Q')
                ++cnt;
            if (cnt > 1)
            {
                // puts("downwards lower echelon invalid");
                return false;
            }
        }

        ++j;
    }

    i = 0;
    j = 1;
    while (1)
    {
        if (j >= board_size)
            break;

        int cnt = 0;
        for (int idx = 0; idx < board_size; ++idx)
        {
            if (j - idx < 0)
                break;
            if (i + idx >= board_size)
                break;
            if (board[j - idx][i + idx] == 'Q')
                ++cnt;
            if (cnt > 1)
            {
                // puts("upwards upper echelon invalid");
                return false;
            }
        }

        ++j;
    }

    i = 0;
    j = board_size - 1;
    while (1)
    {
        if (i >= board_size)
            break;

        int cnt = 0;
        for (int idx = 0; idx < board_size; ++idx)
        {
            if (j - idx < 0)
                break;
            if (i + idx >= board_size)
                break;
            if (board[j - idx][i + idx] == 'Q')
                ++cnt;
            if (cnt > 1)
            {
                // puts("upwards lower echelon invalid");
                return false;
            }
        }

        ++i;
    }

    return true;
}

inline bool is_valid(const board_t &board)
{
    const bool row_valid = is_row_valid(board);
    const bool col_valid = is_col_valid(board);
    const bool diag_valid = is_diag_valid(board);

    return row_valid && col_valid && diag_valid;
}

void combos(combos_t &xcombos, const board_t &ref, board_t cur, const int idx, const int n)
{
    if (idx >= static_cast<int>(ref.size()))
    {
        if (static_cast<int>(cur.size()) != n)
            return;
        if (!is_valid(cur))
            return;

        xcombos.push_back(cur);
        return;
    }

    for (int i = 0; i < static_cast<int>(ref.size()); ++i)
    {
        cur.push_back(ref.at(i));
        combos(xcombos, ref, cur, idx + 1, n);
        cur.pop_back();
    }
}

combos_t solveNQueens(const int n)
{
    combos_t xcombos;
    const auto ref = gen_qstr(n);
    combos(xcombos, ref, {}, 0, n);
    return xcombos;
}

int main()
{
    const auto boards = solveNQueens(4);
    print_combos(boards);
    return 0;
}
