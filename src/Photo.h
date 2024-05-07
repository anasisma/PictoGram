#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>

#include "Date.h"

class Photo {
    friend ostream &operator<<(ostream &, const Photo &);

   public:
    // constructors
    Photo(const string &, const string &, const Date &, const string &);
    Photo(const Photo &);

    // destructor
    ~Photo();

    bool equals(const string &) const;

    const Date &getDate() const;
    const string &getCategory() const;
    const string &getTitle() const;
    const string &getContent() const;

    void print(ostream &) const;
    void display(ostream &) const;

   private:
    string category;
    Date date;
    string title;
    string content;
};
#endif
