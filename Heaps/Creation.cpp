#include<iostream>
#include<queue>
using namespace std;

class MaxHeap{
    public:
        int arr[100];
        int size;

        MaxHeap()
        {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val)
        {
            size++;
            int index = size;
            arr[index] = val;

            while(index > 1)
            {
                int parent = index/2;
                if(arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                {
                    break;
                }
            }
        }
        void print()
        {
            for(int i = 1; i <= size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void deleteNode()
        {
            if(size == 0)
            {
                cout<<"Heap is empty"<<endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            int index = 1;
            while(index <= size)
            {
                int left = index*2;
                int right = index*2 + 1;
                int largest = index;

                if(left <= size && arr[left] > arr[largest])
                {
                    largest = left;
                }
                if(right <= size && arr[right] > arr[largest])
                {
                    largest = right;
                }

                if(largest == index)
                {
                    break;
                }
                else
                {
                    swap(arr[largest], arr[index]);
                    index = largest;
                }
            }
        }
};

void heapify(int * arr,int n,int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

void heapSort(int * arr, int n)
{
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = n; i > 0; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, i-1, 1);
    }
}
int main()
{
    MaxHeap h;

    h.insert(40);
    h.insert(50);
    h.insert(20);
    h.insert(10);
    h.insert(60);
    h.insert(30);

    h.print();

    h.deleteNode();
    h.print();

    int arr[] = {-1, 10, 20, 15, 40, 50, 100, 25, 45};
    int n = sizeof(arr)/sizeof(arr[0])-1;
    
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);

    for(int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Using Priority Queue:"<<endl;

    // MaxHeap
    priority_queue<int> pq;
    pq.push(40);
    pq.push(50);
    pq.push(20);
    pq.push(10);
    pq.push(60);
    pq.push(30);

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    // MinHeap
    priority_queue<int, vector<int>, greater<int> > pq1;
    pq1.push(40);
    pq1.push(50);
    pq1.push(20);
    pq1.push(10);
    pq1.push(60);
    pq1.push(30);

    while(!pq1.empty())
    {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;
    return 0;
}