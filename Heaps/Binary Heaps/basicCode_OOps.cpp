// C++ program for implementation of Binary Heaps OOPS

#include <bits/stdc++.h>
using namespace std;

class Heap{
    public:
        vector<int> arr;
        int N;
        void printVector();
        void heapify( int i);
        void buildHeap();
        void heapSort();
        int  maxi();
        int extractMax();
        void  heapIncKey(int ind, int key);
        void insertKey(int key);
        void deleteKey(int ind);
        int parent(int i){
            return (i-1)/2;
        }
};


void Heap :: printVector()
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


void Heap :: heapify(int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(largest);
    }
}

void Heap ::buildHeap(){
     // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(i);
}


void Heap :: heapSort(){
     // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(i);

    for (int i = N-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(0);
    }
    
}

int Heap :: maxi(){
    return arr[0];
}

int Heap :: extractMax(){
    if(N < 0){
        cout<<"Overflow"<<endl;
        return -1;
    }
    int maxi = arr[0];
    swap(arr[0],arr[N-1]);
    N = N - 1;
    heapify(0);
    return maxi;
}

void Heap :: heapIncKey(int ind, int key){

    if(key < arr[ind]){
        cout<<"key is lesser";
        return;
    }
    arr[ind] = key;
    while (ind > 0 && arr[parent(ind)] < arr[ind])
    {
         swap(arr[ind], arr[parent(ind)]);
         ind = parent(ind);
    }
    
}

 

void Heap :: insertKey(int key){
    N = N + 1;
    arr[N] = -1e9;
    heapIncKey(N, key);
}

void Heap :: deleteKey(int ind){
    arr[ind] = 1e9;
    heapIncKey(ind, arr[ind]);
    extractMax();
}

int main()
{
    Heap h1;
    h1.arr = { 12, 11, 13, 5, 6, 7 };
    h1.N = h1.arr.size();
 
    h1.printVector();
    h1.buildHeap();
    h1.printVector();
 
    cout<<h1.extractMax()<<endl;
    h1.printVector();
    h1.heapIncKey(h1.N - 1,100);
    h1.printVector();
    h1.insertKey(90);
    h1.printVector();
    h1.deleteKey(3);
    h1.printVector();
 
 
}