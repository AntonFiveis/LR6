#pragma once
#include <iostream>

template <class T>
class Tree
{
public:
	class Node {
	private:
		T value;
		int index;
		Node* right;
		Node* left;
	public:
		Node(T,int);
		void addRightChild(T,int);
		void addLeftChild(T,int);
		int getIndex() { return index; }
		Node* getRightChild() { return right; }
		Node* getLeftChild() { return left; }
		T getValue() { return value; };
	};
	Node* root;
	Tree(T);
	Tree();
	void addToTree(T,int);
	int findByValue(T);
};

template <class T>
Tree<T>::Tree(T value) {
	root = new Node(value,0);
}

template<class T>
Tree<T>::Tree()
{
	root = nullptr;
}

template<class T>
void Tree<T>::addToTree(T value,int index)
{
	Node* temp = root;
	if (temp == nullptr) {
		root = new Node(value,0);
	}
	else {
		while (true) {
			if (temp->getValue() > value) {
				if (temp->getRightChild() == nullptr) {
					temp->addRightChild(value,index);
					break;
				}
				else {
					temp = temp->getRightChild();
				}
			}
			else {
				if (temp->getLeftChild() == nullptr) {
					temp->addLeftChild(value,index);
					break;
				}
				else {
					temp = temp->getLeftChild();
				}
			}
		}
	}
}

template<class T>
int Tree<T>::findByValue(T value)
{
	Node* temp = root;
	if (temp == nullptr)
		return -1;
	while (true) {
		if (temp->getValue() > value) {
			if (temp->getRightChild() == nullptr) {
				return -1;
			}
			else {
				temp = temp->getRightChild();
			}
		}
		else if (temp->getValue() < value) {
			if (temp->getLeftChild() == nullptr) {
				return -1;
			}
			else {
				temp = temp->getLeftChild();
			}
		}
		else {
			return temp->getIndex();
		}
	}
}

template<class T>
Tree<T>::Node::Node(T value,int index) :value(value),index(index)
{
	right = left = nullptr;
}

template<class T>
void Tree<T>::Node::addRightChild(T value,int index)
{
	right = new Node(value,index);
}

template<class T>
void Tree<T>::Node::addLeftChild(T value,int index)
{
	left = new Node(value,index);
}

