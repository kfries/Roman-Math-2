#include <stdint.h>

#ifndef __ROMAN_MATH_2_H_
#define __ROMAN_MATH_2_H_

typedef struct {
   char Symbol;
   int Value;
   int NextValue;
} RomanDigit;

typedef struct {
   int Size;
   RomanDigit Digit[100];
} RomanNumber;

RomanDigit newRomanDigit(char);
RomanNumber newRomanNumber(char *);

uint32_t to_a(RomanNumber);
char *to_string(RomanNumber);

void rnRemoveSubtractive(RomanNumber *);
RomanNumber rnConcatinate(RomanNumber, RomanNumber);
void rnSort(RomanNumber *);
void rnConsolidate(RomanNumber *);

#endif
