//Lin
// Created by alicee on 27.11.2023.
//
#include <vector>
#include <string>
#include <iostream>

struct Node {
    std::string s;
    Node *next;

    Node(std::string _s) {
        s = _s;
        next = nullptr;
    }
};

struct list_n {
    Node *head;
    Node *tail;

    list_n() {
        head = nullptr;
        tail = nullptr;
    }

    [[maybe_unused]] bool isempty() {
        return ((head == nullptr) && (tail == nullptr));
    };

    [[maybe_unused]] void pushback(std::string a) {
        Node *n = new Node(a);
        if (isempty()) // if list is empty
        {
            head = n;
            tail = n;
            return;
        }
        tail->next = n;
        tail = n;

    }

    [[maybe_unused]] std::string print_head_element() {
        return head->s;
    };

    [[maybe_unused]] std::string print_tail_element() {
        return tail->s;
    };

    // TODO : print all elements of list
    [[maybe_unused]] std::vector<std::string> get_all_as_vector() {
        std::vector<std::string> out;
        Node *current_elem = head;
        while (current_elem != nullptr) {
            out.push_back(current_elem->s);
            current_elem = (current_elem->next);
        }
        std::cout << "out.size() = " << out.size() << std::endl;
        return out;
    }

    // TODO : find index of the element, return -1 if it doesnt exist
    [[maybe_unused]] const int find_element_index(const std::string _s) {
        Node *current_elem = head;
        int ind = 0;
        while (current_elem != nullptr) {
            if (current_elem->s == _s) {
                return ind;
            } else {
                current_elem = current_elem->next;
                ind++;
            }
        }
        return -1;
    }

    //TODO : delete first Node
    [[maybe_unused]] std::string pop_head() {
        std::string temp = head->s;
        head = head->next;
        return temp;
    }

    //TODO : delete tail Node
    [[maybe_unused]] std::string pop_tail() {
        std::string out = tail->s;
        Node *temp_n = head;
        while (temp_n->next != tail) {
            temp_n = temp_n->next;
        }
        tail = temp_n;
        tail->next = nullptr;
        return out;
    }

    // TODO : delete node by its value, returns index of deleted Node
    [[maybe_unused]] const int pop_by_value(std::string _s) {
        int ind = 0;
        Node *temp = head;
        Node *parent = head;
        if (head->s == _s) {
            head = head->next;
            return 0;
        }
        while (temp != nullptr) {
            if (temp->s == _s) {
                parent->next = temp->next;
                return ind;
            }
            parent = temp;
            temp = temp->next;
            ind++;
        }
        return -1;
    }

    //TODO : print element by its index
    [[maybe_unused]] std::string print_element(const int index) {
        if (isempty() == 0 && index >= 0) {
            Node *tmp = head;
            for (int i = 0; i < index; i++) {
                if (tmp->next != nullptr) {
                    tmp = tmp->next;
                } else return "List out of range";
            }
            return tmp->s;
        } else {
            return "Empty Linked List or Wrong Input";
        }
    }

    //TODO : linked list reverse function
};

