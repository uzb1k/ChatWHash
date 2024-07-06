#include "Chat.h"


Chat::Chat() : count(0), size(100) {
    array = new Pair[size];
}

Chat::~Chat() {
    delete[] array;
}

int Chat::hash_func(string& key, int offset) {
    const double A = 0.6180339887; // Константа золотого сечения
    const int M = size;

    // Преобразование строки в числовое значение
    unsigned long hash = 0;
    for (char c : key) {
        hash = hash * 31 + static_cast<int>(c);
    }

    // Метод умножения
    double fractional_part = (hash * A) - static_cast<int>(hash * A);
    return (static_cast<int>(M * fractional_part) + offset * offset) % M;
}

void Chat::add(string& login, string& password) {
    int index = -1, i = 0;
    int password_hash = hash_func(password, i);

    for (; i < login.size(); i++) {
        index = hash_func(login, i);

        if (array[index].status == enPairStatus::free) {
            break;
        }
    }

    if (i >= login.size()) {
        return;
    }

    array[index] = Pair(login, password_hash);
    count++;
    cout << "The user " << login << " has been registered!" << endl;
}

int Chat::find(string& login) {

    for (int i = 0; i < login.size(); i++) {
        int index = hash_func(login, i);
        if (array[index]._login == login && array[index].status == enPairStatus::engaged) {
            return array[index]._password_hash;
        }
        else if (array[index].status == enPairStatus::free) {
            return -1;
        }
    }

    return -1;
}

void Chat::del(string& login) {
    int index = -1, i = 0;

    for (; i < login.size(); i++) {
        index = hash_func(login, i);
        if (array[index].status == enPairStatus::engaged && array[index]._login == login) {
            array[index].status = enPairStatus::deleted;
            --count;
            cout << "The user: " << login << " has been deleted" << endl;
            return;
        }
        else if (array[index].status == enPairStatus::free) {
            return;
        }
    }
}