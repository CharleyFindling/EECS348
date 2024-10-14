# include <stdio.h>
# include <stdlib.h>
# include <string.h>


void pad_to_n(char *str, int n) {
    printf("%s", str);
    for (int i = 0; i < n-strlen(str); i++) {
        printf(" ");
    }
}



int main() {
    FILE* f;
    f = fopen("input.txt", "r");
    double sales[12];

    for (int i = 0; i < 12; i++) {
        char line[15];
        fgets(line, 15, f); // read the line and store it in line
        line[strcspn(line, "\n")] = 0; // remove the newline char from the line
        double rounded = ((int)(strtof(line, NULL) * 100 + .5) / 100.0); // convert the line to a number and round it very close to 2 decimals
        sales[i] = rounded;
    }
    
    fclose(f);


    printf("Monthly Sales Report for 2024:\n");
    pad_to_n("Month", 12);
    printf("Sales\n");
    char months[][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        pad_to_n(months[i], 12);
        printf("%.2f\n", sales[i]);
    }

    int min = 0;
    int max = 0;
    double total = 0;
    for (int i=0; i < 12; i++) {
        if (sales[i] < sales[min]) {
            min = i; // min is the min sales month index
        }
        if (sales[i] > sales[max]) {
            max = i;
        }
        total += sales[i];
    }
    printf("Sales summary report:\n");
    printf("Minimum sales:   %.2f (%s)\n", sales[min], months[min]);
    printf("Maximum sales:   %.2f (%s)\n", sales[max], months[max]);
    printf("Average sales:   %.2f\n", (float) total / 12);

    // Six month moving avg
    pad_to_n("January-June", 18);
    printf("%.2f\n", (float) (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5]) / 6);
    pad_to_n("February-July", 18);
    printf("%.2f\n", (float) (sales[6] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5]) / 6);
    pad_to_n("March-August", 18);
    printf("%.2f\n", (float) (sales[6] + sales[7] + sales[2] + sales[3] + sales[4] + sales[5]) / 6);    
    pad_to_n("April-September", 18);
    printf("%.2f\n", (float) (sales[6] + sales[7] + sales[8] + sales[3] + sales[4] + sales[5]) / 6);    
    pad_to_n("May-October", 18);
    printf("%.2f\n", (float) (sales[6] + sales[7] + sales[8] + sales[9] + sales[4] + sales[5]) / 6);    
    pad_to_n("June-November", 18);
    printf("%.2f\n", (float) (sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[5]) / 6);    
    pad_to_n("July-December", 18);
    printf("%.2f\n", (float) (sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 6);    

    printf("Sales report (highest to lowest):\n");

    pad_to_n("Month", 12);
    printf("Sales\n");

for (int j = 0; j < 12; j++) { 
    int maxIndex = 0; 
    for (int i = 1; i < 12; i++) { 
        if (sales[i] > sales[maxIndex]) {
            maxIndex = i; 
        }
    }
    pad_to_n(months[maxIndex], 12);
    printf("$%.2f\n", sales[maxIndex]);
    sales[maxIndex] = 0; 
}





    return 0;
}