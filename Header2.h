#pragma once
#include "Header1.h"
#include <iostream>
#include <algorithm>
using namespace std;
template<typename T>
class LQueue : public Queue {
private:
	struct QItem {
		T info;
		QItem* next;
		QItem(T Ainfo) : info(Ainfo), next(NULL) {}
	};
	QItem *front, *rear;
	unsigned size;
	virtual void Erase();
	virtual void Clone(const Queue&);
public:
	LQueue() : front(NULL), rear(NULL), size(0) {};
	LQueue(const LQueue&);
	void SortQueue(LQueue &);
	virtual ~LQueue(); // только сообщение о вызове
	virtual void Push(T AInfo);
	virtual LQueue& operator = (const LQueue&);
	virtual bool Pop();
	virtual T GetFirst() const;
	virtual bool IsEmpty()const;
	virtual unsigned GetSize() const;
	virtual T& operator [] (unsigned);
	virtual const T& GetByIndex(unsigned) const;
	virtual void Browse(void ItemWork(T)) const;
	virtual void Browse(void ItemWork(T&));
};
