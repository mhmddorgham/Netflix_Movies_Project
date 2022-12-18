#ifndef NETFLIXLISTPROJECT_MOVIE_H
#define NETFLIXLISTPROJECT_MOVIE_H
#include <iostream>
using namespace std;

class Movie
{
public:
    Movie();
    ~Movie();

    string name , genre;
    int duration;
    long id;
    double rating;
    short releaseDate;

    Movie(string name, string genre, double rating, short releaseDate, long id, int duration){
        this->name = name;
        this->genre = genre;
        this->rating = rating;
        this->releaseDate = releaseDate;
        this->id = id;
        this->duration = duration;
    }
};


#endif //NETFLIXLISTPROJECT_MOVIE_H
