// https://en.wikipedia.org/wiki/Shunting_yard_algorithm#The_algorithm_in_detail
#include <iostream>
#include <list>
#include <unordered_map>

static std::unordered_map<char,int> prescedence_map { {'(', 1}, {')', 1}, {'-', 2}, {'+', 3}, {'/', 4}, {'*', 5}};

inline bool is_operand(const char c)
{
    return c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/';
}

inline bool prescedence(char c1, char c2)
{
    return prescedence_map[c1] < prescedence_map[c2];
}

std::string shunting_yard(const std::string& mstr)
{
    std::list<std::string> mstack;
    std::list<char> operands;
    const char control_char = '@';

    const auto handle_operand = [&operands,&mstack,&control_char](char m) {
        char top = '_';

        if (operands.size() > 0)
        {
            top = operands.back();
        }

        while(operands.size() > 0 && prescedence(m, top))
        {
            top = operands.back();
            operands.pop_back();

            mstack.push_back(std::string(1, top));
        }

        if (m != control_char)
        {
            operands.push_back(m);
        }
    };

    for(const auto& m : mstr)
    {
        if (m == '(')
        {
            operands.push_back(m);
        }
        else if (m == ')')
        {
            char top = '_';

            while(top != '(' && operands.size() > 0)
            {
                if (operands.size() == 0)
                {
                    return "ERR";
                }

                top = operands.back();
                operands.pop_back();

                if(top != '(')
                {
                    mstack.push_back(std::string(1, top));
                }
            }
        }
        else if (is_operand(m))
        {
            handle_operand(m);
        }
        else
        {
            mstack.push_back(std::string(1, m));
        }
    }

    handle_operand(control_char);

    std::string retstr("");

    while(mstack.size() > 0)
    {
        const auto& top = mstack.back();
        mstack.pop_back();
        retstr += top;
    }

    return std::string(retstr.rbegin(), retstr.rend());
}

int main()
{
    const auto ret = shunting_yard("(3-2)*4+5");
    std::cout << "ret: " << ret << "\n";
    return 0;
}
