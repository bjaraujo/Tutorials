
#include <iostream>

using namespace std;

extern "C" int GetValueFromAsm();

int main()
{

	cout << "ASM said: " << GetValueFromAsm() << endl;

	return 0;

}