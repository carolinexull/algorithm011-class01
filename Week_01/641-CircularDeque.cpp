#include<vector>
using namespace std;

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        m_front = 0;
        m_rear = 0;
        m_size = k + 1;
        m_data.reserve(m_size);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        
        m_front = (m_front + m_size - 1) % m_size;
        m_data[m_front] = value;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;

        m_data[m_rear] = value;
        m_rear = (m_rear + 1) % m_size;

        return true; 
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;

        m_front = (m_front + 1) % m_size;

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;

        m_rear = (m_rear + m_size - 1) % m_size;

        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        
        return m_data[m_front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        
        return m_data[(m_rear + m_size - 1) % m_size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return m_front == m_rear;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (((m_rear + 1) % m_size) == m_front);
    }
private:
    vector<int> m_data;
    unsigned int m_size;
    unsigned int m_front;
    unsigned int m_rear;
};