#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdio>
#include <cstring>
using namespace std;

struct ContactRecord {
	char name[20];
	char phone[12];
	char address[50];
	char postcode[8];
	char email[20];
	char group[30];
};
ContactRecord contacts[30];
unordered_map<string,string> mp;
int num=0;
int* num_contacts=&num;
int searchContactByName(struct ContactRecord contacts[], int* num_contacts, const char* name){
	return 0; 
}								
int searchContactByPhone(struct ContactRecord contacts[], int* num_contacts, const char* phone){
	return 0;
}								
int searchContactByAddress(struct ContactRecord contacts[], int* num_contacts, const char* address){
	return 0;
}							

int searchContactByPostcode(struct ContactRecord contacts[], int* num_contacts, char* postcode){
	return 0;
}								

int searchContactByEmail(ContactRecord contacts[], int* num_contacts, char* email){
	return 0;
}										
int fuzzySearchContacts(const ContactRecord contacts[], int* num_contacts, const char* keyword){
	return 0;
}
int searchContactsByGroup(struct ContactRecord contacts[], int* num_contacts, char* group){
	return 0;
}
int deleteContact(struct ContactRecord contacts[], int* num_contacts, char* key, int delete_type){
	return 0;
}
/*
������:showDeleteRecordInterface
����:��ʾɾ������
�����:�Ϻ�

*/
void showDeleteRecordInterface(struct ContactRecord contacts[], int* num_contacts) {
char op = 'y';
    int res = -1;

    while (1) {
        system("cls");
        printf("\t\t************* ������ɾ��ʱ���ҷ�ʽ ***********\n\n");
        printf("\t\t\t1.��������\n");
        printf("\t\t\t2.�绰����\n");
        printf("\t\t\t3.��ַ����\n");
        printf("\t\t\t4.�ʱ����\n");
        printf("\t\t\t5.�������\n");
        printf("\t\t\t6.ģ������\n");
        printf("\t\t\t7.�������\n");
        printf("\t\t\t8.�˳�\n");

        char s[80];
        int a = 0;
        do {
            printf("Enter your choice (1~8): ");
            scanf("%s", s);
            a = atoi(s);
            while (getchar() != '\n'); // ��������
        } while (a < 1 || a > 8);

        if (a == 8) {
            break;
        }

        system("cls");
        char key[80];
        printf("\t\t������ҹؼ���:\n");
        scanf("%s", key);
        while (getchar() != '\n'); // ��������

        switch (a) {
            case 1:
                res = searchContactByName(contacts, num_contacts, key);
                break;
            case 2:
                res = searchContactByPhone(contacts, num_contacts, key);
                break;
            case 3:
                res = searchContactByAddress(contacts, num_contacts, key);
                break;
            case 4:
                res = searchContactByPostcode(contacts, num_contacts, key);
                break;
            case 5:
                res = searchContactByEmail(contacts, num_contacts, key);
                break;
            case 6:
                res = fuzzySearchContacts(contacts, num_contacts, key);
                break;
            case 7:
                res = searchContactsByGroup(contacts, num_contacts, key);
                break;
        }

        if (res == 0) {
            deleteContact(contacts,num_contacts,key,a);
            printf("ɾ���ɹ�\n");
        } else {
            printf("ɾ��ʧ��\n");
        }

        printf("�Ƿ�������� (y/n)? ");
        scanf("%c", &op);
        while (getchar() != '\n'); // ��������

        if (op != 'y' && op != 'Y') {
            break;
        }
    }
}

/*
������:showSearchInterface
����:��ʾ���ҽ���
�����:�Ϻ�

*/
void showSearchInterface(struct ContactRecord contacts[], int* num_contacts) {
    char op = 'y';
    int res = -1;

    while (1) {
        system("cls");
        printf("\t\t************* ��������ҷ�ʽ ***********\n\n");
        printf("\t\t\t1.��������\n");
        printf("\t\t\t2.�绰����\n");
        printf("\t\t\t3.��ַ����\n");
        printf("\t\t\t4.�ʱ����\n");
        printf("\t\t\t5.�������\n");
        printf("\t\t\t6.ģ������\n");
        printf("\t\t\t7.�������\n");
        printf("\t\t\t8.�˳�\n");

        char s[80];
        int a = 0;
        do {
            printf("Enter your choice (1~8): ");
            scanf("%s", s);
            a = atoi(s);
            while (getchar() != '\n'); // ��������
        } while (a < 1 || a > 8);

        if (a == 8) {
            break;
        }

        system("cls");
        char key[80];
        printf("\t\t������ҹؼ���:\n");
        scanf("%s", key);
        while (getchar() != '\n'); // ��������

        switch (a) {
            case 1:
                res = searchContactByName(contacts, num_contacts, key);
                break;
            case 2:
                res = searchContactByPhone(contacts, num_contacts, key);
                break;
            case 3:
                res = searchContactByAddress(contacts, num_contacts, key);
                break;
            case 4:
                res = searchContactByPostcode(contacts, num_contacts, key);
                break;
            case 5:
                res = searchContactByEmail(contacts, num_contacts, key);
                break;
            case 6:
                res = fuzzySearchContacts(contacts, num_contacts, key);
                break;
            case 7:
                res = searchContactsByGroup(contacts, num_contacts, key);
                break;
        }

        if (res == 0) {
            printf("���ҳɹ�\n");
        } else {
            printf("����ʧ��\n");
        }

        printf("�Ƿ�������� (y/n)? ");
        scanf("%c", &op);
        while (getchar() != '\n'); // ��������

        if (op != 'y' && op != 'Y') {
            break;
        }
    }
}


int addTagToContact(struct ContactRecord contact[], int* num_contacts, string contactName, string tag) {
	const char* cStr = contactName.c_str();
	char* tmp=new char[contactName.size()+1];
	strcpy(tmp, cStr);
	int findres = searchContactByName(contacts,num_contacts,tmp);
	if (findres != 0) {
		printf("\t\t�����ڸ���ϵ��!\n\t\t�Ƿ���������?\n\t\ty/n?\n");
		char s;
		string rcontactname = {};
		string rtag = {};
		scanf("%c", &s);
		if (s == 'y' || s == 'Y') {
			std::cin >> rcontactname >> rtag;
			addTagToContact(contact, num_contacts, rcontactname, rtag);
		}
		else return -1;
	}
	else {
		mp.insert(pair<string, string>(tag, contactName));
		return 0;
	}
}


