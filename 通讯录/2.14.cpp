#include <iostream>
#include <cstring>

using namespace std;

struct ContactRecord {
    char name[20];
    char phone[12];
    char address[50];
    char postcode[8];
    char email[20];
    char group[20]; // 假设联系人结构体中有一个分组字段
};

// 删除分组中的联系人
int deleteGroup(struct ContactRecord contacts[], int* num_contacts, const char* group)
{
    int original_count = *num_contacts;
    int i = 0;

    while (i < *num_contacts)
    {
        if (strcmp(contacts[i].group, group) == 0)
        {
            // 删除当前联系人，覆盖该联系人并减少联系人数量
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

    return original_count - *num_contacts; // 返回删除的联系人数量
}

int main()
{
    // 示例联系人数组
    ContactRecord contacts[] = {
        {"Alice", "123456789", "123 Wonderland", "12345", "alice@example.com", "friends"},
        {"Bob", "987654321", "456 Nowhere Street", "67890", "bob@example.com", "work"},
        {"Charlie", "555555555", "789 Somewhere Avenue", "54321", "charlie@example.com", "friends"}
    };
    int num_contacts = sizeof(contacts) / sizeof(contacts[0]);

    char group[20];
    cout << "请输入要删除的分组：";
    cin.getline(group, 20);

    int deleted_count = deleteGroup(contacts, &num_contacts, group);
    if (deleted_count > 0)
    {
        cout << "已删除 " << deleted_count << " 个联系人。" << endl;
    }
    else
    {
        cout << "未找到分组 " << group << " 中的联系人。" << endl;
    }

    // 打印剩余联系人
    for (int i = 0; i < num_contacts; i++)
    {
        cout << "姓名：" << contacts[i].name << ", 分组：" << contacts[i].group << endl;
    }

    return 0;
}
