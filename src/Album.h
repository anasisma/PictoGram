#ifndef ALBUM_H
#define ALBUM_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Array.h"
#include "Photo.h"

using namespace std;

class Album {
    friend ostream &operator<<(ostream &, const Album &);
   public:
    // constructors
    Album(const string&, const string&);

    // getters
    string getTitle() const;
    string getDesc() const;

    // others
    Photo* getPhoto(int) const;

    bool equals(const string&) const;
    void addPhoto(Photo*);
    void print(ostream&) const;
    void display(ostream&) const;
    int size() const;

   private:
    // variables
    string title;
    string description;
    Array<Photo*> photoArray;
};
#endif