#include "head.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
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

        // д���ļ����������з�
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