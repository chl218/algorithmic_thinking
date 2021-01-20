#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Not true prefix
int prefix_length(char s1[], char s2[]) {
   int i = 1;
   while (s1[i] == s2[i]) {
      i++;
   }
   return i - 1;
}

// Not true suffix
int suffix_length(char s1[], char s2[], int len) {
   int i = len;
   while (i >= 2 && s1[i] == s2[i - 1]) {
      i--;
   }
   return len - i;
}

#define SIZE 1000000

// Not a true spell check. Deletes a repeated letter
// This isn't a good problem
int main() {
   static char s1[SIZE + 1], s2[SIZE + 1];

   gets(&s1[1]);
   gets(&s2[1]);

   int len = strlen(&s1[1]);
   int prefix = prefix_length(s1, s2);
   int suffix = suffix_length(s1, s2, len);

   int total = (prefix + 1) - (len - suffix) + 1;
   if (total < 0) {
      total = 0;
   }
   printf("%d\n", total);

   for (int i = 0; i < total; i++) {
      printf("%d", i + len - suffix);
      if (i < total - 1) {
         printf(" ");
      } else {
         printf("\n");
      }
   }

   return 0;
}
