class Stack {
private:
    int maxSize;
    int current;
    int* stack;

public:
    Stack(int size) {
        maxSize = size;
        current = 0;
        stack = new int[maxSize];
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int item) {
        if (current == maxSize) {
            resize();
        }
        stack[current] = item;
        current++;
    }

    int pop() {
        if (is_empty()) {
            throw "Stack is empty";
        }
        current--;
        return stack[current];
    }

    int peek() {
        if (is_empty()) {
            throw "Stack is empty";
        }
        return stack[current - 1];
    }

    bool is_empty() {
        return current == 0;
    }

    int size() {
        return current;
    }

    int get_max_size() {
        return maxSize;
    }

private:
    void resize() {
        int newMaxSize = maxSize * 2;
        int* newStack = new int[newMaxSize];
        
        for (int i = 0; i < current; i++) {
            newStack[i] = stack[i];
        }
        
        delete[] stack;
        stack = newStack;
        maxSize = newMaxSize;
    }
};