#include"head.h"
#include <iostream>
using namespace std;

int main() {
	ContactRecord contacts[MAX_CONTACTS];
	int num_contacts=0;
	int flag = -1;
	flag=showLoginInterface();
	//flag = 0;
	if (flag == 0) {
		readContacts(contacts,& num_contacts);
		menuSelect(contacts, &num_contacts);
		writeContacts(contacts, num_contacts);
	}
	
	return 0;
}

