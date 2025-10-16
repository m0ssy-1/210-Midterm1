#include <iostream>
using namespace std;

//constant values for demonstration purposes
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:

//node sttructure represents one element in the doublylinkedlist
  struct Node {
    int data; //values stored in trhis one
    Node *prev; //pointer to the '*previous' node
    Node *next; //pointer to the '*next' node

//constructor initialized the noe with data and previous/next pointers
    Node(int val, Node *p = nullptr, Node *n = nullptr) {
      data = val;
      prev = p;
      next = n;
    }
  };

  Node *head; //pointer to the first node in the list
  Node *tail; //pointer to the last node in the list

public:
//initializes an empty list
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }
  //inserts new node with 'value" AFTER the given position
  void insert_after(int value, int position) {
    if (position < 0) {
      cout << "Position must be >= 0." << endl;
      return;
    }
// creates new node
    Node *newNode = new Node(value);
//if list is empty, new node vecomes head and tail
    if (!head) {
      head = tail = newNode;
      return;
    }
//start at front
    Node *temp = head;
//move 'temp' to node at 'position"
    for (int i = 0; i < position && temp; ++i)
      temp = temp->next;

    //if position doesn't exist
    if (!temp) {
      cout << "Position exceeds list size. Node not inserted.\n";
      delete newNode;
      return;
    }

    //link newNode into list after temp
    newNode->next = temp->next; //connect newNodes next pointer
    newNode->prev = temp; //connects newNodes previous pointer
    if (temp->next)
      temp->next->prev = newNode; //if tempwasnt tail, links next node vack
    else
      tail = newNode; //if temp was tail, update tail pointer
    temp->next = newNode; //limk temp to newNode
  }

  // delets the first node with same 'value'
  void delete_val(int value) {
    if (!head)
      return; //nothing to dfelete if list is empty

    Node *temp = head;
    //seasch for new node with new value
    while (temp && temp->data != value)
      temp = temp->next;
//value not found
    if (!temp)
      return;
//adjust previous noed next pointer
    if (temp->prev)
      temp->prev->next = temp->next;
    else
      head = temp->next; //delets head node

      //adjust next nodes previous pointer
    if (temp->next)
      temp->next->prev = temp->prev;
    //deleting tail node
    else
      tail = temp->prev;
    //free memory
    delete temp;
  }
  //deletes node at given position
  void delete_pos(int pos) {
    if (!head) {
      cout << "List is empty." << endl;
      return;
    }
    //deletes first node
    if (pos == 1) {
      pop_front();
      return;
    }
    //outputs
    Node *temp = head;
    for (int i = 1; i < pos; i++) {
      if (!temp) {
        cout << "Position doesn't exist." << endl;
        return;
      } else
        temp = temp->next;
    }
    //deleting last element
    if (!temp) {
      cout << "Position doesn't exist." << endl;
      return;
    }
    if (!temp->next) {
      pop_back();
      return;
    }
    
    Node *tempPrev = temp->prev;
    tempPrev->next = temp->next;
    temp->next->prev = tempPrev;
    delete temp;
  }
  void push_back(int v) {
    Node *newNode = new Node(v);
    if (!tail)
      head = tail = newNode;
    else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }
  void push_front(int v) {
    Node *newNode = new Node(v);
    if (!head)
      head = tail = newNode;
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }
  void pop_front() {
    if (!head) {
      cout << "List is empty." << endl;
      return;
    }
    Node *temp = head;
    if (head->next) {
      head = head->next;
      head->prev = nullptr;
    } else
      head = tail = nullptr;
    delete temp;
  }
  void pop_back() {
    if (!tail) {
      cout << "List is empty." << endl;
      return;
    }
    Node *temp = tail;
    if (tail->prev) {
      tail = tail->prev;
      tail->next = nullptr;
    } else
      head = tail = nullptr;
    delete temp;
  }
  ~DoublyLinkedList() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  void print() {
    Node *current = head;
    if (!current) {
      cout << "List is empty." << endl;
      return;
    }
    while (current) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
  void print_reverse() {
    Node *current = tail;
    if (!current) {
      cout << "List is empty." << endl;
      return;
    }
    while (current) {
      cout << current->data << " ";
      current = current->prev;
    }
    cout << endl;
  }
};
int main() {
  cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid
 return 0;
}