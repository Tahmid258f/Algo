#include<bits/stdc++.h>
using namespace std;
void Merge(int A[],int l,int m,int h)
{
    int a=m+1-l;
    int b=h-m;
    int a1[a],a2[b];
    int i,j;
    for(int i=0;i<a;i++)
    {
        a1[i]=A[l+i];
    }
    for(int j=0;j<b;j++)
    {
        a2[j]=A[m+1+j];
    }
    i=0,j=0;
    int k=l;
    while(i<a && j<b)
    {
        if(a1[i]<=a2[j])
        {
            A[k]=a1[i];
            i++;
            k++;
        }
        else{
            A[k]=a2[j];
            j++;
            k++;
        }
    }
    while(j<b)
    {
        A[k]=a2[j];
        k++;
        j++;
    }
    while(i<a)
    {
        A[k]=a1[i];
        k++;
        i++;
    }
}
void MergeSort(int A[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,h);
        Merge(A,l,m,h);
    }
}
int main()
{
    int A[9]={10,2,3,17,55,1,3,99,1};
    int l=0,h=8;
    int m=(l+h)/2;
    MergeSort(A,l,h);
    for(int i=0;i<=h;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
