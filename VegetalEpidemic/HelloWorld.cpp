#include <iostream>

int main(){
#pragma omp parallel
	{
		printf("Hello world\n");
	}
	system("pause");
	return 0;
}