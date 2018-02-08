#ifndef queueArray_H
#include<iostream>
class queueArray {
public:
	queueArray(int Maxs=100);
	queueArray(const queueArray &x);
	~queueArray();
	size_t size;
	bool Is_empty()const;
	size_t length()const;
	int first()const;
	int last()const;
	int enqueue(const int a);
	int dequeue();
	bool visit(int (*f)(int n));
	void operator =(queueArray& x);
	bool clean(int Maxs = 100);
	void s() { for (int i = 0; i < Maxsize; i++)std::cout << t[i] << std::endl; }
private:
	int *t;
	int rear;
	int front;
	int Maxsize;
};

#endif // !queueArray_H
