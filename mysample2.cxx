#include <iostream>

class A
{
     public:
         A( int a ): a(a) {}
         int a;
};

class B
{
     public:
         B(A &a) : a(a) {}
         A &a;
};

int main()
{
     B *b=NULL;
     {
         A a(5);
         b = new B(a);
     }
     std::cout<<b->a.a<<std::endl;
     delete(b);
}