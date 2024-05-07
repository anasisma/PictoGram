#include "Album.h"

Album::Album(const string& title, const string& description) : title(title), description(description) {
}

string Album::getTitle() const {
    return title;
}

string Album::getDesc() const {
    return description;
}

bool Album::equals(const string& t) const {
    if (title.compare(t) == 0)
        return true;
    return false;
}

void Album::addPhoto(Photo* p) {
    photoArray += p;
}

Photo* Album::getPhoto(int index) const {
    return photoArray[index];
}

void Album::print(ostream& ost) const {
    ost << "Title: " << title << ", description: " << description << ", number of photos: " << photoArray.size() << endl;
}

void Album::display(ostream& ost) const {
    print(ost);
    ost << "Photos: " << endl;
    for (int i = 0; i < photoArray.size(); i++) {
        photoArray[i]->display(ost);
    }
    ost << endl;
}

int Album::size() const {
    return photoArray.size();
}

ostream& operator<<(ostream& ost, const Album& a) {
    a.print(ost);
    return ost;
}
