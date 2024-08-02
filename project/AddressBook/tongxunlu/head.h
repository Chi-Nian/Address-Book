#pragma once


#include <cstring>
#include<string>
#include<map>
#include<vector>
#define MAX_CONTACTS 100
#define MAX_INPUT 100


using namespace std;
extern  multimap <string, int> mp;

extern  vector   < int> idx;
// 1.1�ṹ�嶨��
 struct ContactRecord {
    char name[20];
    char phone[12];
    char address[50];
    char postcode[8];
    char email[20];
   // char group[20];
};



//1.2��ȡ��ϵ����Ϣ
int readContacts(struct ContactRecord contacts[], int* num_contacts);

/*
������:
����: ���ļ��ж�ȡ��ϵ����Ϣ�����洢�� contacts �����С�
����:
    contacts[]: �ṹ�����飬���ڴ洢��ȡ����ϵ����Ϣ��
    num_contacts: ָ�룬���ڴ洢��ȡ����ϵ��������
����ֵ:
    0: ��ȡ�ɹ�
    -1: ��ȡʧ��
*/


//1.3д����ϵ����Ϣ
extern int writeContacts(struct ContactRecord contacts[], int num_contacts);

/*
������:
����: �� contacts �����е���ϵ����Ϣд���ļ���
����:
    contacts[]: �ṹ�����飬����Ҫд�����ϵ����Ϣ��
    num_contacts: ��ϵ��������
����ֵ:
    0: д��ɹ�
    -1: д��ʧ��
*/




//1.4��֤�û����˺ź�����

extern bool authenticateUser(const char* filename, const char* username, const char* password);

/*
������:
����: ��֤�û���ݣ���ָ���ļ��ж�ȡ�û��������룬�����û�������û�����������бȽϡ�
����:
    filename: �û���Ϣ�ļ����ļ�����
    username: �û�������û�����
    password: �û���������롣
����ֵ:
    true: ��֤�ɹ�
    false: ��֤ʧ��
*/




void read_groups();












//2�����(serve) 4��



// 2.1 �����ϵ����Ϣ(����)
extern int addContact(struct ContactRecord contacts[], int* num_contacts);

/*
������:
����: ����µ���ϵ����Ϣ�� contacts �����С�
����:
    contacts[]: �ṹ�����飬���ڴ洢��ϵ����Ϣ��
    num_contacts: ָ�룬���ڴ洢��ϵ��������
����ֵ:
    0: ��ӳɹ�
    -1: ���ʧ��
*/


// 2.2 �г�������ϵ����Ϣ(����)
extern void listContacts(struct ContactRecord contacts[], int num_contacts);

/*
������:
����: ��ӡ������ϵ����Ϣ������̨��
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ��ϵ��������
����ֵ:
    void
*/

// 2.3 ������������ϵ��(����)
extern int searchContactByName(struct ContactRecord contacts[], int num_contacts, char* name);

/*
������:
����: �� contacts �����в���ָ����������ϵ�ˡ�
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ��ϵ��������
    name: Ҫ���ҵ���ϵ��������
����ֵ:
    -1: δ�ҵ���ϵ��
    >= 0: �ҵ���ϵ�ˣ�������ϵ������
*/

// 2.4 ���绰���������ϵ��(����)
extern int searchContactByPhone(struct ContactRecord contacts[], int num_contacts, char* phone);

/*
������:
����: �� contacts �����в���ָ���绰�������ϵ�ˡ�
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ��ϵ��������
    phone: Ҫ���ҵ���ϵ�˵绰���롣
����ֵ:
    -1: δ�ҵ���ϵ��
    >= 0: �ҵ���ϵ�ˣ�������ϵ������
*/


//2.5 ����ַ������ϵ��
extern int searchContactByAddress(struct ContactRecord contacts[], int num_contacts, char* address);

/*
������:
����: �� contacts �����в���ָ����ַ����ϵ�ˡ�
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ��ϵ��������
    address: Ҫ���ҵ���ϵ�˵�ַ��
����ֵ:
    -1: δ�ҵ���ϵ��
    >= 0: �ҵ���ϵ�ˣ�������ϵ������
*/


//2.6 ���ʱ������ϵ��
extern int searchContactByPostcode(struct ContactRecord contacts[], int num_contacts, char* postcode);

/*
������:
����: �� contacts �����в���ָ���ʱ����ϵ�ˡ�
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ��ϵ��������
    postcode: Ҫ���ҵ���ϵ���ʱࡣ
����ֵ:
    -1: δ�ҵ���ϵ��
    >= 0: �ҵ���ϵ�ˣ�������ϵ������
*/


//2.7 �����������ϵ��
extern int searchContactByEmail(struct ContactRecord contacts[], int num_contacts, char* email);

/*
������:
����: �� contacts �����в���ָ���������ϵ�ˡ�
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ��ϵ��������
    email: Ҫ���ҵ���ϵ�������ַ��
����ֵ:
    -1: δ�ҵ���ϵ��
    >= 0: �ҵ���ϵ�ˣ�������ϵ������
*/

//2.8 ɾ����ϵ����Ϣ
extern int deleteContact(struct ContactRecord contacts[], int* num_contacts, char* key, int delete_type);

/*
������:
����: �� contacts ������ɾ��ָ����������ϵ�ˡ�
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ָ�룬���ڴ洢��ϵ��������
    key: Ҫɾ������ϵ����Ϣ�������������绰��������䡣
    delete_type: ɾ�����ͣ�0 Ϊ������ɾ����1 Ϊ���绰����ɾ����2 Ϊ������ɾ����
����ֵ:
    0: ɾ���ɹ�
    -1: ɾ��ʧ��
*/











//2.9 ������������ϵ����Ϣ(����)
extern int sortContactsByName(struct ContactRecord contacts[], int num_contacts);

/*
������:
����: �������� contacts �����е���ϵ����Ϣ��������
����:
    contacts[]: �ṹ�����飬������ϵ����Ϣ��
    num_contacts: ��ϵ��������
����ֵ:
    0: ����ɹ�
    -1: ����ʧ��
*/



// ���¾�Ϊ��չ
// 2.10 ģ��������ϵ��
extern int fuzzySearchContacts(struct ContactRecord contacts[], int num_contacts, char* keyword);

// 2.11 ������������ϵ��
extern int multiConditionSearch(struct ContactRecord contacts[], int num_contacts, char* name, char* phone, char* address, char* postcode, char* email);

// 2.12 �����������ϵ��
extern int searchContactsByGroup(struct ContactRecord contacts[], int num_contacts, char* group);

// 2.13 ��ӷ���
extern int addGroup(struct ContactRecord contacts[], int * num_contacts, char* group);

// 2.14 ɾ������
extern int deleteGroup( string group);

// 2.15 Ϊ��ϵ����ӱ�ǩ
extern int addTagToContact(struct ContactRecord contacts[], int num_contacts, char* contactName, char* tag);

// 2.16 ɾ����ϵ�˱�ǩ
extern int deleteTagFromContact(struct ContactRecord contacts[], int num_contacts, char* contactName, char* tag);
















//3.��ʾ��(View) 7��


// 3.1 ��ʾ�˵�����ȡ�û�ѡ��(����)
extern int menuSelect(struct ContactRecord contacts[], int *num_contacts);

/*
������:
����: ��ʾ�˵�ѡ���ȡ�û���ѡ��
����: void
����ֵ: �û�ѡ���ֵ������ 1��2��3 �ȡ�
*/



//3.2 ��ʾ��¼����
extern int showLoginInterface();

/*
������:
����: ��ʾ��¼���棬����ȡ�û�������û��������롣
����: void
����ֵ:
    0: ��¼�ɹ�
    -1: ��¼ʧ��
*/


//3.3 ��ʾ������
extern void showMainInterface();

/*
������:
����: ��ʾ�����棬�������ֹ���ѡ����������ϵ�ˡ�ɾ����ϵ�˵ȡ�
����: void
����ֵ: void
*/



//3.4 ��ʾ�༭��¼����
extern void showEditRecordInterface(struct ContactRecord contacts[], int num_contacts);
/*
������:
����: ��ʾ�༭��¼���棬�����û�ѡ��Ҫ�༭����ϵ�ˣ��������µ���ϵ��Ϣ��
����:
contacts: �����ϵ�˵����顣
num_contacts: ��������ϵ�˵�������
����ֵ: void
*/




// 3.5 ��ʾɾ����¼����
extern void showDeleteRecordInterface(struct ContactRecord contacts[], int *num_contacts);
/*
������:
����: ��ʾɾ����¼���棬�����û�ѡ��Ҫɾ������ϵ�ˣ���ȷ��ɾ��������
����:
contacts: �����ϵ�˵����顣
num_contacts: ��������ϵ�˵�������
����ֵ: void
*/


//3.6 ��ʾ�����¼����
extern void showInsertRecordInterface(struct ContactRecord contacts[], int* num_contacts);
/*
������:
����: ��ʾ�����¼���棬�����û������µ���ϵ����Ϣ����������ϵ�˲��뵽�����С�
����:
contacts: �����ϵ�˵����顣
num_contacts: ��������ϵ�˵��������ò���Ϊָ�룬���ڸ�����ϵ��������
����ֵ: void
*/



// 3.7 ��ʾ���ҽ���
extern void showSearchInterface(struct ContactRecord contacts[], int num_contacts);
/*
������:
����: ��ʾ���ҽ��棬�����û�����ؼ��֣������ݹؼ��ֲ���ƥ�����ϵ�ˡ�
����:
contacts: �����ϵ�˵����顣
num_contacts: ��������ϵ�˵�������
����ֵ: void
*/



// 3.8 ��ʾ����������(��չ)
extern void showGroupManagementInterface(struct ContactRecord contacts[], int *num_contacts);

// 3.9 ��ʾ��ǩϵͳ����(��չ)
extern void showTagSystemInterface(struct ContactRecord contacts[], int num_contacts);
