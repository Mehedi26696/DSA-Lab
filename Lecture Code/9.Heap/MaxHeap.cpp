
// Max Heap
// A complete binary tree where the value of each node is greater than or equal to the values of its children.
// The root is the maximum element in the tree.

// Insert, Extract Max, Get Max

// Time Complexity
// Insert: O(logn)
// Extract Max: O(logn)
// Get Max: O(1)





#include <iostream>
using namespace std;

int heap[1000];
int last_index = -1;

int get_max()
{
    if (last_index == -1)
    {
        return -1;
    }
    return heap[0];
}

int parent(int i)
{
    return (i - 1) / 2;
}

void heapifyUp(int i)
{
    while (1)
    {
        if (i == 0)
            break;
        if (heap[parent(i)] > heap[i])
            break;

        // swap
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;

        i = parent(i);
    }
}

void insert(int x)
{

    heap[last_index + 1] = x;
    last_index++;
    heapifyUp(last_index);
}

int leftChild(int i)
{
    return 2 * i + 1;
}

int rightChild(int i)
{
    return 2 * i + 2;
}

void heapifyDown(int i)
{   

    // if left child is not present
    
    if (leftChild(i) > last_index)
    {
        return;
    }

    int mx_node = -1;

    // if right child is not present
    if (leftChild(i) <= last_index && rightChild(i) > last_index)  
    { 
        mx_node = leftChild(i);
    }
    // if left child is greater than right child
    else if (heap[leftChild(i)] > heap[rightChild(i)])
    {
        mx_node = leftChild(i);
    }
    // if right child is greater than left child
    else
    {
        mx_node = rightChild(i);
    }

    if (heap[i] >= heap[mx_node])
    {
        return;
    }

    // swap
    int temp = heap[i];
    heap[i] = heap[mx_node];
    heap[mx_node] = temp;

    heapifyDown(mx_node);
}
int extractMax()
{
    int ret = heap[0];

    heap[0] = heap[last_index];
    last_index--;

    heapifyDown(0);

    return ret;
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(x);
    }

    for (int i = 0; i < n; i++)
    {
        cout << extractMax() << " ";
    }

    return 0;
}