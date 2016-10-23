#include <map>
#include <vector>
#include <string>
#include <iostream>

int main()
{

	std::map<std::string, std::vector<int> > map;
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	map["one"] = v; // copy

	v.push_back(4);
	v.push_back(5);
	map["second"] = v; //copy

	for (const auto& kvp : map)
	{
		std::cout << kvp.first << std::endl;

		for (auto v : kvp.second)
		{
			std::cout << v << std::endl;
		}
	}

	int arr[] = { 1, 2, 3, 4, 5 };
	for (int& e : arr)
	{
		e = e*e;
	}

}
