#pragma once
#include <string>
#include <iostream>

using namespace std;


class Chat {
public:
	Chat();
	~Chat();

	void add(string& login, string& password);
	int find(string& login);
	void del(string& login);
	int hash_func(string& password, int offset);

private:
	enum enPairStatus {
		free,
		engaged,
		deleted
	};

	struct Pair {
		Pair() :
			_login(""),
			_password(""),
			status(enPairStatus::free)
		{}

		Pair(string login, int password_hash) :
			_login(login),
			_password_hash(password_hash),
			status(enPairStatus::engaged)
		{}

		Pair& operator=(const Pair& other) {
			if (this != &other) { // Проверка на самоприсваивание
				_password_hash = other._password_hash;
				_login = other._login; // Используем оператор присваивания для std::string
				status = other.status;
			}
			return *this;
		}

		bool operator==(const Pair& other) const {
			return status == other.status &&
				(status != enPairStatus::engaged || (_password_hash == other._password_hash && _login == other._login));
		}

		string _login;
		string _password;
		int  _password_hash;
		enPairStatus status;
	};

	Pair* array;
	int size;
	int count;
};



