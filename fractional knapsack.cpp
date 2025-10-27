#include<bits/stdc++.h>
using namespace std;

double fractinalknapsack(vector<int>value,vector<int>weight,int capacity)
{
    int n=value.size();
    vector<pair<double,pair<int,int>>>items;

    for(int i=0;i<n;i++)
    {
        double ratio=(double)value[i]/weight[i];
        items.push_back({ratio,{value[i],weight[i]}});
    }
    sort(items.rbegin(),items.rend());
    double totalValue=0.0;
    int remainingcapacity=capacity;
    for(int i=0;i<n;i++)
    {
        int w=items[i].second.second;
        int v=items[i].second.first;
        if(w<=remainingcapacity)
        {
            totalValue+=v;
            remainingcapacity-=w;
        }
        else{
            totalValue+=items[i].first*remainingcapacity;
            break;
        }
    }
    return totalValue;
}

int main()
{
    vector<int>value={60,100,120};
    vector<int>weight={10,20,30};
    int capacity=50;
    double maxvalue=fractinalknapsack(value,weight,capacity);
    cout<<"Maximum value in knapsack= "<<maxvalue<<endl;
}

