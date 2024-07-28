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
函数名:showDeleteRecordInterface
功能:显示删除界面
完成者:老胡

*/
void showDeleteRecordInterface(struct ContactRecord contacts[], int* num_contacts) {
char op = 'y';
    int res = -1;

    while (1) {
        system("cls");
        printf("\t\t************* 请输入删除时查找方式 ***********\n\n");
        printf("\t\t\t1.姓名查找\n");
        printf("\t\t\t2.电话查找\n");
        printf("\t\t\t3.地址查找\n");
        printf("\t\t\t4.邮编查找\n");
        printf("\t\t\t5.邮箱查找\n");
        printf("\t\t\t6.模糊查找\n");
        printf("\t\t\t7.分组查找\n");
        printf("\t\t\t8.退出\n");

        char s[80];
        int a = 0;
        do {
            printf("Enter your choice (1~8): ");
            scanf("%s", s);
            a = atoi(s);
            while (getchar() != '\n'); // 清理缓冲区
        } while (a < 1 || a > 8);

        if (a == 8) {
            break;
        }

        system("cls");
        char key[80];
        printf("\t\t输入查找关键词:\n");
        scanf("%s", key);
        while (getchar() != '\n'); // 清理缓冲区

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
            printf("删除成功\n");
        } else {
            printf("删除失败\n");
        }

        printf("是否继续输入 (y/n)? ");
        scanf("%c", &op);
        while (getchar() != '\n'); // 清理缓冲区

        if (op != 'y' && op != 'Y') {
            break;
        }
    }
}

/*
函数名:showSearchInterface
功能:显示查找界面
完成者:老胡

*/
void showSearchInterface(struct ContactRecord contacts[], int* num_contacts) {
    char op = 'y';
    int res = -1;

    while (1) {
        system("cls");
        printf("\t\t************* 请输入查找方式 ***********\n\n");
        printf("\t\t\t1.姓名查找\n");
        printf("\t\t\t2.电话查找\n");
        printf("\t\t\t3.地址查找\n");
        printf("\t\t\t4.邮编查找\n");
        printf("\t\t\t5.邮箱查找\n");
        printf("\t\t\t6.模糊查找\n");
        printf("\t\t\t7.分组查找\n");
        printf("\t\t\t8.退出\n");

        char s[80];
        int a = 0;
        do {
            printf("Enter your choice (1~8): ");
            scanf("%s", s);
            a = atoi(s);
            while (getchar() != '\n'); // 清理缓冲区
        } while (a < 1 || a > 8);

        if (a == 8) {
            break;
        }

        system("cls");
        char key[80];
        printf("\t\t输入查找关键词:\n");
        scanf("%s", key);
        while (getchar() != '\n'); // 清理缓冲区

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
            printf("查找成功\n");
        } else {
            printf("查找失败\n");
        }

        printf("是否继续输入 (y/n)? ");
        scanf("%c", &op);
        while (getchar() != '\n'); // 清理缓冲区

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
		printf("\t\t不存在该联系人!\n\t\t是否重新输入?\n\t\ty/n?\n");
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


