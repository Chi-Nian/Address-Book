#include "head.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_INPUT 100
#define _CRT_SECURE_NO_WARNINGS

int readContacts(ContactRecord* contacts, int* num_contacts)
{
    FILE* fp = fopen("contacts.txt", "rb");             // �Զ�����ֻ����ʽ��
    if (fp == NULL) {
        perror("���ļ�ʧ��");
        return -1;
    }

    *num_contacts = 0;                                  // ��ʼ����ϵ������Ϊ0

    struct ContactRecord tmp;

    //%20s���߼��� ��ȡ��ʱ��һֱ�� ֱ�������ո�/����/���߶���20��
    while (fscanf(fp, "%20s%20s%30s%20s%20s\n",         //����ĸ�ʽ����ȡ�����⣬Ҫ����ָ���ĸ�ʽ����ȡ�����ܶ�ȡ��
        tmp.name, tmp.phone, tmp.address, tmp.postcode, tmp.email) == 5)
    {
        contacts[*num_contacts] = tmp;
        (*num_contacts)++;

        // ��ӡ
        printf("��ϵ��: %d\n", *num_contacts);
        printf("Name: %s\nPhone: %s\nAddress: %s\nPostcode: %s\nEmail: %s\n",
            tmp.name, tmp.phone, tmp.address, tmp.postcode, tmp.email);
        printf("-----------------------------------------------------------\n");
        if (*num_contacts >= MAX_CONTACTS) break;        //���������ϵ������
    }

    fclose(fp);  // �ر��ļ�
    fp = NULL;


    return 0;
}


// ����ѻ��и����ţ���Ȼ��������
int writeContacts(ContactRecord contacts[], int* num_contacts)
{
    FILE* fp = fopen("contacts.txt", "a");  // ��׷�ӷ�ʽ���ļ�
    if (fp == NULL) {
        perror("���ļ�ʧ��");
        return -1;
    }

    ContactRecord newContact;
    char input[MAX_INPUT];
    int new_contacts = 0;

    printf("��������ϵ����Ϣ������'q'�˳�����\n");

    while (1) {

        printf("����: ");
        fgets(newContact.name, sizeof(newContact.name), stdin);
        if (strcmp(newContact.name, "q\n") == 0) break;
        //if (strlen(newContact.name) < 4+1 || strlen(newContact.name) > 8+1) {   // + 1��Ϊ������\n
        //    printf("�������������������������\n");
        //    continue;
        //}

        printf("�绰: ");
        fgets(newContact.phone, sizeof(newContact.phone), stdin);

        /*if (phoneLength != 7 && phoneLength != 8 && phoneLength != 11) {
            printf("������ĵ绰��������������\n");
            continue;
        }*/


        printf("��ַ: ");
        fgets(newContact.address, sizeof(newContact.address), stdin);
        /*if (0 < strlen(newContact.address) || strlen(newContact.address) < 15) {
            printf("������ĵ�ַ��������������\n");
            continue;
        }*/


        printf("�ʱ�: ");
        fgets(newContact.postcode, sizeof(newContact.postcode), stdin);
        /*if (0 < strlen(newContact.postcode) && strlen(newContact.postcode) < 6+1 || strlen(newContact.postcode) > 6+1) {
            printf("��������ʱ���������������\n");
            continue;
        }*/

        printf("����: ");
        fgets(newContact.email, sizeof(newContact.email), stdin);
        //if (0 < strlen(newContact.email) && strlen(newContact.email) < 9 || strlen(newContact.email) > 18) {    //��������Ϊ�յ�����
        //    printf("�������������������������\n");
        //    continue;
        //}

        // д���ļ���������з�
        fprintf(fp, "%s%s%s%s%s",
            newContact.name,
            newContact.phone,
            newContact.address,
            newContact.postcode,
            newContact.email);

        if (*num_contacts < MAX_CONTACTS) {
            contacts[*num_contacts] = newContact;
            (*num_contacts)++;
            new_contacts++;
        }
        else {
            printf("��ϵ�������Ѵﵽ������ƣ��޷���Ӹ���\n");
            break;
        }

        printf("��ϵ������ӡ��Ƿ������ӣ�(y/n): ");
        fgets(input, MAX_INPUT, stdin);
        if (input[0] != 'y' && input[0] != 'Y') break;
    }

    fclose(fp);
    printf("�ɹ�д�� %d ������ϵ�˵��ļ���\n", new_contacts);
    return 0;
}

void showInsertRecordInterface(struct ContactRecord contacts[], int* num_contacts) {
    if (*num_contacts >= MAX_CONTACTS) {
        printf("��ϵ���б��������޷��������ϵ�ˡ�\n");
        return;
    }

    struct ContactRecord newContact;
    printf("\n=== ��������ϵ�� ===\n");

    // ��ȡ����
    printf("���������� (���19���ַ�): ");
    scanf(" %19[^\n]", newContact.name);

    // ��ȡ�绰����
    printf("������绰���� (���11���ַ�): ");
    scanf(" %11[^\n]", newContact.phone);

    // ��ȡ��ַ
    printf("�������ַ (���49���ַ�): ");
    scanf(" %49[^\n]", newContact.address);

    // ��ȡ�ʱ�
    printf("�������ʱ� (���7���ַ�): ");
    scanf(" %7[^\n]", newContact.postcode);

    // ��ȡ����
    printf("���������� (���19���ַ�): ");
    scanf(" %19[^\n]", newContact.email);

    char confirm;
    printf("\n=== ��ȷ��������Ϣ ===\n");
    printf("����: %s\n", newContact.name);
    printf("�绰: %s\n", newContact.phone);
    printf("��ַ: %s\n", newContact.address);
    printf("�ʱ�: %s\n", newContact.postcode);
    printf("����: %s\n", newContact.email);
    printf("\nȷ�����������¼��? (Y/N): ");
    scanf(" %c", &confirm);

    if (toupper(confirm) == 'Y') {
        contacts[*num_contacts] = newContact;
        (*num_contacts)++;
        printf("����ϵ���ѳɹ���ӡ�\n");
    }
    else {
        printf("��ȡ���������ϵ�ˡ�\n");
    }
}
void showInsertRecordInterface(struct ContactRecord contacts[], int* num_contacts) {
    if (*num_contacts >= MAX_CONTACTS) {
        printf("��ϵ���б��������޷��������ϵ�ˡ�\n");
        return;
    }

    struct ContactRecord newContact;
    printf("\n=== ��������ϵ�� ===\n");

    // ��ȡ����
    printf("���������� (���19���ַ�): ");
    scanf(" %19[^\n]", newContact.name);

    // ��ȡ�绰����
    printf("������绰���� (���11���ַ�): ");
    scanf(" %11[^\n]", newContact.phone);

    // ��ȡ��ַ
    printf("�������ַ (���49���ַ�): ");
    scanf(" %49[^\n]", newContact.address);

    // ��ȡ�ʱ�
    printf("�������ʱ� (���7���ַ�): ");
    scanf(" %7[^\n]", newContact.postcode);

    // ��ȡ����
    printf("���������� (���19���ַ�): ");
    scanf(" %19[^\n]", newContact.email);

    char confirm;
    printf("\n=== ��ȷ��������Ϣ ===\n");
    printf("����: %s\n", newContact.name);
    printf("�绰: %s\n", newContact.phone);
    printf("��ַ: %s\n", newContact.address);
    printf("�ʱ�: %s\n", newContact.postcode);
    printf("����: %s\n", newContact.email);
    printf("\nȷ�����������¼��? (Y/N): ");
    scanf(" %c", &confirm);

    if (toupper(confirm) == 'Y') {
        contacts[*num_contacts] = newContact;
        (*num_contacts)++;
        printf("����ϵ���ѳɹ���ӡ�\n");
    }
    else {
        printf("��ȡ���������ϵ�ˡ�\n");
    }
}

//3.9 ��ʾ��ǩϵͳ����(��չ)
void showTagSystemInterface(struct ContactRecord contacts[], int num_contacts) {
    char tags[MAX_TAGS] = { 0 };  // ���ڼ�¼ÿ����ĸ�Ƿ����
    char uniqueTags[MAX_TAGS][4] = { {0} };  // ���ڴ洢Ψһ��ǩ
    int uniqueTagCount = 0;
    int choice;

    // �ռ�����Ψһ�ı�ǩ����������ĸ��
    for (int i = 0; i < num_contacts; i++) {
        char firstLetter[4] = { 0 };
        strncpy(firstLetter, contacts[i].name, 3);
        int isNewTag = 1;
        for (int j = 0; j < uniqueTagCount; j++) {
            if (strcmp(uniqueTags[j], firstLetter) == 0) {
                isNewTag = 0;
                break;
            }
        }
        if (isNewTag) {
            strncpy(uniqueTags[uniqueTagCount], firstLetter, 3);
            uniqueTagCount++;
        }
    }

    while (1) {
        // ��ʾ��ǩϵͳ����
        printf("\n��ǩϵͳ���� (����������ĸ)\n");
        printf("============================\n");
        for (int i = 0; i < uniqueTagCount; i++) {
            printf("%s ", uniqueTags[i]);
        }
        printf("\n============================\n");
        printf("1. �鿴�ض���ǩ����ϵ��\n");
        printf("2. �������˵�\n");
        printf("��ѡ�����: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char tag[4];
            printf("������Ҫ�鿴�ı�ǩ�����3���ַ���: ");
            scanf(" %3s", tag);

            printf("\n��ǩ '%s' ����ϵ�ˣ�\n", tag);
            int found = 0;
            for (int i = 0; i < num_contacts; i++) {
                if (strncmp(contacts[i].name, tag, strlen(tag)) == 0) {
                    found = 1;
                    printf("---------------------------\n");
                    printf("����: %s\n", contacts[i].name);
                    printf("�绰: %s\n", contacts[i].phone);
                    printf("��ַ: %s\n", contacts[i].address);
                    printf("�ʱ�: %s\n", contacts[i].postcode);
                    printf("����: %s\n", contacts[i].email);
                    printf("---------------------------\n");
                }
            }
            if (!found) {
                printf("û���ҵ��� '%s' ��ͷ����ϵ�ˡ�\n", tag);
            }
            break;
        }
        case 2:
            return;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    }
}

int showLoginInterface() {
    char username[20];
    char password[20];
    printf("\n\t\t\t***********登录界面***********\n");
    printf("\t\t\t用户名：");
    scanf("%s", username);
    printf("\t\t\t密码：");
    scanf("%s", password);

    encrypt(password);  //对输入的密码进行加密处理，方便后面与存储的密码比较
    if (authenticateUser("user_data.txt", username, password)) {
        printf("\n\t\t\t登录成功！");
        return 0;
    }
    else {
        printf("\n\t\t\t用户名或密码有误，请重新输入！");
        return -1;
    }
}

void showEditRecordInterface(struct ContactRecord contacts[], int num_contacts) {
    int choice;                 //联系人的序号
    int index = choice - 1;     //将序号转换为数组索引
    printf("联系人总数：%d\n", num_contacts);
    for (int i = 0; i < num_contacts; i++) {
        printf("%d.姓名：%s，电话：%s，地址：%s，邮编：%s，邮箱：%s\n", i + 1, contacts[i].name,
            contacts[i].phone, contacts[i].address, contacts[i].postcode, contacts[i].email);;
    }

    printf("\n\t\t\t请选择需要编辑的联系人（序号）：\n");
    scanf("%d", &choice);
    if (index >= 0 && index < num_contacts) {
        printf("\n\t\t\t请编辑该联系人：\n");
        printf("\t\t\t输入新姓名：");
        scanf("%s", contacts[index].name);
        printf("\n\t\t\t输入新电话：");
        scanf("%s", contacts[index].phone);
        printf("\n\t\t\t输入新地址：");
        scanf("%s", contacts[index].address);
        printf("\n\t\t\t输入新邮编：");
        scanf("%s", contacts[index].postcode);
        printf("\n\t\t\t输入新邮箱：");
        scanf("%s", contacts[index].email);
        printf("编辑成功！");
    }
    else {
        printf("没有所选的序号，请重新选择。");
        scanf("%d", &choice);
    }
}

// 2.13 添加分组(拓展)
int addGroup(struct ContactRecord contacts[], int* num_contacts, char* group) {
    char new_group[20];
    printf("请输入要添加的新分组名： ");
    scanf("%19s", new_group);

    //1.先选择查找方式查找到要插入该分组的联系人
    int choice;
    printf("请选择查找方式：\n");
    printf("1.按姓名查找\n");
    printf("2.按电话查找\n");
    printf("3.按地址查找\n");
    printf("4.按邮编查找\n");
    printf("5.按邮箱查找\n");
    printf("6.模糊查找\n");
    printf("7.多条件查找\n");
    scanf("%d", &choice);
    getchar();                        //捕获换行符

    //2.再去执行相应的查找
    int index = -1;                  //保存返回的索引
    switch (choice) {
    case 1: {
        char name[20];
        printf("输入要查找的联系人姓名：");
        scanf("19%s", name);
        index = searchContactByName(contacts, *num_contacts, name);
        break;
    }
    case 2: {
        char phone[20];
        printf("输入要查找的联系人电话：");
        scanf("%19s", phone);
        index = searchContactByPhone(contacts, *num_contacts, phone);
        break;
    }
    case 3: {
        char address[20];
        printf("输入要查找的联系人地址：");
        scanf("%19s", address);
        index = searchContactByAddress(contacts, *num_contacts, address);
        break;
    }
    case 4: {
        char postcode[8];
        printf("输入要查找的联系人邮编：");
        scanf("%7s", postcode);
        index = searchContactByPostcode(contacts, *num_contacts, postcode);
        break;
    }
    case 5: {
        char e_mail[20];
        printf("输入要查找的联系人邮箱：");
        scanf("%19s", e_mail);
        index = searchContactByEmail(contacts, *num_contacts, e_mail);
        break;
    }
    case 6: {
        char keyword[50];
        printf("输入要查找的联系人关键字：");
        scanf("%49s", keyword);
        index = fuzzySearchContacts(contacts, *num_contacts, keyword);
        break;
    }
    case 7: {
        char name[20];
        char phone[20];
        char address[20];
        char postcode[8];
        char e_mail[20];
        printf("输入要查找的联系人信息：");
        scanf("19%s", name);
        scanf("%19s", phone);
        scanf("%19s", address);
        scanf("%7s", postcode);
        scanf("%19s", e_mail);
        index = multiConditionSearch(contacts, *num_contacts, name, phone, address, postcode, e_mail);
        break;
    }
    default: {
        printf("没有这个查找方式选项.\n");
        return -1;
    }
    }

    //3.检查查找结果并更改分组
    if (index != -1) {
        strcpy(contacts[index].group, new_group);
        printf("添加新分组成功！\n");
    }
    else {
        printf("未找到该联系人，添加分组失败\n");
    }
    return 0;//返回0表示成功添加分组
}

