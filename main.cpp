/*****************************************************
this main contains examples of how to use class List
*****************************************************/
#include <iostream>
#include "List.h"
int main(){
    //atomic lists
    //the name is optional
    List<int> * list1 = new List<int>(3, "list1");
    List<int> * list2 = new List<int>(5, "list2");
    List<int> * list3 = new List<int>(6, "list3");
    List<int> * list4 = new List<int>(7, "list4");
    List<int> * list5 = new List<int>(10, "list5");

    //non atomic lists: lists that contains other lists
    //the name is optional
    List<int> *list6 = new List<int>(list1, list2, "list6", -1);
    List<int> *list7 = new List<int>(list3, list4, "list7", -1);
    List<int> *list8 = new List<int>(list6, list7, "list8", -1);
    List<int> *list9 = new List<int>(list5, list8, "list9", -1);

    //show lists
    std::cout<<"Name: "<<list9->getName()<<std::endl;
    std::cout<<list9->toString()<<std::endl;

    //get head and tail of a list
    std::cout<<"Head: "<<list9->getHead()->toString()<<std::endl;
    std::cout<<"Tail: "<<list9->getTail()->toString()<<std::endl;

    //search (atomic) values in a list
    std::cout<<"Find -1: "<<list9->find(-1)<<std::endl;
    std::cout<<"Find 10: "<<list9->find(10)<<std::endl;

    //getting sublists by name
    //Example 1
    List<int> *aux = list9->getSubList("list0");
    if(aux!=nullptr){
        std::cout<<"List list0:  "<<aux->toString()<<std::endl;
    }
    else{
        std::cout<<"List list0:  Doesn't exists"<<std::endl;
    }
    //Example 2
    aux = list9->getSubList("list6");
    if(aux!=nullptr){
        std::cout<<"List list6:  "<<aux->toString()<<std::endl;
    }
    else{
        std::cout<<"Doesn't exists"<<std::endl;
    }

    //free memory
    delete list9;

}