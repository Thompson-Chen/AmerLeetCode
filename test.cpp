#include <iostream>
#include <cmath>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<string,string> nums = {{"zero","0"}, {"one","1"}, {"two","2"}, {"three","3"}, {"four","4"}, {"five","5"}, {"six","6"}, {"seven","7"}, {"eight","8"}, {"nine","9"}};
	for(auto &item:nums) 
	{	cout<<item.first<<" {";
		unordered_map<int,int> temp;
		for(char c: item.first)
		{
			temp[c-'a']++;
		}
		for(auto &item: temp)
		{
			cout<<"{"<<item.first<<","<<item.second<<"},";
		}
		cout<<"}"<<endl;
	}
	return 0;
}