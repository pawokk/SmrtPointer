#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <sstream>

class Deck {
private:
    struct Node {
        int data;
        std::unique_ptr<Node> next;

        Node(int data) : data(data), next(nullptr) {}
    };

    std::unique_ptr<Node> first;
    size_t size;
public:
    Deck() : first(nullptr) {}

    void push_front(int data) {
        auto newNode = std::make_unique<Node>(data);
        newNode->next = std::move(first);
        first = std::move(newNode);
    }

    void push_back(int data) {
        auto newNode = std::make_unique<Node>(data);

        if (!first) {
            first = std::move(newNode);
            return;
        }

        Node* current = first.get();
        while (current->next) {
            current = current->next.get();
        }

        current->next = std::move(newNode);
        size++;
    }

    std::string toString() {
        std::stringstream buffer;

        Node* thisNode = first.get();

        while (thisNode != nullptr) {
            buffer << thisNode->data << " ";
            thisNode = thisNode->next.get();
        }

        return buffer.str();
    }

    void pop() {
        if (first) {
            first = std::move(first->next);
            size--;
        }
    }
    int peekFront()  {
        if (first) {
            return first->data;
        }
        
    }


};
