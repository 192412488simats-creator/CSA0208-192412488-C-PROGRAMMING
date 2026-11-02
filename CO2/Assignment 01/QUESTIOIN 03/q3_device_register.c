#include <stdio.h>
enum { LIGHT=0, FAN=1, AC=2, HEATER=3, PUMP=4 };
unsigned char switch_on(unsigned char reg, int dev) {
    return (unsigned char)(reg | (1u << dev));       /* TODO 1: set */
}
unsigned char switch_off(unsigned char reg, int dev) {
    return (unsigned char)(reg & ~(1u << dev));      /* TODO 2: clear */
}
unsigned char toggle(unsigned char reg, int dev) {
    return (unsigned char)(reg ^ (1u << dev));       /* TODO 3: flip */
}
int is_on(unsigned char reg, int dev) {
    return (reg & (1u << dev)) != 0;                 /* TODO 4: test */
}
void show(unsigned char reg) {
    for (int bit=7; bit>=0; bit--) putchar(((reg >> bit) & 1u) ? '1' : '0');
    putchar('\\n');
}
int main(void) {
    unsigned char reg=0;
    reg=switch_on(reg,LIGHT); /* 00000001 = 1 */
    reg=switch_on(reg,AC);    /* 00000101 = 5 */
    show(reg);
    reg=toggle(reg,FAN);      /* 00000111 = 7 */
    reg=switch_off(reg,LIGHT);/* 00000110 = 6 */
    show(reg);
    printf("AC is %s, PUMP is %s\\n",
           is_on(reg,AC) ? "ON" : "OFF", is_on(reg,PUMP) ? "ON" : "OFF");
    return 0;
}
