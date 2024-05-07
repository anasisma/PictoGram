#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Album.h"
#include "Array.h"
#include "MediaFactory.h"
#include "Photo.h"
#include "View.h"

using namespace std;

class PhotoGram {
   public:
    // constructor
    PhotoGram();

    // destructor
    ~PhotoGram();

    // others
    void addAlbum(const string&, const string&);
    void addToAlbum(int, Array<Photo*>&);

    void uploadPhoto(const string&);

    void deleteAlbum(int);

    void getPhotos(const Criteria&, Array<Photo*>&);

    int printAlbums(View&);
    void displayAlbum(int, View&);
    void displayPhoto(int, View&);
    int printPhotos(View&);

   private:
    // variables
    Array<Album*> albumArray;
    Array<Photo*> photoArray;
    MediaFactory factory;
};
#endif