#include "Photo.h"

Photo::Photo(const string& t, const string& categ, const Date& d, const string& cont) : title(t), category(categ), date(d), content(cont) {
}

Photo::Photo(const Photo &) {
}

Photo::~Photo(){

}

bool Photo::equals(const string& title) const {
    if (this->title.compare(title) == 0)
        return true;
    return false;
}

const Date& Photo::getDate() const {
    return date;
}

const string& Photo::getCategory() const {
    return category;
}

const string& Photo::getTitle() const {
    return title;
}

const string& Photo::getContent() const {
    return content;
}

void Photo::print(ostream& ost) const {
    ost << getTitle() << ", taken on ";
    getDate().print();
    ost << endl;
}

void Photo::display(ostream& ost) const {
    print(ost);
    ost << getContent() << endl;
}

ostream& operator<<(ostream& ost, const Photo& p) {
    ost << "Category: " << p.getCategory() << ", date: " << p.getDate() << ", title: " << p.getTitle() << ", content:\n" << p.getContent() << endl;
    return ost;
}
