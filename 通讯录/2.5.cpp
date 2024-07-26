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

// 按地址查找联系人
int searchContactByAddress(struct ContactRecord contacts[], int num_contacts, const char* address)
{
    for (int i = 0; i < num_contacts; i++)
    {
        if (strcmp(contacts[i].address, address) == 0)
        {
            return i; // 找到联系人，返回索引
        }
    }
    return -1; // 未找到联系人
}

int main()
{
    // 示例联系人数组
    ContactRecord contacts[] = {
        {"Alice", "123456789", "123 Wonderland", "12345", "alice@example.com"},
        {"Bob", "987654321", "456 Nowhere Street", "67890", "bob@example.com"},
        {"Charlie", "555555555", "789 Somewhere Avenue", "54321", "charlie@example.com"}
    };
    int num_contacts = sizeof(contacts) / sizeof(contacts[0]);

    char address[50];
    cout << "请输入要查找的地址：";
    cin.getline(address, 50);

    int index = searchContactByAddress(contacts, num_contacts, address);
    if (index >= 0)
    {
        cout << "找到联系人：" << endl;
        cout << "姓名：" << contacts[index].name << endl;
        cout << "电话：" << contacts[index].phone << endl;
        cout << "地址：" << contacts[index].address << endl;
        cout << "邮编：" << contacts[index].postcode << endl;
        cout << "电子邮件：" << contacts[index].email << endl;
    }
    else
    {
        cout << "未找到联系人" << endl;
    }

    return 0;
}
*/