# include <stdio.h>

const int TD = 6;
const int FG = 3;
const int safety = 2;
const int TDplus2 = 8;
const int TDplus1 = 7;

void generate_scores(int score) { // this function loops through all possible score combinations up to and including point value / score for each score type, and prints the combinations that reach the desired score.
    for (int safeties = 0; safeties <= score / safety; safeties++) {
        for (int FGs = 0; FGs <= score / FG; FGs++) {
            for (int TDs = 0; TDs <= score / TD; TDs++) {
                for (int TDplus1s = 0; TDplus1s <= score / TDplus1; TDplus1s++) {
                    for (int TDplus2s = 0; TDplus2s <= score / TDplus2; TDplus2s++) {
                        if (safeties * safety + FGs * FG + TDs * TD + TDplus1s * TDplus1 + TDplus2s * TDplus2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TDplus2s, TDplus1s, TDs, FGs, safeties);
                        }
                    }
                }
            }
        }
    }
}




int main() {
    while(1) {
        int input;
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &input); // get the input integer from the user and store it in the input variable
        if (input <= 1) { // if the input is 0 or 1 (or negative), stop the program by returning 0
            return 0;
        }
        else {
            generate_scores(input); // call the generate scores function on the input
        }
    }
    return 0;
}