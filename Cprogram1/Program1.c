//Author: Tanner Barcus
//KUID: 3053822
//Date: 02/10/2023
//Lab: 03
//Cprogram1


#include <stdio.h>
#include <string.h>


void salesrep_ordered(char months[12][10], float *sales) {

	printf("Month      Sales\n");
        for (int j = 0; j < 12; j++) {
                printf("%-11s""$""%.2f\n", months[j], sales[j]);
        }
}

void sales_sum(char months[12][10], float *sales) {

	printf("\nSales Summary:\n");
	float min = sales[0];
	int min_i = 0;
	for (int j = 1; j < 12; j++) {
		if (sales[j] < min) {
		min = sales[j];
		min_i = j;
	}
	}
	printf("Minimum: $""%-11.2f"" (""%s"")\n", min, months[min_i]);

	float max = sales[0];
	int max_i = 0;
	for (int k = 1; k < 12; k++) {
		if (sales[k] > max) {
			max = sales[k];
			max_i = k;
		}
	}
	printf("Maximum: $""%-11.2f"" (""%s"")\n", max, months[max_i]);

	float avg = sales[0];
	for (int l = 1; l < 12; l++) {
		avg = avg + sales[l];
	}
	float avg_fin = avg / 12;
	printf("Average: $""%-11.2f\n", avg_fin);
}


void six_avg(char months[12][10], float *sales) {

	printf("\nSix-Month Moving Average Report:\n");
	for (int j = 0; j < 7; j++) {
		float sixmo;
		sixmo = ((sales[j] + sales[j + 1] + sales[j + 2] + sales[j + 3] + sales[j + 4] + sales[j + 5]) / 6);
		printf("%-11s""-  ""%-11s""$""%.2f""\n", months[j], months[j + 5], sixmo);
		}
}

void dec_sales(char months[12][10], float *sales) {

	printf("\nSales Report (Highest to Lowest):\n");
	for (int i = 0; i < 12; ++i) {
		for (int j = i + 1; j < 12; ++j) {
			if (sales[i] < sales[j]) {
				char temp2[11];
				float temp = sales[i];
				strcpy(temp2, months[i]);
				sales[i] = sales[j];
				strcpy(months[i], months[j]);
				sales[j] = temp;
				strcpy(months[j], temp2);
			}	
		}
	}

	printf("Months     Sales\n");
	for (int k = 0; k < 12; ++k) {
		printf("%-11s""$""%.2f\n", months[k], sales[k]);
	}

}

int main() {

        FILE *fp;
        int i = 0;
        float sales[12];
        char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        fp = fopen("file.txt", "r");
        if (fp == NULL) {
                printf("File could not be opened");
                return 1;
        }
        while (fscanf(fp, "%f", &sales[i]) != EOF) {
                ++i;
        }
        fclose(fp);

        salesrep_ordered(months, sales);
	sales_sum(months, sales);
	six_avg(months, sales);
	dec_sales(months, sales);

        return 0;
}

