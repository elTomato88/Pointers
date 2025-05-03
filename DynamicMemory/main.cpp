#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Enter the length: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Enter additional value: "; cin >> value;
	//1) Создаем буферный массив нужного размера. 
	int* buffer = new int[n + 1];
	//2 копируем все содержимое исходного массива в буферный. 
	for (int i = 0; i < n;i++)
	{
		buffer[i] = arr[i];
	}
	//3/ Удаляем исходный массив
	delete[] arr;
	//4/ Подменяем адрес в указателе Arr адресом нового массива. 
	arr = buffer;
	//5 только после всего этого в конце массива появляется элемент, который можно сохранить добавляемое значение. 
	arr[n] = value;
	//6 после того как в массив добавился элемент, количество его элементов увеличивается на один
	n++;
	//7 Значение добавлено, проверяем результат
	Print(arr, n);

	delete[] arr;
	//Memory leak
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}