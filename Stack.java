public class Stack {
    static int MAX = 5;
    static int[] stack = new int[MAX];
    static int top = -1;

    // Push operation
    static void push(int value) {
        if (top == MAX - 1) {
            System.out.println("Stack Overflow");
        } else {
            top++;
            stack[top] = value;
            System.out.println(value + " pushed into stack");
        }
    }

    // Pop operation
    static void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow");
        } else {
            System.out.println(stack[top] + " popped from stack");
            top--;
        }
    }

    // Display operation
    static void display() {
        if (top == -1) {
            System.out.println("Stack is empty");
        } else {
            System.out.println("Stack elements:");
            for (int i = top; i >= 0; i--) {
                System.out.println(stack[i]);
            }
        }
    }

    public static void main(String[] args) {
        push(10);
        push(20);
        push(30);

        display();

        pop();

        display();
    }
}