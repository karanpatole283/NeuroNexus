#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
   string name;
   cout << "Player Name: ";
   cin >> name;
   cout << "Dear " << name << ", Welcome to the Number Guessing Game!\n";

   srand((unsigned int)time(NULL));

   int number = (rand() % 100) + 1;

   int guess = 0;

   do {
       cout << "Guess a number (1-100): ";
       cin >> guess;

       if (guess > number) {
           cout << "Guess lower!\n";
       } else if (guess < number) {
           cout << "Guess higher!\n";
       }
   } while (guess != number);

   cout << "Congratulations, " << name << "! You won the match!\n";

   return 0;
}
