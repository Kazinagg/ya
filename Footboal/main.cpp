#include <iostream>
#include <string>
#include <map>

using namespace std;



struct Match
{
    int matchType;
    int team1Goals;
    int team2Goals;

};


void input(Match&, Match&);

int main(){
    
    Match match1;
    Match match2;

    input(match1, match2);

    int team1GuestsGoals;
    int team2GuestsGoals;

    // match1.matchType = 1? team1GuestsGoals = match1.team1Goals, team2GuestsGoals = match2.team2Goals : team2GuestsGoals = match1.team2Goals, team1GuestsGoals = match2.team2Goals;
    if (match1.matchType == 1) {
        team1GuestsGoals = match1.team1Goals;
        team2GuestsGoals = match2.team2Goals;
    } else {
        team2GuestsGoals = match1.team2Goals;
        team1GuestsGoals = match2.team1Goals;
    }

    int goalDifference = (match1.team2Goals + match2.team2Goals) - (match1.team1Goals + match2.team1Goals);
    int guestsGoalsDifference = team2GuestsGoals - team1GuestsGoals;
    cout << "team2GuestsGoals: " << team2GuestsGoals << endl;
    cout << "team1GuestsGoals: " << team1GuestsGoals << endl;

    // if ((match1.team1Goals + match2.team1Goals) > (match1.team2Goals + match2.team2Goals)){
    //     cout << 0;
    // } 
    // else if ((match1.team1Goals + match2.team1Goals) == (match1.team2Goals + match2.team2Goals))
    // {
    //     if (team1GuestsGoals > team2GuestsGoals){
    //         cout << 0;
    //     } else if (team1GuestsGoals == team2GuestsGoals){
    //         cout << 1; 
    //     } else {
    //          if (match2.matchType == 1){
    //             cout << (match1.team2Goals + match2.team2Goals) - (match1.team1Goals + match2.team1Goals);
    //         } else if (match2.matchType == 2){
    //             guestsGoalsDifference < goalDifference? cout << guestsGoalsDifference : cout << goalDifference;
    //         }
    //     }
    // } 
    // else{
    //     if (team1GuestsGoals > team2GuestsGoals){
    //         cout << 0;
    //     } else if (team1GuestsGoals == team2GuestsGoals){
    //         cout << 1; 
    //     } else {
    //          if (match2.matchType == 1){
    //             cout << (match1.team2Goals + match2.team2Goals) - (match1.team1Goals + match2.team1Goals);
    //         } else if (match2.matchType == 2){
    //             guestsGoalsDifference < goalDifference? cout << guestsGoalsDifference : cout << goalDifference; 1 = 1 ком дома
    //         }
    //     }
    // }

    if (match2.matchType == 1){
        goalDifference < 0? cout << 0: cout << goalDifference+1;
    } else if (match2.matchType == 2){
        if (guestsGoalsDifference + goalDifference > 0){
            goalDifference < 0? cout << 0: cout << goalDifference;
        } else{
            goalDifference < 0? cout << 0: cout << goalDifference+1;
        }
    }
    

    // cout << match1.team1Goals << " " << match1.team2Goals << endl;
    // cout << match2.matchType << endl;
    // cout << match2.team1Goals << " " << match2.team2Goals << endl;
}

void input(Match& match1_, Match& match2_) {
    string temp1;
    string temp2;
    int temp3;

    // cin >> temp1;
    // cin >> temp2;
    // cin >> temp3;
    temp1 = "0:2";
    temp2 = "0:3";
    temp3 = 2;


    match1_.matchType = temp3;
    match1_.team1Goals = temp1[0] - '0';
    match1_.team2Goals = temp1[2] - '0';

    temp3 = (temp3 == 1) ? 2 : 1;

    match2_.matchType = temp3;
    match2_.team1Goals = temp2[0] - '0';
    match2_.team2Goals = temp2[2] - '0';
}





// for (int i = 0; i < 5; i++){
//         cout << check[i] << endl;
//     }