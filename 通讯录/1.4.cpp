
#include <iostream>
#include <fstream>
/*
#include <string>

using namespace std;

// ��֤�û����
bool authenticateUser(const char* filename, const char* username, const char* password)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "�޷����ļ���" << filename << endl;
        return false;
    }

    string fileUsername;
    string filePassword;

    while (file >> fileUsername >> filePassword)
    {
        if (fileUsername == username && filePassword == password)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int main()
{
    const char* filename = "user.txt";
    char username[100];
    char password[100];

    cout << "�������û�����";
    cin >> username;
    cout << "���������룺";
    cin >> password;

    if (authenticateUser(filename, username, password))
    {
        cout << "��֤�ɹ���" << endl;
    }
    else
    {
        cout << "��֤ʧ�ܣ�" << endl;
    }

    return 0;
}
*/