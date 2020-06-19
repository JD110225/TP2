#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <sstream>
template <class T>
class List {
public:
    List() {

    }
    List(List* head, List* tail, T nullValue) {
        this->head = head;
        this->tail = tail;
        this->value = nullValue;
        this->name = "no name";
    }
    List(List* head, List* tail, std::string name, T nullValue) {
        this->head = head;
        this->tail = tail;
        this->value = nullValue;
        this->name = name;
    }

    List(T value) {
        this->head = nullptr;
        this->tail = nullptr;
        this->value = value;
        this->name = "no name";
    }
    List(T value, std::string name) {
        this->head = nullptr;
        this->tail = nullptr;
        this->value = value;
        this->name = name;
    }
    ~List() {
        delete head;
        delete tail;
        std::cout << "Deleted: " << this->name << std::endl;
    }
    List* getHead() {
        return this->head;
    }
    List* getTail() {
        return this->tail;
    }

    T getValue() {
        return value;
    }
    void addHead(List* head) {
        this->head = head;
    }
    void addTail(List* tail) {
        this->tail = tail;
    }
    bool find(T value) {
        bool exists = false;
        //atomic value
        if (this->head == nullptr && this->tail == nullptr) {
            if (value == this->value) {
                exists = true;
            }
        }
        else {
            exists = this->head->find(value);
            if (!exists) {
                exists = this->tail->find(value);
            }
        }
        return exists;
    }
    std::string toString() {
        std::stringstream ss;
        if (this->head == nullptr && this->tail == nullptr) {
            ss << this->value;
        }
        else {
            ss << "(" << this->head->toString() << " " << this->tail->toString() << ")";
        }
        return ss.str();
    }
    void setName(std::string str) {
        this->name = str;
    }

    std::string getName() {
        return this->name;
    }
protected:
    List* head;
    List* tail;
    T value;
    std::string name;

};
#endif
