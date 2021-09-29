#include "pch.h"
#include "Header2.h"
#include <iostream>
using namespace std;

LQueue& LQueue::operator = (const LQueue& Q)
{
	if (typeid(Q) != typeid(*this))
		throw My_exception("Different types");

	if (this != &Q) {
		Erase();
		Clone(Q);
	}
	return *this;
}

void LQueue::Erase()
{
	while (!this->IsEmpty())
		this->Pop();
}

void LQueue::Clone(const Queue& Q)
{
	if (typeid(Q) != typeid(*this))
		throw My_exception("Different types");
	const LQueue* Qu = (const LQueue*)&Q;
	front = NULL;
	rear = NULL;
	size = 0;
	QItem* tmp = Qu->front;
	for (unsigned int i = 0; i < Qu->size; ++i)
	{
		Push(tmp->info);
		tmp = tmp->next;
		size++;
	}

}

LQueue::LQueue(const LQueue& Q)
{
	front = NULL;
	rear = NULL;
	size = 0;
	Clone(Q);
}

void LQueue::SortQueue(LQueue & Q)
{
	for (unsigned int i = 0; i < Q.size; ++i)
	{
		for (unsigned int j = i + 1; j < Q.size; ++j)
		{
			if (Q[i].fio > Q[j].fio)
			{
				Node tmp = Q[i];
				Q[i] = Q[j];
				Q[j] = tmp;
			}
		}
	}
}

LQueue::~LQueue()
{
	cout << "LQueue deleted.\n";
}
template<typename T>

void LQueue::Push(T AInfo)
{
	QItem* e = new QItem(AInfo);
	if (size > 0) {
		rear->next = e;
	}
	else {
		front = e;
		front->next = rear;
	}
	rear = e;
	++size;
}

bool LQueue::Pop()
{
	if (this->IsEmpty())
		return false;
	QItem* tmp = front;
	front = front->next;
	delete tmp;
	--size;
	if (size == 0)
		rear = NULL;
	return true;

}

T LQueue::GetFirst() const
{
	if (this->IsEmpty())
		throw "Queue is empty";
	return front->info;

}

bool LQueue::IsEmpty()const
{
	return (!front);
}

unsigned LQueue::GetSize() const
{
	size_t cnt = 0u;
	const QItem* iter = front;
	do {
		cnt++;
		iter = iter->next;
	} while (iter != rear->next);
	return cnt;
}

T& LQueue::operator [] (unsigned u)
{
	if (u > size)
		throw My_exception("Too big [index]\n");
	size_t cnt = 0u;
	QItem* iter = front;
	while (cnt != u)
	{
		cnt++;
		iter = iter->next;
	}
	return iter->info;

}

const T& LQueue::GetByIndex(unsigned u) const
{
	if (u > size)
		throw My_exception("Too big index\n");
	size_t cnt = 0u;
	QItem* iter = front;
	while (cnt != u)
	{
		cnt++;
		iter = iter->next;
	}
	return iter->info;
}

void LQueue::Browse(void ItemWork(T)) const
{
	if (this->IsEmpty())
		throw My_exception("Queue is empty");
	QItem* temp = front;
	while (temp != rear)
	{
		ItemWork(temp->info);
		temp = temp->next;
	}
	ItemWork(temp->info);
}
void LQueue::Browse(void ItemWork(T&))
{
	if (this->IsEmpty())
		throw My_exception("Queue is empty");
	QItem* temp = front;
	while (temp != rear)
	{
		ItemWork(temp->info);
		temp = temp->next;
	}
	ItemWork(temp->info);
}