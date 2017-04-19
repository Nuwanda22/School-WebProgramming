// Cplusplus.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

template <typename T>
class node {
public:
	T value;
	node *next = nullptr;
};

template <typename T>
class list {
	node<T> *head;
	node<T> *tail;
	node<T> *cur;
	int count;

public:
	list() {
		head = nullptr;
		tail = nullptr;
		cur = nullptr;
		count = 0;
	}

	void add(T item) {
		node<T> *newNode = new node<T>;
		newNode->next = nullptr;
		newNode->value = item;

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			node<T> *temp = head;
			while (temp != nullptr)
			{
				if (temp->next == nullptr)
				{
					temp->next = newNode;
					break;
				}
				temp = temp->next;
			}
		}
	}

	void print() {
		node<T> *cur = head;
		while (true) {
			std::cout << cur->value << std::endl;
			cur = cur->next;
			if (cur == nullptr) break;
		}
	}
};

int main()
{
	list<int> integers;
	integers.add(1);
	integers.add(2);
	integers.add(10);
	integers.print();

	list<char *> strings;
	strings.add("Hello");
	strings.add("Template");
	strings.add("World!");
	strings.print();
}