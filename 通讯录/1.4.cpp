
#include <iostream>
#include <fstream>
/*
#include <string>

using namespace std;

// 验证用户身份
bool authenticateUser(const char* filename, const char* username, const char* password)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "无法打开文件：" << filename << endl;
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

    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;

    if (authenticateUser(filename, username, password))
    {
        cout << "验证成功！" << endl;
    }
    else
    {
        cout << "验证失败！" << endl;
    }

    return 0;
}
*/