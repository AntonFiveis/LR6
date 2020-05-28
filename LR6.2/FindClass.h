#pragma once
#include "Tree.h"
#include "dateTime.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

template<class T>
class FindClass
{
private:
	vector<T> arr;
	int size;
	Tree<T>* tree;
public:
	FindClass(vector<T>);
	FindClass(int size);
	vector<T> getArr() { return arr; }
	int findByValue(T);
	T operator[](int index) { return arr[index]; }
	static void sort(vector<T>&,int,int);
};

template<class T>
FindClass<T>::FindClass(vector<T> arr) :arr(arr), size(arr.size()) {
	tree = new Tree<T>();
	for (int i = 0; i < arr.size();i++) {
		tree->addToTree(arr[i],i);
	}
}
template<>
FindClass<string>::FindClass(int size) :size(size) {
	tree = new Tree<string>();
	for (int i = 0; i < size; i++) {
		string str = std::to_string(rand() % 1000);
		tree->addToTree(str,arr.size());
		arr.push_back(str);
	}
}

template<class T>
int FindClass<T>::findByValue(T value)
{
	return tree->findByValue(value);
}

template<>
int FindClass<dateTime>::findByValue(dateTime value) {
	int i = arr.size() / 2;
	int hi = arr.size() - 1;
	int lo = 0;
	while (!(arr[i] == value)&& lo<hi) {
		if (arr[i] > value) {
			lo = i;
		}
		else {
			hi = i;
		}
		i = (lo + hi) / 2;
	}
	if (arr[i] == value) {
		return i;
	}
	else {
		return -1;
	}
}

template<class T>
void FindClass<T>::sort(vector<T>& a,int lo, int hi)
{
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;
	sort(a, lo, mid);
	sort(a, mid + 1, hi);
	vector<T> buf(a.size());

	for (int k = lo; k <= hi; k++)
		buf[k] = a[k];

	int i = lo, j = mid +1;
	for (int k = lo; k <= hi; k++) {

		if (i > mid) {
			a[k] = buf[j];
			j++;
		}
		else if (j > hi) {
			a[k] = buf[i];
			i++;
		}
		else if (buf[j] < buf[i]) {
			a[k] = buf[j];
			j++;
		}
		else {
			a[k] = buf[i];
			i++;
		}
	}
}
template<>
FindClass<int>::FindClass(int size) :size(size) {
	tree = new Tree<int>();
	for (int i = 0; i < size; i++) {
		int number = rand() % 100;
		tree->addToTree(number,arr.size());
		arr.push_back(number);
	}
}
template<>
FindClass<double>::FindClass(int size) :size(size) {
	tree = new Tree<double>();
	for (int i = 0; i < size; i++) {
		double number = double(rand() % 1000) / 10;

		tree->addToTree(number,arr.size());
		arr.push_back(number);
	}
}
template<>
FindClass< char*>::FindClass(int size) :size(size) {
	tree = new Tree< char*>();
	for (int i = 0; i < size; i++) {
		char* a = new char[4];
		for (int j = 0; j < 3; j++) {
			a[j] = rand() % 10+'0';
		}
		a[3] = '\0';
		tree->addToTree(a,i);
		arr.push_back(a);
		//std::cout << arr[i];
	}
	
}

template<>
FindClass<dateTime>::FindClass(vector<dateTime> v) :arr(v) {
	//tree = new Tree<dateTime>();
	sort(arr,0,arr.size()-1);
	//for (int i = 0; i < arr.size(); i++) {
	//	std::cout << arr[i].getDate() << arr[i].getTime() << std::endl;
	//}
}

