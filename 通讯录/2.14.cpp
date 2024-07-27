#include <iostream>
#include <cstring>

using namespace std;

struct ContactRecord {
    char name[20];
    char phone[12];
    char address[50];
    char postcode[8];
    char email[20];
    char group[20]; // ������ϵ�˽ṹ������һ�������ֶ�
};

// ɾ�������е���ϵ��
int deleteGroup(struct ContactRecord contacts[], int* num_contacts, const char* group)
{
    int original_count = *num_contacts;
    int i = 0;

    while (i < *num_contacts)
    {
        if (strcmp(contacts[i].group, group) == 0)
        {
            // ɾ����ǰ��ϵ�ˣ����Ǹ���ϵ�˲�������ϵ������
            for (int j = i; j < *num_contacts - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }
            (*num_contacts)--;
        }
        else
        {
            i++;
        }
    }

    return original_count - *num_contacts; // ����ɾ������ϵ������
}

int main()
{
    // ʾ����ϵ������
    ContactRecord contacts[] = {
        {"Alice", "123456789", "123 Wonderland", "12345", "alice@example.com", "friends"},
        {"Bob", "987654321", "456 Nowhere Street", "67890", "bob@example.com", "work"},
        {"Charlie", "555555555", "789 Somewhere Avenue", "54321", "charlie@example.com", "friends"}
    };
    int num_contacts = sizeof(contacts) / sizeof(contacts[0]);

    char group[20];
    cout << "������Ҫɾ���ķ��飺";
    cin.getline(group, 20);

    int deleted_count = deleteGroup(contacts, &num_contacts, group);
    if (deleted_count > 0)
    {
        cout << "��ɾ�� " << deleted_count << " ����ϵ�ˡ�" << endl;
    }
    else
    {
        cout << "δ�ҵ����� " << group << " �е���ϵ�ˡ�" << endl;
    }

    // ��ӡʣ����ϵ��
    for (int i = 0; i < num_contacts; i++)
    {
        cout << "������" << contacts[i].name << ", ���飺" << contacts[i].group << endl;
    }

    return 0;
}
