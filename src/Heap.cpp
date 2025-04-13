#include <iostream>
#include <vector>

class Heap
{
  public:
    Heap() : min_heap(true)
    {
    }

    void push(const int d);
    int pop();
    void print();
    bool empty();

  protected:
    void heapify_down();
    void heapify_up();

    int get_parent(int c_idx);
    int get_left_child(int c_idx);
    int get_right_child(int c_idx);

    bool has_parent(int c_idx);
    bool has_left_child(int c_idx);
    bool has_right_child(int c_idx);

  private:
    std::vector<int> items;
    bool min_heap;
};

bool Heap::empty()
{
    return items.size() == 0;
}

void Heap::print()
{
    for (const auto &i : items)
    {
        std::cout << i << " ";
    }
    puts("");
}

int Heap::get_parent(int c_idx)
{
    if (c_idx < 1)
        return -1;
    const int pidx = c_idx / 2;
    return pidx < 0 ? -1 : pidx;
}

int Heap::get_left_child(int c_idx)
{
    const int lc_idx = 2 * c_idx;
    return lc_idx >= static_cast<int>(items.size()) ? -1 : lc_idx;
}

int Heap::get_right_child(int c_idx)
{
    const int lc_idx = get_left_child(c_idx);
    if (lc_idx == -1)
        return -1;
    return (lc_idx + 1) >= static_cast<int>(items.size()) ? -1 : (lc_idx + 1);
}

bool Heap::has_parent(int c_idx)
{
    return get_parent(c_idx) != -1;
}

bool Heap::has_left_child(int c_idx)
{
    return get_left_child(c_idx) != -1;
}

bool Heap::has_right_child(int c_idx)
{
    return get_right_child(c_idx) != -1;
}

void Heap::push(const int d)
{
    if (min_heap)
    {
        items.insert(items.begin(), d);
        heapify_down();
        return;
    }

    items.push_back(d);
    heapify_up();
}

int Heap::pop()
{
    if (empty())
    {
        return -1;
    }

    const auto itm = items.front();
    items.erase(items.begin());

    if (min_heap)
    {
        heapify_down();
    }
    else
    {
        heapify_up();
    }

    return itm;
}

void Heap::heapify_up()
{
    if (items.size() < 2)
        return;

    int idx = items.size() - 1;
    int p_idx = -1;

    while (has_parent(idx))
    {
        p_idx = get_parent(idx);

        if (items.at(p_idx) >= items.at(idx))
            break;

        std::swap(items.at(p_idx), items.at(idx));

        idx = p_idx;
    }
}

void Heap::heapify_down()
{
    if (items.size() < 2)
        return;

    int idx = 0;
    int left = -1;
    int right = -1;

    while (has_left_child(idx))
    {
        left = get_left_child(idx);

        if (items.at(left) >= items.at(idx))
            break;

        std::swap(items.at(left), items.at(idx));

        idx = left;
        left = get_left_child(idx);
        right = get_right_child(idx);
    }

    while (has_right_child(idx))
    {
        right = get_right_child(idx);

        if (items.at(right) >= items.at(idx))
            break;

        std::swap(items.at(right), items.at(idx));

        idx = right;
        left = get_left_child(idx);
        right = get_right_child(idx);
    }
}

int main()
{
    Heap hp;

    hp.push(5);
    hp.print();

    hp.push(3);
    hp.print();

    hp.push(1);
    hp.print();

    hp.push(2);
    hp.print();

    hp.push(4);
    hp.print();

    while (hp.empty() == false)
    {
        std::cout << "Item: " << hp.pop() << "\n";
    }
    puts("");

    return 0;
}
