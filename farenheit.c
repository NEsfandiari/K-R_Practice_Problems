#include <stdio.h>

float convert(float fahr){
    return 5 * (fahr-32) / 9;;
}

// Print celsius to faranheit
int main(void) {
    float fahr, celsius;
    int lower, upper, step, c;
    
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("Celsius to Faranheit Table\n");
    printf("%3s\t%6s\n", "cel", "far");
    while (fahr <= upper){
        celsius = convert(fahr);
        printf("%3.0f\t%6.1f\n",fahr, celsius);
        fahr = fahr + step;
    }
    printf("\nIn Reverse Order\n");
    for(fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3.0f\t%6.1f\n",fahr, convert(fahr));
    c = getchar();
    putchar(c);
}
