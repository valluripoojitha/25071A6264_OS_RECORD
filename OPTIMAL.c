#include <stdio.h>
int main() {
 printf("Roll no: 25071A6238\n");
 int f, n, p[30], m[10], pf = 0;
 printf("Enter number of frames and pages: "); scanf("%d %d", &f, &n);
 printf("Enter page reference string: "); for (int i = 0; i < n; i++) scanf("%d", &p[i]);
 for (int i = 0; i < f; i++) m[i] = -1;
 for (int i = 0; i < n; i++) {
 int hit = 0, opt = -1, max = -1;
 for (int j = 0; j < f; j++) if (m[j] == p[i]) hit = 1;
 if (!hit) {
 for (int j = 0; j < f; j++) {
 int k; for (k = i + 1; k < n; k++) if (m[j] == p[k]) break;
 if (k > max) { max = k; opt = j; }
 }
 m[opt] = p[i]; pf++;
 }
 }
 printf("Total Page Faults = %d\nPage Fault Rate = %.2f%%\n", pf, (float)pf / n * 100);
 return 0;
}
