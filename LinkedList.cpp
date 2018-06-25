#include "LinkedList.h"
//constructor
LinkedList::LinkedList() {
    length=0;
}
//copy constructor
LinkedList::LinkedList(const LinkedList &list) {
        this->head= list.head;
        this->tail=list.tail;
        this->length=list.length;
}

//this method adds new data to the linkedlist
void LinkedList::pushTail(Member data) {
    length++;
    if(head==0){
        head = new Node(data);
        tail= head;
    }
    else{
        tail->next = new Node(data);
        tail = tail->next;
    }
}
//operator overloading
LinkedList& LinkedList::operator=(const LinkedList &list) {
    this->length=list.length;
    //if this object is already have data, delete them and copy the lists data.
    if(head){
        delete this->head;
        delete this->tail;
        this->head = new Node(*(list.head));
        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        this->tail=tmp;
    }

    return *this;
}
//destructor
LinkedList::~LinkedList() {
        if(head) delete head;
}
