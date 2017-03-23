/************************************************************
 
 CIS 22B
 Lab2: [This program reads a file containing movie data (Tile, Director, Genre, Year Released, Running Time) into a vector of structures. This program will also reads the content of the file, sort the data and prints it on the screen]

 *************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Movie {
    string title;
    string director;
    string genre;
    string year;
    string duration;
};

//function prototype
void display (vector<Movie>);
bool compareByTitle(Movie const& m1, Movie const& m2);
bool compareByDirector(Movie const& m1, Movie const& m2);
bool compareByYear(Movie const& m1, Movie const& m2);
bool compareByGenre(Movie const& m1, Movie const& m2);
bool compareByDuration(Movie const& m1, Movie const& m2);

int main()
{
    //Declare variable
    ifstream inputFile;
    string line;
    int choice;
    
    Movie m;
    vector <Movie> movies;
    
    inputFile.open("Movie_entries.txt");
    while (getline(inputFile, line))   // reads a line from the file
    {
        //cout << line << endl; // prints the line on the screen
        stringstream lineStream(line);   // transforms the line into a string stream
        
        // get fields from the string stream to the struct fields; data is separated by comma
        getline(lineStream, m.title, ',');
        getline(lineStream, m.director, ',');
        getline(lineStream, m.genre, ',');
        getline(lineStream, m.year, ',');
        getline(lineStream, m.duration, ',');
        
        movies.push_back(m);
        
    }
    inputFile.close();
    
    
    do {
    //prompt the user input for the type of sorting
    cout << "You can sort the movies by title, director, year released, or duration." << endl;
    cout << "Please enter the corresponding number:" << endl;
    cout << "1 : to sort by title" << endl;
    cout << "2 : to sort by director" << endl;
    cout << "3 : to sort by year released" << endl;
    cout << "4 : to sort by genre" << endl;
    cout << "5 : to sort by the duration time" << endl;
    cout << "0 : to exit the program" << endl;
    cin >> choice;

    //sorting depending on users choice
    if (choice == 1)
    {
        sort(movies.begin(), movies.end(), compareByTitle);
    }
    else if (choice == 2)
    {
        sort(movies.begin(), movies.end(), compareByDirector);
    }
    else if (choice == 3)
    {
        sort(movies.begin(), movies.end(), compareByYear);
    }
    else if (choice == 4)
    {
        sort(movies.begin(), movies.end(), compareByGenre);
    }
    else if (choice == 5)
    {
        sort(movies.begin(), movies.end(), compareByDuration);
    }
    else if (choice == 0) // exit the program
    {
        cout << "Goodbye!" << endl;
        exit(1);
    }
        
    //Printing movie info once the sorting is done
    display(movies);
        
    }
    while (choice <= 5); //this will repeat until user chooses to exit
    
    return 0;

}//main
//////////////////////


void display(vector<Movie> movies)
{
    /* Pre: movies - the movie lists
       Post: nothing 
       Purpose: print out the header and the sorted data
     */
    
    //header
    cout << left<< setw(35) << "\nTitle" << left << setw(25)<< "Director" << left << setw(25)<< "Genre" << left << setw(25)<< "Year Released" << left << setw(25) << "Duration"<< endl;
    
    //loop through the movie list and display the data
    for (int i = 0; i < movies.size(); ++i)
    {
    cout << left<< setw(35) << movies[i].title<< left << setw(25)<< movies[i].director<< left << setw(25)<< movies[i].genre<< left << setw(25)<< movies[i].year << left << setw(25) << movies[i].duration<< endl;
    }

}//display
///////////////////////

//Comparing Functions
bool compareByTitle(Movie const& m1,Movie const& m2)
    {return m1.title < m2.title;}
    
bool compareByDirector(Movie const& m1, Movie const& m2)
    {return m1.director < m2.director;}

bool compareByYear(Movie const& m1, Movie const& m2)
{return m1.year < m2.year;}

bool compareByGenre(Movie const& m1, Movie const& m2)
    {return m1.genre < m2.genre;}
        

bool compareByDuration(Movie const& m1, Movie const& m2)
    {return m1.duration < m2.duration;}


/**
 You can sort the movies by title, director, year released, or duration.
 Please enter the corresponding number:
 1 : to sort by title
 2 : to sort by director
 3 : to sort by year released
 4 : to sort by genre
 5 : to sort by the duration time
 0 : to exit the program
 1
 
 Title                             Director                 Genre                    Year Released            Duration
 A Thousand Words                   Brian Robbins            comedy                   2012                     91
 
 Avengers: Age of Ultron            Joss Whedon              science fiction          2015                     120
 
 Captain America: The Winter SoldierRusso                    science fiction          2014                     120
 
 Chungking Express                  Kai Wai Wong             drama                    1994                     98
 
 Earthlings                         Shaun Monson             documentary              2005                     95
 
 Ghost in the Shell                 Mamoru Oshii             manga                    1995                     82
 
 Gone Girl                          David Fincher            mystery                  2014                     129
 
 Guardians of the Galaxy            James Gunn               fantasy                  2014                     120
 
 Happy Feet                         George Miller            comedy                   2006                     108
 
 Inglourious Basterds               Quentin Tarantino        drama                    2009                     120
 
 Interstellar                       Christopher Nollan       science fiction          2014                     160
 
 Kung Fu Hustle                     Stephen Chow             fantasy                  2004                     99
 
 Limitless                          Neil Burger              Thriller                 2011                     105
 
 Mean Girls                         Mark Waters              comedy                   2004                     97
 
 Saving Private Ryan                Steven Spielberg         drama                    1998                     120
 
 Superbad                           Gret Mottola             comedy                   2007                     113
 
 Surf's Up                          Chris Buck               advanture                2007                     85
 
 The Great Escape                   John Sturges             thriller                 1963                     172
 
 The Matrix                         Andy Wachowski           fantasy                  1999                     136
 
 Under the Tuscan Sun               Audrey Wells             drama                    2003                     113
 
 Whiplash                           Damien Chazelle          drama                    2014                     106
 
 Zoolander                          Ben Stiller              comedy                   2001                     105
 
 You can sort the movies by title, director, year released, or duration.
 Please enter the corresponding number:
 1 : to sort by title
 2 : to sort by director
 3 : to sort by year released
 4 : to sort by genre
 5 : to sort by the duration time
 0 : to exit the program
 2
 
 Title                             Director                 Genre                    Year Released            Duration
 The Matrix                         Andy Wachowski           fantasy                  1999                     136
 
 Under the Tuscan Sun               Audrey Wells             drama                    2003                     113
 
 Zoolander                          Ben Stiller              comedy                   2001                     105
 
 A Thousand Words                   Brian Robbins            comedy                   2012                     91
 
 Surf's Up                          Chris Buck               advanture                2007                     85
 
 Interstellar                       Christopher Nollan       science fiction          2014                     160
 
 Whiplash                           Damien Chazelle          drama                    2014                     106
 
 Gone Girl                          David Fincher            mystery                  2014                     129
 
 Happy Feet                         George Miller            comedy                   2006                     108
 
 Superbad                           Gret Mottola             comedy                   2007                     113
 
 Guardians of the Galaxy            James Gunn               fantasy                  2014                     120
 
 The Great Escape                   John Sturges             thriller                 1963                     172
 
 Avengers: Age of Ultron            Joss Whedon              science fiction          2015                     120
 
 Chungking Express                  Kai Wai Wong             drama                    1994                     98
 
 Ghost in the Shell                 Mamoru Oshii             manga                    1995                     82
 
 Mean Girls                         Mark Waters              comedy                   2004                     97
 
 Limitless                          Neil Burger              Thriller                 2011                     105
 
 Inglourious Basterds               Quentin Tarantino        drama                    2009                     120
 
 Captain America: The Winter SoldierRusso                    science fiction          2014                     120
 
 Earthlings                         Shaun Monson             documentary              2005                     95
 
 Kung Fu Hustle                     Stephen Chow             fantasy                  2004                     99
 
 Saving Private Ryan                Steven Spielberg         drama                    1998                     120
 
 You can sort the movies by title, director, year released, or duration.
 Please enter the corresponding number:
 1 : to sort by title
 2 : to sort by director
 3 : to sort by year released
 4 : to sort by genre
 5 : to sort by the duration time
 0 : to exit the program
 3
 
 Title                             Director                 Genre                    Year Released            Duration
 The Great Escape                   John Sturges             thriller                 1963                     172
 
 Chungking Express                  Kai Wai Wong             drama                    1994                     98
 
 Ghost in the Shell                 Mamoru Oshii             manga                    1995                     82
 
 Saving Private Ryan                Steven Spielberg         drama                    1998                     120
 
 The Matrix                         Andy Wachowski           fantasy                  1999                     136
 
 Zoolander                          Ben Stiller              comedy                   2001                     105
 
 Under the Tuscan Sun               Audrey Wells             drama                    2003                     113
 
 Kung Fu Hustle                     Stephen Chow             fantasy                  2004                     99
 
 Mean Girls                         Mark Waters              comedy                   2004                     97
 
 Earthlings                         Shaun Monson             documentary              2005                     95
 
 Happy Feet                         George Miller            comedy                   2006                     108
 
 Surf's Up                          Chris Buck               advanture                2007                     85
 
 Superbad                           Gret Mottola             comedy                   2007                     113
 
 Inglourious Basterds               Quentin Tarantino        drama                    2009                     120
 
 Limitless                          Neil Burger              Thriller                 2011                     105
 
 A Thousand Words                   Brian Robbins            comedy                   2012                     91
 
 Guardians of the Galaxy            James Gunn               fantasy                  2014                     120
 
 Whiplash                           Damien Chazelle          drama                    2014                     106
 
 Captain America: The Winter SoldierRusso                    science fiction          2014                     120
 
 Interstellar                       Christopher Nollan       science fiction          2014                     160
 
 Gone Girl                          David Fincher            mystery                  2014                     129
 
 Avengers: Age of Ultron            Joss Whedon              science fiction          2015                     120
 
 You can sort the movies by title, director, year released, or duration.
 Please enter the corresponding number:
 1 : to sort by title
 2 : to sort by director
 3 : to sort by year released
 4 : to sort by genre
 5 : to sort by the duration time
 0 : to exit the program
 4
 
 Title                             Director                 Genre                    Year Released            Duration
 Limitless                          Neil Burger              Thriller                 2011                     105
 
 Surf's Up                          Chris Buck               advanture                2007                     85
 
 A Thousand Words                   Brian Robbins            comedy                   2012                     91
 
 Superbad                           Gret Mottola             comedy                   2007                     113
 
 Happy Feet                         George Miller            comedy                   2006                     108
 
 Zoolander                          Ben Stiller              comedy                   2001                     105
 
 Mean Girls                         Mark Waters              comedy                   2004                     97
 
 Earthlings                         Shaun Monson             documentary              2005                     95
 
 Under the Tuscan Sun               Audrey Wells             drama                    2003                     113
 
 Whiplash                           Damien Chazelle          drama                    2014                     106
 
 Chungking Express                  Kai Wai Wong             drama                    1994                     98
 
 Inglourious Basterds               Quentin Tarantino        drama                    2009                     120
 
 Saving Private Ryan                Steven Spielberg         drama                    1998                     120
 
 The Matrix                         Andy Wachowski           fantasy                  1999                     136
 
 Guardians of the Galaxy            James Gunn               fantasy                  2014                     120
 
 Kung Fu Hustle                     Stephen Chow             fantasy                  2004                     99
 
 Ghost in the Shell                 Mamoru Oshii             manga                    1995                     82
 
 Gone Girl                          David Fincher            mystery                  2014                     129
 
 Captain America: The Winter SoldierRusso                    science fiction          2014                     120
 
 Interstellar                       Christopher Nollan       science fiction          2014                     160
 
 Avengers: Age of Ultron            Joss Whedon              science fiction          2015                     120
 
 The Great Escape                   John Sturges             thriller                 1963                     172
 
 You can sort the movies by title, director, year released, or duration.
 Please enter the corresponding number:
 1 : to sort by title
 2 : to sort by director
 3 : to sort by year released
 4 : to sort by genre
 5 : to sort by the duration time
 0 : to exit the program
 5
 
 Title                             Director                 Genre                    Year Released            Duration
 Limitless                          Neil Burger              Thriller                 2011                     105
 
 Zoolander                          Ben Stiller              comedy                   2001                     105
 
 Whiplash                           Damien Chazelle          drama                    2014                     106
 
 Happy Feet                         George Miller            comedy                   2006                     108
 
 Under the Tuscan Sun               Audrey Wells             drama                    2003                     113
 
 Superbad                           Gret Mottola             comedy                   2007                     113
 
 Inglourious Basterds               Quentin Tarantino        drama                    2009                     120
 
 Guardians of the Galaxy            James Gunn               fantasy                  2014                     120
 
 Avengers: Age of Ultron            Joss Whedon              science fiction          2015                     120
 
 Saving Private Ryan                Steven Spielberg         drama                    1998                     120
 
 Captain America: The Winter SoldierRusso                    science fiction          2014                     120
 
 Gone Girl                          David Fincher            mystery                  2014                     129
 
 The Matrix                         Andy Wachowski           fantasy                  1999                     136
 
 Interstellar                       Christopher Nollan       science fiction          2014                     160
 
 The Great Escape                   John Sturges             thriller                 1963                     172
 
 Ghost in the Shell                 Mamoru Oshii             manga                    1995                     82
 
 Surf's Up                          Chris Buck               advanture                2007                     85
 
 A Thousand Words                   Brian Robbins            comedy                   2012                     91
 
 Earthlings                         Shaun Monson             documentary              2005                     95
 
 Mean Girls                         Mark Waters              comedy                   2004                     97
 
 Chungking Express                  Kai Wai Wong             drama                    1994                     98
 
 Kung Fu Hustle                     Stephen Chow             fantasy                  2004                     99
 
 You can sort the movies by title, director, year released, or duration.
 Please enter the corresponding number:
 1 : to sort by title
 2 : to sort by director
 3 : to sort by year released
 4 : to sort by genre
 5 : to sort by the duration time
 0 : to exit the program
 0
 Goodbye!
 Program ended with exit code: 1
**/
