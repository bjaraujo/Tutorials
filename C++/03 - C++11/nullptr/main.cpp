
#include <map>
#include <vector>
#include <string>
#include <memory>

void foo(int* p) {}

void bar(std::shared_ptr<int> p) {}

int main()
{

	int* p1 = NULL;
	int* p2 = nullptr;
	if (p1 == p2)
	{
	}

	foo(nullptr);
	bar(nullptr);

	bool f = nullptr;
	int i = 0;


}