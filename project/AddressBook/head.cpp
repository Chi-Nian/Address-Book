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
    FILE* fp = fopen("contacts.txt", "rb");             // 以二进制只读方式打开
    if (fp == NULL) {
        perror("打开文件失败");
        return -1;
    }

    *num_contacts = 0;                                  // 初始化联系人数量为0

    struct ContactRecord tmp;

    //%20s的逻辑是 读取的时候一直读 直到遇见空格/换行/或者读满20个
    while (fscanf(fp, "%20s%20s%30s%20s%20s\n",         //这里的格式化读取有问题，要按照指定的格式来读取，才能读取到
        tmp.name, tmp.phone, tmp.address, tmp.postcode, tmp.email) == 5)
    {
        contacts[*num_contacts] = tmp;
        (*num_contacts)++;

        // 打印
        printf("联系人: %d\n", *num_contacts);
        printf("Name: %s\nPhone: %s\nAddress: %s\nPostcode: %s\nEmail: %s\n",
            tmp.name, tmp.phone, tmp.address, tmp.postcode, tmp.email);
        printf("-----------------------------------------------------------\n");
        if (*num_contacts >= MAX_CONTACTS) break;        //限制最大联系人数量
    }

    fclose(fp);  // 关闭文件
    fp = NULL;


    return 0;
}


// 必须把换行给留着，不然会读入错误
int writeContacts(ContactRecord contacts[], int* num_contacts)
{
    FILE* fp = fopen("contacts.txt", "a");  // 以追加方式打开文件
    if (fp == NULL) {
        perror("打开文件失败");
        return -1;
    }

    ContactRecord newContact;
    char input[MAX_INPUT];
    int new_contacts = 0;

    printf("请输入联系人信息（输入'q'退出）：\n");

    while (1) {

        printf("姓名: ");
        fgets(newContact.name, sizeof(newContact.name), stdin);
        if (strcmp(newContact.name, "q\n") == 0) break;
        //if (strlen(newContact.name) < 4+1 || strlen(newContact.name) > 8+1) {   // + 1是为了算入\n
        //    printf("您输入的姓名有误，请重新输入\n");
        //    continue;
        //}

        printf("电话: ");
        fgets(newContact.phone, sizeof(newContact.phone), stdin);

        /*if (phoneLength != 7 && phoneLength != 8 && phoneLength != 11) {
            printf("您输入的电话有误，请重新输入\n");
            continue;
        }*/


        printf("地址: ");
        fgets(newContact.address, sizeof(newContact.address), stdin);
        /*if (0 < strlen(newContact.address) || strlen(newContact.address) < 15) {
            printf("您输入的地址有误，请重新输入\n");
            continue;
        }*/


        printf("邮编: ");
        fgets(newContact.postcode, sizeof(newContact.postcode), stdin);
        /*if (0 < strlen(newContact.postcode) && strlen(newContact.postcode) < 6+1 || strlen(newContact.postcode) > 6+1) {
            printf("您输入的邮编有误，请重新输入\n");
            continue;
        }*/

        printf("邮箱: ");
        fgets(newContact.email, sizeof(newContact.email), stdin);
        //if (0 < strlen(newContact.email) && strlen(newContact.email) < 9 || strlen(newContact.email) > 18) {    //可以允许为空的输入
        //    printf("您输入的邮箱有误，请重新输入\n");
        //    continue;
        //}

        // 写入文件，保留换行符
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
            printf("联系人数量已达到最大限制，无法添加更多\n");
            break;
        }

        printf("联系人已添加。是否继续添加？(y/n): ");
        fgets(input, MAX_INPUT, stdin);
        if (input[0] != 'y' && input[0] != 'Y') break;
    }

    fclose(fp);
    printf("成功写入 %d 个新联系人到文件。\n", new_contacts);
    return 0;
}
void showInsertRecordInterface(struct ContactRecord contacts[], int* num_contacts) {
    if (*num_contacts >= MAX_CONTACTS) {
        printf("联系人列表已满，无法添加新联系人。\n");
        return;
    }

    struct ContactRecord newContact;
    printf("\n=== 插入新联系人 ===\n");

    // 获取姓名
    printf("请输入姓名 (最多19个字符): ");
    scanf(" %19[^\n]", newContact.name);

    // 获取电话号码
    printf("请输入电话号码 (最多11个字符): ");
    scanf(" %11[^\n]", newContact.phone);

    // 获取地址
    printf("请输入地址 (最多49个字符): ");
    scanf(" %49[^\n]", newContact.address);

    // 获取邮编
    printf("请输入邮编 (最多7个字符): ");
    scanf(" %7[^\n]", newContact.postcode);

    // 获取邮箱
    printf("请输入邮箱 (最多19个字符): ");
    scanf(" %19[^\n]", newContact.email);

    char confirm;
    printf("\n=== 请确认以下信息 ===\n");
    printf("姓名: %s\n", newContact.name);
    printf("电话: %s\n", newContact.phone);
    printf("地址: %s\n", newContact.address);
    printf("邮编: %s\n", newContact.postcode);
    printf("邮箱: %s\n", newContact.email);
    printf("\n确认添加这条记录吗? (Y/N): ");
    scanf(" %c", &confirm);

    if (toupper(confirm) == 'Y') {
        contacts[*num_contacts] = newContact;
        (*num_contacts)++;
        printf("新联系人已成功添加。\n");
    }
    else {
        printf("已取消添加新联系人。\n");
    }
}
void showInsertRecordInterface(struct ContactRecord contacts[], int* num_contacts) {
    if (*num_contacts >= MAX_CONTACTS) {
        printf("联系人列表已满，无法添加新联系人。\n");
        return;
    }

    struct ContactRecord newContact;
    printf("\n=== 插入新联系人 ===\n");

    // 获取姓名
    printf("请输入姓名 (最多19个字符): ");
    scanf(" %19[^\n]", newContact.name);

    // 获取电话号码
    printf("请输入电话号码 (最多11个字符): ");
    scanf(" %11[^\n]", newContact.phone);

    // 获取地址
    printf("请输入地址 (最多49个字符): ");
    scanf(" %49[^\n]", newContact.address);

    // 获取邮编
    printf("请输入邮编 (最多7个字符): ");
    scanf(" %7[^\n]", newContact.postcode);

    // 获取邮箱
    printf("请输入邮箱 (最多19个字符): ");
    scanf(" %19[^\n]", newContact.email);

    char confirm;
    printf("\n=== 请确认以下信息 ===\n");
    printf("姓名: %s\n", newContact.name);
    printf("电话: %s\n", newContact.phone);
    printf("地址: %s\n", newContact.address);
    printf("邮编: %s\n", newContact.postcode);
    printf("邮箱: %s\n", newContact.email);
    printf("\n确认添加这条记录吗? (Y/N): ");
    scanf(" %c", &confirm);

    if (toupper(confirm) == 'Y') {
        contacts[*num_contacts] = newContact;
        (*num_contacts)++;
        printf("新联系人已成功添加。\n");
    }
    else {
        printf("已取消添加新联系人。\n");
    }
}

//3.9 显示标签系统界面(拓展)
void showTagSystemInterface(struct ContactRecord contacts[], int num_contacts) {
    char tags[MAX_TAGS] = { 0 };  // 用于记录每个字母是否出现
    char uniqueTags[MAX_TAGS][4] = { {0} };  // 用于存储唯一标签
    int uniqueTagCount = 0;
    int choice;

    // 收集所有唯一的标签（姓名首字母）
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
        // 显示标签系统界面
        printf("\n标签系统界面 (按姓名首字母)\n");
        printf("============================\n");
        for (int i = 0; i < uniqueTagCount; i++) {
            printf("%s ", uniqueTags[i]);
        }
        printf("\n============================\n");
        printf("1. 查看特定标签的联系人\n");
        printf("2. 返回主菜单\n");
        printf("请选择操作: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char tag[4];
            printf("请输入要查看的标签（最多3个字符）: ");
            scanf(" %3s", tag);

            printf("\n标签 '%s' 的联系人：\n", tag);
            int found = 0;
            for (int i = 0; i < num_contacts; i++) {
                if (strncmp(contacts[i].name, tag, strlen(tag)) == 0) {
                    found = 1;
                    printf("---------------------------\n");
                    printf("姓名: %s\n", contacts[i].name);
                    printf("电话: %s\n", contacts[i].phone);
                    printf("地址: %s\n", contacts[i].address);
                    printf("邮编: %s\n", contacts[i].postcode);
                    printf("邮箱: %s\n", contacts[i].email);
                    printf("---------------------------\n");
                }
            }
            if (!found) {
                printf("没有找到以 '%s' 开头的联系人。\n", tag);
            }
            break;
        }
        case 2:
            return;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    }
}