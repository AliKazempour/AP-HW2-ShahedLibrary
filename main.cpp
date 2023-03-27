#include <iostream>

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
        this->name = name this->Location = location
    }
};

int main()
{
    
}