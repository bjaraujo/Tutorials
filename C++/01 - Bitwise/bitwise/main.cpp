

#include <bitset>
#include <iostream>

void main()
{

	volatile unsigned int num1 = 8;              // 00001000
	volatile unsigned int num2 = 24;             // 00011000
	volatile unsigned int num3 = num1 & num2;
	volatile unsigned int num4 = num1 | num2;
	volatile unsigned int num5 = num1 ^ num2;
	volatile unsigned int num6 = ~num1;
	volatile unsigned int num7 = num1 << 2;
	volatile unsigned int num8 = num1 >> 2;

	std::cout << std::bitset<8>(num1) << " = " << num1 << std::endl;
	std::cout << std::bitset<8>(num2) << " = " << num2 << std::endl;
	std::cout << std::bitset<8>(num3) << " = " << num3 << std::endl;
	std::cout << std::bitset<8>(num4) << " = " << num4 << std::endl;
	std::cout << std::bitset<8>(num5) << " = " << num5 << std::endl;
	std::cout << std::bitset<8>(num6) << " = " << num6 << std::endl;
	std::cout << std::bitset<8>(num7) << " = " << num7 << std::endl;
	std::cout << std::bitset<8>(num8) << " = " << num8 << std::endl;

	std::cin.get();

}
