#pragma once

#define MAX_CONTACTS 100

struct ContactRecord {
    char name[20];
    char phone[12];
    char address[50];
    char postcode[8];
    char email[20];
};

extern struct record student[100];											// ����һ����Ϊrecord�Ľṹ�����ͣ������洢ѧ������Ϣ

extern void encrypt(char* pwd);												// ����һ����Ϊencrypt�ĺ��������ڶԴ�����ַ������м򵥵ļ��ܴ���

extern int  get_record_count();												//������һ��get_record_count�����������ǻ�ȡ��ǰͨѶ¼�м�¼������

extern int menu_select();													// ����һ����Ϊmenu_select�ĺ�����������ʾ�˵�����ȡ����ѡ��

extern int num;																// ����һ����Ϊnum�����ͱ���

extern int adduser();														// ����һ����Ϊadduser�ĺ������������ѧ����Ϣ

extern void list();															// ����һ����Ϊlist�ĺ�����������ʾ����ѧ����Ϣ

extern int searchbyname();													// ����һ����Ϊsearchbyname�ĺ�������������������ѧ����Ϣ

extern int searchbyphone();													//����һ����Ϊsearchbyphone�ĺ������������绰�������ѧ����Ϣ

extern void deletebyphone();												//������һ����Ϊdeletebyphone�ĺ��������ڸ����û�����ĵ绰����ɾ��ͨѶ¼�ж�Ӧ�ļ�¼

extern void deletebyname();													//������һ��deletebyname�������ú����������Ǵ�ͨѶ¼��ɾ��ָ���������û���Ϣ

extern int dele();															//����һ����Ϊdele�ĺ��������ڴ�ͨѶ¼��ɾ����ϵ�˵���Ϣ��

extern int sortbyname();													//����һ����Ϊsortbyname�ĺ��������ڽ�ͨѶ¼�е�ѧ����¼�����������ֵ��������������




int readContacts(ContactRecord* contacts, int* num_contacts);

int writeContacts(ContactRecord contacts[], int* num_contacts);