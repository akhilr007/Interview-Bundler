// 1. using two queues
class Stack{
private:
    queue<int> q1, q2;
    int curSize;
public:
    Stack(){
        curSize=0;
    }

    void push(int x){

        curSize++;

        q2.push(x); // add to q2

        // q1 -> q2
        while(q1.size()>0){
            q2.push(q1.front());
            q1.pop();
        }

        // q2 -> q1
        while(q2.size() > 0){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){

        curSize--;
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top(){
        if(curSize == 0) return -1;
        return q1.front();
    }

    bool isEmpty(){
        if(curSize == 0) return true;
        return false;
    }

    int size(){
        return curSize;
    }
};

// 2. using one queue
class Stack{
private:
    queue<int> q;
    int s;
public:
    Stack(int size){
        s=0;
    }

    void push(int x){

        s++;

        q.push(x);

        int iteration = s-1;
        while(iteration-- > 0){
            int val = q.front();
            q.pop();
            q.push(val);
        }
    }

    int pop(){
        if(s==0) return -1;
        s--;

        int val = q.front();
        q.pop();
        return val;
    }

    int top(){
        if(s==0) return -1;
        return q.front();
    }

    bool isEmpty(){
        if(s==0) return true;
        return false;
    }

    int size(){
        return s;
    }
};