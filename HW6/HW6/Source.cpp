#include <iostream>
#include <ctime>
#include <windows.h>

void Fiber(int amount, int** arr) {
    int len = 0;

    for (int i = 0; i < amount; ++i) {
        len = len + 10 - arr[i][1];
    }

	while (len != 0)
	{
		int* fb = new int[len];
		int num = 0;
		int pr = 10 - arr[num][1];
		for (int i = 0; i < len; ++i)
		{
			while (pr == 0)
			{
				num++;
				pr = 10 - arr[num][1];
			}
			fb[i] = num;
			pr--;
		}
		
		bool t = true;

		while (t)
		{
			int n = rand() % len;
			std::cout << " The process " << fb[n] + 1 << " is running." << std::endl;
			Sleep(1000);

			arr[fb[n]][0]--;
			if (arr[fb[n]][0] == 0)
			{
				std::cout << "PROCESS " << fb[n] + 1 << " IS FINISHED." << std::endl;
				len = len - 10 + arr[fb[n]][1];
				arr[fb[n]][1] = 10;
				t = false;
			}
		}
		delete[] fb;
	}
    
}

void test() {
    const int amount = 4;
    int** tasks = new int* [amount];

    for (int i = 0; i < amount; ++i) {
        tasks[i] = new int[2];
        tasks[i][0] = rand() % 20 + 1; // время выполнения 
        tasks[i][1] = rand() % 10 + 1 ; // приоритет задачи от 1 до 10 
    }

    Fiber(amount, tasks);

    for (int i = 0; i < amount; ++i) {
        delete[] tasks[i];
    }

    delete[] tasks;
}

int main() {
    srand(time(0));

    test();

    return EXIT_SUCCESS;
}
