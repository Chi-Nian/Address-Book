#include "head.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
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