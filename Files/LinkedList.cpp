#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *head, *tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void createNode(int);
    void display();
    int getLength();
    void insertAtFirst(int);
    void insertAtEnd(int);
    void insertAtPosition(int, int);
    void deleteFirst();
    void deleteLast();
    void deleteAtPosition(int pos);

};

void LinkedList::createNode(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
void LinkedList::display(){
    Node *temp = new Node;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
}
int LinkedList::getLength() {
    Node *temp = new Node;
    temp = head;
    int largo = 0;
    while(temp != NULL){
        temp = temp->next;
        largo++;
    }
    return largo;
}

void LinkedList::insertAtFirst(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}
void LinkedList::insertAtEnd(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}
void LinkedList::insertAtPosition(int pos, int value){
    Node *pre = new Node;
    Node *cur = new Node;
    Node *temp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++){
        pre = cur;
        cur = cur->next;
    }
    temp->data = value;
    pre->next = temp;
    temp->next = cur;
}

void LinkedList::deleteFirst(){
    Node *temp = new Node;
    temp = head;
    head = head->next;
    delete temp;
}
void LinkedList::deleteLast(){
    Node *current = new Node;
    Node *previous = new Node;
    current = head;
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
}
void LinkedList::deleteAtPosition(int pos){
    Node *current = new Node;
    Node *previous = new Node;
    current = head;
    for(int i = 1; i < pos; i++){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}


int main(){
    LinkedList list;
    list.createNode(25);
    list.createNode(50);
    list.createNode(90);
    list.createNode(40);

    cout<<"\n--------------------------------------------------\n";
    cout<<"---------------Displaying All nodes---------------";
    cout<<"\n--------------------------------------------------\n";
    list.display();
    cout << endl << " ** Largo de la lista: " << list.getLength() << " ** " << endl << endl;

    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Inserting At End-----------------";
    cout<<"\n--------------------------------------------------\n";
    list.insertAtEnd(55);
    list.display();
    cout << endl << " ** Largo de la lista: " << list.getLength() << " ** " << endl << endl;

    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Inserting At Start----------------";
    cout<<"\n--------------------------------------------------\n";
    list.insertAtFirst(50);
    list.display();
    cout << endl << " ** Largo de la lista: " << list.getLength() << " ** " << endl << endl;

    cout<<"\n--------------------------------------------------\n";
    cout<<"-------------Inserting At Particular--------------";
    cout<<"\n--------------------------------------------------\n";
    list.insertAtPosition(5, 60);
    list.display();
    cout << endl << " ** Largo de la lista: " << list.getLength() << " ** " << endl << endl;

    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Deleting At Start-----------------";
    cout<<"\n--------------------------------------------------\n";
    list.deleteFirst();
    list.display();
    cout << endl << " ** Largo de la lista: " << list.getLength() << " ** " << endl << endl;

    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Deleting At End-------------------";
    cout<<"\n--------------------------------------------------\n";
    list.deleteLast();
    list.display();
    cout << endl << " ** Largo de la lista: " << list.getLength() << " ** " << endl << endl;

    cout<<"\n--------------------------------------------------\n";
    cout<<"--------------Deleting At Particular--------------";
    cout<<"\n--------------------------------------------------\n";
    list.deleteAtPosition(4);
    list.display();
    cout << endl << " ** Largo de la lista: " << list.getLength() << " ** " << endl << endl;

    cout<<"\n--------------------------------------------------\n";

    return 0;
}