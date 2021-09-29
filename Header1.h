#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
using namespace std;

struct Node {
	string fio;
	int num;
};

class My_exception : public exception
{
private:
	char* s;
	char* t;
	void operator =(My_exception& e) {};
public:
	My_exception(const char* l) { s = new char[90]; strcpy_s(s, 90, l); };
	const char* what() { t = new char[strlen(s) + 1]; strcpy_s(t, strlen(s) + 1, s); return t; };
	~My_exception()
	{
		delete[] s;
		delete[] t;
	};
};

template<typename T>
class Queue {
private:
	virtual void Erase() = 0 {};
	virtual void Clone(const Queue&) = 0 {};
public:
	Queue() {}
	Queue(const Queue&);
	virtual ~Queue();
	virtual Queue& operator = (const Queue&);
	virtual void Push(T AInfo) = 0;
	virtual bool Pop() = 0;
	virtual T GetFirst() const = 0;
	virtual bool IsEmpty()const = 0;
	virtual unsigned GetSize() const = 0;
	virtual T& operator [] (unsigned) = 0;
	virtual const T& GetByIndex(unsigned) const = 0;
	virtual void Browse(void ItemWork(T)) const = 0;
	virtual void Browse(void ItemWork(T&)) = 0;
};
