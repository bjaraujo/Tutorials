
#include <iostream>

class B
{
public:
	virtual void f(short) { std::cout << "B::f" << std::endl; }
};

class D : public B
{
public:
	virtual void f(int) override { std::cout << "D::f" << std::endl; }
};

int main()
{


}