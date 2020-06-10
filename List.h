/**
 * @file List.h
 * @author your name Jose David Urena Torres
 * @brief This class is a list that contains a list head and a list tail, or list values
 * @version 0.1
 * @date 2020-06-10
 * 
 * 
 */
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
template <class T>
class List{
    public:
        /**
         * @brief Construct a new List object
         * 
         * @param head a list pointer
         * @param tail a list pointer
         * @param nullValue is only used in atomic values
         */
        List(List *head, List *tail, T nullValue){
            this->head = head;
            this->tail = tail;
            this->value = nullValue;
            this->name = "no name";
        }
        /**
         * @brief Construct a new List object
         * 
         * @param head a list pointer
         * @param tail a list pointer
         * @param name name of the list
         * @param nullValue 
         */
        List(List *head, List *tail, std::string name, T nullValue){
            this->head = head;
            this->tail = tail;
            this->value = nullValue;
            this->name = name;
        }
        /**
         * @brief Construct a new List object of an list atomic value. 
         * 
         * @param value value of the atomic value. Ex: In (3 5) 3 is atomic value and
         * 5 is an atomic value. Each atomic value is a list by itsetf
         */
        List(T value){
            this->head = nullptr;
            this->tail = nullptr;
            this->value = value;
            this->name = "no name";
        }
        /**
         * @brief Construct a new List object of an list atomic value. 
         * 
         * @param value value of the atomic value. Ex: In (3 5) 3 is atomic value and
         * 5 is an atomic value. Each atomic value is a list by itsetf
         * @param name name of the list
         */
        List(T value, std::string name){
            this->head = nullptr;
            this->tail = nullptr;
            this->value = value;
            this->name = name;
        }
        /**
         * @brief Destroy the List object
         * 
         */
        ~List(){
            delete head;
            delete tail;
            std::cout<<"Deleted: "<<this->name<<std::endl;
        }
        /**
         * @brief Get the Head object
         * 
         * @return List* head pointer
         */
        List *getHead(){
            return this->head;
        }
        /**
         * @brief Get the Tail object
         * 
         * @return List* tail pointer
         */
        List *getTail(){
            return this->tail;
        }
        /**
         * @brief Adds a head
         * 
         * @param head A head list pointer
         */
        void addHead(List *head){
            this->head = head;
        }
        /**
         * @brief Adds a tail
         * 
         * @param tail A tail list pointer
         */
        void addTail(List *tail){
            this->tail = tail;
        }
        /**
         * @brief find an atomic value in the list in a recursive way
         * 
         * @param value atomic value to be searched
         * @return true 
         * @return false 
         */
        bool find(T value){
            bool exists = false;
            //atomic value
            if(this->head == nullptr && this->tail == nullptr){
               if(value == this->value){
                   exists = true;
               } 
            }
            else{
                exists = this->head->find(value);
                if(!exists){
                    exists = this->tail->find(value);
                }
            }
            return exists;
        }
        /**
         * @brief return a string with a formatted list. Ex ((3 6) (5 2))
         * 
         * @return std::string formatted list
         */
        std::string toString(){
            std::string str="";
            if(this->head==nullptr && this->tail==nullptr){
                str = std::to_string(this->value);
            }
            else{
                str = "("+this->head->toString()+" "+this->tail->toString()+")";
            }
            return str;
        }
        /**
         * @brief Set the Name object
         * 
         * @param str name
         */
        void setName(std::string str){
            this->name = str;
        }
        /**
         * @brief Get the Name object
         * 
         * @return std::string name
         */
        std::string getName(){
            return this->name;
        }

        /**
         * @brief Get the Sub List with the name param
         * 
         * @param name name of the list
         * @return List* a sublist pointer
         */
        List * getSubList(std::string name){
            List * aux = nullptr;
            if(this->name == name){
                aux = this;
            }
            else{
                if(this->getHead()!=nullptr){
                    aux = this->getHead()->getSubList(name);
                }
                if(aux == nullptr && this->getTail()!=nullptr){
                    aux = this->getTail()->getSubList(name);
                }
            }
            return aux;
        }
    protected:
        List *head;
        List *tail;
        T value;
        std::string name;

};
#endif