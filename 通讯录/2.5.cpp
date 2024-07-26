/*
#include <iostream>
#include <cstring>

using namespace std;

struct ContactRecord {
    char name[20];
    char phone[12];
    char address[50];
    char postcode[8];
    char email[20];
};

// ����ַ������ϵ��
int searchContactByAddress(struct ContactRecord contacts[], int num_contacts, const char* address)
{
    for (int i = 0; i < num_contacts; i++)
    {
        if (strcmp(contacts[i].address, address) == 0)
        {
            return i; // �ҵ���ϵ�ˣ���������
        }
    }
    return -1; // δ�ҵ���ϵ��
}

int main()
{
    // ʾ����ϵ������
    ContactRecord contacts[] = {
        {"Alice", "123456789", "123 Wonderland", "12345", "alice@example.com"},
        {"Bob", "987654321", "456 Nowhere Street", "67890", "bob@example.com"},
        {"Charlie", "555555555", "789 Somewhere Avenue", "54321", "charlie@example.com"}
    };
    int num_contacts = sizeof(contacts) / sizeof(contacts[0]);

    char address[50];
    cout << "������Ҫ���ҵĵ�ַ��";
    cin.getline(address, 50);

    int index = searchContactByAddress(contacts, num_contacts, address);
    if (index >= 0)
    {
        cout << "�ҵ���ϵ�ˣ�" << endl;
        cout << "������" << contacts[index].name << endl;
        cout << "�绰��" << contacts[index].phone << endl;
        cout << "��ַ��" << contacts[index].address << endl;
        cout << "�ʱࣺ" << contacts[index].postcode << endl;
        cout << "�����ʼ���" << contacts[index].email << endl;
    }
    else
    {
        cout << "δ�ҵ���ϵ��" << endl;
    }

    return 0;
}
*/