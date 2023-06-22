#include <iostream>
using namespace std;

int main()
{
    // 方法1——在范围给定的情况下，利用数组下标进行标记（通过洛谷用例，平均耗时3.4ms，空间复杂度700KB左右）
    int n,m;
    cin>>n>>m;
    // 每位同学有从0到N-1的唯一编号
    int number[1000] = {0};
    for(int i = 0; i<m;i++)
    {
        int temp = 0;
        cin>>temp;
        number[temp] = 1;
    }
    bool is_lose = false;//判断是否有人缺席
    for(int i = 0; i<n;i++)
    {
        if(number[i]!= 1)
        {
            cout<< i <<" ";
            is_lose = true;
        }
    }
    // 如果没有人缺席则输出N
    if(!is_lose)
    {
        cout<<n;
    }
    return 0;
}