#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string director;
    int duration;

public:
    // Constructor
    Movie(string title, string director, int duration) {
        this->title = title;
        this->director = director;
        this->duration = duration;
    }

    void displayMovie() const {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
        cout << "---------------------------" << endl;
    }
};

class CinemaHall {
private:
    string name;
    int movieCount;
    Movie **movies; // Composition
    int currentIndex;

public:
    // Constructor
    CinemaHall(string name, int movieCount) {
        this->name = name;
        this->movieCount = movieCount;
        this->currentIndex = 0;

        this->movies = new Movie *[movieCount]; 
        for (int i = 0; i < movieCount; i++) {
            movies[i] = nullptr;
        }
    }

    void addMovie(string title, string director, int duration) {
        if (currentIndex < movieCount) {
            movies[currentIndex] = new Movie(title, director, duration);
            currentIndex++;
        } else {
            cout << "Cannot add more movies, cinema hall is full!" << endl;
        }
    }

    void display() const {
        cout << "Cinema Hall: " << name << endl;
        cout << "---------------------------" << endl;
        for (int i = 0; i < currentIndex; i++) { 
            if (movies[i] != nullptr) {
                movies[i]->displayMovie();
            }
        }
    }

    // Destructor
    ~CinemaHall() {
        for (int i = 0; i < currentIndex; i++) {
            delete movies[i];
        }
        delete[] movies;
    }
};

int main() {
    CinemaHall cinemaHall("NUPLEX", 5);
    cinemaHall.addMovie("Interstellar", "Christopher Nolan", 120);
    cinemaHall.addMovie("The Fast And The Furious", "Rob Cohen", 106);
    cinemaHall.addMovie("Harry Potter and the Philosopher's Stone", "Chris Columbus", 152);

    cinemaHall.display();

    return 0;
}
