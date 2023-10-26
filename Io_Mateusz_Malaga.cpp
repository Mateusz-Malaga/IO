#in#include <iostream>
#include <string>
#include <map>

enum class AcountType {
    Nauczyciel,
    Uczen
};
struct UserData {
    std::string login;
    std::string password;
    AcountType type;
};

std::map<std::string, UserData> users;

bool RegisterUser(std::string login, std::string password) {
    if (users.find(login) != users.end()) {
        std::cout << "Uzytkownik juz istnieje" << std::endl;
        return false;
    }

    UserData data;
    data.login = login;
    data.password = password;
    users[login] = data;
    std::cout << "Uzytkownik zarejestrowany" << std::endl;
    return true;
}

bool Login(std::string login, std::string password) {
    if (users.find(login) != users.end() && users[login].password == password) {
        std::cout << "Uzytkownik zalogowany" << std::endl;
        return true;
    }

    std::cout << "Uzytkownik niezalogowany" << std::endl;
    return false;
}

int main() {
    int choice;

    while (true) {
        std::cout << "Wybierz opcje: " << std::endl;
        std::cout << "1. Rejestracja" << std::endl;
        std::cout << "2. Logowanie" << std::endl;
        std::cout << "3. Wyjscie" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
            {
                std::string login, password;
                std::cout << "Rejestracja uzytkownika: ";
                std::cin >> login;
                std::cout << "Podaj haslo: ";
                std::cin >> password;
                RegisterUser(login, password);
            }
                break;
            case 2:
            {
                std::string login, password;
                std::cout << "Logowanie uzytkownika: ";
                std::cin >> login;
                std::cout << "Podaj haslo: ";
                std::cin >> password;
                Login(login, password);
            }
                break;
            case 3:
                return 0;
            default:
                std::cout << "Nieprawidlowy wybor" << std::endl;
                break;
        }
    }

    return 0;
}
