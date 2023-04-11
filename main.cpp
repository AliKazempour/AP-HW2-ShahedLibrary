#include <iostream>
#include <vector>
#include <string>

using namespace std;
double abs(double n)
{
    if (n > 0)
    {
        return n;
    }
    return -n;
}
int number_publish = 1;
int number_library = 1;
enum BookType
{
    SCIENTIFIC,
    CRIME,
    FANTASY,
    HORROR,
    CLASSICS
};
class Publisher
{
private:
    int id;
    string name;
    string Location;

public:
    Publisher() {}
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
        this->Location = Location;
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
        id = number_publish;
        number_publish++;
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
    Book(string name, Publisher publisher, BookType type)
    {
        this->name = name;
        this->publisher = publisher;
        this->type = type;
        borrowed = 0;
    }
    Book() {}
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
    void setBorrowed(bool Borrowed)
    {
        this->borrowed = Borrowed;
    }
    bool getBorrowed()
    {
        return borrowed;
    }
};
class Member
{
private:
    string id;
    string name;
    vector<Book> books;

public:
    void setId(string id)
    {
        this->id = id;
    }
    string getId()
    {
        return id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void addedBook(Book book)
    {
        books.push_back(book);
    }
    vector<Book> getBook()
    {
        return books;
    }
    void removeBook(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {

            if (books[i].getName() == name)
            {
                books.erase(books.begin() + i);
            }
        }
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

public:
    Library(string name, int position)
    {
        this->name = name;
        this->position = position;
        id = number_library;
        number_library++;
    }
    void setborrowed(string name, bool value)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getName() == name)
            {
                books[i].setBorrowed(value);
            }
        }
    }
    string getName()
    {
        return name;
    }
    Book Search(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getName() == name)
            {
                return books[i];
            }
        }
        return {};
    }
    vector<Book> bookList()
    {
        return books;
    }
    void addBook(Book book)
    {
        books.push_back(book);
    }
    vector<Book> filterByType(BookType type)
    {
        vector<Book> v;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getType() == type)
            {
                v.push_back(books[i]);
            }
        }
        return v;
    }

    int Position()
    {
        return position;
    }
    int getId()
    {
        return id;
    }
};
class LibrariesHandler
{
private:
    vector<Library> ShahedLibrary;
    vector<Member> ShahedMembers;

public:
    void createLibrary(string name, int position)
    {
        bool interference = 0;
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getName() == name)
            {
                cout << "A library with this name already exists";
                interference = 1;
                break;
            }
            if (ShahedLibrary[i].Position() == position)
            {
                cout << "There is now a library in this place";
                interference = 1;
                break;
            }
        }
        if (interference == false)
        {
            Library newlibrary(name, position);
            ShahedLibrary.push_back(newlibrary);
        }
    }
    void addBook(int libId, string name, Publisher publisher, BookType type)
    {
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId() == libId)
            {
                ShahedLibrary[i].addBook({name, publisher, type});
                return;
            }
        }
        cout << "No";
    }
    void addBook(int libId, Book book)
    {
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId() == libId)
            {
                ShahedLibrary[i].addBook(book);
                return;
            }
        }
        cout << "No";
    }
    void addMember(string name, string id)
    {
        for (int i = 0; i < ShahedMembers.size(); i++)
        {
            if (name == ShahedMembers[i].getName())
            {
                cout << "This is duplicate member!!\n";
                return;
            }
        }
        Member nMember(id, name);
        ShahedMembers.push_back(nMember);
    }
    vector<Book> getAllBooks(int libId)
    {
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId() == libId)
            {
                return ShahedLibrary[i].bookList();
            }
        }
    }

    string getAllBooksInfo(int libId)
    {
        string s = "";
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId() == libId)
            {
                for (int j = 0; j < ShahedLibrary[i].bookList().size(); j++)
                {
                    s += to_string(j + 1) + ". " + ShahedLibrary[i].bookList()[j].getName() + "\n";
                }
            }
        }
        return s;
    }
    vector<Book> filterByType(int libId, BookType type)
    {
        vector<Book> mybooks;
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId() == libId)
            {
                for (int j = 0; j < ShahedLibrary[i].bookList().size(); j++)
                {
                    if (ShahedLibrary[i].bookList()[j].getType() == type)
                    {
                        mybooks.push_back(ShahedLibrary[i].bookList()[j]);
                    }
                }
            }
        }
        return mybooks;
    }
    string filterByTypeAndShowInfo(int libId, BookType type)
    {
        vector<Book> x = filterByType(libId, type);
        string a = "";
        for (int i = 0; i < x.size(); i++)
        {
            a += to_string(i + 1) + ". " + x[i].getName() + "\n";
        }
        return a;
    }
    bool borrow(string memberId, int libraryId, string name)
    {
        bool b = 0;
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId() == libraryId)
            {
                b = 1;
                for (int j = 0; j < ShahedLibrary[i].bookList().size(); j++)
                {
                    if (ShahedLibrary[i].bookList()[j].getName() == name && !ShahedLibrary[i].bookList()[j].getBorrowed())
                    {
                        for (int k = 0; i < ShahedMembers.size(); k++)
                        {
                            if (ShahedMembers[k].getId() == memberId)
                            {
                                if (ShahedMembers[k].getBook().size() < 5)
                                {
                                    ShahedLibrary[i].setborrowed(name, true);
                                    ShahedMembers[k].addedBook(ShahedLibrary[i].Search(name));
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    bool returnBook(string memberId, int libraryId, string name)
    {
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            if (ShahedLibrary[i].getId() == libraryId)
            {
                for (int j = 0; j < ShahedMembers.size(); j++)
                {
                    if (ShahedMembers[j].getId() == memberId)
                    {
                        for (int k = 0; k < ShahedLibrary[i].bookList().size(); k++)
                        {
                            if (ShahedLibrary[i].bookList()[k].getName() == name)
                            {
                                ShahedLibrary[i].setborrowed(name, 0);
                                ShahedMembers[j].removeBook(name);
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

public:
    int size()
    {
        int sum = 0;
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            sum += ShahedLibrary[i].bookList().size();
        }
        return sum;
    }
    Library findNearestLibraryByPosition(string name, int position)
    {
        vector<Library> v;
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            for (int j = 0; j < ShahedLibrary[i].bookList().size(); j++)
            {
                if (ShahedLibrary[i].bookList()[j].getName() == name)
                {
                    v.push_back(ShahedLibrary[i]);
                    break;
                }
            }
        }
        int index = 0;
        int curPos = abs(position - v[0].Position());
        string curName = v[0].getName();
        for (int i = 1; i < v.size(); i++)
        {
            if (abs(position - v[i].Position()) < curPos || (abs(position - v[i].Position()) == curPos && curName > v[i].getName()))
            {
                curPos = abs(position - v[i].Position());
                curName = v[i].getName();
                index = i;
            }
        }
        return v[index];
    }
    string findLibrariesHaveBook(string name, int position)
    {
        vector<Library> x;
        for (int i = 0; i < ShahedLibrary.size(); i++)
        {
            for (int j = 0; j < ShahedLibrary[i].bookList().size(); j++)
            {
                if (ShahedLibrary[i].bookList()[j].getName() == name)
                {
                    x.push_back(ShahedLibrary[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < x.size(); i++)
        {
            for (int j = 0; j < x.size() - i; j++)
            {
                if (abs(x[j].Position() - position) > abs(x[j + 1].Position() - position))
                {
                    swap(x[i], x[j + 1]);
                }
            }
        }
        string s;
        for (int i = 0; i < x.size(); i++)
        {
            s += to_string(i + 1) + ". " + ShahedLibrary[i].getName() + " " + to_string(abs(ShahedLibrary[i].Position() - position)) + "\n";
        }
        return s;
    }
};
int main()
{
}