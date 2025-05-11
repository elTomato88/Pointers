#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------\n"
//#define DYNAMIC_MEMORY_1
#define HOMEWORK

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* insert(T arr[], int& n, const T value=0, int index=0);
template<typename T>T* erase(T arr[], int& n, int index=0);

template<typename T>void ArithmeticPrint(T** arr, const int rows, const int cols);
template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index=0);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index = 0);


template<typename T>void insert_col(T** arr, const int rows, int& cols, int index=0);
template<typename T>void erase_col(T** arr, const int rows, int& cols, int index=0);



void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1



	int n;
	cout << "Enter the length: "; cin >> n;
	
	int value;
	int index;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

	cout << "Enter additional value: "; cin >> value;

	arr = push_back(arr, n, value);
	//7 Значение добавлено, проверяем результат
	Print(arr, n);




	cout << "Enter additional value: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Enter additional value: "; cin >> value;

	cout << "Enter index: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Enter index: "; cin >> index;
	arr = erase(arr, n, index);

	Print(arr, n);
	delete[] arr; //Memory leak
#endif
#ifdef HOMEWORK
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** argentum = Allocate<int>(rows, cols);
	FillRand(argentum, rows, cols);
	Print(argentum, rows, cols);
	argentum = erase_row(argentum, rows, cols, 25);
	Print(argentum, rows, cols);
	insert_col(argentum, rows, cols,35);
	Print(argentum, rows, cols);
	erase_col(argentum, rows, cols,150);
	Print(argentum, rows, cols);
	Clear(argentum, rows);

	
	
#endif
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

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << delimeter;
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* insert(T arr[], int& n,  const T value, int index)
{
	if (index < 0)index = 0;
	if (index >= n)index = n;
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index + 1; i < n + 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
template<typename T>T* erase(T arr[], int& n, int index)
{
	if (index < 0)index = 0;
	if (index >= n)index = n - 1;
	T* buffer = new T[n - 1];
	for (int i = 0; i < index;i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n - 1;i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}


template<typename T>void ArithmeticPrint(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0;j < cols; j++)
		{
			cout << *(*(arr + i) + j) << tab;
		}
		cout << endl;
	}
	cout << delimeter;
}
template<typename T>T** Allocate(const int rows, const int cols)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols] {};
	}
	return buffer;
}
template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	cout << "Удаление выделенной памяти завершено успешно" << endl;
}


template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	return insert(arr, rows, new T[cols]{}, index);
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
	if (index < 0)index = 0;
	if (index >= rows)index = rows - 1;
	delete[]arr[index];
	return erase(arr, rows, index);
}


template<typename T>void insert_col(T** arr, const int rows, int& cols, int index)
{
	if (index < 0)index = 0;
	if (index >= cols)index = cols;
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j] = arr[i][j-1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	
}
template<typename T>void erase_col(T** arr, const int rows, int& cols, int index)
{
	cols--;
	if (index < 0)index = 0;
	if (index >= cols)index = cols;
	T** buffer = new T* [rows];
	for (int i = 0; i < rows;i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	
	
}

