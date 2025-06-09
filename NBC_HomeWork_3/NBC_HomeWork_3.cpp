#include<iostream>
#include<algorithm>

template <typename T>
class simpleVector
{
public:
	T* arr;
	int currentSize;
	int currentCapacity;

	simpleVector()
	{
		arr = new T[10];
		currentSize = 0;
		currentCapacity = 10;
	}

	simpleVector(int a)
	{
		arr = new T[a];
		currentSize = 0;
		currentCapacity = a;
	}

	~simpleVector()
	{
		delete[] arr;
	}

	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			std::size_t newCap = currentCapacity + 5;
			T* newArr = new T[newCap];
			std::copy(arr, arr + currentSize, newArr);
			delete[] arr;
			arr = newArr;
			currentCapacity = newCap;
		}
		arr[currentSize++] = value;
	}

	void pop_back()
	{
		if (currentSize > 0)
		{
			arr[currentSize-1] = 0;
			currentSize--;
		}
	}

	int size()
	{
		return currentSize;
	}

	int capacity()
	{
		return currentCapacity;
	}

	void resize(std::size_t newCap) {
		if (newCap > currentCapacity) {
			T* newArr = new T[newCap];
			std::copy(arr, arr + currentSize, newArr);
			delete[] arr;
			arr = newArr;
			currentCapacity = newCap;
		}
	}

	void sortData() {
		std::sort(arr, arr + currentSize);
	}
};

int main()
{
	simpleVector<int> sv;

	sv.push_back(7);
	sv.push_back(8);
	std::cout << sv.arr[0] << sv.arr[1];
	sv.pop_back();
	std::cout << sv.arr[0] << sv.arr[1];
	sv.push_back(4);
	sv.sortData();
	std::cout << sv.arr[0] << sv.arr[1];
	
}