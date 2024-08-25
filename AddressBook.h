/**
  * @FileName : AddressBook.h
  * @Author   : 蜡笔小松
  * @Date     : 2024/8/24
  */


#include <iostream>
#include <string>

#define MAX 4

using namespace std;

/**
 * 联系人结构体
 */
struct Person {
    string m_Name; //姓名
    int m_Sex; //性别：1男 2女
    int m_Age; //年龄
    string m_Phone; //电话
    string m_Addr; //住址
};


/**
 * 通讯录结构体
 */
struct AddressBook {
    struct Person personArray[MAX]; //通讯录中保存的联系人数组
    int m_Size = 0; //通讯录中人员个数
};


/**
 * 显示菜单
 */
void showMenu();


/**
 * 添加联系人
 * @param addressBook
 */
void addPerson(AddressBook* addressBook);


/**
 * 显示联系人
 * @param addressBook
 */
void showPerson(AddressBook* addressBook);


/**
 * 判断联系人是否存在
 * @param abs
 * @param name
 * @return
 */
int isExist(AddressBook* addressBook, string name);


/**
 * 删除联系人
 * @param addressBook
 */
void deletePerson(AddressBook* addressBook);


/**
 * 查找联系人
 * @param addressBook
 */
void findPerson(AddressBook* addressBook);


/**
 * 修改联系人
 * @param addressBook
 */
void modifyPerson(AddressBook* addressBook);


/**
 * 清空联系人
 * @param addressBook
 */
void clearAllPerson(AddressBook* addressBook);