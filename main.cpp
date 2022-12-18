#include <iostream>
#include <fstream>
using namespace std;
#include "Movie.h"

// linked list node:
struct Node {
    Movie movie;
    Node* next;
};

//create two global nodes
// Set header to point to null
Node *head = nullptr;

//Set tail pointer to point to null
Node *tail = nullptr;

// A method that returns true if the list is empty or false if it is not empty
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
};

//A method that counts the number of nodes in the list,
// then return the size of the list
int getListSize()
{
    Node *tempNode = head;
    int size = 0;
    while (tempNode != NULL)
    {
        tempNode = tempNode->next;
        size++;
    }
    return size;
}

//A method that creates a new node, asks the user to enter the specification of the movie,
//and adds the node at the end of the list
void addToList()
{
    Node *newNode = new Node();
    // get user input for the movie
    string name, genre;
    int duration;
    long id;
    double rating;
    short releaseDate;
    cout << "Enter the name of the movie: ";
    getline(cin>>ws, name);
    cout << "Enter the genre of the movie: ";
    getline(cin>> ws, genre);
    cout << "Enter the rating of the movie: ";
    cin >> rating;
    cout << "Enter the release year of the movie: ";
    cin >> releaseDate;
    cout << "Enter the id of the movie (numbers): ";
    cin >> id;
    cout << "Enter the duration of the movie (in minutes): ";
    cin >> duration;

    // assign user input to the new node
    newNode->next = NULL;
    newNode->movie = Movie(name, genre, rating, releaseDate, id, duration);
    // if the list is empty:
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
        // if the list is not empty:
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
};
// A method that Adds a new node in specific location using index:
void addToIndex()
{
    // get list size to handle exceptions
    int listSize = getListSize();
    // get user input for the movie
    short index;
    cout << "Enter the index of the movie: ";
    cin >> index;
    if (index < listSize)
    {
        Node *newNode = new Node();
        // get user input for the movie
        string name, genre;
        int duration;
        long id;
        double rating;
        short releaseDate;
        cout << "Enter the name of the movie: ";
        getline(cin>> ws, name);
        cout << "Enter the genre of the movie: ";
        getline(cin>> ws, genre);
        cout << "Enter the rating of the movie: ";
        cin >> rating;
        cout << "Enter the release year of the movie: ";
        cin >> releaseDate;
        cout << "Enter the id of the movie (numbers): ";
        cin >> id;
        cout << "Enter the duration of the movie (in minutes): ";
        cin >> duration;

        // assign user input to the new node
        newNode->next = NULL;
        newNode->movie = Movie(name, genre, rating, releaseDate, id, duration);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *tempNode = head;
            for (int i = 0; i < index - 1; i++)
            {
                tempNode = tempNode->next;
            }
            newNode->next = tempNode->next;
            tempNode->next = newNode;
        }
    }
    else
    {
        cout << "Error index : " << index << " is out of bounds."
             << " (the size of the list is " << listSize << ")" << endl;
    }
}
//A method that asks a user to enter the id of a movie ,
// and prints all information about this movie
void findMovieById()
{
    long id;
    cout << "Enter the id of the movie you want to find: ";
    cin >> id;
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        if (tempNode->movie.id == id)
        {
            cout << "Movie found!" << endl;
            cout << "Name: " << tempNode->movie.name << endl;
            cout << "Genre: " << tempNode->movie.genre << endl;
            cout << "Rating: " << tempNode->movie.rating << endl;
            cout << "Release Date: " << tempNode->movie.releaseDate << endl;
            cout << "Id: " << tempNode->movie.id << endl;
            cout << "Duration: " << tempNode->movie.duration << endl;
            return;
        }
        tempNode = tempNode->next;
    }
    cout << "Movie not found!" << endl;
}

void deleteMovieById()
{
    {
        long id;
        cout << "Enter the id of the movie you want to delete: ";
        cin >> id;
        Node *tempNode = head;
        Node *prevNode = NULL;
        while (tempNode != NULL)
        {
            if (tempNode->movie.id == id)
            {
                if (prevNode == NULL)
                {
                    head = tempNode->next;
                }
                else
                {
                    prevNode->next = tempNode->next;
                }
                delete tempNode;
                cout << "Movie with id " << id << " deleted!" << endl;
                return;
            }
            else
            {
                prevNode = tempNode;
                tempNode = tempNode->next;
            }
        }
        cout << "Movie with id " << id << " is not found " << endl;
    }
}
// deleteAllMovies method, a method that creates a temp nodem and loop through each node in the list, and delete it,
// and set the temp node to point to the temp node -> next
void deleteAllMovies()
{
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        delete tempNode;
        tempNode = tempNode->next;
    }
    head = NULL; // to say that the list is empty
}

// a method that sorts the movie by according to the name ascending and descending:
// a method that creates a temp node and set it to head pointer and next Node, and set it to null
// then asks the user if he/ she wants to sort the movies list in ascending order or descending order
// using if statement, then compare the name of the temp node movie with the name of the next node movie, and then
// use the swap concept to swap the both to make the list sorted (either ascending or descending order )
void sortListByName()
{
    Node *tempNode = head; // i
    Node *nextNode = NULL; // j
    Movie tempMovie;
    short order;
    cout << "Chose the order of the list: (1) for ascending order - (2) for descending order." << endl;
    cin >> order;
    if (order != 1 && order != 2)
    {
        cout << "Invalid order" << endl;
        return;
    }

    while (tempNode != NULL)
    {
        nextNode = tempNode->next;
        while (nextNode != NULL)
        {
            if (order == 1)
            {
                if (tempNode->movie.name > nextNode->movie.name)
                {
                    tempMovie = tempNode->movie;
                    tempNode->movie = nextNode->movie;
                    nextNode->movie = tempMovie;
                }
            }
            else if (order == 2)
            {
                if (tempNode->movie.name < nextNode->movie.name)
                {
                    tempMovie = tempNode->movie;
                    tempNode->movie = nextNode->movie;
                    nextNode->movie = tempMovie;
                }
            }
            nextNode = nextNode->next;
        }
        tempNode = tempNode->next;
    }
}
// A method that prints the info of each movie in the list:
// A method that creates a temp Node , and sets it to head pointer. With using while loop,
// will loop through the list the print all movie's specification , then set the temp node to point
// to the temp node->Next
void printLinkedList()
{
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        cout << "* Movie name: " << tempNode->movie.name << endl;
        cout << "* Movie genre: " << tempNode->movie.genre << endl;
        cout << "* Movie rating: " << tempNode->movie.rating << endl;
        cout << "* Movie release year: " << tempNode->movie.releaseDate << endl;
        cout << "* Movie id: " << tempNode->movie.id << endl;
        cout << "* Movie duration: " << tempNode->movie.duration << " minutes" << endl;
        cout << "***********************************************" << endl;
        tempNode = tempNode->next;
    }
};

// save list to file  (txt mode)
// a method that saves the list of the netflix's movie in a file called "movies.txt" using OFstream, and while loop
// to loop through each node, and get the movie information, and save them in the movies.txt file, and once the loop stop,
// the file will be closed and print a message that the list has been saved to a file
void saveListToFile()
{
    ofstream file("movies.txt");
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        file << tempNode->movie.name << endl;
        file << tempNode->movie.genre << endl;
        file << tempNode->movie.rating << endl;
        file << tempNode->movie.releaseDate << endl;
        file << tempNode->movie.id << endl;
        file << tempNode->movie.duration << endl;
        tempNode = tempNode->next;
    }
    file.close();
    cout << "List saved to file!" << endl;
}

void loadListFromFile(){
    deleteAllMovies();
    string line;
    ifstream file("movies.txt");

    string name, genre;
    int duration;
    long id;
    double rating;
    short releaseDate;
    int count = 0;

    while (getline(file, line)) {

        if(count == 0){
            name = line;
            count += 1;
        }
        else if(count == 1){
            genre = line;
            count += 1;
        }
        else if(count == 2){
            rating = stod(line);
            count += 1;
        }
        else if(count == 3){
            releaseDate = stoi(line);
            count += 1;
        }
        else if(count == 4){
            id = stoi(line);
            count += 1;
        }
        else{
            duration = stoi(line);
            Node *newNode = new Node();
            newNode->next = NULL;
            newNode->movie = Movie(name, genre, rating, releaseDate, id, duration);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            count = 0;
        }
    }

    cout << "List loaded from file!" << endl;
    file.close();

};

int main()
{
    short choice;
    cout << "****************** WELCOME TO NETFLIX FILM LIST ******************" << endl;
    do
    {
        cout << endl;
        cout << "****************** CHOSE FROM THESE OPTIONS ******************" << endl;
        cout << "Enter (1) to add a movie to the list" << endl;
        cout << "Enter (2) to add a movie to a specific index the list" << endl;
        cout << "Enter (3) to find a specific movie by its id" << endl;
        cout << "Enter (4) to delete a specific movie by its id" << endl;
        cout << "Enter (5) to delete all movies" << endl;
        cout << "Enter (6) to sort the movies list by their name" << endl;
        cout << "Enter (7) to save the movie list into a .txt file" << endl;
        cout << "Enter (8) to load a linked list from a .txt file" << endl;
        cout << "Enter (9) to check if the movie list is empty" << endl;
        cout << "Enter (10) display all movies in the list" << endl;
        cout << "Enter (11) to exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                cout << "Please enter the number of movies you want to add to the list: ";
                short numberOfMovies;
                cin >> numberOfMovies;
                cin.ignore();

                for (int i = 0; i < numberOfMovies; i++)
                {
                    addToList();
                    cout << endl;
                    cout << "****************** MOVIE HAS BEEN ADDED TO THE LIST ******************" << endl;
                    cout << endl;
                }
                break;

            case 2:
                cout << endl;
                addToIndex();
                break;

            case 3:
                cout << endl;
                findMovieById();
                break;
            case 4:
                cout << endl;
                deleteMovieById();
                break;
            case 5:
                cout << endl;
                deleteAllMovies();
                break;
            case 6:
                cout << endl;
                sortListByName();
                break;
            case 7:
                cout << endl;
                saveListToFile();
                break;
            case 8:
                cout << endl;
                loadListFromFile();
                break;

            case 9:
                cout << endl;
                if (isEmpty())
                    cout << "The list is  empty" << endl;
                else
                    cout << "The list is not empty" << endl;
                break;
            case 10:
                cout << endl;
                cout << "****************** FILM LIST ******************" << endl;
                printLinkedList();
                break;

            default:
                break;
        }

        if (choice > 11 || choice < 1)
        {
            cout << "ENTER A NUMBER BETWEEN 1 AND 9" << endl;
        }

        // to prevent infinite loop when "cin" fail
        if (cin.fail())
        {
            break;
        }
    } while (choice != 11);
    cout << endl;
    cout << "****************** YOU EXITED NETFLIX FILM LIST ******************" << endl;

    return 0;
}
