#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void BestBaller(int*,const char*[5]);
void BestBatsman(long double*,const char*[11]);
void BestBallFile();
void BestBatFile();

int Player1to5() {           //Probability for first 5 players
    int x = 0;
    x = rand() % 100;
    if (x < 89) {
        int y;
        y = rand() % 7;
        if (y >= 0 && y < 7) {
            return y;
        }

    }
    else if (x > 89 && x < 99) {
        int y = 11;
        return y;
    }
}

int Player6to11() {                 //Probability of bowlers
    int x = 0;
    x = rand() % 2;
    if (x == 0) {
        int y;
        y = rand() % 7;
        if (y == 0 && y<7) {
            return y;
        }
    }
    if (x == 1) {
        return 11;
    }
}

void DisplayBowlers(const char* bowlers [5] , int wickets[5]) {    //Func to Display Bowlers Summary
    cout << "\n\n\nBOWLER" << "\t\t" << "WICKETS" << endl;
    for (int i = 0; i < 5; i++) {
        cout << bowlers[i] << "| \t\t |" << wickets[i] << " wickets." << endl;
        cout << "---------------------------------------------" << endl;
    }
}

void DisplayBatsman(const char *players[11],long double runs[11]) {   //Func to Display Batsman Summary
    cout << "\n\n\nBATSMAN" << "\t\t" << "SCORE" << endl<<endl;
    for (int i = 0; i < 11; i++) {
        cout << players[i] << "| \t\t |" << runs[i] << " runs." << endl;
        cout << "---------------------------------------------" << endl;
    }
}

int DisplayRunrate(int overs ,int score) {
    return ((double)score / (double)overs);
}
int Team2(bool tr, int ss) {              //Func for Pakistan Batting
    char f;
    int score = 0, i = 0, swap1 = 0, balls = 1, j = 0;
    const char* swap = "";
    const char* bowler[5] = { "Cameron Green" , "Travis Head" , "Josh Inglis" ,
        "Marnus L" , "Ben McDerm" };
    const char* Players[11] = { "Babar Azam", "Shadab Khan",
        "Abdullah Shaf", "Asif Afridi", "Asif Ali", "Fakhar Zaman", "Haider Ali", "Haris Rauf",
        "Hasan Ali", "Iftikhar Ahm", "Imam ul" };
    long double *Runs = new long double[11] {};
    int wickets[5] = {};
    int r = rand() % 3;
    int b = r;

    double overs = 0;                            //file handline
    string config = "configuration.txt";
    ifstream file(config);
    file >> overs;
    file.close();

    if (ss > 1) {
        cout << "Target:" << ss + 1 << endl;
    }

    while (balls <= overs*6  && i < 11) {            //condition for innings
        cin.get(f);
        if (j > 4) {
            j = 0;
        }

        int x = 0;
        if (i < 6) {
            do {
                x = Player1to5();
            } while (x > 11);
        }

        else if (i > 5) {
            x = Player6to11();
            do {
                x = Player1to5();
            } while (x > 11);
            if (ss > 1) {                      //if second inning
                cout << "\nRequired score: " << ss - score + 1 << endl;
            }
        }
        if (x == 11) {
            cout << "\n\n\nPlayer " << Players[i] << " got out!" << endl << endl;
            wickets[i] = wickets[i] + 1;
            i++;
            if (i == 9) {
                break;
            }
        }
        else {
            cout << "\n\nPlayer " << Players[i] << " scored:" << x << endl;
            Runs[i] = x + Runs[i];
        }
        if (x == 1 || x == 3 || x == 5) {
            swap = Players[i];
            Players[i] = Players[i + 1];
            Players[i + 1] = swap;

            swap1 = Runs[i];
            Runs[i] = Runs[i + 1];
            Runs[i + 1] = swap1;
        }
        if (x != 11) {
            score = score + x;
        }
        cout << "Ball: " << balls << endl;
        cout << "Ball bowled by Player: " << bowler[j];

        if (balls % 6 == 0) {                //if over up change batter
            cout << "\n\nOver Up." << endl;
            cout << "Completed " << balls / 6 << " overs" << endl;;
            cout << "Runrate : " << DisplayRunrate(balls / 6, score) << endl;
                        if (ss > 1) {
                cout << "Required runrate:" << DisplayRunrate(balls / 6, ss) - DisplayRunrate(balls / 6, score) << endl;
            }
            swap = Players[i];
            Players[i] = Players[i + 1];
            Players[i + 1] = swap;

            swap1 = Runs[i];
            Runs[i] = Runs[i + 1];
            Runs[i + 1] = swap1;
            j++;
        }
        
        balls++;
        if (ss > 1 && score>ss+1) {
            cout << "Pakistan won in "<<balls/6.0<<"overs." << endl;
            break;
        }
        
    }
    if (ss > 1 && score < ss) {
        cout << "Australia won by"<<ss-score<<"runs" << endl;
    }
    cout << "\n\nTotal Score " << score << endl;

    DisplayBatsman(Players, Runs);
    DisplayBowlers(bowler , wickets);
    BestBaller(wickets, bowler);
    BestBatsman(Runs, Players);
    BestBallFile();
    BestBatFile();
    return score;

}


int Team1(bool tr, int ss) {                 //Func for AUS batting
    int score = 0, i = 0, swap1 = 0, balls = 1, j = 0;
    const char* swap;
    char f;
    const char* bowler[5] = { "Haider Ali", "Haris Rauf",
        "Hasan Ali", "Iftikhar Ahm", "Imam ul" };
    const char* Players[11] = { "Aaron Finch", "Sean Abbott", "Ashton Agar",
        "Jason Behrend", "Alex Carey" , "Nathan Ellis" , "Cameron Green" , "Travis Head" , "Josh Inglis" ,
        "Marnus L" , "Ben McDerm" };
    long double* Runs = new long double[11]{};
    int wickets[5] = {};
    int r = rand() % 3;
    int b = r;

    double overs = 0;
    string config = "configuration.txt";
    ifstream file(config);
    file >> overs;
    file.close();

    if (ss > 1) {
    cout << "Target:" << ss + 1 << endl;
    }

    while (balls <= overs*6  && i < 11) {
        cin.get(f);
        if (j > 4) {
            j = 0;
        }

        int x = 0;
        if (i < 6) {
            do {
                x = Player1to5();
            } while (x > 11);
        }

        else if (i > 5) {
            x = Player6to11();
            do {
                x = Player1to5();
            } while (x > 11);
        }
        if (ss > 1) {               //if second inning
            cout << "\nRequired score: " << ss - score + 1 << endl;
            cin.get(f);
        }
        if (x == 11) {
            cout << "\n\n\nPlayer " << Players[i] << " got out!" << endl << endl;
            i++;
            cin.get(f);
            wickets[i] = wickets[i] + 1;
            if (i == 9) {
                break;
            }
        }
        else {
            cout << "\n\nPlayer " << Players[i] << " scored:" << x << endl;
            Runs[i] = x + Runs[i];
        }
        if (x == 1 || x == 3 || x == 5) {           //swap for runs
            swap = Players[i];
            Players[i] = Players[i + 1];
            Players[i + 1] = swap;

            swap1 = Runs[i];
            Runs[i] = Runs[i + 1];
            Runs[i + 1] = swap1;
        }
        if (x != 11) {
            score = score + x;
        }
        cout << "Ball: " << balls << endl;
        cout << "Ball bowled by Player: " << bowler[j];
        if (balls % 6 == 0) {            //short summary after overs
            cout << "\n\nOver Up." << endl;
            cout << "Completed " << balls /6 << " overs"<<endl;
            cout << "Runrate of over: " << DisplayRunrate(balls / 6, score) << endl;
            if (ss > 1) {
                cout << "Required runrate:" << DisplayRunrate(balls / 6, ss) - DisplayRunrate(balls / 6, score) << endl;
            }
            swap = Players[i];
            Players[i] = Players[i + 1];
            Players[i + 1] = swap;

            swap1 = Runs[i];
            Runs[i] = Runs[i + 1];
            Runs[i + 1] = swap1;
            j++;
        }
        balls++;
        if (ss > 1 && score > ss + 1) {
            cout << "\n\nPakistan won in " << balls / 6.0 << "overs." << endl;
            break;
        }

    }
    if (ss > 1 && score < ss) {
        cout << "\n\nAustralia won by " << ss - score << " runs." << endl;
    }
    if (score == ss && ss>1) {
        cout << "\n\n\nMatch draw!" << endl;
    }
    //Summary
    cout << "\n\nTotal Score " << score << endl;
    cout << "Total Runrate" << DisplayRunrate(balls / 6, score) << endl;
    DisplayBatsman(Players, Runs);
    DisplayBowlers(bowler, wickets);
    BestBaller(wickets, bowler);
    BestBatsman(Runs, Players);
    BestBallFile();
    BestBatFile();
    return score;
}


int Bat(int x, string z, string y, bool t) {  // Func to process the toss
    
    double overs=0;
    string config = "configuration.txt";
    ifstream file(config);  //rread overs from file
    file >> overs;
    file.close();

    cout <<"Match of " <<overs<<" overs" << endl;  

    //Innings according to toss
    if (x == 0) {
        int ss = Team2(t, 0);
        system("CLS");
        cout << "Team " << y << " Batting :" << endl;
        t = 0;
        Team1(t, ss);
        return 0;
    }
    else if (x == 1) {
        int ss = Team1(t, 0);
        system("CLS");
        cout << "Team " << z << " Batting :" << endl;
        t = 0;
        Team2(t, ss);

        return 0;
    }
}

int main()  //main function
{
    int players_a[11], players_b[11];
    string team1 = "Pakistan", team2 = "Australia";
    bool target = 1;
    srand(time(0));
    int toss = rand() % 2;   //For Toss
    if (toss == 0) {
        cout << team1 << " won the toss and chose to bat!" << endl;
        Bat(toss, team1, team2, target);
    }
    else if (toss == 1) {
        cout << team2 << " won the toss and chose to bat!" << endl;
        Bat(toss, team1, team2, target);
    }
}


//Below functions are for final file handling
void BestBaller(int* a,const char* n[5]) {
    int max = a[0];
    int c = 0;
    for (int i = 0; i < 5; i++) {
        if (max < a[i]) {
            max = a[i];
            c = i;
        }
    }
    ofstream file;
    file.open("Bowler.txt",fstream::app);
    file << n[c] << " " << max << "  ";
    file.close();
}

void BestBatsman(long double* a,const char* b[11]) {
    int max = a[0];
    int c = 0;
    for (int i = 0; i < 11; i++) {
        if (max < a[i]) {
            max = a[i];
            c = i;
        }
    }
    ofstream file;
    file.open("Bat.txt",fstream::app);
    file << b[c] << " " << max << "  ";
    file.close();
}

void BestBallFile() {
    string s,score1,score2;
    int s1, s2;
    bool flag = false;
    ifstream file;
    file.open("Bowler.txt");
    getline(file, s);
    int size;
    size = s.length();
    for (int c = 1; c < size; c++) {
        if ((s[c] > 47 && s[c] < 59) && flag == false) {
            score1[0] = s[c];
            flag = true;
        }
        else if ((s[c] > 47 && s[c] < 59) && flag == true) {
            score2[0] = s[c];
            break;
        }
    }
    s1 = stoi(score1);
    s2 = stoi(score2);
    if (s1 > s2) {
        for (int c = 0; s[c] != score1[0]; c++) {
            cout << s[c];
        }
        cout << "is the best bowler of the match.";
    }
    else {
        int c = 0;
        for (; s[c] != score1[0]; c++);
        for (; s[c] != ' '; c++);
        c++;
        for (; s[c] != score2[0]; c++) {
            cout << s[c];
        }
        cout << "is the best bowler of the match.";
    }
    
}

void BestBatFile() {
    string s, score1, score2;
    int s1, s2;
    bool flag = false;
    ifstream file;
    file.open("Bat.txt");
    getline(file, s);
    int size;
    size = s.length();
    for (int c = 1; c < size; c++) {
        if ((s[c] > 47 && s[c] < 59) && flag == false) {
            score1[0] = s[c];
            flag = true;
        }
        else if ((s[c] > 47 && s[c] < 59) && flag == true) {
            score2[0] = s[c];
            break;
        }
    }
    s1 = stoi(score1);
    s2 = stoi(score2);
    if (s1 > s2) {
        for (int c = 0; s[c] != score1[0]; c++) {
            cout << s[c];
        }
        cout << "is the best batsman of the match.";
    }
    else {
        int c = 0;
        for (; s[c] != score1[0]; c++);
        for (; s[c] != ' '; c++);
        c++;
        for (; s[c] != score2[0]; c++) {
            cout << s[c];
        }
        cout << "is the best batsman of the match.";
    }
}