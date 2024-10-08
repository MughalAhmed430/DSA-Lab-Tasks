#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int array[5]={1,2,3,4,5};

    int ele;
    cout<<"Enter the Element you want to Delete : ";
    cin>>ele;

    for (int i = ele; i < n-1; i++)
    {
        array[i]=array[i+1];
    }

    cout<<"After Deletion : "<<endl;
    for (int i = 0; i < n-1; i++)
    {
        cout<<array[i]<<" "<<endl;
    }
    
    return 0;
}