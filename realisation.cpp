#include "header.h"
//���������� ������, �������� �������� �� ��'��� �-��� �������� � �������
//(������� ��� ���������� ����������, ��� ��� ���� ��������)
void sort_stacks(Stack*st,int sizeofmas){
    for(int i=0;i<sizeofmas-1;i++){
        for(int k=0;k<sizeofmas-i-1;k++){
            if(st[k]>st[k+1]){
                Stack tmp = st[k];
                st[k] = st[k+1];
                st[k+1] = tmp;
            }
        }
    }
}
//��������� ������ �����, ������������� ����� �������� �-��� put(), ��� �� ��� ����� � ��������� �����
void put_stacks(Stack*st,int sizeofmas){
    for(int i=0;i<sizeofmas;i++){
        cout<<"Stack "<<i+1<<endl;
        st[i].put();
        cout<<endl;
    }
}
//�������������� �������� =, �������� ��������� �� �������� � ������� ����� � ������(���, �� ������� ��� ��������)
//��� ����� �� ���������� �������� ���� , � ���� �������� ���� �������� � ���������� ����� � �-���
Stack& Stack::operator=(Stack&st){
        int*tmp = new int[st.size];
        for(int i=0;i<st.size;i++){
            tmp[i] = st.arr[i];
        }
        delete[]arr;
        arr = tmp;
        this->size = st.size;
        this->countofelements = st.countofelements;
        delete[]tmp;
        return *this;
}
//�������������� �������� ''�����'', ������ ��, �� ������ ������
bool operator>(Stack&st1, Stack &st2){
        if(st1.size>st2.size){
            return true;
        }
        return false;
}
//�������������� ��������+ , ��������������� ��� ����� �������� �-��� push()
void Stack::operator+(int value){
    this->push(value);
}
//������������� �������� +=, ��� ��������� �������� � ������ ����� �� �����, �� ������� ��� ��������, ����� �� ''��������''
// ��� �����
// � ����
void Stack::operator+=(Stack& st){
        for(int i=st.size-1;i>=0;i--){
            this->push(st.arr[i]);
        }
}
//����� � ��������� � 2-� ���:)
//�����������
Stack::Stack(){
        arr = nullptr;
        size = 0;
        countofelements=0;
}
//����������
Stack::~Stack(){
    if(arr!=nullptr){
         delete[] arr;
    }
}
//��������� �������� � ����
void Stack::push(int value){
        int* tmp = new int[size+1];
        for(int i=1, k=0;i<size+1;i++,k++){
            tmp[i] = arr[k];
        }
        tmp[0] = value;
        delete[] arr;
        arr = tmp;
        delete[] tmp;
        size++;
        countofelements++;
}
//��������� �������� � �����
void Stack::pop(){
        if(size==0){
            return;
        }
        if(size==1){
            delete arr;
            arr = nullptr;
            countofelements--;
            size=0;
            return;
        }
        int* tmp = new int[size-1];
        for(int i=0, k=1;i<size-1;i++, k++){
            tmp[i] = arr[k];
        }
        delete[]arr;
        arr = tmp;
        delete[] tmp;
        size--;
        countofelements--;
}
//����������� �������������
int Stack::getmax(){
        if(size==0){
            return -1;
        }
        int max = arr[0];
        for(int i=0;i<this->size;i++){
            if(max<arr[i]){
                max = arr[i];
            }
        }
        return max;
}
//����������� ����������
int Stack::getmin(){
        if(size==0){
            return -1;
        }
        int min = arr[0];
        for(int i=0;i<this->size;i++){
            if(min>arr[i]){
                min = arr[i];
            }
        }
        return min;
}
//�-��� ��������
int Stack::getcount(){
    return countofelements;
}
//��������� �����
void Stack::put(){
    if(this->size==0){
            return;
    }
    for(int i=0;i<this->size;i++){
            cout<<arr[i]<<endl;
    }
}

