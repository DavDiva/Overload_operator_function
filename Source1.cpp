#include <iostream>
using namespace std;

class MyClass
{
private:
	int size;
	int* pointer_data;
public:

	MyClass(int size)//constructor with arguments
	{
		this->size = size;
		this->pointer_data = new int[size];
		for (int i = 0; i < size; i++)
		{
			pointer_data[i] = i + 1;
		}
		cout << "Constructor called " << this << endl;
	}
	MyClass(const MyClass& other)//Copy constructor
	{
		this->size = other.size;
		this->pointer_data = new int[other.size];
		for (int i = 0; i < size; i++)
		{
			this->pointer_data[i] = other.pointer_data[i];
		}
		cout << "Copy Constructor called " << this << endl;

	}
	MyClass& operator = (const MyClass& other)//Overload operator function
	{
		this->size = other.size;
		if (this->pointer_data != nullptr)
		{
			delete[] this->pointer_data;
		}
		this->pointer_data = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->pointer_data[i] = other.pointer_data[i];
		}
		cout << "Function Operator = Overload called." << endl;

		return *this;

	}
	~MyClass()
	{
		delete[] pointer_data;
		cout << "Destructor called " << this << endl;
	}
	void GetData()
	{
		for (int i = 0; i < size; i++)
		{
			cout << pointer_data[i] << endl;
		}
	}
};



int main()
{
	MyClass a(10);
	/*MyClass b(a);*/
	MyClass b(3);
	MyClass c(6);
	cout << "Array a: " << endl;
	a.GetData();
	cout << "Array b: " << endl;
	b.GetData();
	cout << "Array c: " << endl;
	c.GetData();
	a = b = c;
	cout << "__________________________" << endl;
	cout << "Array a: " << endl;
	a.GetData();
	cout << "Array b: " << endl;
	b.GetData();
	cout << "Array c: " << endl;
	c.GetData();
	return 0;
}
