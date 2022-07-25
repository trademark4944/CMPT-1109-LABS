#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class movie { //create class movie
public: //create public variables for class
    int ratings[5];
    string MPAA, title;

public:
    movie() {
        title = "Untitled";
        MPAA = "Unrated";
        for (int i = 0; i < 5; i++) {
            ratings[i] = 0;
        }
    }
    movie(string name, string mpaa) { //default constructor for objects of class movie
        title = name;
        MPAA = mpaa;
        for (int i = 0; i < 5; i++) {
            ratings[i] = 0;
        }
    }
    void addRating(int rating) { //class function to add a rating for a movie object
        switch (rating) { //detect what rating is give, 1 or 2 or etc
        case 1:
            ratings[0]++; //increase the ammount of the given rating
            break;

        case 2:
            ratings[1]++;
            break;

        case 3:
            ratings[2]++;
            break;

        case 4:
            ratings[3]++;
            break;

        case 5:
            ratings[4]++;
            break;

        default: //catch any invalid inputs (input greater than 5 or less than 1)
            cout << "ERROR: Invalid Input";
            break;
        }
    }
    float averageRating() { //class function to calculate and return the average rating for the movie object
        float totalRatings = ratings[0] + ratings[1] + ratings[2] + ratings[3] + ratings[4];
        float average = (ratings[0] * 1) + (ratings[1] * 2) + (ratings[2] * 3) + (ratings[3] * 4) + (ratings[4] * 5);
        return (average / totalRatings);
    }
};

int main() {
    srand(time(NULL)); //used for rand()
    int rating;
    float average;

    movie movie1("Ponyo", "G"); //initialize movie objects using default constructor
    movie movie2("From up on Poppy Hill", "PG");

    for (int i = 1; i <= 5; i++) {
        rating = rand() % 5 + 1; //create rating between 1 and 5
        movie1.addRating(rating); //add the generated rating to the movie object
    }

    for (int j = 1; j <= 5; j++) {
        rating = rand() % 5 + 1; //see above lines 64, 65
        movie2.addRating(rating);
    }

    average = movie1.averageRating(); //calculate average rating for movie object movie1
    cout << "Title: " << movie1.title << " | MPAA Rating: " << movie1.MPAA << " | Average Star Rating: " << average << endl; //output desired attributes of object movie1

    average = movie2.averageRating(); //calculate average rating for movie object movie2
    cout << "Title: " << movie2.title << " | MPAA Rating: " << movie2.MPAA << " | Average Star Rating: " << average << endl; //output desired attributes of object movie2
    return 0;
}
