// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
#include <stdexcept> // for out_of_range exception
using namespace std;

// Node structure to represent each element in the queue
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// Queue class template
template <typename T>
class Queue {
private:
    Node<T>* frontNode;  // Front of the queue
    Node<T>* rearNode;   // Rear of the queue
    int queueSize;       // Size of the queue

public:
    // Constructor
    Queue();

    // Destructor to clean up memory
    ~Queue();

    // Push an element into the queue
    void push(T value);

    // Pop an element from the queue
    void pop();

    // Get the front element of the queue
    T front();

    // Get the size of the queue
    int size();

    // Check if the queue is empty
    bool empty();

    // Move the element at the front to the rear of the queue
    void move_to_rear();

    // Display all elements in the queue
    void display();

    // Sort the queue using insertion sort
    void insertion_sort_queue();

private:
    // Helper function for sorting the queue
    void insertion_sort(std::vector<int>& num);
};

// Function to display the contents of a vector
template <typename T>
void display_vector(const vector<T>& vec);

// Linear search function to find the last occurrence of a target in a vector
template <typename Item_Type>
int linear_search(vector<Item_Type>& items, Item_Type& target, size_t pos_first);

#endif // QUEUE_H
