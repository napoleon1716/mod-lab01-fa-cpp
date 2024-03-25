// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char* str) {
    unsigned int count = 0;

    while (*str) {
        // Пропускаем пробелы в начале строки
        while (*str && std::isspace(*str)) {
            ++str;
        }

        // Проверяем, если это начало слова
        if (*str && !std::isspace(*str)) {
            bool hasDigit = false;
            // Считаем слово до первого пробела или конца строки
            while (*str && !std::isspace(*str)) {
                if (std::isdigit(*str)) {
                    hasDigit = true;
                    break;
                }
                ++str;
            }
            // Если слово не содержит цифр, увеличиваем счетчик слов
            if (!hasDigit) {
                ++count;
            }
        }
        // Пропускаем остаток слова
        while (*str && !std::isspace(*str)) {
            ++str;
        }
    }

    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;

    // Флаг, указывающий на начало слова
    bool inWord = false;

    // Проходим по строке
    while (*str) {
        // Если текущий символ - буква и это начало слова
        if (std::isalpha(*str) && !inWord) {
            // Если текущий символ - заглавная буква
            if (std::isupper(*str)) {
                // Переходим к следующему символу
                ++str;

                // Пропускаем остальные буквы слова
                while (std::isalpha(*str) && std::islower(*str)) {
                    ++str;
                }

                // Если слово закончилось и не достигнут конец строки,
                // и следующий символ - не буква, увеличиваем счетчик слов
                if (std::isspace(*str)) {
                    ++count;
                }
            } else {
                // Если текущий символ не заглавная буква, это не начало слова
                ++str;
                continue;
            }
        } else {
            // Если текущий символ - не буква, это конец слова
            if (!std::isspace(*str)) {
                inWord = false;
            } else {
                inWord = true;
            }

            // Переходим к следующему символу
            ++str;
        }
    }

    return count;
}

unsigned int faStr3(const char* str) {
    unsigned int sumLength = 0; // Суммарная длина слов
    unsigned int wordCount = 0; // Количество слов
    bool inWord = false; // Флаг, указывающий на то, находимся ли мы внутри слова
    while (*str) {
        if (std::isalpha(*str)) { // Если текущий символ - буква
            if (!inWord) { // Если это начало нового слова
                inWord = true; // Устанавливаем флаг, что мы внутри слова
                ++wordCount; // Увеличиваем счетчик слов
            }
            ++sumLength; // Увеличиваем суммарную длину слов
        } else {
            inWord = false; // Если текущий символ не буква, заканчиваем слово
        }
        ++str; // Переходим к следующему символу
    }
    if (wordCount == 0) {
        return 0; // Для избежания деления на ноль
    }
    return sumLength / wordCount; // Возвращаем среднюю длину слова
}
