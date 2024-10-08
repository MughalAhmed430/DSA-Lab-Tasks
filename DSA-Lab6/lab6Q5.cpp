#include <iostream>
#include <string>

using namespace std;

class Song
{
public:
    string title;  
    string artist; 
    Song *next;    
    Song *prev;   
    Song(string t, string a) : title(t), artist(a), next(nullptr), prev(nullptr) {}
};

class Playlist
{
private:
    Song *head; 
    Song *tail; 

public:
    Playlist() : head(nullptr), tail(nullptr) {}

    ~Playlist()
    {
        while (head != nullptr)
        {
            Song *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addSong(const string &title, const string &artist)
    {
        Song *newSong = new Song(title, artist);
        if (head == nullptr)
        {
            head = newSong; 
            tail = newSong; 
        }
        else
        {
            tail->next = newSong; 
            newSong->prev = tail; 
            tail = newSong;     
        }
        cout << "Added: " << title << " by " << artist << "\n";
    }
    void traverseForward() const
    {
        Song *current = head;
        cout << "Playlist (Forward):\n";
        while (current != nullptr)
        {
            cout << current->title << " by " << current->artist << "\n";
            current = current->next; 
        }
    }

    void traverseBackward() const
    {
        Song *current = tail;
        cout << "Playlist (Backward):\n";
        while (current != nullptr)
        {
            cout << current->title << " by " << current->artist << "\n";
            current = current->prev; 
        }
    }

    void deleteSong(const string &title)
    {
        Song *current = head;

        while (current != nullptr)
        {
            if (current->title == title)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next; 
                }

                if (current->next != nullptr)
                {
                    current->next->prev = current->prev; 
                }
                else
                {
                    tail = current->prev; 
                }

                delete current; 
                cout << "Deleted: " << title << "\n";
                return;
            }
            current = current->next; 
        }
        cout << "Song not found: " << title << "\n";
    }
};

int main()
{
    Playlist playlist;
    int choice;
    string title, artist;

    do
    {
        cout << "\n1. Add Song\n2. Traverse Forward\n3. Traverse Backward\n4. Delete Song\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            playlist.addSong(title, artist);
            break;

        case 2:
            playlist.traverseForward();
            break;

        case 3:
            playlist.traverseBackward();
            break;

        case 4:
            cout << "Enter song title to delete: ";
            cin.ignore();
            getline(cin, title);
            playlist.deleteSong(title);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}