#include <iostream>
using namespace std;

int main()
{
    int cst = 7;

    for(int i = -2147483648; i <= 2147483647; ++i)
    {   
        if(i%10000 == 0)cout<<"@"<<i<<endl;
        int temp = i^cst;
        temp = temp^cst;
        if (temp != i)
        {
            cout<<i<<endl;
            cout<<temp<<endl;
            return 0;
        }
    }
    cout<<"Finished"<<endl;
    return 0;
}