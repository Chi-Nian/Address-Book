#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"header.h"
#define  _CRT_SECURE_NO_WARNINGS
#define MAX_CONTACTS 100
struct ContactRecord							// ����һ����Ϊrecord�Ľṹ�����ͣ������洢ѧ������Ϣ
{
	char name[20];						// ���������20���ַ�
	char phone[12];						// �绰�����12���ַ�
	char address[50];					// ��ַ�����50���ַ�
	char postcode[8];					// �ʱ࣬���8���ַ�
	char e_mail[20];					// �������䣬���20���ַ�
	char group[20];						//����
};							// ����һ���ṹ�����飬�����洢���ѧ������Ϣ�������СΪ100�������洢100��ѧ������Ϣ

//���ֲ��ҷ�ʽ���������ҳ�����˺������ӷ��麯������Ҳ����ȥ���ò���ҳ�溯��
//����Ϊ������ӷ��麯����Ҫ�õ��⼸�������ķ��ص���ϵ��������
int searchContactByName(struct ContactRecord contacts[], int num_contacts, char* name);
int searchContactByPhone(struct ContactRecord contacts[], int num_contacts, char* phone);
int searchContactByAddress(struct ContactRecord contacts[], int num_contacts, char* address);
int searchContactByPostcode(struct ContactRecord contacts[], int num_contacts, char* postcode);
int searchContactByEmail(struct ContactRecord contacts[], int num_contacts, char* email);
int fuzzySearchContacts(struct ContactRecord contacts[], int num_contacts, char* keyword);
int multiConditionSearch(struct ContactRecord contacts[], int num_contacts, char* name, char* phone, char* address, char* postcode, char* email);


void encrypt(char* pwd)					//����һ����Ϊencrypt�ĺ��������ڶԴ�����ַ������м򵥵ļ��ܴ���
{
	int pwdlen = strlen(pwd);			// ��ȡ�ַ����ĳ��ȣ�����ѭ������ÿ���ַ���
	for (int i = 0; i < pwdlen; i++)	//�����ַ����е�ÿ���ַ���
	{
		pwd[i] ^= 15;					// ����ÿ���ַ���ʹ��������������м��ܴ���
	}
}
														// ����һ����Ϊnum�����ͱ���

// 3.2 ��ʾ��¼����
/*
������:
����: ��ʾ��¼���棬����ȡ�û�������û��������롣
����: void
����ֵ:
	0: ��¼�ɹ�
	-1: ��¼ʧ��
*/
int showLoginInterface() {
	char username[20];
	char password[20];
	printf("\n\t\t\t***********��¼����***********\n");
	printf("\t\t\t�û�����");
	scanf("%s", username);
	printf("\t\t\t���룺");
	scanf("%s", password);

	encrypt(password);  //�������������м��ܴ������������洢������Ƚ�
	if (authenticateUser("user_data.txt", username, password)) {
		printf("\n\t\t\t��¼�ɹ���");
		return 0;
	}
	else {
		printf("\n\t\t\t�û����������������������룡");
		return -1;
	}
}

// 3.4 ��ʾ�༭��¼����
/*
������:
����: ��ʾ�༭��¼���棬�����û�ѡ��Ҫ�༭����ϵ�ˣ��������µ���ϵ��Ϣ��
����:
contacts: �����ϵ�˵����顣
num_contacts: ��������ϵ�˵�������
����ֵ: void
*/
void showEditRecordInterface(struct ContactRecord contacts[], int num_contacts) {
	int choice;                 //��ϵ�˵����
	int index = choice - 1;     //�����ת��Ϊ��������
	printf("��ϵ��������%d\n", num_contacts);
	for (int i = 0; i < num_contacts; i++) {
		printf("%d.������%s���绰��%s����ַ��%s���ʱࣺ%s�����䣺%s\n", i + 1, contacts[i].name,
			contacts[i].phone, contacts[i].address, contacts[i].postcode, contacts[i].e_mail);;
	}

	printf("\n\t\t\t��ѡ����Ҫ�༭����ϵ�ˣ���ţ���\n");
	scanf("%d", &choice);
	if (index >= 0 && index < num_contacts) {
		printf("\n\t\t\t��༭����ϵ�ˣ�\n");
		printf("\t\t\t������������");
		scanf("%s", contacts[index].name);
		printf("\n\t\t\t�����µ绰��");
		scanf("%s", contacts[index].phone);
		printf("\n\t\t\t�����µ�ַ��");
		scanf("%s", contacts[index].address);
		printf("\n\t\t\t�������ʱࣺ");
		scanf("%s", contacts[index].postcode);
		printf("\n\t\t\t���������䣺");
		scanf("%s", contacts[index].e_mail);
		printf("�༭�ɹ���");
	}
	else {
		printf("û����ѡ����ţ�������ѡ��");
		scanf("%d", &choice);
	}
}

// 2.13 ��ӷ���
int addGroup(struct ContactRecord contacts[], int* num_contacts, char* group) {
	char new_group[20];
	printf("������Ҫ��ӵ��·������� ");
	scanf("%19s", new_group);

	//1.��ѡ����ҷ�ʽ���ҵ�Ҫ����÷������ϵ��
	int choice;
	printf("��ѡ����ҷ�ʽ��\n");
	printf("1.����������\n");
	printf("2.���绰����\n");
	printf("3.����ַ����\n");
	printf("4.���ʱ����\n");
	printf("5.���������\n");
	printf("6.ģ������\n");
	printf("7.����������\n");
	scanf("%d", &choice);
	getchar();                        //�����з�

	//2.��ȥִ����Ӧ�Ĳ���
	int index = -1;                  //���淵�ص�����
	switch (choice) {
	case 1: {
		char name[20];
		printf("����Ҫ���ҵ���ϵ��������");
		scanf("19%s", name);
		index = searchContactByName(contacts, *num_contacts, name);
		break;
	}
	case 2: {
		char phone[20];
		printf("����Ҫ���ҵ���ϵ�˵绰��");
		scanf("%19s", phone);
		index = searchContactByPhone(contacts, *num_contacts, phone);
		break;
	}
	case 3: {
		char address[20];
		printf("����Ҫ���ҵ���ϵ�˵�ַ��");
		scanf("%19s", address);
		index = searchContactByAddress(contacts, *num_contacts, address);
		break;
	}
	case 4: {
		char postcode[8];
		printf("����Ҫ���ҵ���ϵ���ʱࣺ");
		scanf("%7s", postcode);
		index = searchContactByPostcode(contacts, *num_contacts, postcode);
		break;
	}
	case 5: {
		char e_mail[20];
		printf("����Ҫ���ҵ���ϵ�����䣺");
		scanf("%19s", e_mail);
		index = searchContactByEmail(contacts, *num_contacts, e mail);
		break;
	}
	case 6: {
		char keyword[50];
		printf("����Ҫ���ҵ���ϵ�˹ؼ��֣�");
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
		printf("����Ҫ���ҵ���ϵ����Ϣ��");
		scanf("19%s", name);
		scanf("%19s", phone);
		scanf("%19s", address);
		scanf("%7s", postcode);
		scanf("%19s", e_mail);
		index = multiConditionSearch(contacts, *num_contacts, name, phone, address, postcode, e_mail);
		break;
	}
	default:
		printf("û��������ҷ�ʽѡ��.\n");
		return -1; 
	}

	//3.�����ҽ�������ķ���
	if (index != -1) {
		strcpy(contacts[index].group, new_group);
		printf("����·���ɹ���\n");
	}
	else {
		printf("δ�ҵ�����ϵ�ˣ���ӷ���ʧ��\n");
	}
	return 0;				//����0��ʾ�ɹ���ӷ���
}


