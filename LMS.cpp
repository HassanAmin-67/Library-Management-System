#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a book
struct Book {
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isBorrowed = false;
    }
};

// Function prototypes
void addBook(vector<Book>& library);
void deleteBook(vector<Book>& library);
void searchBook(const vector<Book>& library);
void borrowBook(vector<Book>& library);
void returnBook(vector<Book>& library);
void displayBooks(const vector<Book>& library);

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display All Books\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                deleteBook(library);
                break;
            case 3:
                searchBook(library);
                break;
            case 4:
                borrowBook(library);
                break;
            case 5:
                returnBook(library);
                break;
            case 6:
                displayBooks(library);
                break;
            case 0:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void addBook(vector<Book>& library) {
    int id;
    string title, author;
    cout << "Enter book ID: ";
    cin >> id;
    cin.ignore();  // Clear the input buffer
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);

    Book newBook(id, title, author);
    library.push_back(newBook);
    cout << "Book added successfully!\n";
}

void deleteBook(vector<Book>& library) {
    int id;
    cout << "Enter book ID to delete: ";
    cin >> id;

    bool found = false;
    for (vector<Book>::iterator it = library.begin(); it != library.end(); ++it) {
        if (it->id == id) {
            library.erase(it);
            cout << "Book deleted successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}

void searchBook(const vector<Book>& library) {
    int id;
    cout << "Enter book ID to search: ";
    cin >> id;

    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].id == id) {
            cout << "Book found:\n";
            cout << "ID: " << library[i].id << ", Title: " << library[i].title << ", Author: " << library[i].author;
            cout << ", Status: " << (library[i].isBorrowed ? "Borrowed" : "Available") << "\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

void borrowBook(vector<Book>& library) {
    int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;

    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].id == id) {
            if (!library[i].isBorrowed) {
                library[i].isBorrowed = true;
                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Book is already borrowed.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void returnBook(vector<Book>& library) {
    int id;
    cout << "Enter book ID to return: ";
    cin >> id;

    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].id == id) {
            if (library[i].isBorrowed) {
                library[i].isBorrowed = false;
                cout << "Book returned successfully!\n";
            } else {
                cout << "Book is not currently borrowed.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void displayBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "Books in the library:\n";
    for (size_t i = 0; i < library.size(); ++i) {
        cout << "ID: " << library[i].id << ", Title: " << library[i].title << ", Author: " << library[i].author;
        cout << ", Status: " << (library[i].isBorrowed ? "Borrowed" : "Available") << "\n";
    }
}
