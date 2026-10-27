# CSA02 Assignment 1 – Rural Electricity Co-operative Billing Program

## Compiler Details
- **Compiler:** GCC (GNU Compiler Collection)
- **Version:** GCC 16.2.0
- **Platform:** Windows using MSYS2 UCRT64
- **Language:** C

## Project Structure

- `Task01/` – Data analysis and input validation
- `Task02/` – Data types, limits, and meter consumption
- `Task03/` – Electricity billing using slab tariffs
- `Task04/` – Safe macros and macro evaluation

## Compilation and Execution

Open the MSYS2 UCRT64 terminal and navigate to the folder containing the C source files:

```bash
cd "/c/Users/srivy/Downloads/CSA02_Task_C_Programs (1)"
```

### Task 01 – Data Analysis and Validation

```bash
gcc Task01_data_analysis_demo.c -o task1
./task1
```

Enter the household number, category, previous meter reading, and current meter reading when prompted.

### Task 02 – Meter Consumption

```bash
gcc Task02_consumption.c -o task2
./task2
```

**Expected results:**
- Meter data type size: 2 bytes
- Maximum meter reading: 65535
- Consumption: 330 units
- Rollover consumption: 256 units

### Task 02 – Data Type Limits

```bash
gcc Task02_datatype_limits.c -o task2limits
./task2limits
```

Displays the sizes and ranges of C data types, including `char`, `short`, `int`, `long`, `long long`, `float`, and `double`.

### Task 03 – Electricity Billing

```bash
gcc Task03_billing.c -o task3
./task3
```

Expected billing results:

| Units consumed | Bill amount |
|---:|---:|
| 0 | Rs. 50.00 |
| 100 | Rs. 50.00 |
| 150 | Rs. 162.50 |
| 200 | Rs. 275.00 |
| 350 | Rs. 950.00 |

### Task 04 – Safe Macros

```bash
gcc Task04_safe_macros.c -o task4
./task4
```

Demonstrates safe macro usage and explains common macro evaluation problems.

## Output Screenshots

Each task folder contains its C source files, README documentation, and available program output screenshots.

## Conclusion

The programs demonstrate C programming concepts including input validation, data types, meter reading rollover, electricity billing calculations, and safe macro usage.
# CSA0208-192412488-C-PROGRAMMING
