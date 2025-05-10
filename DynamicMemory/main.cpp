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


/*HomeWork*/

void ArithmeticPrint(int** arr, const int rows, const int cols);

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows, const int cols);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int index);

void push_col_back(int** arr, const int rows, int& cols);
int** push_col_front(int** arr, const int rows, int& cols);
int** insert_col(int** arr, const int rows, int& cols, int index);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);

int** pop_col_back(int** arr, const int rows, int& cols);
int** pop_col_front(int** arr, const int rows, int& cols);
int** erase_col(int** arr, const int rows, int& cols, int index);
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
	Print(arr, rows, cols);
	cout << "ArithmeticPrint: " << endl;
	ArithmeticPrint(arr, rows, cols);
	
	/*
	int** array_check = Allocate(rows, cols);
	FillRand(array_check, rows, cols);
	cout << "Checking Allocate: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check=push_row_front(array_check, rows, cols);
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
	array_check = erase_row(array_check, rows, cols,2);
	cout << "Checking erase: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = pop_col_back(array_check, rows, cols);
	cout << "Checking pop_col_back: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = pop_col_front(array_check, rows, cols);
	cout << "Checking pop_col_front: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	array_check = erase_col(array_check, rows, cols,3);
	cout << "Checking erase_col: " << endl;
	ArithmeticPrint(array_check, rows, cols);
	Clear(array_check, rows, cols);
	*/
	
	

	/*
	arr=push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	

	delete[] arr;
	*/
	
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




void ArithmeticPrint(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows*cols; i++)
	{
		cout << *arr[i];
		if (!i%cols) cout << endl;
	}
}
int** Allocate(const int rows, const int cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols] {};
	}
	return buffer;
}
void Clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	cout << "Удаление выделенной памяти завершено успешно"<<endl;
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
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [++rows];
	for (int i = 1; i < rows; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[]arr;
	buffer[0] = new int[cols] {};
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [++rows];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index+1; i < rows; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	buffer[index] = new int[cols] {};
	return buffer;
}

int** push_col_back(int** arr, const int rows, int& cols)
{
	
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1] {};
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
int** push_col_front(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0;i < rows; i++)
	{
		buffer[i] = new int[cols+1] {};
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
int** insert_col(int** arr, const int rows, int& cols, int index)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1] {};
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

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr[0];
	delete[]  arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows-1];
	for (int i = 0; i < index;i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index;i < rows - 1;i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr[index];
	delete[] arr;
	
	rows--;
	return buffer;
}

int** pop_col_back(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1];
		for (int j = 0; j < cols-1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	cols--;
	
	return buffer;
}
int** pop_col_front(int** arr, const int rows, int& cols)
{
	--cols;
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}
int** erase_col(int** arr, const int rows, int& cols, int index)
{
	cols--;
	int** buffer = new int* [rows];
	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols];
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index;j < cols;j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
		delete[]arr[i];
	}
	delete[] arr;
	return buffer;
}

