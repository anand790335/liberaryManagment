#include <iostream>
#include <vector>
#include <string>
Using namespace std;

class Book {
public:
    string title;
    bool available;

    Book(const std::string& t) : title(t), available(true) {}

    void setAvailability(bool status) {
        available = status;
    }
};

class MemberRecord {
public:
    string name;
    int booksIssued;

    MemberRecord(const std::string& n) : name(n), booksIssued(0) {}

    bool isValidMember() const {
        // You can implement more sophisticated validation logic here
        return booksIssued <= 3;
    }

    void issueBook() {
        booksIssued++;
    }
};

class Librarian {
public:
    bool validateMember(const MemberRecord& member) const {
        return member.isValidMember();
    }

    void registerMember(MemberRecord& member) {
        // Perform member registration, if needed
    }

    void issueBook(Book& book, MemberRecord& member) {
        if (!book.available) {
            cout << "Sorry, the book is not available." << endl;
            return;
        }

        if (!validateMember(member)) {
            cout << "Invalid member. Please register or check your book quota." << endl;
            return;
        }

        if (member.booksIssued >= 3) {
            cout << "You have reached the maximum book quota. Cannot issue more books." << std::endl;
            return;
        }

        // Issue the book
        book.setAvailability(false);
        member.issueBook();
   cout << "Book issued successfully." << endl;
    }
};

class Student {
public:
    void inquireAboutBook(const Librarian& librarian, Book& book, MemberRecord& member) {
        librarian.issueBook(book, member);
    }
};

int main() {
    Book book("Sample Book");
    MemberRecord member("John Doe");
    Librarian librarian;
    Student student;

    // Inquire about the book
    student.inquireAboutBook(librarian, book, member);

    return 0;
}
