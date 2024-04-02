#include <iostream>
using namespace std;

class Node{
public:
    char id;
    Node *next;

    Node(){
        next = NULL;
    }
};

class LinkedList{
public:
    Node *head;
    Node *tail;

    LinkedList(){
        head = tail = NULL;
    }

    void insertToHead(char data){
        Node *node = new Node;
        node -> id = data;

        if(head == NULL){
            head = tail = node;
        }else{
            Node *tmp = head;
            head = node;
            head -> next = tmp;
        }
    }

    void insertToTail(char data){
        Node *node = new Node;
        node -> id = data;

        if(head == NULL){
            head = tail = node;
        }else{
            tail -> next = node;
            tail = node;
        }
        
    }

    void insertDataAfter(char data, char after){
        if(head == NULL){
            cout << "Error : LinkedList is Empty!" << endl;
        }else if(after == tail->id){
            insertToTail(data);
        }else{
            Node *tmp = head;
            while(tmp != NULL && tmp->id!=after){
                tmp = tmp->next;
            }

            if(tmp == NULL){
                cout << "After data not found" << endl;
            }else{
                Node*newNode = new Node();
                newNode->id = data;
                
                newNode->next = tmp->next;
                tmp->next = newNode;
            }
        }
    }

    void printAll(){
        Node *tmp = head;
        while(tmp != NULL){
            cout << tmp -> id << " > ";
            tmp = tmp -> next;
        }
    }

    void deleteData(char target){
        Node *current = head;
        Node *prev = NULL;

        // If target data is in the head
        if (current != NULL && current->id == target) {
            head = current->next;
            delete current;
            return;
        }

        while (current != NULL && current->id != target) {
            prev = current;
            current = current->next;
        }

        if(current == NULL) {
            cout << "Data not found!" << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }
};

int main(){
    LinkedList list1;

    list1.insertToHead('A');
    list1.insertToTail('B');

    cout << list1.head->id << endl;
    cout << list1.tail->id << endl;

    list1.insertToHead('X');

    cout << list1.head->id << endl;
    cout << list1.tail->id << endl;

    list1.insertToHead('Y');
    list1.insertToTail('C');

    cout << list1.head->id << endl;
    cout << list1.tail->id << endl;

    list1.insertDataAfter('Z', 'K');

    list1.deleteData('Y');

    cout << endl;

    list1.printAll();
}
