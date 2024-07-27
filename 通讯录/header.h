#pragma once

#define MAX_CONTACTS 100

struct ContactRecord {
    char name[20];
    char phone[12];
    char address[50];
    char postcode[8];
    char email[20];
};

extern struct record student[100];											// 定义一个名为record的结构体类型，用来存储学生的信息

extern void encrypt(char* pwd);												// 定义一个名为encrypt的函数，用于对传入的字符串进行简单的加密处理

extern int  get_record_count();												//定义了一个get_record_count函数，作用是获取当前通讯录中记录的数量

extern int menu_select();													// 定义一个名为menu_select的函数，用来显示菜单并获取操作选项

extern int num;																// 声明一个名为num的整型变量

extern int adduser();														// 定义一个名为adduser的函数，用来添加学生信息

extern void list();															// 定义一个名为list的函数，用来显示所有学生信息

extern int searchbyname();													// 定义一个名为searchbyname的函数，用来按姓名查找学生信息

extern int searchbyphone();													//定义一个名为searchbyphone的函数，用来按电话号码查找学生信息

extern void deletebyphone();												//定义了一个名为deletebyphone的函数，用于根据用户输入的电话号码删除通讯录中对应的记录

extern void deletebyname();													//定义了一个deletebyname函数，该函数的作用是从通讯录中删除指定姓名的用户信息

extern int dele();															//这是一个名为dele的函数，用于从通讯录中删除联系人的信息。

extern int sortbyname();													//这是一个名为sortbyname的函数，用于将通讯录中的学生记录按照姓名的字典序进行升序排序




int readContacts(ContactRecord* contacts, int* num_contacts);

int writeContacts(ContactRecord contacts[], int* num_contacts);