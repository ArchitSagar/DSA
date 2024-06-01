#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int length = 0;

class Node {
public:
  int data;
  Node *next;
} *head, *tail;

void insert(int val) {
  Node *a = new Node();
  a->data = val;
  if (head == NULL)
    tail = a;
  a->next = head;
  head = a;
  length++;
}

void insertAtend(int val) {
  Node *a = new Node();
  a->data = val;
  a->next = NULL;
  if (tail == NULL) {
    tail = a;
    head = a;
  } else {
    tail->next = a;
    tail = a;
  }
  length++;
}

void insertAtpos(int val, int pos) {

  if (pos == 1) {
    insert(val);
    return;
  }
  Node *temp = head;
  int cnt = 1;

  while (cnt < pos - 1) {
    temp = temp->next;
    cnt++;
  }

  if (temp->next == NULL) {
    insertAtend(val);
    return;
  }

  Node *a = new Node();
  a->data = val;
  a->next = temp->next;
  temp->next = a;
  length++;
}

void search(int data) {
  Node *temp = head;
  while (temp != NULL) {
    if (data == temp->data) {
      cout << "Data found" << endl << "data is " << temp->data << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "Data not found" << endl;
}

void deleteAtHead() {
  Node *temp = head;
  head = head->next;
  free(temp);
  length--;
}

void deleteAtEnd() {
  Node *end = tail;
  Node *temp = head;
  for (int i = 1; i < length - 1; i++)
    temp = temp->next;
  temp->next = NULL;
  tail = temp;
  free(end);
  length--;
}

void deleteAtPos(int pos) {
  if (pos == 1) {
    deleteAtHead();
    return;
  }
  if (pos == length) {
    deleteAtEnd();
    return;
  }
  Node *prev = NULL;
  Node *end = head;
  for (int i = 1; i < pos; i++) {
    prev = end;
    end = end->next;
  }
  prev->next = end->next;
  free(end);
  length--;
}

void display() {
  Node *temp = head;
  if (temp != NULL)
    cout << "Data are:  ";
  else
    cout << "No Data Available" << endl;

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}


int main() {
  head = NULL;
  tail = NULL;
  int op, pos, data;
  while (true) {
    cout << "enter a choice\n 1.insertAthead\n 2.insertAtEnd\n 3.insertAtPos\n "
            "4.display\n 5.Search\n 6.DeleteAtHead\n 7.DeleteAtEnd\n "
            "8.DeleteAtPos\n 9.exit"
         << endl;
    cin >> op;
    switch (op) {
    case 1:
      cout << "enter a data" << endl;
      cin >> data;
      insert(data);
      break;
    case 2:
      cout << "enter a data" << endl;
      cin >> data;
      insertAtend(data);
      break;
    case 3:
      cout << "enter a data" << endl;
      cin >> data;
      while (true) {
        cout << "enter a pos starting from 1" << endl;
        cin >> pos;
        if (pos > length + 1 || pos < 1)
          cout << "Invalid position" << endl
               << "Re-enter position again" << endl;
        else
          break;
      }
      insertAtpos(data, pos);
      break;
    case 4:
      display();
      break;
    case 5:
      int x;
      cout << "enter the data to be searched" << endl;
      cin >> x;
      search(x);
      break;
    case 6:
      deleteAtHead();
      break;
    case 7:
      deleteAtEnd();
      break;
    case 8:
      while (true) {
        cout << "enter the pos you want to delete" << endl;
        cin >> pos;
        if (pos > length + 1 || pos < 1)
          cout << "Invalid position" << endl
               << "Re-enter position again" << endl;
        else
          break;
      }
      deleteAtPos(pos);
      break;
    case 9:
      exit(0);
    default:
      cout << "wrong option" << endl;
      break;
    }
  }
  return 0;
}
