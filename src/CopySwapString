#include <iostream>
#include <memory>

class mystring
{
 public:
    mystring() : data(nullptr), length(0) { clean(); }
    mystring(const char* md, const size_t ml) : mystring()
    {
        length = ml;

        if (length == 0) return;

        data = new char[length];

        std::copy(md, md + length, data);
    }
    mystring(const mystring& other) : mystring(other.data, other.length) {}
    mystring(mystring&& other) : mystring() { swap(*this, other); }

    virtual ~mystring()
    {
        clean();
    }

    void print()
    {
        std::cout << std::string(data, length) << std::endl;
    }

    size_t size() const { return length; }

    mystring& operator=(mystring other)
    {
        swap(*this, other);
        return *this;
    }

    friend void swap(mystring& first, mystring& second)
    {
        std::swap(first.data, second.data);
        std::swap(first.length, second.length);
    }

 protected:
    void clean()
    {
        if (data)
        {
            delete[] data;
            data = nullptr;
        }

        length = 0;
    }

 private:
    char* data;
    size_t length;
};

int main()
{
    mystring mstring = mystring("asdf", 4);

    std::cout << "mstring.size " << mstring.size() << "\n";
    mstring.print();

    return 0;
}
