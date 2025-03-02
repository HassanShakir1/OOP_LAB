#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Catalog {
    vector<string> ISBN;      
    vector<string> locations; 
    
public:
    void addISBN(string s, string l) {
        ISBN.push_back(s);         
        locations.push_back(l);    
        cout << "\nISBN Added: " << s << " at location " << l;
    }

    string getLocation(string isbn) {
        for (size_t i = 0; i < ISBN.size(); ++i) {
            if (isbn == ISBN[i]) {
                return locations[i];
            }
        }
        return "ISBN not found"; 
    }
};

class Book {
    string title;
    string author;
    string isbn;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getISBN() const {
        return isbn;
    }
};

class Library {
    Catalog catalog; 
    vector<Book> books; 

public:
    void addBook(const Book& book, string location) {
        catalog.addISBN(book.getISBN(), location); 
        books.push_back(book); 
    }

    void searchBookByISBN(string isbn) {
        string location = catalog.getLocation(isbn);
        if (location != "ISBN not found") {
            cout << "Book found at location: " << location << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found in the catalog." << endl;
        }
    }

    void printLibraryBooks() {
        for (const auto& book : books) {
            cout << "Book: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << endl;
        }
    }
};

int main() {
    Library myLibrary;

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    Book book2("1984", "George Orwell", "9780451524935");
    Book book3("To Kill a Mockingbird", "Harper Lee", "9780061120084");

    myLibrary.addBook(book1, "A1");
    myLibrary.addBook(book2, "B1");
    myLibrary.addBook(book3, "C1");

    cout << "\nBooks in the library:\n";
    myLibrary.printLibraryBooks();

    cout << "\nSearching for book with ISBN 9780451524935...\n";
    myLibrary.searchBookByISBN("9780451524935");

    cout << "\nSearching for book with ISBN 0000000000000...\n";
    myLibrary.searchBookByISBN("0000000000000");

    return 0;
}