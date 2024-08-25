/**
  * @FileName : main.cpp
  * @Author   : ����С��
  * @Date     : 2024/8/24
  */

#include "AddressBook.h"

int main() {

    AddressBook addressBook;
    addressBook.m_Size = 0;

    int select = 0;
    while (true) {
        showMenu();

        cin >> select;

        switch (select) {
            case 1:
                addPerson(&addressBook);
                break;
            case 2:
                showPerson(&addressBook);
                break;
            case 3:
                deletePerson(&addressBook);
                break;
            case 4:
                findPerson(&addressBook);
                break;
            case 5:
                modifyPerson(&addressBook);
                break;
            case 6:
                clearAllPerson(&addressBook);
                break;
            case 0:
                cout << "��ӭ�´�ʹ�ã�" << endl;
                return 0;
            default:
                break;
        }
    }
}