// Name: Aryan Jadile
// Roll no: 29
// SE Computer

// <---------------------------------------------------------------------->

#include<iostream>
using namespace std;

class Node {
public:
    double stime;
    double etime;
    bool flag;
    string name;
    Node* next;

    Node(double stime, double etime) {
        this->stime = stime;
        this->etime = etime;
        this->name = "Not Booked";
        this->flag = false;
        this->next = NULL;
    }
};

void clist(Node* head) {
    int t = 1;
    Node* tra = head;
    while (t < 5) {
        double st = t;
        double et = st + 1;
        Node* temp = new Node(st, et);
        if (head->next == NULL) {
            head->next = temp;
        }
        else {
            while (tra->next != NULL) {
                tra = tra->next;
            }
            tra->next = temp;
        }
        t = t + 1.00;
    }
}

void displaySlots(Node* head) 
{
    int count=0;
    Node* temp = head;
    cout << "Slotes Are :  "<< endl;
    cout << "---------------------------" << endl;
    while (temp != NULL)
    {
            count ++;
            cout << count<<" : "<<endl;
            cout << "Starting Time : " << temp->stime << endl;
            cout << "Ending Time : " << temp->etime <<endl;
        if (temp->flag) 
        {
            cout <<"Booked Slot By "<<temp->name<<"\n\n";
        }
        else
        {
            cout <<"Free Slot "<<"\n\n";
        }
        temp = temp->next;
    }
    cout << "---------------------------" << endl;
}

void displayFreeSlots(Node* head) 
{
    int count=0;
    Node* temp = head;
    cout << "Available Free Slotes Are :  "<< endl;
    cout << "---------------------------" << endl;
    while (temp != NULL)
    {
        if (!temp->flag) {
            count ++;
            cout << count<<" : "<<endl;
            cout << "Starting Time: " << temp->stime << endl;
            cout << "Ending Time: " << temp->etime <<"\n";
        }
        temp = temp->next;
    }
    cout << "---------------------------" << endl;
    if(count==0)
    {
        cout<<"Sorry Free Slots Not Available !!! "<<endl;
    }
}

void displayBookSlots(Node* head) 
{
    int count=0;
    Node* temp = head;
    cout << "Booked Slotes Are :  "<< endl;
    cout << "---------------------------" << endl;
    while (temp != NULL)
    {
        if (temp->flag) {
            count ++;
            cout << count<<" : "<<endl;
            cout << "Starting Time : " << temp->stime << endl;
            cout << "Ending Time : " << temp->etime <<endl;
            cout << "Name : " << temp->name <<"\n";
        }
        temp = temp->next;
    }
    cout << "---------------------------" << endl;
    if(count==0)
    {
        cout<<"Sorry Free Slots Not Available !!! "<<endl;
    }
}

void bookSlotes(Node* head)
{   double st;
    string n;
    displayFreeSlots(head);
    cout<<"Enter Start Time : ";
    cin>>st;
    cout<<"Enter Your Name : ";
    cin>>n;
    Node* tra = head;
    while (tra->stime != st) 
        {
            tra = tra->next;
        }
        tra->name=n;
        tra->flag=1;
        cout<<"Slot Booked Successfully....!"<<endl;

}
int main() 
{
    Node* head = new Node(12.00, 1.00);
    bool f=1;
    int ch,ch1;
    clist(head);
    /*displayFreeSlots(head);
    bookSlotes(head);
    displayBookSlots(head);
    return 0;*/
    
    while(f)
    {
      cout<<"1: Display Free Slots " <<endl;
      cout<<"2: Book Slot " <<endl;
      cout<<"3: Display Booked Slots " <<endl;
      cout<<"4: Display  Slots " <<endl;
      cout<<"5: Exit "<<endl;
      cout<<"Enter Your Choice : " <<endl;
      cin>>ch;
      
      switch(ch)
      {
            case 1:
                displayFreeSlots(head);
                break;
            case 2:
                bookSlotes(head);
                break;
            case 3:
                displayBookSlots(head);
                break;
            case 4:
                displaySlots(head);
                break;
            case 5:
                f=0;
                cout<<"Thank You...!";
    
      }
      
    }
}
