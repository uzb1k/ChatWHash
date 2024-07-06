#include "Chat.h"

int main()
{
    Chat c;
    string login;
    string password;
    int choose;
    int password_hash;
    int f;
    bool isRunning = true;

    while (isRunning) {
        cout << "Choose your option: (1 - Register, 2 - Login in, 3 - Delete your account, 4 - Exit)" << endl;
        cin >> choose;

        switch (choose) {
        case 1:
            cout << "Enter your new Login: " << endl;
            cin >> login;

            cout << endl << "Enter your new Password: " << endl;
            cin >> password;
            cout << endl;

            c.add(login, password);

            break;

        case 2:
            cout << "Enter your Login:" << endl;
            cin >> login;

            cout << endl << "Enter your Password:" << endl;
            cin >> password;

            password_hash = c.hash_func(password, 0);
            f = c.find(login);
            if (f != -1) {
                if (f == password_hash) {
                    cout << "Access allowed!" << endl;
                }
            }
            else {
                cout << "Wrong Login or Pasword(" << endl;
            }

            break;

        case 3:
            cout << "Enter your Login:" << endl;
            cin >> login;

            cout << endl << "Enter your Password:" << endl;
            cin >> password;

            password_hash = c.hash_func(password, 0);
            f = c.find(login);
            if (f != -1) {
                if (f == password_hash) {
                    c.del(login);
                }
            }
            else {
                cout << "Wrong Login or Pasword(" << endl;
            }

            break;
        case 4:
            cout << "Goodbye!)" << endl;
            isRunning = false;
        }
    }
    
    return 0;
}

