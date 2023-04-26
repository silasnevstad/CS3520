#include <iostream>
#include "repository.h"

class Book {
public:
    Book(int id, const std::string& title) : id(id), title(title) {}

    int getId() const {
        return id;
    }

    const std::string& getTitle() const {
        return title;
    }

    bool operator==(const Book& other) const {
        return id == other.id;
    }

    bool operator!=(const Book& other) const {
        return id != other.id;
    }

private:
    int id;
    std::string title;
};

int main() {
    // book example
    Repository<Book, std::string> bookRepo;

    Book book1(1, "Book1");
    Book book2(2, "Book2");
    Book book3(3, "Book3");

    bookRepo.add(book1, "Borrowed on 2022-10-01");
    bookRepo.add(book2, "Borrowed on 2022-10-05");
    bookRepo.add(book3, "Borrowed on 2022-10-10");

    std::cout << "Book1 position: " << bookRepo.getOrder(book1) << std::endl;
    std::cout << "Book2 position: " << bookRepo.getOrder(book2) << std::endl;
    std::cout << "Book3 position: " << bookRepo.getOrder(book3) << std::endl;

    std::cout << "Number of books in the repository: " << bookRepo.size() << std::endl;

    bookRepo.remove(book2);

    std::cout << "Book2 position after removal: " << bookRepo.getOrder(book2) << std::endl;
    std::cout << "Number of books in the repository after removal: " << bookRepo.size() << std::endl;
    std::cout << std::endl;

    // password example
    Repository<std::string, std::string> passwordRepo;

    passwordRepo.add("password123", "Last used on 2022-10-01");
    passwordRepo.add("qwerty123", "Last used on 2022-10-05");
    passwordRepo.add("abc123", "Last used on 2022-10-10");

    std::cout << "password123 position: " << passwordRepo.getOrder("password123") << std::endl;
    std::cout << "qwerty123 position: " << passwordRepo.getOrder("qwerty123") << std::endl;
    std::cout << "abc123 position: " << passwordRepo.getOrder("abc123") << std::endl;

    std::cout << "Number of passwords in the repository: " << passwordRepo.size() << std::endl;

    passwordRepo.remove("qwerty123");

    std::cout << "qwerty123 position after removal: " << passwordRepo.getOrder("qwerty123") << std::endl;
    std::cout << "Number of passwords in the repository after removal: " << passwordRepo.size() << std::endl;
    std::cout << std::endl;

    // file example
    Repository<std::string, std::string> fileRepo;
    
    fileRepo.add("file1.txt", "Last modified on 2022-10-01");
    fileRepo.add("file2.txt", "Last modified on 2022-10-05");
    fileRepo.add("file3.txt", "Last modified on 2022-10-10");

    std::cout << "file1.txt position: " << fileRepo.getOrder("file1.txt") << std::endl;
    std::cout << "file2.txt position: " << fileRepo.getOrder("file2.txt") << std::endl;
    std::cout << "file3.txt position: " << fileRepo.getOrder("file3.txt") << std::endl;

    std::cout << "Number of files in the repository: " << fileRepo.size() << std::endl;

    fileRepo.remove("file2.txt");

    std::cout << "file2.txt position after removal: " << fileRepo.getOrder("file2.txt") << std::endl;
    std::cout << "Number of files in the repository after removal: " << fileRepo.size() << std::endl;
    std::cout << std::endl;

    // student example
    Repository<std::string, std::string> studentRepo;
    
    studentRepo.add("John", "Last modified on 2022-10-01");
    studentRepo.add("Mary", "Last modified on 2022-10-05");
    studentRepo.add("Peter", "Last modified on 2022-10-10");
    
    std::cout << "John position: " << studentRepo.getOrder("John") << std::endl;
    std::cout << "Mary position: " << studentRepo.getOrder("Mary") << std::endl;
    std::cout << "Peter position: " << studentRepo.getOrder("Peter") << std::endl;

    std::cout << "Number of students in the repository: " << studentRepo.size() << std::endl;

    studentRepo.remove("Peter");

    std::cout << "Peter position after removal: " << studentRepo.getOrder("Peter") << std::endl;
    std::cout << "Number of students in the repository after removal: " << studentRepo.size() << std::endl;
    std::cout << std::endl;

    return 0;
}

