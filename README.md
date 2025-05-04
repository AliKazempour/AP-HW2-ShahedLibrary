# 📚 Shahid Unified Library System

Welcome to the **Shahid University Library System**, a unified platform designed to help students instantly find and borrow books from *any* department library across campus — all from a single place.

---

**Made by:** Ali Kazempour  
**University:** Shahed University  
**Term:** Spring 2022  
**contact me on Telegram:** [https://t.me/A_Kazempour83](https://t.me/A_Kazempour83)

---

## 💡 Story Behind the Project

Meet **Vahid**.  
He's passionate about coding but… his code is a complete mess. 😅  
His professor recommends reading *Clean Code* by Robert C. Martin.

But there's a problem.

Vahid doesn’t have enough money to buy the book. So he heads to the university library — only to find out it's not available there.

Should he now visit every faculty on foot in search of a book?

No. Instead, he builds this system:  
A centralized library network where students can:
- 🔍 **Search any book** by name or genre across all libraries
- 📚 **Borrow and return** from any library — not just one
- 🗺️ **Locate the nearest library** that has the book
- 📄 **View complete book info** and availability in real time
- ✅ Enjoy a single, unified **member registration**

This project is not just for Vahid — it’s for every student tired of running in circles for knowledge.

---

## 🧱 Core Components

- `Publisher`: Holds publisher info and auto-generated ID.
- `Book`: Contains title, type (e.g., SCIENTIFIC, HORROR), publisher, and availability.
- `Member`: Represents students, allowing a max of 5 borrowed books.
- `Library`: Holds a collection of books and supports search and filtering.
- `LibrariesHandler`: Manages all libraries and members. Handles borrowing, returning, filtering, and location-based search.

All internal IDs are auto-incremented. Proper error handling and validations are enforced (e.g., duplicate names, over-borrowing, etc.).

---

## 🚀 Quick Test Example

```cpp
#include <iostream>
using namespace std;

int main()
{
    LibrariesHandler handler;

    // Create publishers
    Publisher pub1("O'Reilly Media", "USA");
    Publisher pub2("Penguin Books", "UK");

    // Create libraries
    handler.createLibrary("Central Library", 10);
    handler.createLibrary("West Wing Library", 30);

    // Add books to libraries
    handler.addBook(1, "Clean Code", pub1, SCIENTIFIC);
    handler.addBook(1, "The Hobbit", pub2, FANTASY);
    handler.addBook(2, "Dracula", pub2, HORROR);
    handler.addBook(2, "Crime and Punishment", pub2, CRIME);

    // Register members
    handler.addMember("Alice", "M001");
    handler.addMember("Bob", "M002");

    // Show all books in Central Library
    cout << "Books in Central Library:\n";
    cout << handler.getAllBooksInfo(1) << endl;

    // Filter by book type
    cout << "Fantasy books in Central Library:\n";
    cout << handler.filterByTypeAndShowInfo(1, FANTASY) << endl;

    // Borrow book
    cout << "Borrowing 'Clean Code' by Alice:\n";
    if (handler.borrow("M001", 1, "Clean Code"))
        cout << "Borrowed successfully!\n";
    else
        cout << "Failed to borrow.\n";

    // Try to borrow the same book again (should fail)
    cout << "Trying to borrow 'Clean Code' again by Bob:\n";
    if (handler.borrow("M002", 1, "Clean Code"))
        cout << "Borrowed successfully!\n";
    else
        cout << "Failed to borrow.\n";

    // Return book
    cout << "Returning 'Clean Code' by Alice:\n";
    if (handler.returnBook("M001", 1, "Clean Code"))
        cout << "Returned successfully!\n";
    else
        cout << "Failed to return.\n";

    // Find nearest library that has "Dracula"
    Library nearest = handler.findNearestLibraryByPosition("Dracula", 15);
    cout << "Nearest library with 'Dracula': " << nearest.getName() << endl;

    return 0;
}

```

---

## 🎯 Goal of the Project

To build a **clean**, **modular**, and **realistic** C++ application that simulates the coordination of multiple university libraries — and to help students (like Vahid) get their hands on good books, fast.


