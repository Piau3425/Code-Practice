#include <iostream>
using namespace std;
#ifdef OJ_MODE
#define main student_main
#endif

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* head = nullptr;

// Add the element x to the "end" of the list
void push_Back(int element) {
    if (head) {
        Node *tail = head;
        while (tail->next) tail = tail->next;
        return tail->next = new Node(element), void();
    }
    head = new Node(element);
}

// Add an element to the "head" of the list
void push_Front(int element) {
    Node *node = new Node(element);
    node->next = head;
    head = node;
}

// Delete "the specified element" from the list.
void remove_Node(int element) {
    Node **cur = &head;
    while (Node *now = *cur) {
        if (now->data == element) {
            *cur = now->next;
            return delete now, void();
        }
        cur = &now->next;
    }
}

// Check if x is in the list, Yes return True; No return False
bool contain(int element) {
    Node *now = head;
    while (now) {
        if (now->data == element) return true;
        now = now->next;
    }
    return false;
}

// Reverse linked list
void invert_List() { // nxt<-now<-prev
    Node *prev = nullptr, *now = head;
    while (now) {
        Node *nxt = now->next;
        now->next = prev;
        prev = now;
        now = nxt;
    }
    head = prev;
}

// Clear the entire list
void clean() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// DON'T TOUCH !!!!!
// Output the result
void print_List() {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

// You can modify the main() below, it won't be executed.
int main() {
    int n, x;
    string op;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "b") {
            cin >> x;
            push_Back(x);
        }
        else if (op == "f") {
            cin >> x;
            push_Front(x);
        }
        else if (op == "r") {
            cin >> x;
            remove_Node(x);
        }
        else if (op == "c") {
            cin >> x;
            cout << (contain(x) ? "True" : "False") << endl;
        }
        else if (op == "i") {
            invert_List();
        }
        else if (op == "C") {
            clean();
            cout << "Clear the list!" << endl;
        }
    }

    print_List();
    return 0;
}

// -----------------------------------------------------
// DON'T TOUCH !!!!!
#ifdef OJ_MODE
#undef main
int main() {
    int n, x;
    string op;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "b") {
            cin >> x;
            push_Back(x);
        }
        else if (op == "f") {
            cin >> x;
            push_Front(x);
        }
        else if (op == "r") {
            cin >> x;
            remove_Node(x);
        }
        else if (op == "c") {
            cin >> x;
            cout << (contain(x) ? "True" : "False") << endl;
        }
        else if (op == "i") {
            invert_List();
        }
        else if (op == "C") {
            clean();
            cout << "Clear the list!" << endl;
        }
    }

    print_List();
    return 0;
}
#endif