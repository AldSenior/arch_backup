#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

// Функция для проверки, содержит ли слово все символы подстроки
bool containsAllChars(const char* word, const char* substr) {
    int count[256] = {0};   
    for (int i = 0; substr[i    ]; i++) {   
        count[(unsigned char)sub    str[i]]++;  
    }   
    for (int i = 0; word[i]; i++)                   {
            if (count[(unsigned char)word[i]] > 0) {
            count[(unsigned char)word[i]]--;
        }
    }
    for (int i = 0; substr[i]; i++) {
        if (count[(unsigned char)substr[i]] > 0) {
            return false;
        }
    }
    return true;
}

// Функция для формирования новой строки из слов, содержащих все символы подстроки
char* formNewString(const char* str, const char* substr) {
    vector<char*> words;
    char* tempStr = strdup(str);
    char* word = strtok(tempStr, " ");
    while (word != nullptr) {
        if (containsAllChars(word, substr)) {
            words.push_back(strdup(word));
        }
        word = strtok(nullptr, " ");
    }
    free(tempStr);

    // Формируем новую строку
    char* newStr = (char*)malloc(1);
    newStr[0] = '\0';
    for (size_t i = 0; i < words.size(); i++) {
        newStr = (char*)realloc(newStr, strlen(newStr) + strlen(words[i]) + 2);
        strcat(newStr, words[i]);
        if (i < words.size() - 1) {
            strcat(newStr, " ");
        }
        free(words[i]);
    }
    return newStr;
}

// Функция для проверки, содержит ли слово подстроку
bool containsSubstring(const char* word, const char* substr) {
    return strstr(word, substr) != nullptr;
}

// Функция для перемещения первого слова, содержащего подстроку, в начало строки
char* moveFirstWordToFront(const char* str, const char* substr) {
    vector<char*> words;
    char* tempStr = strdup(str);
    char* word = strtok(tempStr, " ");
    while (word != nullptr) {
        words.push_back(strdup(word));
        word = strtok(nullptr, " ");
    }
    free(tempStr);

    // Находим первое слово, содержащее подстроку
    size_t index = 0;
    for (; index < words.size(); index++) {
        if (containsSubstring(words[index], substr)) {
            break;
        }
    }

    if (index < words.size()) {
        // Перемещаем найденное слово в начало
        char* temp = words[index];
        for (size_t i = index; i > 0; i--) {
            words[i] = words[i - 1];
        }
        words[0] = temp;
    }

    // Формируем новую строку
    char* newStr = (char*)malloc(1);
    newStr[0] = '\0';
    for (size_t i = 0; i < words.size(); i++) {
        newStr = (char*)realloc(newStr, strlen(newStr) + strlen(words[i]) + 2);
        strcat(newStr, words[i]);
        if (i < words.size() - 1) {
            strcat(newStr, " ");
        }
        free(words[i]);
    }
    return newStr;
}

// Функция для разбиения строки по словам
vector<string> split(const string& str) {
    vector<string> words;
    istringstream iss(str);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// Основная функция
int main() {
    string inputString;
    string substring;

    // Ввод строки от пользователя
    cout << "Введите строку: ";
    getline(cin, inputString);

    // Ввод подстроки от пользователя
    cout << "Введите подстроку: ";
    getline(cin, substring);

    // Подзадача 1
    char* result1 = formNewString(inputString.c_str(), substring.c_str());
    cout << "Новая строка (Задание 1.1): " << result1 << endl;
    free(result1);

    // Подзадача 2
    char* result2 = moveFirstWordToFront(inputString.c_str(), substring.c_str());
    cout << "Измененная строка (Задание 1.2): " << result2 << endl;
    free(result2);

    // Задание 2
    vector<string> words = split(inputString);
    cout << "Разделенная строка (Задание 2):" << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}