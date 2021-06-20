#include "header.h"
int main()
{
    int size;
    cout<<"Enter the number of stacks"<<endl;
    cin>>size;
    Stack *stacks = new Stack[size];
    string answer;
    for(int i=0;i<size;i++){
        cout<<"Enter first element of "<<i+1<<" stack"<<endl;
        do{
            int num;
            cin>>num;
            stacks[i]+num;
            cout<<"If u`d like to add more elements to "<<i+1<<" stack, choose 'y'"<<endl;
            cin>>answer;
        }while(answer=="y");
    }
    cout<<"Stacks"<<endl;
    put_stacks(stacks,size);
    cout<<"Sorted stacks"<<endl;
    sort_stacks(stacks,size);
    put_stacks(stacks,size);
    Stack FinalStack;
    for(int i=0;i<size;i++){
        FinalStack+=stacks[i];
    }
    cout<<"Merged stacks in one"<<endl;
    FinalStack.put();
    return 0;
}
