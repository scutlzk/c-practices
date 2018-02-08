#include"queueArray.h"
#include<iostream>


queueArray::queueArray(int Maxs) 
{
	t = new int[Maxs];
	Maxsize = Maxs;
	this->size = 0; 
	rear = -1; 
	front = 0;
}
queueArray::queueArray(const queueArray &x)
{
	this->size = x.size;
	this->front = 0;
	this->Maxsize = x.Maxsize;
	this->rear = x.rear - x.front;
	t = new int[Maxsize];
	if (size == 0)return ;
	if (x.front <= x.rear)
		for (int i = 0; i < x.size; ++i)
			t[i] = x.t[x.front + i];
	else
	{
		int i;
		for (i = 0; (i + front) < x.Maxsize; ++i)
			t[i] = x.t[front + i];
		for (int j = 0; j <= rear; ++j, ++i)
			t[i] = x.t[j];
	}
}
queueArray::~queueArray() 
{ 
	delete t; 
}
bool queueArray::clean(int Maxs)
{
	delete t;
	t = new int[Maxs];
	Maxsize = Maxs;
	this->size = 0;
	rear = -1;
	front = 0;
	return 1;
}

bool queueArray::Is_empty()const 
{ 
	if (size==0)return 1; 
	return 0; 
}

size_t queueArray::length()const 
{ 
	return this->size; 
}

int queueArray::first()const 
{
	if (this->size == 0) { std::cout << "is empty" << std::endl; return 0; }
	return t[front];
}

int queueArray::last()const
{
	if (this->size == 0) { std::cout << "is empty" << std::endl; return 0; }
	return t[rear];
}

int queueArray::enqueue(const int a) 
{
	if (this->size == Maxsize)
	{
		int *p = new int[Maxsize*2];
		int i;
		for (i = 0; (i + front) < Maxsize; ++i)
			p[i] = t[front + i];
		if (rear != (Maxsize - 1))
			for (int j = 0; j <= rear; ++j, ++i)
				p[i] = t[j];
		t = p;
		front = 0;
		rear = Maxsize - 1;
		Maxsize *= 2;
	}

	t[(++rear)%Maxsize] = a;
	++this->size;
	return a;
}
int queueArray::dequeue()
{
	if (size == 0) { std::cout << "is empty" << std::endl; return 0; }
	if (front == (Maxsize - 1)) { front = 0; --size; return t[Maxsize - 1]; }
	--size;
	return t[front++];
}
void queueArray::operator =(queueArray& x)
{
	this->size = x.size;
	this->front = 0;
	this->Maxsize = x.Maxsize;
	this->rear = x.rear-x.front;
	if (t)delete t;
	t = new int[Maxsize];	
	if (x.front <= x.rear)
		for (int i = 0; i < x.size; ++i)
			t[i] = x.t[x.front + i];
	else 
	{
		int i;
		for (i = 0; (i + front) < x.Maxsize; ++i)
			t[i] = x.t[front + i];
		for (int j = 0; j <= rear; ++j, ++i)
			t[i] = x.t[j];
	}
}
bool queueArray::visit(int(*f)(int n)) 
{
	if (size == 0)return 0;
	if (front <= rear)
		for (int i = 0; i < this->size; ++i)
			f(t[i+front]);
	else
	{
		int i;
		for (i = 0; (i + front) < Maxsize; ++i)
			f(t[front + i]);
		for (int j = 0; j <= rear; ++j, ++i)
			f(t[j]);
	}
	return 1;
}