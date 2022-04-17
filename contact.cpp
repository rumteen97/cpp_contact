#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int count_of_contacts=0;
class contact
{
    public:
        char name[10],lastname[10],phone_number[11];
        int age;
};
class contact_list
{
    public:
        void add_contact(contact contacts[100])
        {
            char name[10],lastname[10],phone_number[11];
            int age;
            cout<<"Enter name:";
            cin>>name;
            cout<<"Enter last name:";
            cin>>lastname;
            cout<<"Enter phone number:";
            cin>>phone_number;
            cout<<"Enter age:";
            cin>>age;
            strcpy(contacts[count_of_contacts].name,name);
            strcpy(contacts[count_of_contacts].lastname,lastname);
            strcpy(contacts[count_of_contacts].phone_number,phone_number);
            contacts[count_of_contacts].age=age;
            count_of_contacts++;
        }
        void update_contact(contact contacts[100],char name[10],char lastname[],char phone[],int age,int found)
        {
            strcpy(contacts[found].name,name);
            strcpy(contacts[found].lastname,lastname);
            strcpy(contacts[found].phone_number,phone);
            contacts[found].age=age;
        }
        void delete_contact(contact contacts[100],int found)
        {
            for(int i=found;i<count_of_contacts;i++)
            {
                update_contact(contacts,contacts[i+1].name,contacts[i+1].lastname,contacts[i+1].phone_number,contacts[i+1].age,i);
            }
            count_of_contacts--;
        }
        int search_contact(contact contacts[100])
        {
            int type;
            char searchn[10];
            char search_phone[11];
            cout<<"What do you want to search:\n1.Name\n2.Last name\n3.Phone number\n";
            cin>>type;
            if(type==1)
            {
                cout<<"Enter the name:";
                cin>>searchn;
                for(int i=0;i<count_of_contacts;i++)
                {
                    if(strcmp(contacts[i].name,searchn)==0)
                    {
                        return i;
                    }
                }
            }
            else if(type==2)
            {
                cout<<"Enter the last name:";
                cin>>searchn;
                for(int i=0;i<count_of_contacts;i++)
                {
                    if(strcmp(contacts[i].lastname,searchn)==0)
                    {
                        return i;
                    }
                }
            }
            else if (type==3)
            {
                cout<<"Enter the phone number:";
                cin>>search_phone;
                for(int i=0;i<count_of_contacts;i++)
                {
                    if(strcmp(contacts[i].phone_number,search_phone)==0)
                    {
                        return i;
                    }
                }
            }
        }
        void sort_contacts(contact contacts[100])
        {
            for (int i=0;i<count_of_contacts;i++)
            {
                int min_temp=i;
                for(int j=i+1;i<count_of_contacts;j++)
                {
                    if (strcmp(contacts[min_temp].lastname, contacts[j].lastname)<0)
                    {
                        min_temp=j;
                    }
                }
                if(min_temp!=i)
                {
                    char temp_name[10],temp_lastname[10],temp_phone_number[11];
                    int temp_age;
                    strcpy(contacts[i].name,temp_name);
                    strcpy(contacts[i].lastname,temp_lastname);
                    strcpy(contacts[i].phone_number,temp_phone_number);
                    temp_age=contacts[i].age;
                    update_contact(contacts,contacts[min_temp].name,contacts[min_temp].lastname,contacts[min_temp].phone_number,contacts[min_temp].age,i);
                    update_contact(contacts,temp_name,temp_lastname,temp_phone_number,temp_age,min_temp);
                }
            }
        }
        void show_contact(contact contacts[100],int counter)
        {
            cout<<"Name:";
            for (int i=0;i<10;i++)
                {
                    cout<<contacts[counter].name[i];
                }
            cout<<endl<<"Last name:";
            for (int i=0;i<10;i++)
                {
                    cout<<contacts[counter].lastname[i];
                }
            cout<<endl<<"Phone number:";
            for (int i=0;i<11;i++)
                {
                    cout<<contacts[counter].phone_number[i];
                }
            cout<<endl<<"Age:"<<contacts[counter].age<<endl;
        }
        void random_selection_contact(contact contacts[100])
        {
            int a=(rand()/(count_of_contacts*count_of_contacts))+1;
            a=pow(static_cast<float>(a),0.5);
            show_contact(contacts,a);
        }
};
int main()
{
    bool repeat=true;
    int choice=0;
    char name[10],lastname[10],phonenumber[11];
    int age;
    int temp;
    int temp_update;
    int temp_delete;
    contact contacts[100];
    contact_list list_1;
    while (repeat)
    {
        cout<<"What do you want to do:\n1.Add contact\n2.Update contact\n3.Delete contact\n4.Search contacts\n5.Sort contacts\n6.Random select\n7.Exit\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            list_1.add_contact(contacts);
            cout<<"Contact added\n\n";
            break;
        case 2:
            temp_update=list_1.search_contact(contacts);
            cout<<"Enter new name:";
            cin>>name;
            cout<<"Enter new last name:";
            cin>>lastname;
            cout<<"Enter new phone number:";
            cin>>phonenumber;
            cout<<"Enter new age:";
            cin>>age;
            list_1.update_contact(contacts,name,lastname,phonenumber,age,temp);
            cout<<"Contact updated\n\n";
            break;
        case 3:
            temp_delete=list_1.search_contact(contacts);
            list_1.delete_contact(contacts,temp_delete);
            cout<<"Contact deleted\n\n";
            break;
        case 4:
            list_1.show_contact(contacts,list_1.search_contact(contacts));
            break;
        case 5:
            list_1.sort_contacts(contacts);
            cout<<"Contacts sorted based on last name\n\n";
            break;
        case 6:
            list_1.random_selection_contact(contacts);
            break;
        case 7:
            return 0;
        }
    }
    return 0;
}
