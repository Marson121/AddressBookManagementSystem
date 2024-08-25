/**
  * @FileName : AddressBook.cpp
  * @Author   : 蜡笔小松
  * @Date     : 2024/8/24
  */

#include "AddressBook.h"


/**
 * 显示菜单
 */
void showMenu() {
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}


/**
 * 添加联系人
 * @param addressBook
 */
void addPerson(AddressBook *addressBook) {
    if (addressBook->m_Size == MAX) {
        cout << "通讯录已满，无法添加！";
        return;
    }

    cout << "请输入姓名：" << endl;
    string name;
    cin >> name;
    addressBook->personArray[addressBook->m_Size].m_Name = name;

    cout << "请输入性别：" << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;
    int sex = 0;
    while (true) {
        cin >> sex;
        // TODO 当用户输入不是数字时无法通过测试，会陷入死循环
        if (sex == 1 || sex == 2) {
            addressBook->personArray[addressBook->m_Size].m_Sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请输入年龄：" << endl;
    int age = 0;
    while (true) {
        cin >> age;
        // TODO 当用户输入不是数字时无法通过测试，会陷入死循环
        if (age >= 0 && age <= 150) {
            addressBook->personArray[addressBook->m_Size].m_Age = age;
            break;
        }
        cout << "输入年龄不合法，请重新输入" << endl;
    }

    cout << "请输入联系电话：" << endl;
    string phone;
    cin >> phone;
    addressBook->personArray[addressBook->m_Size].m_Phone = phone;

    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    addressBook->personArray[addressBook->m_Size].m_Addr = address;

    addressBook->m_Size++;

    cout << "添加成功！" << endl;
}


/**
 * 显示联系人
 * @param addressBook
 */
void showPerson(AddressBook *addressBook) {
    if (addressBook->m_Size == 0) {
        cout << "当前记录为空！" << endl;
        return;
    }
    for (int i = 0; i < addressBook->m_Size; ++i) {
        cout << "姓名：" << addressBook->personArray[i].m_Name << "\t";
        cout << "性别：" << (addressBook->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << addressBook->personArray[i].m_Age << "\t";
        cout << "电话：" << addressBook->personArray[i].m_Phone << "\t";
        cout << "住址：" << addressBook->personArray[i].m_Addr << endl;
    }
}


/**
 * 判断联系人是否存在
 * @param abs
 * @param name
 * @return
 */
int isExist(AddressBook *addressBook, string name) {
    for (int i = 0; i < addressBook->m_Size; ++i) {
        if (addressBook->personArray[i].m_Name == name) {
            return i;
        }
    }
    return -1;
}


/**
 * 删除联系人
 * @param addressBook
 */
void deletePerson(AddressBook *addressBook) {
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "该用户不存在，无法删除！" << endl;
        return;
    }

    // index 0 1 2 3
    // 元素   a b c d
    // < m_Size index = 1
    // i = 1 i < 4    personArray[1] = personArray[2]
    // i = 2 i < 4    personArray[2] = personArray[3]
    // i = 3 i < 4    personArray[3] = personArray[4]

    // < m_Size-1 index = 1
    // i = 1   i < 3    personArray[1] = personArray[2]
    // i = 2   i < 3    personArray[2] = personArray[3]
    for (int i = index; i < addressBook->m_Size - 1; i++) {
        addressBook->personArray[i] = addressBook->personArray[i + 1];
    }
    addressBook->m_Size--;

    cout << "删除成功！" << endl;
}


/**
 * 查找联系人
 * @param addressBook
 */
void findPerson(AddressBook *addressBook) {
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "查无此人！" << endl;
        return;
    }

    cout << "姓名：" << addressBook->personArray[index].m_Name << "\t";
    cout << "性别：" << addressBook->personArray[index].m_Sex << "\t";
    cout << "年龄：" << addressBook->personArray[index].m_Age << "\t";
    cout << "电话：" << addressBook->personArray[index].m_Phone << "\t";
    cout << "住址：" << addressBook->personArray[index].m_Addr << endl;
}


/**
 * 修改联系人
 * @param addressBook
 */
void modifyPerson(AddressBook *addressBook) {
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "查无此人！" << endl;
        return;
    }

    cout << "请输入修改后的姓名：" << endl;
    cin >> name;
    addressBook->personArray[index].m_Name = name;

    cout << "请输入修改后的性别：" << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;
    int sex = 0;
    while (true) {
        cin >> sex;
        // TODO 当用户输入不是数字时无法通过测试，会陷入死循环
        if (sex == 1 || sex == 2) {
            addressBook->personArray[index].m_Sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请输入修改后的年龄：" << endl;
    int age = 0;
    while (true) {
        cin >> age;
        // TODO 当用户输入不是数字时无法通过测试，会陷入死循环
        if (age >= 0 && age <= 150) {
            addressBook->personArray[index].m_Age = age;
            break;
        }
        cout << "输入年龄不合法，请重新输入" << endl;
    }

    cout << "请输入修改后的联系电话：" << endl;
    string phone;
    cin >> phone;
    addressBook->personArray[index].m_Phone = phone;

    cout << "请输入修改后的家庭住址：" << endl;
    string address;
    cin >> address;
    addressBook->personArray[index].m_Addr = address;

    cout << "修改成功！" << endl;
}


/**
 * 清空联系人
 * @param addressBook
 */
void clearAllPerson(AddressBook *addressBook) {
    addressBook->m_Size = 0;
    cout << "通讯录已清空！" << endl;
}