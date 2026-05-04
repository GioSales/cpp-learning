#ifndef DOUBLE_ENDED_QUEUE_H
#define DOUBLE_ENDED_QUEUE_H

#include <cassert>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

class DequeNode {
public:
    int value = 0;
    std::unique_ptr<DequeNode> next = nullptr;
    DequeNode* prev = nullptr;
};


class Deque {
    size_t dequeSize = 0;
    std::unique_ptr<DequeNode> frontNode;
    DequeNode* backNode = nullptr;

public:
    // Add an element to the front of the deque
    void push_front(const int& value) {
        auto newNode = std::make_unique<DequeNode>();
        newNode->value = value;

        newNode->next = std::move(frontNode);
        frontNode = std::move(newNode);

        // TODO: improve this if else
        if (frontNode->next == nullptr) {
            backNode = frontNode.get();
        }else {
            frontNode->next->prev = frontNode.get();
        }

        dequeSize++;
    }

    // Add an element to the back of the deque
    void push_back(const int& value) {
        auto newNode = std::make_unique<DequeNode>();
        newNode->value = value;

        if (frontNode == nullptr) {
            frontNode = std::move(newNode);
            backNode = frontNode.get();
            dequeSize++;
            return;
        }

        newNode->prev = backNode;
        backNode->next = std::move(newNode);
        backNode = backNode->next.get();

        dequeSize++;
    }

    // Remove an element from the front of the deque
    void pop_front() {
        assert(frontNode != nullptr && "Deque is empty, can't pop front");

        frontNode = std::move(frontNode->next);
        // deque became empty
        if (frontNode == nullptr) {
            backNode = nullptr;
        } else {
            frontNode->prev = nullptr;
        }
        dequeSize--;
    }

    // Remove an element from the back of the deque
    void pop_back() {
        assert(frontNode != nullptr && "Deque is empty, can't pop back");

        // one element remaining, deque will become empty
        if (frontNode->next == nullptr) {
            frontNode = nullptr;
            backNode = nullptr;
        } else {
            backNode = backNode->prev;
            backNode->next = nullptr;
        }
        dequeSize--;
    }

    // Get the element at the front of the deque
    [[nodiscard]]
    int front() const {
        assert(frontNode != nullptr && "Deque is empty, can't call front()");
        return frontNode->value;
    }

    // Get the element at the back of the deque
    [[nodiscard]]
    int back() const {
        assert(frontNode != nullptr && "Deque is empty, can't call back()");
        return backNode->value;
    }

    // Check if the deque is empty
    [[nodiscard]]
    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Get the number of elements in the deque
    [[nodiscard]]
    size_t size() const {
        return dequeSize;
    }
};

#endif // DOUBLE_ENDED_QUEUE_H