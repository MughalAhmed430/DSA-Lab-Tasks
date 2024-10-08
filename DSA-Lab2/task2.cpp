#include<iostream>
using namespace std;

int main()
{
    int searchValue;
    cout<<"Enter the value you want to search : ";
    cin>>searchValue;
    bool found = false;

    int numbers[10]={1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++)
    {
        if (numbers[i]==searchValue)
        {
            found=true;
            cout<<"*** Search Found ***"<<endl;
            break;
        }
    }
       if(found==false)
        cout<<"*** Search Not Found ***"<<endl;
    
    return 0;
}