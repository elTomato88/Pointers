#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Pointers" << endl;
	int a = 2;
	int* pa = &a;
	cout << a<<endl;//вывод переменной
	cout << &a << endl; //вывод адреса переменной
	cout << pa << endl; // вывод адреса из указателя
	cout << *pa << endl; // вывод значения переменной из указателя.
	
	return 0;
}