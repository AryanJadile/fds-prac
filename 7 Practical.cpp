// // # Name: Aryan Jadile
// // # Roll no: 29
// // # SE Computer

// // # <---------------------------------------------------------------------->

// #include <iostream>
// #include <string>
// using namespace std;

// class node {
//     int prn;
//     string name;
//     node* next;

// public:
//     node(int x, string nm) {
//         prn = x;
//         next = NULL;
//         name = nm;
//     }

//     friend class list;
// };

// class list
// {
//     node* start;

// public:
//     list() 
//     {
//         start = NULL;
//     }

//     void create();
//     void display();
//     void insertAtBeginning();
//     void insertAtEnd();
//     void insertAfter();
//     void deleteAtFirst();
//     void deleteByValue();
//     void deleteAtEnd();
//     int computeTotal();
//     void sortList();
//     void concatList(list& q1);
//     void displayRev(node* t);
//     bool reverseDisplay();
// };

// void list::displayRev(node* t)
// {
//     if (t == NULL)
//         return;
//     else 
//     {
//         displayRev(t->next);
//         cout << "\nPRN NO:" << t->prn << " Name: " << t->name;
//     }
// }

// void list::create() {
//     int no;
//     string nam;
//     if (start == NULL) {
//         cout << "Enter PRN number: ";
//         cin >> no;
//         cout << "Enter name: ";
//         cin >> nam;
//         start = new node(no, nam);
//         cout << "\n=============== List Created ===============";
//     } else {
//         cout << "\nList is already created.";
//     }
// }

// void list::display() {
//     node* t;
//     t = start;
//     if (start == NULL)
//         cout << "\nList is Empty";
//     else {
//         cout << "\n=============== List: ===============\n";
//         while (t != NULL) {
//             cout << t->prn << " " << t->name << " \n";
//             t = t->next;
//         }
//     }
// }

// void list::insertAtBeginning() {
//     int no;
//     string nam;
//     node* temp;
//     if (start == NULL) {
//         create();
//     } else {
//         cout << "\nEnter PRN Number : ";
//         cin >> no;
//         cout << "Enter Name : ";
//         cin >> nam;
//         temp = new node(no, nam);
//         temp->next = start;
//         start = temp;
//         cout << "Inserted " << temp->name << " at the beginning.";
//     }
// }

// void list::insertAtEnd() {
//     int no;
//     string nam;
//     node* t;
//     if (start == NULL)
//         create();
//     else {
//         cout << "\nEnter PRN Number : ";
//         cin >> no;
//         cout << "Enter Name : ";
//         cin >> nam;
//         t = start;
//         while (t->next != NULL)
//             t = t->next;
//         node* p = new node(no, nam);
//         t->next = p;
//     }
// }

// void list::insertAfter() {
//     int prev_no;
//     cout << "\nEnter PRN No. after which you want to insert : ";
//     cin >> prev_no;
//     node* t;
//     t = start;
//     string nam;
//     int flag = 0, no;
//     while (t != NULL) {
//         if (t->prn == prev_no) {
//             flag = 1;
//             break;
//         }
//         t = t->next;
//     }
//     if (flag == 1) {
//         node* p;
//         cout << "\nEnter PRN Number : ";
//         cin >> no;
//         cout << "Enter Name : ";
//         cin >> nam;
//         p = new node(no, nam);
//         p->next = t->next;
//         t->next = p;
//     } else {
//         cout << "\n" << prev_no << " is not in the list.";
//     }
// }

// void list::deleteAtFirst() {
//     node* t;
//     if (start == NULL)
//         cout << "\nClub is Empty..";
//     else {
//         t = start;
//         start = start->next;
//         t->next = NULL; // Not necessary
//         delete t;
//         cout << "\nPresident deleted..";
//     }
// }

// void list::deleteByValue() {
//     int no, flag = 0;
//     node* t, *prev;
//     if (start == NULL)
//         cout << "\nList/Club is empty";
//     else {
//         cout << "\nEnter PRN No. of member to be deleted : ";
//         cin >> no;
//         t = start->next; // t=start if we have to delete president also..start->next is the first member
//         while (t->next != NULL) {
//             if (t->prn == no)
//             {
//                 flag = 1;
//                 break;
//             }
//             prev = t;
//             t = t->next;
//         }
//         if (flag == 1)
//         {
//             prev->next = t->next;
//             t->next = NULL;
//             delete t;
//             cout << "\nMember with PRN No: " << no << " is deleted.";
//         } else
//             cout << "\nMember not found in List./President or Secretary cannot be deleted.";
//     }
// }

// void list::deleteAtEnd()
// {
//     node* t, *prev;
//     t = start;
//     if (start == NULL)
//         cout << "\nClub is Empty..";
//     else
//     {
//         while (t->next != NULL)
//         {
//             prev = t;
//             t = t->next;
//         }
//         prev->next = NULL;
//         delete t;
//         cout << "\nSecretary Deleted.";
//     }
// }

// int list::computeTotal()
// {
//     node* t;
//     int count = 0;
//     t = start;
//     if (start == NULL)
//     {
//         cout << "\nList is empty.";
//         return 0;
//     }
//     while (t != NULL)
//     {
//         count++;
//         t = t->next;
//     }
//     return count;
// }

// void list::sortList()
// {
//     node* i, *j, *last = NULL;
//     int tprn;
//     string tname;
//     if (start == NULL)
//     {
//         cout << "\nList is empty.";
//         return;
//     }
//     for (i = start; i->next != NULL; i = i->next) {
//         for (j = start; j->next != last; j = j->next) {
//             if ((j->prn) > (j->next->prn)) 
//             {
//                 tprn = j->prn;
//                 tname = j->name;
//                 j->prn = j->next->prn;
//                 j->name = j->next->name;
//                 j->next->prn = tprn;
//                 j->next->name = tname;
//             }
//         }
//     }
//     cout << "\n List is sorted.";
//     display();
// }

// void list::concatList(list & q1)
// {
//     node* t, *p;
//     t = q1.start;
//     if (t == NULL)
//     {
//         cout << "\nList 2 is empty";
//         return;
//     }
//     p = start; // first list
//     while (p->next != NULL)
//     {
//         p = p->next;
//     }
// }

// #include<iostream>
// using namespace std;

// class Node {
// public:
//     double stime;
//     double etime;
//     bool flag;
//     string name;
//     Node* next;

//     Node(double stime, double etime) {
//         this->stime = stime;
//         this->etime = etime;
//         this->name = "Not Booked";
//         this->flag = false;
//         this->next = NULL;
//     }
// };

// void clist(Node* head) {
//     int t = 1;
//     Node* tra = head;
//     while (t < 5) {
//         double st = t;
//         double et = st + 1;
//         Node* temp = new Node(st, et);
//         if (head->next == NULL) {
//             head->next = temp;
//         }
//         else {
//             while (tra->next != NULL) {
//                 tra = tra->next;
//             }
//             tra->next = temp;
//         }
//         t = t + 1.00;
//     }
// }

// void displaySlots(Node* head) 
// {
//     int count=0;
//     Node* temp = head;
//     cout << "Slotes Are :  "<< endl;
//     cout << "---------------------------" << endl;
//     while (temp != NULL)
//     {
//             count ++;
//             cout << count<<" : "<<endl;
//             cout << "Starting Time : " << temp->stime << endl;
//             cout << "Ending Time : " << temp->etime <<endl;
//         if (temp->flag) 
//         {
//             cout <<"Booked Slot By "<<temp->name<<"\n\n";
//         }
//         else
//         {
//             cout <<"Free Slot "<<"\n\n";
//         }
//         temp = temp->next;
//     }
//     cout << "---------------------------" << endl;
// }

// void displayFreeSlots(Node* head) 
// {
//     int count=0;
//     Node* temp = head;
//     cout << "Available Free Slotes Are :  "<< endl;
//     cout << "---------------------------" << endl;
//     while (temp != NULL)
//     {
//         if (!temp->flag) {
//             count ++;
//             cout << count<<" : "<<endl;
//             cout << "Starting Time: " << temp->stime << endl;
//             cout << "Ending Time: " << temp->etime <<"\n";
//         }
//         temp = temp->next;
//     }
//     cout << "---------------------------" << endl;
//     if(count==0)
//     {
//         cout<<"Sorry Free Slots Not Available !!! "<<endl;
//     }
// }

// void displayBookSlots(Node* head) 
// {
//     int count=0;
//     Node* temp = head;
//     cout << "Booked Slotes Are :  "<< endl;
//     cout << "---------------------------" << endl;
//     while (temp != NULL)
//     {
//         if (temp->flag) {
//             count ++;
//             cout << count<<" : "<<endl;
//             cout << "Starting Time : " << temp->stime << endl;
//             cout << "Ending Time : " << temp->etime <<endl;
//             cout << "Name : " << temp->name <<"\n";
//         }
//         temp = temp->next;
//     }
//     cout << "---------------------------" << endl;
//     if(count==0)
//     {
//         cout<<"Sorry Free Slots Not Available !!! "<<endl;
//     }
// }

// void bookSlotes(Node* head)
// {   double st;
//     string n;
//     displayFreeSlots(head);
//     cout<<"Enter Start Time : ";
//     cin>>st;
//     cout<<"Enter Your Name : ";
//     cin>>n;
//     Node* tra = head;
//     while (tra->stime != st) 
//         {
//             tra = tra->next;
//         }
//         tra->name=n;
//         tra->flag=1;
//         cout<<"Slot Booked Successfully....!"<<endl;

// }
// int main() 
// {
//     Node* head = new Node(12.00, 1.00);
//     bool f=1;
//     int ch,ch1;
//     clist(head);
//     /*displayFreeSlots(head);
//     bookSlotes(head);
//     displayBookSlots(head);
//     return 0;*/
    
//     while(f)
//     {
//       cout<<"1: Display Free Slots " <<endl;
//       cout<<"2: Book Slot " <<endl;
//       cout<<"3: Display Booked Slots " <<endl;
//       cout<<"4: Display  Slots " <<endl;
//       cout<<"5: Exit "<<endl;
//       cout<<"Enter Your Choice : " <<endl;
//       cin>>ch;
      
//       switch(ch)
//       {
//             case 1:
//                 displayFreeSlots(head);
//                 break;
//             case 2:
//                 bookSlotes(head);
//                 break;
//             case 3:
//                 displayBookSlots(head);
//                 break;
//             case 4:
//                 displaySlots(head);
//                 break;
//             case 5:
//                 f=0;
//                 cout<<"Thank You...!";
    
//       }
      
//     }
// }

#include <iostream>
#include <string>
using namespace std;

class node {
    int prn;
    string name;
    node* next;

public:
    node(int x, string nm) {
        prn = x;
        next = NULL;
        name = nm;
    }

    friend class list;
};

class list {
    node* start;

public:
    list() {
        start = NULL;
    }

    void create();
    void display();
    void insertAtBeginning();
    void insertAtEnd();
    void insertAfter();
    void deleteAtFirst();
    void deleteByValue();
    void deleteAtEnd();
    int computeTotal();
    void sortList();
    void concatList(list& q1);
    void displayRev(node* t);
    bool reverseDisplay();
};

void list::displayRev(node* t) {
    if (t == NULL)
        return;
    else {
        displayRev(t->next);
        cout << "\nPRN NO:" << t->prn << " Name: " << t->name;
    }
}

void list::create() {
    int no;
    string nam;
    if (start == NULL) {
        cout << "Enter PRN number: ";
        cin >> no;
        cout << "Enter name: ";
        cin >> nam;
        start = new node(no, nam);
        cout << "\n=============== List Created ===============";
    } else {
        cout << "\nList is already created.";
    }
}

void list::display() {
    node* t;
    t = start;
    if (start == NULL)
        cout << "\nList is Empty";
    else {
        cout << "\n=============== List: ===============\n";
        while (t != NULL) {
            cout << t->prn << " " << t->name << " \n";
            t = t->next;
        }
    }
}

void list::insertAtBeginning() {
    int no;
    string nam;
    node* temp;
    if (start == NULL) {
        create();
    } else {
        cout << "\nEnter PRN Number : ";
        cin >> no;
        cout << "Enter Name : ";
        cin >> nam;
        temp = new node(no, nam);
        temp->next = start;
        start = temp;
        cout << "Inserted " << temp->name << " at the beginning.";
    }
}

void list::insertAtEnd() {
    int no;
    string nam;
    node* t;
    if (start == NULL)
        create();
    else {
        cout << "\nEnter PRN Number : ";
        cin >> no;
        cout << "Enter Name : ";
        cin >> nam;
        t = start;
        while (t->next != NULL)
            t = t->next;
        node* p = new node(no, nam);
        t->next = p;
    }
}

void list::insertAfter() {
    int prev_no;
    cout << "\nEnter PRN No. after which you want to insert : ";
    cin >> prev_no;
    node* t;
    t = start;
    string nam;
    int flag = 0, no;
    while (t != NULL) {
        if (t->prn == prev_no) {
            flag = 1;
            break;
        }
        t = t->next;
    }
    if (flag == 1) {
        node* p;
        cout << "\nEnter PRN Number : ";
        cin >> no;
        cout << "Enter Name : ";
        cin >> nam;
        p = new node(no, nam);
        p->next = t->next;
        t->next = p;
    } else {
        cout << "\n" << prev_no << " is not in the list.";
    }
}

void list::deleteAtFirst() {
    node* t;
    if (start == NULL)
        cout << "\nClub is Empty..";
    else {
        t = start;
        start = start->next;
        t->next = NULL; // Not necessary
        delete t;
        cout << "\nPresident deleted..";
    }
}

void list::deleteByValue() {
    int no, flag = 0;
    node* t, *prev;
    if (start == NULL)
        cout << "\nList/Club is empty";
    else {
        cout << "\nEnter PRN No. of member to be deleted : ";
        cin >> no;
        t = start->next; // t=start if we have to delete president also..start->next is the first member
        while (t->next != NULL) {
            if (t->prn == no) {
                flag = 1;
                break;
            }
            prev = t;
            t = t->next;
        }
        if (flag == 1) {
            prev->next = t->next;
            t->next = NULL;
            delete t;
            cout << "\nMember with PRN No: " << no << " is deleted.";
        } else
            cout << "\nMember not found in List./President or Secretary cannot be deleted.";
    }
}

void list::deleteAtEnd() {
    node* t, *prev;
    t = start;
    if (start == NULL)
        cout << "\nClub is Empty..";
    else {
        while (t->next != NULL) {
            prev = t;
            t = t->next;
        }
        prev->next = NULL;
        delete t;
        cout << "\nSecretary Deleted.";
    }
}

int list::computeTotal() {
    node* t;
    int count = 0;
    t = start;
    if (start == NULL) {
        cout << "\nList is empty.";
        return 0;
    }
    while (t != NULL) {
        count++;
        t = t->next;
    }
    return count;
}

void list::sortList() {
    node* i, *j, *last = NULL;
    int tprn;
    string tname;
    if (start == NULL) {
        cout << "\nList is empty.";
        return;
    }
    for (i = start; i->next != NULL; i = i->next) {
        for (j = start; j->next != last; j = j->next) {
            if ((j->prn) > (j->next->prn)) {
                tprn = j->prn;
                tname = j->name;
                j->prn = j->next->prn;
                j->name = j->next->name;
                j->next->prn = tprn;
                j->next->name = tname;
            }
        }
    }
    cout << "\n List is sorted.";
    display();
}

void list::concatList(list& q1) {
    node* t, *p;
    t = q1.start;
    if (t == NULL) {
        cout << "\nList 2 is empty";
        return;
    }
    p = start; // first list
    while (p->next != NULL) {
        p = p->next;
    }
