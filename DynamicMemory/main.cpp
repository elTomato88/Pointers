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

template<typename T>T* push_back(T arr[], int& n, const int value);
template<typename T>T* push_front(T arr[], int& n, const int value);
template<typename T>T* insert(T arr[], int& n, const T value, const int index);
template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);
template<typename T>T* erase(T arr[], int& n, const int index);


/*HomeWork*/

template<typename T>void ArithmeticPrint(T** arr, const int rows, const int cols);
template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index);

template<typename T>T** push_col_back(T** arr, const int rows, int& cols);
template<typename T>T** push_col_front(T** arr, const int rows, int& cols);
template<typename T>T** insert_col(T** arr, const int rows, int& cols, int index);

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index);

template<typename T>T** pop_col_back(T** arr, const int rows, int& cols);
template<typename T>T** pop_col_front(T** arr, const int rows, int& cols);
template<typename T>T** erase_col(T** arr, const int rows, int& cols, int index);
/*EndOfHomeWork*/


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
	Print(arr, rows, cols);
	cout << "ArithmeticPrint: " << endl;
	ArithmeticPrint(arr, rows, cols);

	int** array_check = Allocate<int>(rows, cols);
	FillRand(array_check, rows, cols);
	cout << "Checking Allocate: " << endl;
	ArithmeticPrint(array_check, rows, cols);


	array_check = push_row_front(array_check, rows, cols);
	cout << "Checking push_row_front: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = insert_row(array_check, rows, cols, 1);
	cout << "Checking insert_row (1st index): " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = push_col_back(array_check, rows, cols);
	cout << "Checking push_col_back: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = push_col_front(array_check, rows, cols);
	cout << "Checking push_col_front: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = insert_col(array_check, rows, cols, 2);
	cout << "Checking insert_col: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	FillRand(array_check, rows, cols);
	cout << "Checking pop_row_back: " << endl;
	array_check = pop_row_back(array_check, rows, cols);
	ArithmeticPrint(array_check, rows, cols);
	array_check = pop_row_front(array_check, rows, cols);
	cout << "Checking pop_row_front: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = erase_row(array_check, rows, cols, 2);
	cout << "Checking erase: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = pop_col_back(array_check, rows, cols);
	cout << "Checking pop_col_back: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = pop_col_front(array_check, rows, cols);
	cout << "Checking pop_col_front: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = erase_col(array_check, rows, cols, 3);
	cout << "Checking erase_col: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	Clear(array_check, rows);



	
	arr=push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}


	delete[] arr;
	
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

template<typename T>T* push_back(T arr[], int& n, const int value)
{
	//1) Создаем буферный массив нужного размера. 
	T* buffer = new T[n + 1];
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
template<typename T>T* push_front(T arr[], int& n, const int value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];

	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>T* insert(T arr[], int& n, const T value, const int index)
{
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
template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1;i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;

	n--;
	return arr;
}
template<typename T>T* erase(T arr[], int& n, const int index)
{
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

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	//1/ создаем буферный массив указателей нужного размера. 
	T** buffer = new T* [rows + 1];
	//2/ Копируем адрес строк в буферный массив указателей. 
	for (int i = 0;i < rows;i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив
	delete[] arr;
	//4) Создаем добавляемую строку и записываем адрес в массив указателей. 

	buffer[rows] = new T[cols] {};
	//5) При добавлении в массив строки, количество его строк увеличивается на 1
	rows++;
	//6) возвращаем новый массив на место вызоваж
	return buffer;


}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [++rows];
	for (int i = 1; i < rows; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[]arr;
	buffer[0] = new T[cols] {};
	return buffer;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [++rows];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < rows; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	buffer[index] = new T[cols] {};
	return buffer;
}

template<typename T>T** push_col_back(T** arr, const int rows, int& cols) // Наверное правильнее сделать через void и манипуляцию с исходным массивом
{

	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[]arr[i];
	}
	delete[]arr;
	cols++;
	return buffer;

}
template<typename T>T** push_col_front(T** arr, const int rows, int& cols)
{
	T** buffer = new T* [rows];
	for (int i = 0;i < rows; i++)
	{
		buffer[i] = new T[cols + 1] {};
		for (int j = 1; j < cols; j++)
		{
			buffer[i][j] = arr[i][j - 1];
		}
		delete[]arr[i];
	}
	cols++;
	delete[]arr;
	return buffer;
}
template<typename T>T** insert_col(T** arr, const int rows, int& cols, int index)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols + 1] {};
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index + 1; j < cols + 1; j++)
		{
			buffer[i][j] = arr[i][j - 1];
		}
		buffer[i][index] = 0;
		delete[] arr[i];
	}
	cols++;
	delete[] arr;
	return buffer;

}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[]  arr;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < index;i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index;i < rows - 1;i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[index];
	delete[] arr;

	rows--;
	return buffer;
}

template<typename T>T** pop_col_back(T** arr, const int rows, int& cols)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	cols--;

	return buffer;
}
template<typename T>T** pop_col_front(T** arr, const int rows, int& cols)
{
	--cols;
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols];
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}
template<typename T>T** erase_col(T** arr, const int rows, int& cols, int index)
{
	cols--;
	T** buffer = new T* [rows];
	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new T[cols];
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index;j < cols;j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[]arr[i];
	}
	delete[] arr;
	return buffer;
}

