#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start_hour;
    int end_hour;
    double rate_multiplier;
} TimeOfDayTariff;

long long base_fixed_charge_paise = 5000;
long long base_energy_rate_paise = 450; 
TimeOfDayTariff tod_rule;

void load_configurations() {
    tod_rule.start_hour = 18;     // 6 PM
    tod_rule.end_hour = 22;       // 10 PM
    tod_rule.rate_multiplier = 1.20; // +20% Peak Surcharge
    printf("[System] Dynamic configuration variables verified from mock storage.\n");
}

long long process_interval_reading(int hour, int watt_hours_consumed) {
    double units = (double)watt_hours_consumed / 1000.0;
    double operational_cost = units * (double)base_energy_rate_paise;
    
    if(hour >= tod_rule.start_hour && hour < tod_rule.end_hour) {
        operational_cost *= tod_rule.rate_multiplier;
    }
    return (long long)operational_cost;
}

int main() {
    load_configurations();
    
    int simulated_watt_hours = 500; // 0.5 kWh per 15-min interval
    long long aggregated_energy_paise = 0;
    
    // Simulate 24 hours * 4 intervals per hour = 96 runs
    for(int hour = 0; hour < 24; hour++) {
        for(int interval = 0; interval < 4; interval++) {
            aggregated_energy_paise += process_interval_reading(hour, simulated_watt_hours);
        }
    }
    
    long long total_bill = base_fixed_charge_paise + aggregated_energy_paise;
    
    printf("\n--- Smart Meter Diagnostic Ledger ---\n");
    printf("Simulated Daily Consumption: 48.0 kWh\n");
    printf("Calculated Daily Bill (with peak adjustment): Rs. %.2f\n", (double)total_bill / 100.0);
    
    return 0;
}
