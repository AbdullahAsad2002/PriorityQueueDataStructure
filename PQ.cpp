#include<iostream>
using namespace std;
class BinaryHeap{
    private:
    int* PQ;
    int count;
    int total;
    int j; //this will be used in dequeue function!!
    public:
    BinaryHeap(){
        total = 10;
        PQ = new int[10];
        count =0;
        j=1;
    }
    BinaryHeap(int size)
    {   
        total = size;
        PQ = new int[size];
        count = 0;
        j=1;
    }
    void addData(int data)
    {   
        count++;
        PQ[count] = data;
    }
    void printList(){
        for (int i = 1; i < count+1; i++)
        {
            cout<<PQ[i]<<" ";
        }
        cout<<endl;
    }
    void enqueue(int data)
    {   
        if (count == total)
        {
            cout<<"Cannot add more!!!"<<endl;
            return;
        }       
        count++;
        PQ[count] = data;
        int i;
        i = count;
        while(i!=1)
        {   
            int j = int(i/2);
            if (PQ[i]<PQ[j])
            {
                int temp = PQ[j];
                PQ[j] = PQ[i];
                PQ[i] = temp;
                i = j;
            }
            else
            {
                break;
            }
        }
    }
    void dequeue()
    {   
        if(PQ[2*j]<=PQ[(2*j)+1] && 2*j<=count && (2*j)+1<=count)
        {
            PQ[j] = PQ[2*j];
            j = 2*j;
            dequeue();
        }
        else if(PQ[(2*j)+1]<PQ[2*j] && 2*j<=count && (2*j)+1<=count)
        {   
            PQ[j] = PQ[(2*j)+1];
            j = (2*j)+1;
            dequeue();
        }
        else{
            PQ[j] = PQ[count];
            count--;
        }
        j=1;
    }
};
int main()
{   int n;
    cout<<"Enter the size of array/heapTree :";
    cin>>n;
    int data;
    BinaryHeap pq(n+1);
    int i =1;
    while(i != n+1)
    {
        cout<<"Enter element/node at "<<i<<" :";
        cin>>data;
        pq.enqueue(data);
        i++;
    }
    cout<<"The current list/tree is : ";
    pq.printList();
    int delchoice=1;
    int j = 1;
    while(delchoice == 1)
    {   
        if(j==n+1){
            cout<<"cannot delete more!!"<<endl;
            break;
        }
        else{
        cout<<"Do you wanna delete Smallest element ??? ";
        cout<<"(YES = 1 / NO = ANY KEY) :";
        cin>>delchoice;
        pq.dequeue();
        cout<<"The current list/tree is : ";
        pq.printList();
        j++;
        }
    }
    return 0;
}