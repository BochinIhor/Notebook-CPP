#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

class Note {
public:
    std::string title;
    std::string content;

    Note(const std::string& t, const std::string& c) : title(t), content(c) {}
};

class Notebook {
private:
    std::vector<Note> notes;

public:
    void addNote() {
        std::string title, content;

        std::cout << "Введите заголовок заметки: ";
        std::getline(std::cin, title);

        std::cout << "Введите текст заметки (для завершения введите '.' на новой строке):\n";
        std::string line;
        while (std::getline(std::cin, line) && line != ".") {
            content += line + "\n";
        }

        notes.push_back(Note{ title, content });
        std::cout << "Заметка добавлена!\n";
    }

    void displayNotes() {
        if (notes.empty()) {
            std::cout << "Заметок пока нет.\n";
        }
        else {
            std::cout << "Список заметок:\n";
            for (const auto& note : notes) {
                std::cout << "-------------------------\n";
                std::cout << "Заголовок: " << note.title << "\n";
                std::cout << "Текст:\n" << note.content << "\n";
            }
            std::cout << "-------------------------\n";
        }
    }

    void saveToFile() {
        std::ofstream file("notes.txt");
        if (file.is_open()) {
            for (const auto& note : notes) {
                file << "-------------------------\n";
                file << "Заголовок: " << note.title << "\n";
                file << "Текст:\n" << note.content << "\n";
            }
            file << "-------------------------\n";
            file.close();
            std::cout << "Заметки сохранены в файл notes.txt\n";
        }
        else {
            std::cerr << "Ошибка открытия файла для сохранения.\n";
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    Notebook notebook;
    char choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить заметку\n";
        std::cout << "2. Просмотреть все заметки\n";
        std::cout << "3. Сохранить заметки в файл\n";
        std::cout << "0. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        std::cin.ignore();  // Очистка буфера ввода
        system("cls");

        switch (choice) {
        case '1':
            notebook.addNote();
            break;
        case '2':
            notebook.displayNotes();
            break;
        case '3':
            notebook.saveToFile();
            break;
        case '0':
            std::cout << "До свидания!\n";
            break;
        default:
            std::cout << "Неверный выбор. Повторите попытку.\n";
        }

    } while (choice != '0');

    return 0;
}
