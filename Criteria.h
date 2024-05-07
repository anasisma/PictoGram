#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>

#include "Photo.h"

using namespace std;

class Criteria {
    friend ostream& operator<<(ostream&, const Criteria&);

   public:
    virtual bool matches(const Photo&) const;

    virtual void print(ostream&) const;

   private:
};

class Cat_Criteria : virtual public Criteria {
   public:
    Cat_Criteria(const string& cat);

    bool matches(const Photo&) const;

    void print(ostream&) const;

   private:
    string category;
};

class Date_Criteria : virtual public Criteria {
   public:
    Date_Criteria(const Date& start, const Date& end);

    bool matches(const Photo&) const;

    void print(ostream&) const;

   private:
    Date startDate;
    Date endDate;
};

class CandD_Criteria : public Cat_Criteria, public Date_Criteria {
   public:
    CandD_Criteria(const Date& start, const Date& end, const string& cat);

    bool matches(const Photo&) const;

    void print(ostream&) const;

   private:
    string category;
    Date startDate;
    Date endDate;
};
#endif