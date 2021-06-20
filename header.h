#include <iostream>
#include <string.h>
using namespace std;
class Stack{
private:
    int* arr;
    int size;
    int countofelements;
public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    int getmax();
    int getmin();
    int getcount();
    void put();
    void operator+(int value);
    friend bool operator>(Stack&st1, Stack &st2);
    void operator+=(Stack& st);
    Stack&operator=(Stack&st);
};
void sort_stacks(Stack*st,int sizeofmas);
void put_stacks(Stack*st,int sizeofmas);
