/**
  * @FileName : AddressBook.cpp
  * @Author   : ����С��
  * @Date     : 2024/8/24
  */

#include "AddressBook.h"


/**
 * ��ʾ�˵�
 */
void showMenu() {
    cout << "***************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "***************************" << endl;
}


/**
 * �����ϵ��
 * @param addressBook
 */
void addPerson(AddressBook *addressBook) {
    if (addressBook->m_Size == MAX) {
        cout << "ͨѶ¼�������޷���ӣ�";
        return;
    }

    cout << "������������" << endl;
    string name;
    cin >> name;
    addressBook->personArray[addressBook->m_Size].m_Name = name;

    cout << "�������Ա�" << endl;
    cout << "1 -- ��" << endl;
    cout << "2 -- Ů" << endl;
    int sex = 0;
    while (true) {
        cin >> sex;
        // TODO ���û����벻������ʱ�޷�ͨ�����ԣ���������ѭ��
        if (sex == 1 || sex == 2) {
            addressBook->personArray[addressBook->m_Size].m_Sex = sex;
            break;
        }
        cout << "������������������" << endl;
    }

    cout << "���������䣺" << endl;
    int age = 0;
    while (true) {
        cin >> age;
        // TODO ���û����벻������ʱ�޷�ͨ�����ԣ���������ѭ��
        if (age >= 0 && age <= 150) {
            addressBook->personArray[addressBook->m_Size].m_Age = age;
            break;
        }
        cout << "�������䲻�Ϸ�������������" << endl;
    }

    cout << "��������ϵ�绰��" << endl;
    string phone;
    cin >> phone;
    addressBook->personArray[addressBook->m_Size].m_Phone = phone;

    cout << "�������ͥסַ��" << endl;
    string address;
    cin >> address;
    addressBook->personArray[addressBook->m_Size].m_Addr = address;

    addressBook->m_Size++;

    cout << "��ӳɹ���" << endl;
}


/**
 * ��ʾ��ϵ��
 * @param addressBook
 */
void showPerson(AddressBook *addressBook) {
    if (addressBook->m_Size == 0) {
        cout << "��ǰ��¼Ϊ�գ�" << endl;
        return;
    }
    for (int i = 0; i < addressBook->m_Size; ++i) {
        cout << "������" << addressBook->personArray[i].m_Name << "\t";
        cout << "�Ա�" << (addressBook->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺" << addressBook->personArray[i].m_Age << "\t";
        cout << "�绰��" << addressBook->personArray[i].m_Phone << "\t";
        cout << "סַ��" << addressBook->personArray[i].m_Addr << endl;
    }
}


/**
 * �ж���ϵ���Ƿ����
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
 * ɾ����ϵ��
 * @param addressBook
 */
void deletePerson(AddressBook *addressBook) {
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;

    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "���û������ڣ��޷�ɾ����" << endl;
        return;
    }

    // index 0 1 2 3
    // Ԫ��   a b c d
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

    cout << "ɾ���ɹ���" << endl;
}


/**
 * ������ϵ��
 * @param addressBook
 */
void findPerson(AddressBook *addressBook) {
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;

    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "���޴��ˣ�" << endl;
        return;
    }

    cout << "������" << addressBook->personArray[index].m_Name << "\t";
    cout << "�Ա�" << addressBook->personArray[index].m_Sex << "\t";
    cout << "���䣺" << addressBook->personArray[index].m_Age << "\t";
    cout << "�绰��" << addressBook->personArray[index].m_Phone << "\t";
    cout << "סַ��" << addressBook->personArray[index].m_Addr << endl;
}


/**
 * �޸���ϵ��
 * @param addressBook
 */
void modifyPerson(AddressBook *addressBook) {
    cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
    string name;
    cin >> name;

    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "���޴��ˣ�" << endl;
        return;
    }

    cout << "�������޸ĺ��������" << endl;
    cin >> name;
    addressBook->personArray[index].m_Name = name;

    cout << "�������޸ĺ���Ա�" << endl;
    cout << "1 -- ��" << endl;
    cout << "2 -- Ů" << endl;
    int sex = 0;
    while (true) {
        cin >> sex;
        // TODO ���û����벻������ʱ�޷�ͨ�����ԣ���������ѭ��
        if (sex == 1 || sex == 2) {
            addressBook->personArray[index].m_Sex = sex;
            break;
        }
        cout << "������������������" << endl;
    }

    cout << "�������޸ĺ�����䣺" << endl;
    int age = 0;
    while (true) {
        cin >> age;
        // TODO ���û����벻������ʱ�޷�ͨ�����ԣ���������ѭ��
        if (age >= 0 && age <= 150) {
            addressBook->personArray[index].m_Age = age;
            break;
        }
        cout << "�������䲻�Ϸ�������������" << endl;
    }

    cout << "�������޸ĺ����ϵ�绰��" << endl;
    string phone;
    cin >> phone;
    addressBook->personArray[index].m_Phone = phone;

    cout << "�������޸ĺ�ļ�ͥסַ��" << endl;
    string address;
    cin >> address;
    addressBook->personArray[index].m_Addr = address;

    cout << "�޸ĳɹ���" << endl;
}


/**
 * �����ϵ��
 * @param addressBook
 */
void clearAllPerson(AddressBook *addressBook) {
    addressBook->m_Size = 0;
    cout << "ͨѶ¼����գ�" << endl;
}