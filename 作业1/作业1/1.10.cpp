#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            swap(arr[count++], arr[i]);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
	int* arr = new int[100];
	int n = 0;
	int count = 0;
    while (true)
    {
		cin >> n;
		if (n == -1)
			break;
		arr[count++] = n;
		
    }

	moveZeroes(arr, count);
	printArray(arr, count);
    return 0;
}