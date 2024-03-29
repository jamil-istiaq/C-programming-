#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void maxHeap(int b[],int i, int n)
{
    int left_child, right_child,largest_index;

    left_child=2*i+1;
    right_child=2*i+2;

    if(left_child<n && b[left_child] > b[i])
    {
        largest_index=left_child;
    }
    else
    {
        largest_index=i;
    }
    if(right_child<n && b[right_child] > b[largest_index])
    {
        largest_index=right_child;
    }

    if(largest_index!=i)
    {
        Swap(&b[largest_index],&b[i]);
        maxHeap(b,largest_index,n);
    }
}

void minHeap(int b[], int i, int n)
{
    int left_child, right_child,min_index;

    left_child=2*i+1;
    right_child=2*i+2;

    if(left_child<n && b[left_child] < b[i])
    {
        min_index=left_child;
    }
    else
    {
        min_index=i;
    }
    if(right_child<n && b[right_child] < b[min_index])
    {
        min_index=right_child;
    }

    if(min_index!=i)
    {
        Swap(&b[i],&b[min_index]);
        minHeap(b,min_index,n);
    }
}

void display(int b[], int n)
{
    int i;

    cout<<"Printing..."<<endl;
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}

void buildHeap(int b[],int n)
{
    int i,choice;

    cout<<"Press 1 for MAX HEAP and 2 for MIN HEAP"<<endl;
    cin>>choice;

    if(choice==1)
    {
        for(i=(n/2)-1;i>=0;i--)
        {
            maxHeap(b,i,n);
        }
    }
    else if(choice==2)
    {
        for(i=(n/2)-1;i>=0;i--)
        {
            minHeap(b,i,n);
        }
    }
    else
    {
        cout<<"Please give valid input"<<endl;
    }
}

int main()
{
    int n,i;
    cout<<"Enter array size: ";
    cin>>n;
    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    buildHeap(a,n);
    display(a,n);
}



