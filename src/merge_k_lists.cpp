#include <iostream>
#include <list>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

class Tree
{
  public:
    Tree() : root(nullptr)
    {
    }
    virtual ~Tree()
    {
    }

    void add(int k);
    std::list<int> extract();

  protected:
    void add_help(TreeNode *&rt, int k);
    void extract_help(std::list<int> &mlist, TreeNode *rt);

  private:
    TreeNode *root;
};

void Tree::add_help(TreeNode *&rt, int k)
{
    if (rt == nullptr)
    {
        rt = new TreeNode(k);
        return;
    }

    if (k < rt->val)
    {
        add_help(rt->left, k);
    }
    else
    {
        add_help(rt->right, k);
    }
}

void Tree::add(int k)
{
    add_help(root, k);
}

void Tree::extract_help(std::list<int> &mlist, TreeNode *rt)
{
    if (rt == nullptr)
    {
        return;
    }

    extract_help(mlist, rt->left);

    mlist.push_back(rt->val);

    extract_help(mlist, rt->right);
}

std::list<int> Tree::extract()
{
    std::list<int> items;
    extract_help(items, root);
    return items;
}

ListNode *merge_k_lists(std::vector<ListNode *> &lists)
{
    ListNode *nhead = nullptr;
    Tree tree;

    const auto xtraverse = [&tree](ListNode *head)
    {
        auto h = head;

        while (h != nullptr)
        {
            tree.add(h->val);
            h = h->next;
        }
    };

    for (const auto &xhead : lists)
    {
        xtraverse(xhead);
    }

    auto nh = nhead;
    auto prev = nh;
    for (const auto &i : tree.extract())
    {
        std::cout << i << " ";

        if (nh == nullptr)
        {
            nh = new ListNode(i);
            nhead = nh;
            prev = nh;
            continue;
        }

        auto xnode = new ListNode(i);

        prev = nh;
        nh = xnode;
        prev->next = nh;
    }

    std::cout << "\n";

    return nhead;
}

void traverse(ListNode *head)
{
    auto h = head;

    while (h != nullptr)
    {
        std::cout << h->val << " ";
        h = h->next;
    }

    std::cout << "\n";
}

void deallocate(ListNode *&head)
{
    auto h = head;

    while (h != nullptr)
    {
        auto tmp = h->next;

        if (h)
        {
            delete h;
        }

        h = nullptr;
        h = tmp;
    }
}

inline void app()
{
    ListNode *head1 = new ListNode(1);
    ListNode *head2 = new ListNode(1);
    ListNode *head3 = new ListNode(2);

    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    head3->next = new ListNode(6);

    std::vector<ListNode *> mpointers{head1, head2, head3};
    auto nhead = merge_k_lists(mpointers);

    traverse(nhead);

    deallocate(head1);
    deallocate(head2);
    deallocate(head3);
    deallocate(nhead);
}

int main()
{
    app();
    return 0;
}
