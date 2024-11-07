#include <iostream>
#include <vector>
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
    Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    // Destructor to clean up memory
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    // Push an element into the queue
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        queueSize++;
    }

    // Pop an element from the queue
    void pop() {
        if (empty()) {
            cout << "Queue is empty, cannot pop!" << endl;
            return;
        }
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;
        if (empty()) {
            rearNode = nullptr; // If queue is empty, reset rearNode
        }
    }

    // Get the front element of the queue
    T front() {
        if (empty()) {
            throw out_of_range("Queue is empty!");
        }
        return frontNode->data;
    }

    // Get the size of the queue
    int size() {
        return queueSize;
    }

    // Check if the queue is empty
    bool empty() {
        return queueSize == 0;
    }

    // Move the element at the front to the rear of the queue
    void move_to_rear() {
        if (empty() || queueSize == 1) {
            return; // Nothing to move if empty or just one element
        }
        T frontValue = front();  // Get the front element
        pop();  // Remove the front element
        push(frontValue);  // Move it to the rear
    }

    // Display all elements in the queue
    void display() {
        Node<T>* temp = frontNode;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Sort the queue using insertion sort
    void insertion_sort_queue() {
        // Extract elements from the queue into a vector
        vector<T> elements;
        Node<T>* temp = frontNode;
        while (temp) {
            elements.push_back(temp->data);
            temp = temp->next;
        }

        // Sort the vector using the insertion_sort function
        insertion_sort(elements);

        // Rebuild the queue with the sorted elements
        while (!empty()) {
            pop(); // Clear the existing queue
        }

        // Push the sorted elements back into the queue
        for (T value : elements) {
            push(value);
        }
    }
    void insertion_sort(std::vector<int>& num) {
        int i, j, key;
        bool insertionNeeded = false;
        for (j = 1; j < num.size(); j++) {
            key = num[j];
            insertionNeeded = false;
            for (i = j - 1; i >= 0; i--) {
                if (key < num[i]) {
                    num[i + 1] = num[i]; // larger values move right
                    insertionNeeded = true;
                }
                else
                    break;
            }
            if (insertionNeeded)
                num[i + 1] = key; // Put key into its proper location
        }
    }

};

template <typename Item_Type>
int linear_search(vector<Item_Type>& items, Item_Type& target, size_t pos_first) {
    // Base case: If we've reached the end of the vector, return -1 (target not found)
    if (pos_first == items.size()) {
        return -1;
    }

    // Recur to the next position to search
    int index = linear_search(items, target, pos_first + 1);

    // If we found the target in the subsequent recursive call, return the index
    if (index != -1) {
        return index;
    }

    // If the current position matches the target, return this index
    if (items[pos_first] == target) {
        return pos_first;
    }

    // If the target is not found, return -1
    return -1;
}
// Function to display the contents of a vector
template <typename T>
void display_vector(const vector<T>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}
// Main function to perform the operations
int main() {
    // a) Instantiate the queue with integers and push 10 values
    Queue<int> q;

    // Push 10 values into the queue
    for (int i = 10; i >= 0; i--) {  // Pushing values in reverse order
        q.push(i);
    }
   
    // b) Display all elements in the queue
    cout << "Queue contents: ";
    q.display();  // Using the display function to show all elements
    cout << "Sorting que contents: ";
    q.insertion_sort_queue();

    q.display();

    // c) Move the front element to the rear using the move_to_rear function
    cout << "Moving the front element to the rear: " << endl;
    q.move_to_rear();

    // Display the queue after moving the front element to the rear
    cout << "Queue after move_to_rear: ";
    q.display();

    // Optionally, you can perform other operations like pop and check the size
    cout << "Popping an element from the queue: " << endl;
    q.pop();

    cout << "Queue after pop: ";
    q.display(); //displayu the que 
    //check the front elements queue size and if the queue is empty 
    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;
    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl;
   //define the vector and fill the values 
    vector<int> items = { 1, 2, 3, 4, 5, 6, 5, 7, 8, 5 }; 
    int target = 5;
    //print before vector 
    cout << "Vecttor Contents: ";
    //show the items that are found in the vector 
    display_vector(items);
    // Start searching from the first position
    int result = linear_search(items, target, 0);
    //check to find the last occurance of the item by index 
    if (result != -1) {
        cout << "The last occurrence of target " << target << " is at index " << result << endl;
    }
    else {
        cout << "Target " << target << " not found in the vector." << endl;
    }
    return 0;
}
