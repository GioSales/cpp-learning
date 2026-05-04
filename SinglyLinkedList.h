//
// Created by Giovanni on 04/22/2026.
//

#ifndef LEARNING_SINGLYLINKEDLIST_H
#define LEARNING_SINGLYLINKEDLIST_H
#include <memory>
#include <vector>

class LinkNode {
public:
    int value;
    std::unique_ptr<LinkNode> next;
};

class LinkedList {
    std::unique_ptr<LinkNode> head;
    LinkNode* tail;
    int listSize;

public:
    LinkedList() {
        tail = nullptr;
        listSize = 0;
    }

    [[nodiscard]]
    int get(const int index) const {
        if(index >= listSize || index < 0)
            return -1;

        const LinkNode* element = head.get();
        for (int i = 0; i < index; i++) {
            element = element->next.get();
        }

        return element->value;
    }

    void insertHead(const int val) {
        auto newHead = std::make_unique<LinkNode>();
        newHead->value = val;
        newHead->next = std::move(head);
        head = std::move(newHead);
        if (head->next == nullptr) {
            tail = head.get();
        }

        listSize++;
    }

    void insertTail(const int val) {
        auto newTail = std::make_unique<LinkNode>();
        newTail->value = val;

        if (head == nullptr) {
            head = std::move(newTail);
            tail = head.get();
            listSize++;
            return;
        }

        const auto oldTail = tail;
        oldTail->next = std::move(newTail);

        tail = oldTail->next.get();

        listSize++;
    }

    bool remove(int index) {
        if(index >= listSize || index < 0)
            return false;

        if (head->next == nullptr) {
            head = nullptr;
            tail = nullptr;
            listSize--;
            return true;
        }

        if (index == 0) {
            head = std::move(head->next);
            listSize--;
            return true;
        }

        LinkNode* prevNode = head.get();
        for (int i = 0; i < index - 1; i++) {
            prevNode = prevNode->next.get();
        }

        LinkNode* element = prevNode->next.get();

        if (element->next == nullptr) {
            tail = prevNode;
            tail->next = nullptr;
        }else {
            prevNode->next = std::move(element->next);
        }

        listSize--;
        return true;
    }

    [[nodiscard]]
    std::vector<int> getValues() const {
        std::vector<int> values;
        values.reserve(listSize);

        const LinkNode* element = head.get();
        while (element != nullptr) {
            values.push_back(element->value);
            element = element->next.get();
        }

        return values;
    }
};

#endif //LEARNING_SINGLYLINKEDLIST_H
