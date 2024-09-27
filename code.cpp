#include <iostream>
using namespace std;
class Node {
public:
 int data;
 Node* next;
 Node(int value) {
 data = value;
 next = nullptr;
 }
};
class CircularLinkedList {
public:
 Node* head;
 CircularLinkedList() : head(nullptr) {}
 void append(int data) {
 Node* newNode = new Node(data);
 if (head == nullptr) {
 head = newNode;
 newNode->next = head;
 } else {
 Node* temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 temp->next = newNode;
 newNode->next = head;
 }
 }
 void printList() {
 if (head == nullptr) {
 cout << "List is empty." << endl;
 return;
 }
 Node* temp = head;
 int count = 0;
 do {
 cout << temp->data << " -> ";
 temp = temp->next;
 count++;
 } while (temp != head && count < 20);

 if (count >= 20) {
 cout << "... (circular, possibly disrupted)" << endl;
 } else {
 cout << "(head)" << endl;
 }
 }
 void findAndFixDisruption() {
 if (head == nullptr) {
 return;
 }
 Node* current = head;
 Node* last = nullptr;

 while (current->next != head) {
 last = current;
 current = current->next;
 }

 if (last && last->next != head) {
 last->next = head; // Fix it to point to the head
 cout << "Disruption fixed: Last node now points to head." << endl;
 } else {
 cout << "No disruption detected." << endl;
 }
 }
};
int main() {
 CircularLinkedList cll;
 int n, value;
 cout << "Enter the number of keys to insert: ";
 cin >> n;
 for (int i = 0; i < n; ++i) {
 cout << "Enter value " << (i + 1) << ": ";
 cin >> value;
 cll.append(value);
 }

 Node* node = cll.head;
 while (node->next != cll.head) {
 node = node->next;
 }
 if (cll.head && cll.head->next) {
 node->next = cll.head->next; // Make last node point to the second node
 }
 cout << "Disrupted Circular Linked List:" << endl;
 cll.printList();
 cll.findAndFixDisruption();
 cout << "Corrected Circular Linked List:" << endl;
 cll.printList();
 return 0;
}