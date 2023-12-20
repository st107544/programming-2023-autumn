#include <iostream>

struct MinMem
{
	char e[42]{};  //1*42 байт
	
	bool h;        //1 байт
	bool g;		   //1 байт
	double c;      //8 байт
	double d;	   //8 байт
	int f[2]{ 0 }; //4*2 байт
	int b;         //4 байт
	int a;         //4 байт

};


int main(int argc, char* argv[])
{
	std::cout << sizeof(MinMem) << std::endl;

	return EXIT_SUCCESS;
}