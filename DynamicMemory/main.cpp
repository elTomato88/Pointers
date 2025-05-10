#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------\n"
//#define DYNAMIC_MEMORY_1

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value, const int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);


int** push_row_back(int** arr, int& rows, const int cols);



void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1

 

	int n;
	cout << "Enter the length: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	int value;
	int index;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	
	cout << "Enter additional value: "; cin >> value;
	
	arr=push_back(arr, n, value);
	//7 Значение добавлено, проверяем результат
	Print(arr, n);

	
	

	cout << "Enter additional value: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	
	cout << "Enter additional value: "; cin >> value;
	
	cout << "Enter index: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	
	arr=pop_back(arr, n);
	Print(arr, n);
	
	arr = pop_front(arr, n);
	Print(arr, n);
	
	cout << "Enter index: "; cin >> index;
	arr = erase(arr, n, index);
	
	Print(arr, n);
	delete[] arr; //Memory leak
#endif
	int rows;
	int cols;
	cout << "Enter rows: "; cin >> rows;
	cout << "Enter cols: "; cin >> cols;
	
	int** arr = new int* [rows];
	for (int i = 0;i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	
	FillRand(arr, rows, cols);
	arr=push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[] arr;
	
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << delimeter;
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		
		cout << endl;
	}
	cout << delimeter;
}

int* push_back(int arr[], int& n, const int value)
{
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
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];

	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	
	for (int i = index+1; i < n+1; i++)
	{
		buffer[i] = arr[i-1];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i<n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1;i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	
	n--;
	return arr;
}
int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index;i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n-1;i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1/ создаем буферный массив указателей нужного размера. 
	int** buffer = new int* [rows + 1];
	//2/ Копируем адрес строк в буферный массив указателей. 
	for (int i = 0;i < rows;i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив
	delete[] arr;
	//4) Создаем добавляемую строку и записываем адрес в массив указателей. 
	
	buffer[rows] = new int[cols] {};
	//5) При добавлении в массив строки, количество его строк увеличивается на 1
	rows++;
	//6) возвращаем новый массив на место вызоваж
	return buffer;


}