#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file) {
        std::cout << "File created: " << filename << std::endl;
        file.close();
    } else {
        std::cerr << "Failed to create file: " << filename << std::endl;
    }
}

void deleteFile(const std::string& filename) {
    if (fs::remove(filename)) {
        std::cout << "File deleted: " << filename << std::endl;
    } else {
        std::cerr << "Failed to delete file: " << filename << std::endl;
    }
}

void listFilesInDirectory(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::cout << "File: " << entry.path().filename() << std::endl;
        } else if (entry.is_directory()) {
            std::cout << "Directory: " << entry.path().filename() << std::endl;
        }
    }
}

int main() {
    std::string command;
    std::string name;

    while (true) {
        std::cout << "Enter a command (create, delete, list, exit): ";
        std::cin >> command;

        if (command == "create") {
            std::cout << "Enter the name of the file to create: ";
            std::cin >> name;
            createFile(name);
        } else if (command == "delete") {
            std::cout << "Enter the name of the file to delete: ";
            std::cin >> name;
            deleteFile(name);
        } else if (command == "list") {
            std::cout << "Enter the path to the directory: ";
            std::cin >> name;
            listFilesInDirectory(name);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Available commands: create, delete, list, exit." << std::endl;
        }
    }

    return 0;
}
