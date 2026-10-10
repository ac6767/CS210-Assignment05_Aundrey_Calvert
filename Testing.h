#ifndef Testing_h
#define Testing_h

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Stack_Queue_Deque.h"

using namespace std;

class Testing {
public:
    /* clang-format off */
    /////////////////////////////////////////////////// Ai used to create testing ///////////////////////////////////////////////////////////////
    /* clang-format on */

    void check(bool passed, const string& operation) {
        if (!passed)
            throw runtime_error(operation);
        cout << "  PASS " << operation << '\n';
    }

    template <typename T>
    void testStack(const string& name) {
        cout << "\n" << name << '\n';
        T structure;
        int value = -999;
        check(structure.IsEmpty(), "1. IsEmpty on a new stack");
        check(!structure.pop(value) && value == -999, "2. pop on empty stack is handled");
        check(structure.push(10), "3. push 10");
        check(!structure.IsEmpty(), "4. IsEmpty after insertion");
        check(structure.push(20), "5. push 20");
        check(structure.pop(value) && value == 20, "6. pop -> 20");
        check(structure.push(30), "7. push 30");
        check(structure.pop(value) && value == 30, "8. pop -> 30");
        check(structure.pop(value) && value == 10, "9. pop -> 10");
        check(structure.IsEmpty(), "10. IsEmpty after removing all items");
    }

    template <typename T>
    void testQueue(const string& name) {
        cout << "\n" << name << '\n';
        T structure;
        check(structure.IsEmpty(), "1. IsEmpty on a new queue");
        structure.Enqueue(10);
        check(structure.GetLength() == 1, "2. Enqueue 10");
        check(structure.Peek() == 10, "3. Peek -> 10");
        structure.Enqueue(20);
        check(structure.GetLength() == 2, "4. Enqueue 20");
        check(structure.Dequeue() == 10, "5. Dequeue -> 10");
        check(structure.Peek() == 20, "6. Peek -> 20");
        structure.Enqueue(30);
        check(structure.GetLength() == 2, "7. Enqueue 30");
        check(structure.Dequeue() == 20, "8. Dequeue -> 20");
        check(structure.Dequeue() == 30, "9. Dequeue -> 30");
        check(structure.IsEmpty(), "10. IsEmpty after removing all items");
    }

    template <typename T>
    void testDeque(const string& name) {
        cout << "\n" << name << '\n';
        T structure;
        int value = -999;
        check(structure.empty(), "1. empty on a new deque");
        check(!structure.popFront(value) && value == -999, "2. empty popFront is handled");
        check(structure.pushBack(10), "3. pushBack 10");
        check(structure.pushFront(5), "4. pushFront 5");
        check(structure.popBack(value) && value == 10, "5. popBack -> 10");
        check(!structure.empty(), "6. deque is not empty");
        check(structure.popFront(value) && value == 5, "7. popFront -> 5");
        check(structure.empty(), "8. empty after removing all items");
        check(structure.pushBack(20), "9. pushBack 20 after empty");
        check(structure.popFront(value) && value == 20, "10. popFront -> 20");
    }
    Testing() {
        testStack<ArrayStack>("Array-based stack");
        testStack<LinkedListStack>("Linked-list stack");
        testQueue<ArrayQueue>("Array-based queue");
        testQueue<LinkedListQueue>("Linked-list queue");
        testDeque<ArrayDeque>("Array-based deque");
        testDeque<LinkedListDeque>("Linked-list deque");
    }
};

#endif
