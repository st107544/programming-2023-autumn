#include <iostream>

struct MinMem
{
	char e[42]{};  //1*42 ����
	
	bool h;        //1 ����
	bool g;		   //1 ����
	double c;      //8 ����
	double d;	   //8 ����
	int f[2]{ 0 }; //4*2 ����
	int b;         //4 ����
	int a;         //4 ����

};


int main(int argc, char* argv[])
{
	std::cout << sizeof(MinMem) << std::endl;

	return EXIT_SUCCESS;
}