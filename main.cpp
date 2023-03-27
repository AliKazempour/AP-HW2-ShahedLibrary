#include <iostream>
#include <vector>

using namespace std;
enum BookType = {SCIENTIFIC, CRIME, FANTASY, HORROR, CLASSICS};

class Publisher
{
private:
    int id;
    string name;
    string Location;

public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setLocate(string Location)
    {
        this->Location = location;
    }
    string getLocate()
    {
        return Location;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }

    Publisher(string name, string location)
    {
        this->name = name;
        this->Location = location;
    }
};

class Book
{
private:
    int id;
    string name;
    BookType type;
    Publisher publisher;
    bool borrowed;

public:
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void showInfo()
    {
        cout << id << ". " << name << endl;
    }
    BookType getType()
    {
        return type;
    }
    Book(string name, Publisher publisher, BookType type)
    {
        this->name = name;
        this->publisher = publisher;
        this->type = type;
    }
};
class Member
{
private:
    string id;
    string name;
    vector<Book> books;

public:
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    Member(string id, string name)
    {
        this->id = id;
        this->name = name;
    }
};
class Library
{
private:
    int id;
    string name;
    vector<Book> books;
    int position;

    Library(string name, int position)
    {
        this->name = name;
        this->position = position;
    }
    Book Search(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].name == name)
            {
                return books[i];
            }
        }
    }
    void bookList()
    {
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i];
        }
    }
    void addBook(Book book)
    {
        books.push_back(book);
    }
    void booksType()
    {
        cout << "SCIENTIFIC"
             << "\n";
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getType == SCIENTIFIC)
            {
                cout << books[i] << "\n";
            }
        }
        cout << "CRIME"
             << "\n";
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getType == SCIENTIFIC)
            {
                cout << books[i] << "\n";
            }
        }
        cout << "FANTASY"
             << "\n";
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getType == SCIENTIFIC)
            {
                cout << books[i] << "\n";
            }
        }
        cout << "HORROR"
             << "\n";
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getType == SCIENTIFIC)
            {
                cout << books[i] << "\n";
            }
        }
        cout << "CLASSICS"
             << "\n";
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getType == SCIENTIFIC)
            {
                cout << books[i] << "\n";
            }
        }
    }
};
class LibrariesHandler
{
    vector<Library> ShahedLibrary;
    void createLibrary(string name, int position)
    {
        bool interference = 0;
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getname == name)
            {
                cout << "A library with this name already exists";
                interference = 1;
                break;
            }
            if (ShahedLibrary[i].getPosition == position)
            {
                cout << "There is now a library in this place";
                interference = 1;
                break;
            }
        }
        if (interference = false)
        {
            Library newlibrary(name, position);
            ShahedLibrary.push_back(newlibrary);
        }
    }
};
int main()
{
    
}