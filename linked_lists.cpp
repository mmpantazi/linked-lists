#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node *HEAD = NULL;

class linkedList {
    public:
        void createList(Node* &HEAD);
        void displayList(Node* HEAD);
        void insertAfterNode(Node* prev_node);
        void insertNodeAtBegin();
        void insertNodeAtEnd(Node* &HEAD);
	Node *getNodeByIndex();
	Node *getNodeByValue();
	void updateNodeValue();
        void deleteNode();
};

void threeSecondsLoading(){
    for (int i = 1; i <= 3; i++)
    {
        cout << ".";
        Sleep(1000);
    }
}

void displayMenu(){
    cout << "---MAIN MENU---\n"
        "1.Insert element at the beggining of the list\n"
        "2.Insert element at the end of the list\n"
        "3.Insert after a specific element\n"
        "4.Delete element\n"
        "5.Find element by index\n"
        "6.Edit element\n"
        "7.Find element by value\n"
        "8.Create list\n"
        "9.Display list\n"
        "Option: ";
}

int main()
{
    int option;
    linkedList l;

    while (true){
        displayMenu();
        cin >> option;
        switch (option){
            case 1:
                system("cls");
                l.insertNodeAtBegin();
                threeSecondsLoading();
                system("cls");
                break;
            case 2:
                system("cls");
                l.insertNodeAtEnd(HEAD);
                threeSecondsLoading();
                system("cls");
                break;
            case 3:
                system("cls");
                l.insertAfterNode(HEAD);
                threeSecondsLoading();
                system("cls");
                break;
            case 4:
                system("cls");
                if (HEAD) {
                    l.deleteNode();
                    threeSecondsLoading();
                }
                system("cls");
                break;
            case 5:
                system("cls");
                if (HEAD) {
                    cout << l.getNodeByIndex()->data;
                    threeSecondsLoading();
                }
                system("cls");
                break;
            case 6:
                system("cls");
                l.updateNodeValue();
                if (HEAD) threeSecondsLoading();
                system("cls");
                break;
            case 7:
                system("cls");
                l.getNodeByValue();
                threeSecondsLoading();
                system("cls");
                break;
            case 8:
                system("cls");
                l.createList(HEAD);
                system("cls");
                break;
            case 9:
                system("cls");
                l.displayList(HEAD);
                if (HEAD) threeSecondsLoading();
                system("cls");
                break;
            default:
                return 0;
        }
    }
}

// Creare lista  - va permite crearea unei liste cu mai multe elem, inserate in ordine: primul,
// al doilea, etc., elementele fiind introduse de la tastatura
void linkedList :: createList(Node* &HEAD)
{
    int n;
    cout << "Number of elements: "; cin >> n;


    Node *TAIL = HEAD;
    cout << "Elements: ";
    for (int i = 1; i <= n; i++)
    {
        Node *node = new Node;
        cin >> node->data;
        node->next = NULL;
        if (i == 1)
            HEAD = node;
        else
            TAIL->next = node;
        TAIL = node;
    }
}

// Afisare lista – afisarea elementelor listei (de ex. 2->4->9->NULL)
void linkedList :: displayList(Node* HEAD)
{
    if (HEAD == NULL) return;

    for (Node *iter = HEAD; iter != NULL; iter = iter->next)
        cout << iter->data <<"->";
    cout << "NULL" << endl;
}

// Introducere elem – se va cere valoarea de introdus si pozitia noului elem (dupa un element dat)
void linkedList :: insertAfterNode(Node* prev_node)
{
    if (prev_node == NULL)
    {
        cout << "Overflow. Node parameter cannot be NULL.";
        return;
    }

    int new_data;
    cout << "Value of the data to be added: "; cin >> new_data;

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Introducere elem – se va cere valoarea de introdus si pozitia noului elem (la inceput)
void linkedList :: insertNodeAtBegin()
{
    int new_data;
    cout << "Element to be added at the beginning of the list: "; cin >> new_data;

    Node* temp = new Node;
    temp->data = new_data;
    temp->next = HEAD;
    HEAD = temp;
}

// Introducere elem – se va cere valoarea de introdus si pozitia noului elem (la sfarsit)
void linkedList :: insertNodeAtEnd(Node* &HEAD)
{
    int new_data;
    cout << "Element to be added at the end of the list: "; cin >> new_data;

    Node* temp = new Node;
    temp->data = new_data;
    temp->next = NULL;
    if (HEAD == NULL)
    {
        HEAD = temp;
    }
    else
    {
       Node* temp2 = HEAD;
       while (temp2->next != NULL)
            temp2 = temp2->next;
       temp2->next = temp;
    }
}

// Stergere elem  - se va cere informatia elementului de sters; va afisa elementul sters (pentru validare)
void linkedList :: deleteNode()
{
    if (HEAD == NULL) return;

    int n;
    cout << "Index of the element to be deleted: "; cin >> n;

    Node* temp1 = HEAD;
    if(n == 1){
        cout << "Element " << HEAD->data << " was deleted.\n";
        HEAD = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i < n-2; i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    cout << "Element " << temp2->data << " was deleted.\n";
    free(temp2);
}

// Modificare elem  - se va cere pozitia elementului care se doreste sa se modifice (de ex. al i-lea element)
// si noua valoare; elementul dat va fi modificat
void linkedList :: updateNodeValue()
{
    if (HEAD == NULL) return;

    int index, new_data;
    cout << "Index of the element to update: "; cin >> index;
    cout << "New value: "; cin >> new_data;

    Node* temp = HEAD;
    for (int i = 1; i < index; i++){
        temp = temp->next;
    }
    cout << "Data value " << " is now " << new_data << ".\n";
    temp->data = new_data;
}

// Accesare elem  - se va cere pozitia elementului care se doreste sa se acceseze (de ex. al i-lea element);
// va returna pointer la elementul gasit sau NULL daca nu se gaseste
Node* linkedList :: getNodeByIndex()
{
    int index;
    cout << "Index of the element to be returned: "; cin >> index;

    Node* temp = HEAD;
    int pos = 1;
    if (index < 1) {
        cout << "Invalid index." << endl;
        return NULL;
    }

    while (pos < index) {
        if (temp->next == NULL){
            cout << "Invalid index." << endl;
            return NULL;
        }
        temp = temp->next;
        pos++;
    }
    return temp;
}

// Cautare elem – se cauta o valoare data in lista; va returna pointer
// la elementul gasit sau NULL daca valoarea nu este gasita
Node* linkedList :: getNodeByValue() {

    int data;
    cout << "Value of the element to look for: "; cin >> data;

    Node *temp = HEAD;
    int index = 1;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL)
        cout << "Element does not exist." << endl;
    else
        cout << "Element found on index: " << index << endl;

    return temp;
}
