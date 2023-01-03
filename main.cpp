#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const int WHITEBALLS = 69;
const int WHITEPICKS = 5;
const int REDBALLS = 26;

void vector_print(vector <int> const &V);
vector<int> random_lotto();

int main() {
  int numberOfGames;
  vector<int> pb;

  //sets the seeds for a random number
  srand((unsigned) time(NULL));
  
  cout << "How many games would you like to play? ";
  cin >> numberOfGames;
  cout << endl << endl;

  for (int i=0; i<numberOfGames; i++) {
    pb = random_lotto();
    cout << "White Balls are: ";
    for (int j=0; j<pb.size()-1; j++) {
      cout << pb[j] << ' ';
    }
    cout << "Power Ball is: " << pb[WHITEPICKS] << endl << endl;
  }
  
}

void vector_print(vector <int> const &V) {
  cout << "[ ";
  for (int i=0; i< V.size(); i++) {
    cout << V.at(i) << ' ';    
  }
  cout << ']'<< endl;
}

//function of generating 6 numbers
vector<int> random_lotto() {
  vector<int> balls;
  vector<int> random_balls;
  int random;

  //generating 1 - 69
  for (int i = 1; i<= WHITEBALLS; i++) {
    balls.push_back(i);
  }

  //generating 5 balls
  for (int i = 0; i < WHITEPICKS; i++) {
    //chooses num between 1 - 69.
    random = rand()%balls.size();
    //whatever num you choose, it goes into the vector random_balls
    random_balls.push_back(balls[random]);
    //erases that number from the ball pool, missing that num
    balls.erase(balls.begin()+random);
  }

    //prints out sorted vector
    //vector_print(balls);

  
  //sorts those numbers that you chose from least to greatest
  int temp;
  for(int i = 0; i<WHITEPICKS; i++) {
     for(int j = i+1; j<WHITEPICKS; j++) {
        if(random_balls[j] < random_balls[i]) {
           temp = random_balls[i];
           random_balls[i] = random_balls[j];
           random_balls[j] = temp;
        }
     }
  }

  //generates powerball
  random = (rand()%REDBALLS)+1;
  random_balls.push_back(random);
  
  return random_balls;
}/**/

