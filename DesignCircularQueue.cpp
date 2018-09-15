struct Node {
    int value;
    Node * next;
    Node(int value){
        this->value = value;
        next = NULL;
    }
};
class MyCircularQueue {
private:
    Node * front;
    Node * rear;
    int count;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        front = NULL;
        rear = NULL;
        count = 0;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (count == size) return false;
        else{
            if (front == NULL){
                front = new Node(value);
                rear = front;
            }
            else{
                rear->next = new Node(value);
                rear = rear->next;
            }
            count++;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (count == 0) return false;
        count--;
        if (count == 0) {
            front = NULL;
            rear = NULL;
        }
        else{
            front = front->next;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return front->value;   
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return rear->value;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (count == 0);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (count == size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
