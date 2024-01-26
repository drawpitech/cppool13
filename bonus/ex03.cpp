#include <iostream>

#include "../UniquePointer.hpp"

class Example
{
   private:
    int _id;

   public:
    Example(int id) : _id(id)
    {
        std ::cout << "#" << _id << " construction\n";
    }
    ~Example()
    {
        std ::cout << "#" << _id << " destruction\n";
    }
    void method() const
    {
        std ::cout << "#" << _id << " method\n";
    }
};
int main()
{
    UniquePointer<Example> ptr1(new Example(1));
    UniquePointer<Example> ptr2(new Example(2));
    ptr1.reset();
    ptr2 = new Example(3);
    ptr2.get()->method();
    ptr2->method();
    return 0;
}
