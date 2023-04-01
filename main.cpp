#include <iostream>
#include <vector>
#include <string>

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
    vector<book> bookList()
    {
        return books;
    }
    void addBook(Book book)
    {
        books.push_back(book);
    }
    int position()
    {
        return position;
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
    void addBook(int libId, string name, Publisher publisher, BookType type)
    {
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getid() == libId)
            {
                Book NewBook(string name, Publisher publisher, BookType type);
                ShahedLibrary[i].addBook(NewBook);
                return;
            }
        }
        cout << "No Library exist!!!"
    }
    void addBook(int libId, Book book)
    {
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getid() == libId)
            {
                ShahedLibrary[i].addBook(book);
                return;
            }
        }
        cout << "No Library exist!!!"
    }
    vector<Book> getAllBooks(int libId)
    {
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId == libId)
            {
                return ShahedLibrary[i].bookList();
            }
        }
    }

    string getAllBooksInfo(int libId)
    {
        string s;
        for (int i = ; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getid() == libId)
            {
                for (int j = 0; j < ShahedLibrary.bookList.size(); j++)
                {
                    s += to_string(j + 1);
                    s += ". ";
                    s +=
                        ShahedLibrary.bookList[j].name;
                    s += '\n';
                }
            }
        }
        return s;
    }
    vector<Book> filterByType(int libId, BookType type)
    {
        vector<Book>mybooks;
        for(int i=0;i<ShahedLibrary.size();i++)
        {
            if(ShahedLibrary.getid==libId)
            {
                for(int j=0;j<ShahedLibrary[i].bookList.size();j++)
                {
                    if(ShahedLibrary[i].bookList[j].getType()==type)
                    {
                        mybooks.push_back(ShahedLibrary[i].bookList[j]);
                    }
                }
            }
        }
        return mybooks;
    }
};
int main()
{
}