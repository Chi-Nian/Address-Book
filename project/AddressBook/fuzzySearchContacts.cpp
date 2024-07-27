#include "head.h"
#include <corecrt_memory.h>
#include <memory>
// 服务层：模糊搜索联系人
int fuzzySearchContacts(const ContactRecord contacts[], int num_contacts, const char* keyword) {
    for (int i = 0; i < num_contacts; ++i) {
        if (strstr(contacts[i].name, keyword) || strstr(contacts[i].phone, keyword) ||
            strstr(contacts[i].address, keyword) || strstr(contacts[i].postcode, keyword) ||
            strstr(contacts[i].email, keyword)) {
            return i;  // 找到联系人，返回索引
        }
    }
    return -1;  // 未找到联系人
}

// 服务层：多条件搜索联系人
int multiConditionSearch(const ContactRecord contacts[], int num_contacts, const char* name, const char* phone,
    const char* address, const char* postcode, const char* email) {
    for (int i = 0; i < num_contacts; ++i) {
        if ((strlen(name) == 0 || strcmp(contacts[i].name, name) == 0) &&
            (strlen(phone) == 0 || strcmp(contacts[i].phone, phone) == 0) &&
            (strlen(address) == 0 || strcmp(contacts[i].address, address) == 0) &&
            (strlen(postcode) == 0 || strcmp(contacts[i].postcode, postcode) == 0) &&
            (strlen(email) == 0 || strcmp(contacts[i].email, email) == 0)) {
            return i;  // 找到联系人，返回索引
        }
    }
    return -1;  // 未找到联系人
}
