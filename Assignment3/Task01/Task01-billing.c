#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SLAB1_LIMIT 100
#define SLAB2_LIMIT 200

#define FIXED_CHARGE_PAISE 5000 
#define RATE_SLAB1_PAISE 0     
#define RATE_SLAB2_PAISE 225   
#define RATE_SLAB3_PAISE 450   

int calculate_units(int prev, int curr) {
    if (curr >= prev) {
        return curr - prev;
    } else {
        return (65535 - prev) + 1 + curr;
    }
}

long long calculate_bill_paise(int units) {
    long long energy_charge_paise = 0;

    if (units <= SLAB1_LIMIT) {
        energy_charge_paise = (long long)units * RATE_SLAB1_PAISE;
    } else if (units <= SLAB2_LIMIT) {
        energy_charge_paise = ((long long)SLAB1_LIMIT * RATE_SLAB1_PAISE) + 
                              ((long long)(units - SLAB1_LIMIT) * RATE_SLAB2_PAISE);
    } else {
        energy_charge_paise = ((long long)SLAB1_LIMIT * RATE_SLAB1_PAISE) + 
                              ((long long)(SLAB2_LIMIT - SLAB1_LIMIT) * RATE_SLAB2_PAISE) + 
                              ((long long)(units - SLAB2_LIMIT) * RATE_SLAB3_PAISE);
    }

    return FIXED_CHARGE_PAISE + energy_charge_paise;
}

int validate_integer_input(const char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit((unsigned char)*str)) return 0;
        str++;
    }
    return 1;
}

int main() {
    char prev_str[50], curr_str[50];
    int prev_reading, curr_reading, units;
    long long total_bill_paise;

    printf("Grama Jyothi Rural Electricity Billing System\n");
    printf("---------------------------------------------\n");
    printf("Enter Previous Meter Reading: ");
    if (scanf("%49s", prev_str) != 1) return 1;
    printf("Enter Current Meter Reading: ");
    if (scanf("%49s", curr_str) != 1) return 1;

    if (!validate_integer_input(prev_str) || !validate_integer_input(curr_str)) {
        printf("Error: Invalid input. Readings must be positive integers.\n");
        return 1;
    }

    prev_reading = atoi(prev_str);
    curr_reading = atoi(curr_str);

    if (prev_reading > 65535 || curr_reading > 65535) {
        printf("Error: Meter capacity bounds exceeded (Max 65535).\n");
        return 1;
    }

    if (curr_reading < prev_reading && (prev_reading - curr_reading) < 50000) {
        printf("Error: Current reading is less than previous reading without valid rollover.\n");
        return 1;
    }

    units = calculate_units(prev_reading, curr_reading);
    total_bill_paise = calculate_bill_paise(units);

    printf("\n--- Bill Details ---\n");
    printf("Units Consumed: %d\n", units);
    printf("Total Bill: Rs. %.2f\n", (double)total_bill_paise / 100.0);

    return 0;
}
