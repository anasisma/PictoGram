#include "PhotoGram.h"

PhotoGram::PhotoGram() {
}

PhotoGram::~PhotoGram() {
    // delete all albums in album array
    for (int i = 0; i < albumArray.size(); i++) {
        delete albumArray[i];
    }
    // delete all photos in photo array
    for (int i = 0; i < photoArray.size(); i++) {
        delete photoArray[i];
    }
}

void PhotoGram::addAlbum(const string& title, const string& desc) {
    Album* newAlbum = factory.createAlbum(title, desc);
    albumArray += newAlbum;
}

void PhotoGram::addToAlbum(int i, Array<Photo*>& array) {
    for (int j = 0; j < array.size(); ++j) {
        albumArray[i]->addPhoto(array[j]);
    }
}

void PhotoGram::uploadPhoto(const string& title) {
    Photo* photo = factory.uploadPhoto(title);
    photoArray += photo;
}

void PhotoGram::deleteAlbum(int index) {
    if (index < 0 || index >= albumArray.size()) {
        cerr << "Array index out of bounds" << endl;
        return;
    }
    Album* albumPntr = albumArray[index];
    albumArray -= albumPntr;
    delete albumPntr;
}

void PhotoGram::getPhotos(const Criteria& crit, Array<Photo*>& arr) {
    for (int i = 0; i < photoArray.size(); ++i) {
        if (crit.matches(*photoArray[i])) {
            arr += photoArray[i];
        }
    }
}

int PhotoGram::printAlbums(View& v) {
    v.printAlbums(albumArray);
    return albumArray.size();
}

void PhotoGram::displayAlbum(int index, View& v) {
    if (index < 0 || index >= albumArray.size()) {
        cerr << "Array index out of bounds" << endl;
        return;
    }
    v.displayAlbum(*albumArray[index]);
}

void PhotoGram::displayPhoto(int index, View& v) {
    if (index < 0 || index >= photoArray.size()) {
        cerr << "Array index out of bounds" << endl;
        return;
    }
    v.displayPhoto(*photoArray[index]);
}

int PhotoGram::printPhotos(View& v) {
    v.printPhotos(photoArray);
    return photoArray.size();
}
