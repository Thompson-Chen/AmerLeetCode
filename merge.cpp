#include <iostream>
using namespace std;


// 归并
void Merge(int a[], int s, int m, int e, int tmp[])
{
    // 把数组a[s,m]和a[m+1,e]合并到tmp数组，并保证tmp有序
    int pb = 0;
    int p1 = s, p2 = m+1;
    while(p1 <= m && p2 <= e)
    {
        if(a[p1] < a[p2])
        {
            tmp[pb++] = a[p1++];
        }
        else
        {
            tmp[pb++] = a[p2++];
        }
    }
    while(p1 <= m)
    {
        tmp[pb++] = a[p1++];
    }
    while(p2 <= e)
    {
        tmp[pb++] = a[p2++];
    }
    // 覆盖
    for(int i = 0; i < e-s+1;++i)
    {
        a[s+i] = tmp[i];
    }
}
// 排序
void MergeSort(int a[], int s,int e, int tmp[])
{
    if(s < e) {
        int m = s + (e-s)/2;
        MergeSort(a,s,m,tmp);
        MergeSort(a,m+1,e,tmp);
        Merge(a,s,m,e,tmp);
    }
}

int a[10] = {9,8,7,6,5,4,3,2,1,0};
int b[10];

int main()
{
    int size = sizeof(a)/ sizeof(int);
    MergeSort(a,0,size-1,b);
    for(int i = 0; i < size; ++i)
    {
        cout << a[i] << ",";
    }
    cout<<endl;
    return 0;
}