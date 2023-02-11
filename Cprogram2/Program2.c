//Author: Tanner Barcus
//KUID: 3053822
//Date: 02/10/2023
//Lab: 03
//Cprogram2

#include <stdio.h>

int main() {

    int target_score;
    printf("Enter target score: ");
    scanf("%d", &target_score);
    printf("possible combinations of scoring plays: \n");

    for (int tt = 0; tt <= target_score / 8; tt++) {
        for (int to = 0; to <= target_score / 7; to++) {
            for (int td = 0; td <= target_score / 6; td++) {
                for (int fg = 0; fg <= target_score / 3; fg++) {
                    for (int sf = 0; sf <= target_score / 2; sf++) {
                        int total = 8 * tt + 7 * to + 6 * td + 3 * fg + 2 * sf;
                        if (total == target_score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tt, to, td, fg, sf);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
