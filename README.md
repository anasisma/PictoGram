# PictoGram
A program that facilitates the backend logic of popular photo social media applications using C++.


## List of source files:
* Album.cc:  Entity object, contains information about the album.
* Array.h:  An abstract container for data with overloaded operators.
* AlbumCreator.cc:  Control object, controls the interaction of PhotoGram with the View.
* Criteria.cc: Entity object, used to match user searches to matching Photo objects. There are an additional three derived classes arranged in a diamond hierarchy; A_Criteria, C_Criteria, and AorC_Criteria.  
* defs.h: File which contains preprocessor constants.
* main.cc: instantiates a Controller object and calls the launch() function
* Makefile: Compiles a single executeable "a4" using the command "make". It also contains a "clean" command which removes the "a4" executeable and any object files. This "clean" command is ran using the default "make clean" (in Linux).

* MediaFactory.cc: Boundary object, used to create Photos, Albums, and Criteria objects. It separates application logic from the creation of Photos, Albums or Criteria types.
* Photo.cc: Entity object, contains photo information.
* PhotoGram.cc: Container/Control object, contains a collection of Albums. Users can add/remove Albums or Photos, browse Albums and search Photos to create photoalbums based on Criteria they specify.
* View.cc: Boundary object, provides a menu, takes input, displays output.


## Directory structure:   
photos.txt and titles.txt are in the folder "media", and all c++ files, along with the makefile, are located in "src".

## Instructions for compiling code:
Compile using Makefile command "make", which makes the executeable "a4".

## Instructions for running compiled program:
Run the executeable using "./a4".
