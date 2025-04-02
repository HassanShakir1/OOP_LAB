#include <iostream>
#include <vector>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string id, string pub)
        : title(t), publicationDate(pDate), uniqueID(id), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << "\n";
    }
    virtual void checkOut() { cout << title << " checked out.\n"; }
    virtual void returnItem() { cout << title << " returned.\n"; }
    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

class DVD : public Media {
    string director;
    float duration;
    float rating;
public:
    DVD(string t, string pDate, string id, string pub, string dir, float dur, float rate)
        : Media(t, pDate, id, pub), director(dir), duration(dur), rating(rate) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << "\n";
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << "\n";
    }
};

// Function Overloading for Searching Media
void searchMedia(vector<Media *> &library, string title) {
    cout << "Searching by Title: " << title << "\n";
    for (auto media : library) {
        if (media->getTitle() == title) {
            media->displayInfo();
        }
    }
}

void searchMedia(vector<Media *> &library, string author, bool isBook) {
    if (!isBook) return;
    cout << "Searching by Author: " << author << "\n";
    for (auto media : library) {
        Book *book = dynamic_cast<Book *>(media);
        if (book && book->getTitle() == author) {
            book->displayInfo();
        }
    }
}

void searchMedia(vector<Media *> &library, int year) {
    cout << "Searching by Year: " << year << "\n";
    for (auto media : library) {
        if (media->getPublicationDate() == to_string(year)) {
            media->displayInfo();
        }
    }
}

int main() {
    vector<Media *> library;
    library.push_back(new Book("C++ Guide", "2022", "B001", "O'Reilly", "John Doe", "123-456-789", 500));
    library.push_back(new DVD("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8));
    library.push_back(new CD("Thriller", "1982", "C001", "Sony Music", "Michael Jackson", 9, "Pop"));

    cout << "\nLibrary Collection:\n";
    for (auto media : library) {
        media->displayInfo();
        cout << "-------------------\n";
    }

    searchMedia(library, "C++ Guide");
    searchMedia(library, "John Doe", true);
    searchMedia(library, 2010);

    for (auto media : library) delete media;
    return 0;
}
