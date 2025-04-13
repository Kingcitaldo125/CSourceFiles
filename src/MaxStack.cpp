#include <functional>
#include <iostream>
#include <queue>
#include <vector>

template <class T> struct MaxStack
{
    using PQueue_max_T = std::priority_queue<T, std::vector<T>, std::less<T>>;
    using PQueue_T = std::priority_queue<T, std::vector<T>, std::not_equal_to<T>>;

    void Push(T x);
    T Pop();
    T PopMax();
    T Top();
    T Max();

    PQueue_max_T max_q;
    PQueue_T q;
};

template <class T> void MaxStack<T>::Push(T x)
{
    q.push(x);
    max_q.push(x);
}

template <class T> T MaxStack<T>::Pop()
{
    T t = Top();
    q.pop();

    return t;
}

template <class T> T MaxStack<T>::PopMax()
{
    T t = Max();
    max_q.pop();

    PQueue_T q2;

    while (!q.empty())
    {
        const auto itm = Pop();

        if (itm != t)
            q2.push(std::move(itm));
    }

    q.swap(q2);

    return t;
}

template <class T> T MaxStack<T>::Top()
{
    return q.top();
}

template <class T> T MaxStack<T>::Max()
{
    return max_q.top();
}

inline void app()
{
    MaxStack<int> mstack;

    mstack.Push(3);
    mstack.Push(1);
    mstack.Push(4);
    mstack.Push(2);

    std::cout << mstack.PopMax() << "\n";
    std::cout << mstack.PopMax() << "\n";

    std::cout << "Max: " << mstack.Max() << "\n";

    std::cout << mstack.Pop() << "\n";
    std::cout << mstack.Top() << "\n";
}

int main()
{
    app();

    return 0;
}
