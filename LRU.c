 #include <stdio.h>
 int main() {
 printf("Roll no: 25071A6238\n");
 int f, n, p[30], m[10], t[10] = {0}, pf = 0;
 printf("Enter number of frames and pages: "); scanf("%d %d", &f, &n);
 printf("Enter page reference string: "); for (int i = 0; i < n; i++) scanf("%d", &p[i]);
 for (int i = 0; i < f; i++) m[i] = -1;
 for (int i = 0; i < n; i++) {
 int hit = 0, lru = 0;
 for (int j = 0; j < f; j++) if (m[j] == p[i]) { hit = 1; t[j] = i + 1; }
 if (!hit) {
 for (int j = 1; j < f; j++) if (t[j] < t[lru]) lru = j;
 m[lru] = p[i]; t[lru] = i + 1; pf++;
 }
 }
 printf("Total Page Faults = %d\nPage Fault Rate = %.2f%%\n", pf, (float)pf / n * 100);
 return 0;
}
