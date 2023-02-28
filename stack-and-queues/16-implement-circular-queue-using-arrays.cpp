class CircularQueue {
private:
    int* a;
    int front, rear;
    int size;

public:
    CircularQueue(int capacity){
        a = new int[capacity];
        front = rear = -1;
        size = capacity;
    }

    bool push(int x){

        if(isFull()) return false;

        if(front == -1){
            front = 0;
        }

        rear = (rear + 1) % size;
        a[rear] = x;

        return true;
    }

    bool pop(){

        if(isEmpty()) return false;

        int result = a[front];

        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }

        return true;


    }

    int front(){
        if(front == -1) return -1;
        return a[front];
    }

    int rear(){

        if(rear == -1) return -1;
        return a[rear];
    }

    bool isEmpty(){

        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }

    bool isFull(){

        if((rear + 1) % size == front){
            return true;
        }
        return false;
    }
};