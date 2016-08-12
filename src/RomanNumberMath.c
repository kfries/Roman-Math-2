#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "RomanNumberMath.h"

#define NUMDIGITS 7

RomanDigit allowedDigits[NUMDIGITS] = {
   {'I', 1,        5},
   {'V', 5,        2},
   {'X', 10,       5},
   {'L', 50,       2},
   {'C', 100,      5},
   {'D', 500,      2},
   {'M', 1000, 99999}
};

RomanDigit newRomanDigit(char c) {
   RomanDigit rd = {'N', 0};
   int idx;

   for (idx =  0; idx < NUMDIGITS; idx++) {
      if (allowedDigits[idx].Symbol == toupper(c)) {
         rd = allowedDigits[idx];
         break;
      }
   }

   return rd;
}

RomanNumber newRomanNumber(char *number) {
   RomanNumber returnValue;
   int idx;

   returnValue.Size = 0;
   for (idx = 0; number[idx] != '\0'; idx++) {
      RomanDigit rd = newRomanDigit(number[idx]);

      if (rd.Value == 0) {
         returnValue.Size = 0;
         returnValue.Digit[0] = rd;
         return returnValue;
      } else {
         returnValue.Digit[returnValue.Size] = rd;

         if (returnValue.Size > 0)
            if (returnValue.Digit[returnValue.Size].Value > returnValue.Digit[returnValue.Size-1].Value)
               returnValue.Digit[returnValue.Size-1].Value *= -1;

         returnValue.Size++;
      }
   }

   /* Add a Nulle Value on the end to embark zero value in calculations */
   returnValue.Digit[returnValue.Size].Symbol = 'N';
   returnValue.Digit[returnValue.Size].Value = 0;
   return returnValue;
}

uint32_t to_a(RomanNumber number) {
   uint32_t returnValue;
   int idx;

   returnValue = 0;
   for (idx = 0; idx < number.Size; idx++) {
      RomanDigit digit = number.Digit[idx];
      returnValue += digit.Value;
   }

   return returnValue;
}

char *to_string(RomanNumber number) {
   char *returnValue = (char *)malloc((number.Size+1) * sizeof(char));
   int idx;

   returnValue[number.Size] = '\0';
   for (idx = 0; idx < number.Size; idx++)
      returnValue[idx] = number.Digit[idx].Symbol;

   return returnValue;
}

void rnRemoveSubtractive(RomanNumber *number) {
   RomanNumber newValue;
   int idx, idx2, targetValue;

   newValue.Size = 0;
   for (idx = 0; idx < number->Size; idx++) {
      if (number->Digit[idx].Value > number->Digit[idx+1].Value) {
         newValue.Digit[newValue.Size++] = number->Digit[idx];
      } else {
         targetValue = number->Digit[idx+1].Value + number->Digit[idx].Value;

         for (idx2 = NUMDIGITS-1; idx2 >= 0; idx2--) {
            while (targetValue >= allowedDigits[idx2].Value) {
               newValue.Digit[newValue.Size++] = allowedDigits[idx2];
               targetValue -= allowedDigits[idx2].Value;
            }
         }

         idx++;
      }
   }

   number->Size = newValue.Size;
   for (idx = 0; idx < number->Size; idx++) number->Digit[idx] = newValue.Digit[idx];

   return;
}

RomanNumber rnConcatinate(RomanNumber first, RomanNumber second) {
   RomanNumber returnValue;
   int idx;


   returnValue.Size = first.Size + second.Size;

   for (idx = 0; idx < first.Size; idx++)
      returnValue.Digit[idx] = first.Digit[idx];

   for (idx = 0; idx < second.Size; idx++)
      returnValue.Digit[first.Size + idx] = second.Digit[idx];

   return returnValue;
}

int *getDigitFrequencyCounts(RomanNumber *number) {
   int *counts;
   int idx, idx2;

   counts = (int *)calloc(NUMDIGITS, sizeof(int));

   for (idx = 0; idx < NUMDIGITS; idx++)
      for (idx2 = 0; idx2 < number->Size; idx2++)
         if (allowedDigits[idx].Symbol == number->Digit[idx2].Symbol)
            counts[idx]++;

   return counts;
}

void rewriteNumberFromFrequencyCounts(RomanNumber *number, int *counts) {
   int idx;

   number->Size = 0;

   for (idx = (NUMDIGITS-1); idx >= 0; idx--)
      while (counts[idx] > 0) {
         number->Digit[number->Size++] = allowedDigits[idx];
         counts[idx]--;
      }

   return;
}

void rnSort(RomanNumber *number) {
   int *counts = getDigitFrequencyCounts(number);
   rewriteNumberFromFrequencyCounts(number, counts);

   return;
}

void rnConsolidate(RomanNumber *number) {
   int *counts = getDigitFrequencyCounts(number);
   int idx;

   for (idx = 0; idx < NUMDIGITS; idx++)
      while (counts[idx] >= allowedDigits[idx].NextValue) {
         counts[idx+1]++;
         counts[idx] -= allowedDigits[idx].NextValue;
      }

   rewriteNumberFromFrequencyCounts(number, counts);

   return;
}

void rnRewriteSubtractive(RomanNumber *number) {
   int *counts = getDigitFrequencyCounts(number);
   int subtractiveFlag[NUMDIGITS];
   int idx;

   for (idx = 0; idx < NUMDIGITS; idx++) subtractiveFlag[idx] = 0;

   for (idx = 2; idx < NUMDIGITS; idx += 2) {
      if ((counts[idx-2] >= (allowedDigits[idx-2].NextValue-1)) && (counts[idx-1] >= (allowedDigits[idx-1].NextValue-1))) {
         subtractiveFlag[idx] = 1;
         counts[idx-2] -= (allowedDigits[idx-2].NextValue-1);
         counts[idx-1] -= (allowedDigits[idx-1].NextValue-1);
      }
      
      if (counts[idx-2] >= (allowedDigits[idx-2].NextValue-1)) {
         subtractiveFlag[idx-1] = 1;
         counts[idx-2] -= (allowedDigits[idx-2].NextValue-1);
      }
   }

   number->Size = 0;

   for (idx = (NUMDIGITS-1); idx >= 0; idx--) {
      while (counts[idx] > 0) {
         number->Digit[number->Size++] = allowedDigits[idx];
         counts[idx]--;
      }

      if (subtractiveFlag[idx]) {
         RomanDigit digit = allowedDigits[idx];
         int modifierOffset = (idx % 2) == 0 ? 2 : 1;
         RomanDigit modifier = allowedDigits[idx-modifierOffset];
         modifier.Value *= -1;

         number->Digit[number->Size++] = modifier;
         number->Digit[number->Size++] = digit;
      }
   }

   return;
}

void rnEliminateDuplicates(RomanNumber *number1, RomanNumber *number2) {
   int *counts1 = getDigitFrequencyCounts(number1);
   int *counts2 = getDigitFrequencyCounts(number2);
   int idx;

   for (idx = 0; idx < NUMDIGITS; idx++) {
      int dups = counts1[idx] < counts2[idx] ? counts1[idx] : counts2[idx];
      counts1[idx] -= dups;
      counts2[idx] -= dups;
   }

   rewriteNumberFromFrequencyCounts(number1, counts1);
   rewriteNumberFromFrequencyCounts(number2, counts2);

   return;
}

void rnBreakdownDigit(RomanNumber *number1, RomanNumber *number2) {
   int *counts1 = getDigitFrequencyCounts(number1);
   int *counts2 = getDigitFrequencyCounts(number2);
   int idx;

   idx = NUMDIGITS;
   /* find largest digit in number2 */
   while (idx) {
      if (counts2[idx] > 0) break;
      idx--;
   }
   idx++;

   /* find next largest digit than that in number 1 */
   while (idx < NUMDIGITS) {
      if (counts1[idx] > 0) break;
      idx++;
   }

   counts1[idx]--;
   counts1[idx-1] += allowedDigits[idx-1].NextValue;

   rewriteNumberFromFrequencyCounts(number1, counts1);

   return;
}

RomanNumber rnAdd(RomanNumber number1, RomanNumber number2) {
   RomanNumber returnValue;

   rnRemoveSubtractive(&number1);
   rnRemoveSubtractive(&number2);

   returnValue = rnConcatinate(number1, number2);
   rnSort(&returnValue);
   rnConsolidate(&returnValue);
   rnRewriteSubtractive(&returnValue);

   return returnValue;
}

RomanNumber rnSubtract(RomanNumber number1, RomanNumber number2) {
   rnRemoveSubtractive(&number1);
   rnRemoveSubtractive(&number2);

   rnEliminateDuplicates(&number1, &number2);

   while (number2.Size > 0) {
      rnBreakdownDigit(&number1, &number2);
      rnEliminateDuplicates(&number1, &number2);
   }

   rnConsolidate(&number1);
   rnRewriteSubtractive(&number1);

   return number1;
}

