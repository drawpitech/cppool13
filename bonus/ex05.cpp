#include <iostream>

#include "../SharedPointer.hpp"

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

int main(void)
{
    SharedPointer<Example> ptr1(new Example(1));
    SharedPointer<Example> ptr2(ptr1);
    SharedPointer<Example> ptr3;
    ptr1.reset();
    ptr3 = ptr2;
    ptr2 = new Example(2);
    ptr2.get()->method();
    ptr3->method();
    return 0;
}
