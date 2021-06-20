#include "header.h"
//сортування обміном, передаємо вказівник на об'єкт к-сть елементів і сортуємо
//(почитай про сортування бульбашкою, там все норм пояснено)
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
//виведення масиву Стеків, використовуємо раніше написану ф-цію put(), про неї вже писав в попередніх лабах
void put_stacks(Stack*st,int sizeofmas){
    for(int i=0;i<sizeofmas;i++){
        cout<<"Stack "<<i+1<<endl;
        st[i].put();
        cout<<endl;
    }
}
//перевантажений оператор =, дозволяє прирівняти всі елементи з другого стеку у перший(той, що викликає цей оператор)
//для цього ми попередньо видаляєм стек , а потім присвоємо йому значення з переданого стеку в ф-цію
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
//перевантажений оператор ''більше'', виконує те, що задано умовою
bool operator>(Stack&st1, Stack &st2){
        if(st1.size>st2.size){
            return true;
        }
        return false;
}
//перевантажений оператор+ , використовується вже раніше написана ф-цію push()
void Stack::operator+(int value){
    this->push(value);
}
//перевизначена операція +=, для додавання елементів з іншого стеку до стеку, що викликає цей оператор, тобто ми ''склеюємо''
// два стеки
// в один
void Stack::operator+=(Stack& st){
        for(int i=st.size-1;i>=0;i--){
            this->push(st.arr[i]);
        }
}
//решту я пояснював в 2-й лабі:)
//конструктор
Stack::Stack(){
        arr = nullptr;
        size = 0;
        countofelements=0;
}
//деструктор
Stack::~Stack(){
    if(arr!=nullptr){
         delete[] arr;
    }
}
//додавання елементу в стек
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
//видалення елементу зі стеку
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
//знаходження максимального
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
//знаходження мінімального
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
//к-сть елементів
int Stack::getcount(){
    return countofelements;
}
//виведення стеку
void Stack::put(){
    if(this->size==0){
            return;
    }
    for(int i=0;i<this->size;i++){
            cout<<arr[i]<<endl;
    }
}

