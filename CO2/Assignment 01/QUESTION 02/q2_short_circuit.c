#include <stdio.h>
#define N 1000
static int calls, senior[N], eligible[N], disability[N];
static int slow_verify(int card) { ++calls; return card; }
static void setup(void) {
    int i;
    for (i=0;i<N;i++) {
        senior[i] = (i < 200);
        eligible[i] = (i % 2 == 0);
        disability[i] = (i < 100);
    }
}
static int order_a(int i) { return (senior[i] && eligible[i]) || slow_verify(disability[i]); }
static int order_b(int i) { return slow_verify(disability[i]) || (senior[i] && eligible[i]); }
static int nested(int i) {
    if (senior[i] && eligible[i]) return 1;
    if (slow_verify(disability[i])) return 1;
    return 0;
}
static int bitwise(int i) { return (senior[i] & eligible[i]) | slow_verify(disability[i]); }
int main(void) {
    int i, approved=0;
    setup();
    calls=0; for(i=0;i<N;i++) approved+=order_a(i);
    printf("Cheap conditions first: calls=%d approved=%d\n",calls,approved);
    calls=0; approved=0; for(i=0;i<N;i++) approved+=order_b(i);
    printf("Server check first: calls=%d approved=%d\n",calls,approved);
    calls=0; approved=0; for(i=0;i<N;i++) approved+=nested(i);
    printf("Nested if: calls=%d approved=%d\n",calls,approved);
    calls=0; approved=0; for(i=0;i<N;i++) approved+=bitwise(i);
    printf("Bitwise & and |: calls=%d approved=%d\n",calls,approved);
    calls=0; (void)(0 && slow_verify(1));
    printf("0 && slow_verify calls=%d\n",calls);
    (void)(1 || slow_verify(1));
    printf("1 || slow_verify calls=%d\n",calls);
    return 0;
}
