#include <stdio.h>
#include <limits.h>

void simulate_scale(long long iterations, const char* label) {
    float float_total = 0.0f;
    long long paise_total = 0;
    
    long long single_bill_paise = 72500;
    float single_bill_float = 725.00f;
    
    for(long long i = 0; i < iterations; i++) {
        float_total += single_bill_float;
        paise_total += single_bill_paise;
    }
    
    printf("\n--- Scale: %s (%lld bills) ---\n", label, iterations);
    printf("Integer (Paise) Total: Rs. %.2f\n", (double)paise_total / 100.0);
    printf("Floating-Point Total:  Rs. %.2f\n", float_total);
    printf("Absolute Variance:     Rs. %.2f\n", ((double)paise_total / 100.0) - (double)float_total);
}

int main() {
    printf("System Limits and Range Analysis:\n");
    printf("---------------------------------\n");
    printf("sizeof(int): %zu bytes\n", sizeof(int));
    printf("sizeof(long): %zu bytes\n", sizeof(long));
    printf("sizeof(long long): %zu bytes\n", sizeof(long long));
    
    simulate_scale(4000, "1 Village");
    simulate_scale(60000, "1 Taluk");
    simulate_scale(800000, "1 District");
    
    return 0;
}
