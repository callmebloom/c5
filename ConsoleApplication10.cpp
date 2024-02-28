#include <iostream>
#include <string>
#include <algorithm>
#include <random>


std::string reverseWord(std::string word) {
    std::reverse(word.begin(), word.end());
    return word;
}


std::string removeVowels(std::string word) {
    std::string result = "";
    for (char c : word) {
        if (std::tolower(c) != 'а' && std::tolower(c) != 'е' && std::tolower(c) != 'ё' && std::tolower(c) != 'и' && std::tolower(c) != 'о' && std::tolower(c) != 'у' && std::tolower(c) != 'ы' && std::tolower(c) != 'э' && std::tolower(c) != 'ю' && std::tolower(c) != 'я') {
            result += c;
        }
    }
    return result;
}


std::string removeConsonants(std::string word) {
    std::string result = "";
    for (char c : word) {
        if (!isalpha(c) || std::tolower(c) == 'а' || std::tolower(c) == 'е' || std::tolower(c) == 'ё' || std::tolower(c) == 'и' || std::tolower(c) == 'о' || std::tolower(c) == 'у' || std::tolower(c) == 'ы' || std::tolower(c) == 'э' || std::tolower(c) == 'ю' || std::tolower(c) == 'я') {
            result += c;
        }
    }
    return result;
}


std::string shuffleWord(std::string word) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(word.begin(), word.end(), g);
    return word;
}

int main() {
    std::string inputWord;
    int choice;

    setlocale(LC_ALL, "Russian");

    std::cout << "Введите слово: ";
    std::getline(std::cin, inputWord);

    std::cout << "Выберите действие:\n";
    std::cout << "1. Слово выводится задом наперед.\n";
    std::cout << "2. Вывести слово без гласных.\n";
    std::cout << "3. Вывести слово без согласных.\n";
    std::cout << "4. Рандомно раскидывать буквы заданного слова.\n";

    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Слово задом наперед: " << reverseWord(inputWord) << std::endl;
        break;
    case 2:
        std::cout << "Слово без гласных: " << removeVowels(inputWord) << std::endl;
        break;
    case 3:
        std::cout << "Слово без согласных: " << removeConsonants(inputWord) << std::endl;
        break;
    case 4:
        std::cout << "Рандомно раскидывать буквы заданного слова: " << shuffleWord(inputWord) << std::endl;
        break;
    default:
        std::cout << "Некорректный выбор действия.\n";
        break;
    }

    return 0;
}
