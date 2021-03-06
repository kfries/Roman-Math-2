#include <stdint.h>
#include <stdlib.h>
#include <check.h>

#include "RomanNumberMath.h"

/*******************************************************************************
 * Create Data Structure to Represent a Roman Digit                            *
 ******************************************************************************/

/************** Create Data Structure to Represent a Roman Digit **************/
START_TEST(create_data_structure_to_represent_a_roman_digit) {
   RomanDigit rd = {'I', 1};

   ck_assert(rd.Symbol == 'I');
   ck_assert_int_eq(rd.Value, 1);
} END_TEST

/******** Character of "i" or "I" should have symbol "I" and value of 1 *******/
START_TEST(initialize_roman_digit_with_i_or_I_returns_symbol_I_value_1) {
   RomanDigit rd1 = newRomanDigit('i');
   RomanDigit rd2 = newRomanDigit('I');

   ck_assert(rd1.Symbol == 'I');
   ck_assert(rd2.Symbol == 'I');
   ck_assert_int_eq(rd1.Value, 1);
   ck_assert_int_eq(rd2.Value, 1);
} END_TEST

/******** Character of "v" or "V" should have symbol "V" and value of 5 *******/
START_TEST(initialize_roman_digit_with_v_or_V_returns_symbol_V_value_5) {
   RomanDigit rd1 = newRomanDigit('v');
   RomanDigit rd2 = newRomanDigit('V');

   ck_assert(rd1.Symbol == 'V');
   ck_assert(rd2.Symbol == 'V');
   ck_assert_int_eq(rd1.Value, 5);
   ck_assert_int_eq(rd2.Value, 5);
} END_TEST

/******** Character of "x" or "X" should have symbol "X" and value of 10 ******/
START_TEST(initialize_roman_digit_with_x_or_X_returns_symbol_X_value_10) {
   RomanDigit rd1 = newRomanDigit('x');
   RomanDigit rd2 = newRomanDigit('X');

   ck_assert(rd1.Symbol == 'X');
   ck_assert(rd2.Symbol == 'X');
   ck_assert_int_eq(rd1.Value, 10);
   ck_assert_int_eq(rd2.Value, 10);
} END_TEST

/******** Character of "l" or "L" should have symbol "L" and value of 50 ******/
START_TEST(initialize_roman_digit_with_l_or_L_returns_symbol_L_value_50) {
   RomanDigit rd1 = newRomanDigit('l');
   RomanDigit rd2 = newRomanDigit('L');

   ck_assert(rd1.Symbol == 'L');
   ck_assert(rd2.Symbol == 'L');
   ck_assert_int_eq(rd1.Value, 50);
   ck_assert_int_eq(rd2.Value, 50);
} END_TEST

/******* Character of "c" or "C" should have symbol "C" and value of 100 ******/
START_TEST(initialize_roman_digit_with_c_or_C_returns_symbol_C_value_100) {
   RomanDigit rd1 = newRomanDigit('c');
   RomanDigit rd2 = newRomanDigit('C');

   ck_assert(rd1.Symbol == 'C');
   ck_assert(rd2.Symbol == 'C');
   ck_assert_int_eq(rd1.Value, 100);
   ck_assert_int_eq(rd2.Value, 100);
} END_TEST

/******* Character of "d" or "D" should have symbol "D" and value of 500 ******/
START_TEST(initialize_roman_digit_with_d_or_D_returns_symbol_D_value_500) {
   RomanDigit rd1 = newRomanDigit('d');
   RomanDigit rd2 = newRomanDigit('D');

   ck_assert(rd1.Symbol == 'D');
   ck_assert(rd2.Symbol == 'D');
   ck_assert_int_eq(rd1.Value, 500);
   ck_assert_int_eq(rd2.Value, 500);
} END_TEST

/****** Character of "m" or "M" should have symbol "M" and value of 1000 ******/
START_TEST(initialize_roman_digit_with_m_or_M_returns_symbol_M_value_1000) {
   RomanDigit rd1 = newRomanDigit('m');
   RomanDigit rd2 = newRomanDigit('M');

   ck_assert(rd1.Symbol == 'M');
   ck_assert(rd2.Symbol == 'M');
   ck_assert_int_eq(rd1.Value, 1000);
   ck_assert_int_eq(rd2.Value, 1000);
} END_TEST

/*********** Test to insure values other than IVXLCD or M will fail ***********/
START_TEST(initialize_roman_digit_with_invalid_value_returns_symbol_Null_value_0) {
   RomanDigit rd1 = newRomanDigit('A');

   ck_assert(rd1.Symbol == 'N');
   ck_assert_int_eq(rd1.Value, 0);
} END_TEST

/*******************************************************************************
 * Create Data Structure to Represent a Roman Number                           *
 ******************************************************************************/

/************** Create Data Structure to Represent a Roman Number *************/
START_TEST(create_data_structure_to_represent_a_roman_number) {
   RomanDigit rd = newRomanDigit('M');
   RomanNumber rn;
  
   rn.Size = 1;
   rn.Digit[0] = rd;

   ck_assert_int_eq(rn.Size, 1);
   ck_assert(rn.Digit[0].Symbol == 'M');
   ck_assert_int_eq(rn.Digit[0].Value, 1000);
} END_TEST

/***** Initialize a simple value then check the structure that comes back *****/
START_TEST(initialize_roman_number_with_a_simple_single_digit_value) {
   RomanNumber rn = newRomanNumber("I");

   ck_assert_int_eq(rn.Size, 1);
   ck_assert(rn.Digit[0].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[0].Value, 1);
} END_TEST

/**** Initialize a two-digit value then check the structure that comes back ***/
START_TEST(initialize_roman_number_with_a_simple_two_digit_value) {
   RomanNumber rn = newRomanNumber("VI");

   ck_assert_int_eq(rn.Size, 2);
   ck_assert(rn.Digit[0].Symbol == 'V');
   ck_assert_int_eq(rn.Digit[0].Value, 5);
   ck_assert(rn.Digit[1].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[1].Value, 1);
} END_TEST

/***************** Initialize a value with subtractive digits *****************/
START_TEST(initialize_a_value_with_subtractive_digits) {
   RomanNumber rn = newRomanNumber("XIX");

   ck_assert_int_eq(rn.Size, 3);

   ck_assert(rn.Digit[0].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[0].Value, 10);

   ck_assert(rn.Digit[1].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[1].Value, -1);

   ck_assert(rn.Digit[2].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[2].Value, 10);
} END_TEST

/********************** Initialize a Complex Number Value *********************/
START_TEST(initialize_a_value_with_complex_structure) {
   RomanNumber rn = newRomanNumber("MCMXCIX");

   ck_assert_int_eq(rn.Size, 7);

   ck_assert(rn.Digit[0].Symbol == 'M');
   ck_assert_int_eq(rn.Digit[0].Value, 1000);

   ck_assert(rn.Digit[1].Symbol == 'C');
   ck_assert_int_eq(rn.Digit[1].Value, -100);

   ck_assert(rn.Digit[2].Symbol == 'M');
   ck_assert_int_eq(rn.Digit[2].Value, 1000);

   ck_assert(rn.Digit[3].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[3].Value, -10);

   ck_assert(rn.Digit[4].Symbol == 'C');
   ck_assert_int_eq(rn.Digit[4].Value, 100);

   ck_assert(rn.Digit[5].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[5].Value, -1);

   ck_assert(rn.Digit[6].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[6].Value, 10);
} END_TEST

/*******************************************************************************
 * Create a "toInt" function to return value of a Roman Number                 *
 ******************************************************************************/

/********* Create a "toInt" function to return value of a Roman Number ********/
START_TEST(roman_numberal_to_a_function) {
   RomanNumber rn = newRomanNumber("iiiiiii");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 7);
} END_TEST

/******** Create a number from the string "I" -> toInt should return 1 ********/
START_TEST(roman_number_I_should_have_value_1) {
   RomanNumber rn = newRomanNumber("I");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 1);
} END_TEST

/******** Create a number from the string "VI" -> toInt should return 6 *******/
START_TEST(roman_number_VI_should_have_value_6) {
   RomanNumber rn = newRomanNumber("VI");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 6);
} END_TEST

/******* Create a number from the string "XIX" -> toInt should return 19 ******/
START_TEST(roman_number_XIX_should_have_value_19) {
   RomanNumber rn = newRomanNumber("XIX");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 19);
} END_TEST

/**** Create a number from the string "MCMXCIX" -> toInt should return 1999 ***/
START_TEST(roman_number_MCMXCIX_should_have_value_1999) {
   RomanNumber rn = newRomanNumber("MCMXCIX");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 1999);
} END_TEST

/*******************************************************************************
 * Create a "toString" function to return the the string form of Roman Number  *
 ******************************************************************************/

/* Create a "toString" function to return the the string form of Roman Number */
START_TEST(roman_numberal_to_string_function) {
   RomanNumber rn = newRomanNumber("iiiiiii");

   ck_assert_str_eq("IIIIIII", to_string(rn));
} END_TEST

/*************** Testing "to_string()" with single digit value ****************/
START_TEST(roman_numberal_to_string_single_digit) {
   ck_assert_str_eq("I", to_string(newRomanNumber("i")));
} END_TEST

/**************** Testing "to_string()" with multi-digit value ****************/
START_TEST(roman_numberal_to_string_multi_digit) {
   ck_assert_str_eq("VI", to_string(newRomanNumber("vi")));
} END_TEST

/*********** Testing "to_string()" with subtractive notation value ************/
START_TEST(roman_numberal_to_string_with_subtractive_notation) {
   ck_assert_str_eq("XIX", to_string(newRomanNumber("xix")));
} END_TEST

/****************** Testing "to_string()" with complex value ******************/
START_TEST(roman_numberal_to_string_with_complex_value) {
   ck_assert_str_eq("MCMXCIX", to_string(newRomanNumber("mcmxcix")));
} END_TEST

/*******************************************************************************
 * Substitute for any subtractives in value                                    *
 ******************************************************************************/

/******* Create a function to rewrite value into additive only notation *******/
START_TEST(substitute_for_any_subtractives_in_value) {
   RomanNumber rn = newRomanNumber("MDCLXVI");
   char *before, *after;

   before = to_string(rn);
   rnRemoveSubtractive(&rn);
   after = to_string(rn);

   ck_assert_str_eq(before, after);
} END_TEST

/*** A single digit can not be out of order, so it should not change value ****/
START_TEST(substitute_for_any_subtractives_single_digit_value) {
   RomanNumber rn = newRomanNumber("I");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("I", to_string(rn));
} END_TEST

/* Testing a simple number consisting of only a single value needing conversion */
START_TEST(substitute_for_any_subtractives_simple_subtractive_value) {
   RomanNumber rn = newRomanNumber("IV");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("IIII", to_string(rn));
} END_TEST

/********* Testing Remove Subtractive with static and changing values *********/
/** Also testing subtractive value two values above subtractor instead of one */
START_TEST(substitute_for_any_subtractives_with_changing_and_nonchanging_values) {
   RomanNumber rn = newRomanNumber("XIX");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("XVIIII", to_string(rn));
} END_TEST

/*************** Testing Remove Subtractive with complex value ****************/
START_TEST(substitute_for_any_subtractives_complex_subtractive_value) {
   RomanNumber rn = newRomanNumber("MCMXCIX");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("MDCCCCLXXXXVIIII", to_string(rn));
} END_TEST

/*******************************************************************************
 * Concatinate digits of two values into one new one                           *
 ******************************************************************************/

/******** Create a function to create one value from the digits of two ********/
START_TEST(concatinate_all_the_digits_of_two_numbers_into_a_new_value) {
   RomanNumber rnFirst = newRomanNumber("MDC");
   RomanNumber rnSecond = newRomanNumber("LXVI");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("MDCLXVI", to_string(concat));
} END_TEST

/********************** Combine two single digit values ***********************/
START_TEST(concatinate_all_the_digits_two_single_digit_values) {
   RomanNumber rnFirst = newRomanNumber("I");
   RomanNumber rnSecond = newRomanNumber("I");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("II", to_string(concat));
} END_TEST

/***************** Combine a single digit to multiple digits ******************/
START_TEST(concatinate_all_the_digits_of_a_single_and_double_digit_value) {
   RomanNumber rnFirst = newRomanNumber("I");
   RomanNumber rnSecond = newRomanNumber("VI");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("IVI", to_string(concat));
} END_TEST

/************* Concatenate single digit to non-standardized value *************/
START_TEST(concatinate_all_the_digits_of_a_single_and_nonstandard_value) {
   RomanNumber rnFirst = newRomanNumber("I");
   RomanNumber rnSecond = newRomanNumber("XVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("IXVIIII", to_string(concat));
} END_TEST

/***** Concatenate multi-digit value to a non-standardized complex value ******/
START_TEST(concatinate_all_the_digits_of_a_multidigit_and_complex_value) {
   RomanNumber rnFirst = newRomanNumber("VI");
   RomanNumber rnSecond = newRomanNumber("MDCCCCLXXXXVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("VIMDCCCCLXXXXVIIII", to_string(concat));
} END_TEST

/****************** Concatenate two non-standardized numbers ******************/
START_TEST(concatinate_all_the_digits_of_two_nonstandard_values) {
   RomanNumber rnFirst = newRomanNumber("XVIIII");
   RomanNumber rnSecond = newRomanNumber("XVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("XVIIIIXVIIII", to_string(concat));
} END_TEST

/************** Concatenate multi-digit value to a complex value **************/
START_TEST(concatinate_all_the_digits_of_two_complex_values) {
   RomanNumber rnFirst = newRomanNumber("MDCCCCLXXXXVIIII");
   RomanNumber rnSecond = newRomanNumber("MDCCCCLXXXXVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("MDCCCCLXXXXVIIIIMDCCCCLXXXXVIIII", to_string(concat));
} END_TEST

/*******************************************************************************
 * Sort the symbols in order from highest-to-lowest                            *
 ******************************************************************************/

/************** Sort the symbols in order from highest-to-lowest **************/
START_TEST(create_function_to_sort_digits_highest_to_lowest) {
   RomanNumber rn = newRomanNumber("I");

   rnSort(&rn);
   ck_assert_str_eq("I", to_string(rn));
} END_TEST

/************** Sort Test: Sorted values should return themself ***************/
START_TEST(sort_test_already_sorted_values_return_themselves) {
   RomanNumber rn = newRomanNumber("II");

   rnSort(&rn);

   ck_assert_str_eq("II", to_string(rn));
} END_TEST

/************************ Sort Test: Sort simple values ***********************/
START_TEST(sort_test_small_simple_value) {
   RomanNumber rn = newRomanNumber("IVI");

   rnSort(&rn);

   ck_assert_str_eq("VII", to_string(rn));
} END_TEST

/************* Sort Test: Sort Resulting in a non-standard value **************/
START_TEST(sort_test_resulting_in_non_standard_value) {
   RomanNumber rn = newRomanNumber("IXVIIII");

   rnSort(&rn);

   ck_assert_str_eq("XVIIIII", to_string(rn));
} END_TEST

/**************** Sort Test: Sort Multiple Values Out-Of-Order ****************/
START_TEST(sort_test_multiple_digits_out_of_order) {
   RomanNumber rn = newRomanNumber("VIXVIIII");

   rnSort(&rn);

   ck_assert_str_eq("XVVIIIII", to_string(rn));
} END_TEST

/*********************** Sort Test: Sort Complex Values ***********************/
START_TEST(sort_test_complex_values) {
   RomanNumber rn = newRomanNumber("MDCCCCLXXXXVIIIIMDCCCCLXXXXVIIII");

   rnSort(&rn);

   ck_assert_str_eq("MMDDCCCCCCCCLLXXXXXXXXVVIIIIIIII", to_string(rn));
} END_TEST

/*******************************************************************************
 * Combine like digits into larger digits where possible                       *
 ******************************************************************************/

/********* Create function to combine like digits into larger digits **********/
START_TEST(consolidate_like_digits_function) {
   RomanNumber rn = newRomanNumber("MDCLXVI");

   rnConsolidate(&rn);

   ck_assert_str_eq("MDCLXVI", to_string(rn));
} END_TEST

/************** Consolidation: Five I should be written as One V **************/
START_TEST(consolidate_five_i_to_v) {
   RomanNumber rn = newRomanNumber("IIIII");

   rnConsolidate(&rn);

   ck_assert_str_eq("V", to_string(rn));
} END_TEST

/*************** Consolidation: Two V should be written as One X **************/
START_TEST(consolidate_two_v_to_x) {
   RomanNumber rn = newRomanNumber("VV");

   rnConsolidate(&rn);

   ck_assert_str_eq("X", to_string(rn));
} END_TEST

/************** Consolidation: Five X should be written as One L **************/
START_TEST(consolidate_five_x_to_l) {
   RomanNumber rn = newRomanNumber("XXXXX");

   rnConsolidate(&rn);

   ck_assert_str_eq("L", to_string(rn));
} END_TEST

/*************** Consolidation: Two L should be written as One C **************/
START_TEST(consolidate_two_l_to_c) {
   RomanNumber rn = newRomanNumber("LL");

   rnConsolidate(&rn);

   ck_assert_str_eq("C", to_string(rn));
} END_TEST

/************** Consolidation: Five C should be written as One D **************/
START_TEST(consolidate_five_c_to_d) {
   RomanNumber rn = newRomanNumber("CCCCC");

   rnConsolidate(&rn);

   ck_assert_str_eq("D", to_string(rn));
} END_TEST

/*************** Consolidation: Two D should be written as One M **************/
START_TEST(consolidate_two_d_to_m) {
   RomanNumber rn = newRomanNumber("DD");

   rnConsolidate(&rn);

   ck_assert_str_eq("M", to_string(rn));
} END_TEST

/********* Consolidate a complex number with a several consolidations *********/
START_TEST(consolidate_complex_number) {
   RomanNumber rn = newRomanNumber("MMDDCCCCCCCCLLXXXXXXXXVVIIIIIIII");

   rnConsolidate(&rn);

   ck_assert_str_eq("MMMDCCCCLXXXXVIII", to_string(rn));
} END_TEST

/*******************************************************************************
 * Combine like digits into larger digits where possible                       *
 ******************************************************************************/

/******* Create a function to rewrite digits using Subtractive Notation *******/
START_TEST(create_function_to_rewrite_in_subtractive_notation) {
   RomanNumber rn = newRomanNumber("MDCLXVI");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("MDCLXVI", to_string(rn));
} END_TEST

/*********** Reintroduce Subtractive: VIIII should be written as IX ***********/
START_TEST(reintroduce_subtractive_viiii_should_be_ix) {
   RomanNumber rn = newRomanNumber("VIIII");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("IX", to_string(rn));
} END_TEST

/*********** Reintroduce Subtractive: IIII should be written as IV ************/
START_TEST(reintroduce_subtractive_iiii_should_be_iv) {
   RomanNumber rn = newRomanNumber("IIII");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("IV", to_string(rn));
} END_TEST

/*********** Reintroduce Subtractive: XXXX should be written as XL ************/
START_TEST(reintroduce_subtractive_xxxx_should_be_xl) {
   RomanNumber rn = newRomanNumber("XXXX");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("XL", to_string(rn));
} END_TEST

/*********** Reintroduce Subtractive: LXXXX should be written as XC ***********/
START_TEST(reintroduce_subtractive_lxxxx_should_be_xc) {
   RomanNumber rn = newRomanNumber("LXXXX");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("XC", to_string(rn));
} END_TEST

/*********** Reintroduce Subtractive: CCCC should be written as CD ************/
START_TEST(reintroduce_subtractive_cccc_should_be_cd) {
   RomanNumber rn = newRomanNumber("CCCC");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("CD", to_string(rn));
} END_TEST

/*********** Reintroduce Subtractive: DCCCC should be written as CM ***********/
START_TEST(reintroduce_subtractive_dcccc_should_be_cm) {
   RomanNumber rn = newRomanNumber("DCCCC");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("CM", to_string(rn));
} END_TEST

/************* Test a complex number with multiple substitutions **************/
START_TEST(reintroduce_subtractive_complex_number) {
   RomanNumber rn = newRomanNumber("MMMDCCCCLXXXXVIII");

   rnRewriteSubtractive(&rn);

   ck_assert_str_eq("MMMCMXCVIII", to_string(rn));
} END_TEST

/*******************************************************************************
 * Use above API to add two roman numbers                                      *
 ******************************************************************************/

/******************** Test Add Function, start simple 1+1=2 *******************/
START_TEST(create_function_to_add_two_numbers) {
   RomanNumber rn1 = newRomanNumber("I");
   RomanNumber rn2 = newRomanNumber("I");

   RomanNumber sum = rnAdd(rn1, rn2);

   ck_assert_str_eq("II",  to_string(sum));
   ck_assert_int_eq(2, to_a(sum));
} END_TEST

/**************** Test Add Function, using larger digits, 5+2=7 ***************/
START_TEST(test_add_function_with_simple_math_5_plus_2_equals_7) {
   RomanNumber rn1 = newRomanNumber("V");
   RomanNumber rn2 = newRomanNumber("II");

   RomanNumber sum = rnAdd(rn1, rn2);

   ck_assert_str_eq("VII",  to_string(sum));
   ck_assert_int_eq(7, to_a(sum));
} END_TEST

/*** Test Add Function, using two digit numbers that require simplification ***/
START_TEST(test_add_function_with_moderately_complex_numbers_15_plus_17_equals_32) {
   RomanNumber rn1 = newRomanNumber("XV");
   RomanNumber rn2 = newRomanNumber("XVII");

   RomanNumber sum = rnAdd(rn1, rn2);

   ck_assert_str_eq("XXXII",  to_string(sum));
   ck_assert_int_eq(32, to_a(sum));
} END_TEST

/***** Test Add Function with triple digit numbers, exercising full suite *****/
START_TEST(test_add_function_with_complex_numbers_143_plus_352_equals_495) {
   RomanNumber rn1 = newRomanNumber("CXLIII");
   RomanNumber rn2 = newRomanNumber("CCCLII");

   RomanNumber sum = rnAdd(rn1, rn2);

   ck_assert_str_eq("CDXCV",  to_string(sum));
   ck_assert_int_eq(495, to_a(sum));
} END_TEST

/*******************************************************************************
 * Cancel Redundant digits between two values                                  *
 ******************************************************************************/

/******** Create a function to eliminate duplicated between two values ********/
START_TEST(create_function_to_erase_duplicate_digits_between_two_values) {
   RomanNumber rn1 = newRomanNumber("MDCL");
   RomanNumber rn2 = newRomanNumber("XVI");

   rnEliminateDuplicates(&rn1, &rn2);

   ck_assert_str_eq("MDCL",  to_string(rn1));
   ck_assert_str_eq("XVI",  to_string(rn2));
} END_TEST

/******** Test Elimination of Duplicates when both values are the same ********/
START_TEST(test_eleminate_duplictes_where_both_values_are_the_same) {
   RomanNumber rn1 = newRomanNumber("II");
   RomanNumber rn2 = newRomanNumber("II");

   rnEliminateDuplicates(&rn1, &rn2);

   ck_assert_str_eq("",  to_string(rn1));
   ck_assert_str_eq("",  to_string(rn2));
} END_TEST

/** Second value contains only digits that are duplicated in the First Value **/
START_TEST(test_eleminate_duplictes_where_second_is_subset_of_first) {
   RomanNumber rn1 = newRomanNumber("XVII");
   RomanNumber rn2 = newRomanNumber("VI");

   rnEliminateDuplicates(&rn1, &rn2);

   ck_assert_str_eq("XI",  to_string(rn1));
   ck_assert_str_eq("",  to_string(rn2));
} END_TEST

/* Some of the values in the Second Value exit in the First but not all of them */
START_TEST(test_eleminate_duplictes_where_only_some_of_second_digits_exist_in_first) {
   RomanNumber rn1 = newRomanNumber("LXI");
   RomanNumber rn2 = newRomanNumber("LVI");

   rnEliminateDuplicates(&rn1, &rn2);

   ck_assert_str_eq("X",  to_string(rn1));
   ck_assert_str_eq("V",  to_string(rn2));
} END_TEST

/********** None of the values in the Second value exist in the First *********/
START_TEST(test_eleminate_duplictes_where_no_digits_are_in_common) {
   RomanNumber rn1 = newRomanNumber("LX");
   RomanNumber rn2 = newRomanNumber("VI");

   rnEliminateDuplicates(&rn1, &rn2);

   ck_assert_str_eq("LX",  to_string(rn1));
   ck_assert_str_eq("VI",  to_string(rn2));
} END_TEST

/*******************************************************************************
 * Breakdown one digit in the first value, that is larger than the largest in  *
 * the second value                                                            *
 ******************************************************************************/

/* Create function to break down digit in first value larger than largest digit in second value */
START_TEST(create_function_to_breakdown_digit) {
   RomanNumber rn1 = newRomanNumber("MDCL");
   RomanNumber rn2 = newRomanNumber("XVI");

   rnBreakdownDigit(&rn1, &rn2);

   ck_assert_str_eq("MDCXXXXX",  to_string(rn1));
   ck_assert_str_eq("XVI",  to_string(rn2));
} END_TEST

/********** First Value has digit one greater than largest in Second **********/
START_TEST(create_function_to_breakdown_digit_first_has_digit_one_larger) {
   RomanNumber rn1 = newRomanNumber("LX");
   RomanNumber rn2 = newRomanNumber("VI");

   rnBreakdownDigit(&rn1, &rn2);

   ck_assert_str_eq("LVV",  to_string(rn1));
   ck_assert_str_eq("VI",  to_string(rn2));
} END_TEST

/******* First Value has digit multi levels above the largest in Second *******/
START_TEST(create_function_to_breakdown_digit_first_has_digit_multiple_levels_higher) {
   RomanNumber rn1 = newRomanNumber("L");
   RomanNumber rn2 = newRomanNumber("VI");

   rnBreakdownDigit(&rn1, &rn2);

   ck_assert_str_eq("XXXXX",  to_string(rn1));
   ck_assert_str_eq("VI",  to_string(rn2));
} END_TEST


/*******************************************************************************
 * Use above API to subtract two roman numbers                                 *
 ******************************************************************************/

/******************** Test Subtract Function, start simple 2-1=1 *******************/
START_TEST(create_function_to_subtract_two_numbers) {
   RomanNumber rn1 = newRomanNumber("II");
   RomanNumber rn2 = newRomanNumber("I");

   RomanNumber difference = rnSubtract(rn1, rn2);

   ck_assert_str_eq("I",  to_string(difference));
   ck_assert_int_eq(1, to_a(difference));
} END_TEST

/******************** Test Subtract Function, start simple 10-5=5 *******************/
START_TEST(subtraction_10_minus_5_equals_5) {
   RomanNumber rn1 = newRomanNumber("X");
   RomanNumber rn2 = newRomanNumber("V");

   RomanNumber difference = rnSubtract(rn1, rn2);

   ck_assert_str_eq("V",  to_string(difference));
   ck_assert_int_eq(5, to_a(difference));
} END_TEST

/******************** Test Subtract Function, start simple 10-1=9 *******************/
START_TEST(subtraction_10_minus_1_equals_9_subtractive_result) {
   RomanNumber rn1 = newRomanNumber("X");
   RomanNumber rn2 = newRomanNumber("I");

   RomanNumber difference = rnSubtract(rn1, rn2);

   ck_assert_str_eq("IX",  to_string(difference));
   ck_assert_int_eq(9, to_a(difference));
} END_TEST

/********************** Test Subtract Function, complex results *********************/
START_TEST(subtraction_complex_result) {
   RomanNumber rn1 = newRomanNumber("CL");
   RomanNumber rn2 = newRomanNumber("LX");

   RomanNumber difference = rnSubtract(rn1, rn2);

   ck_assert_str_eq("XC",  to_string(difference));
   ck_assert_int_eq(90, to_a(difference));
} END_TEST

Suite * roman_number_math_suite(void) {
   Suite *testSuite;
   TCase *tc_roman_digit, *tc_roman_number, *tc_debug, *tc_remove_sub, *tc_concat, *tc_sort, *tc_consolidate;
   TCase *tc_add_sub_not, *tc_add, *tc_dups, *tc_breakdown, *tc_subtract;

   testSuite = suite_create("Roman Math 2");

   /* Testing Creating of Roman Digits */
   tc_roman_digit = tcase_create("Roman Digits");

   tcase_add_test(tc_roman_digit, create_data_structure_to_represent_a_roman_digit);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_i_or_I_returns_symbol_I_value_1);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_v_or_V_returns_symbol_V_value_5);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_x_or_X_returns_symbol_X_value_10);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_l_or_L_returns_symbol_L_value_50);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_c_or_C_returns_symbol_C_value_100);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_d_or_D_returns_symbol_D_value_500);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_m_or_M_returns_symbol_M_value_1000);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_invalid_value_returns_symbol_Null_value_0);

   suite_add_tcase(testSuite, tc_roman_digit);

   /* Testing Creating of Roman Digits */
   tc_roman_number = tcase_create("Roman Numbers");

   tcase_add_test(tc_roman_number, create_data_structure_to_represent_a_roman_number);
   tcase_add_test(tc_roman_number, initialize_roman_number_with_a_simple_single_digit_value);
   tcase_add_test(tc_roman_number, initialize_roman_number_with_a_simple_two_digit_value);
   tcase_add_test(tc_roman_number, initialize_a_value_with_subtractive_digits);
   tcase_add_test(tc_roman_number, initialize_a_value_with_complex_structure);

   suite_add_tcase(testSuite, tc_roman_number);

   /* Testing Debug/Display functions */
   tc_debug = tcase_create("Debug");

   tcase_add_test(tc_debug, roman_numberal_to_a_function);
   tcase_add_test(tc_debug, roman_number_I_should_have_value_1);
   tcase_add_test(tc_debug, roman_number_VI_should_have_value_6);
   tcase_add_test(tc_debug, roman_number_XIX_should_have_value_19);
   tcase_add_test(tc_debug, roman_number_MCMXCIX_should_have_value_1999);

   tcase_add_test(tc_debug, roman_numberal_to_string_function);
   tcase_add_test(tc_debug, roman_numberal_to_string_single_digit);
   tcase_add_test(tc_debug, roman_numberal_to_string_multi_digit);
   tcase_add_test(tc_debug, roman_numberal_to_string_with_subtractive_notation);
   tcase_add_test(tc_debug, roman_numberal_to_string_with_complex_value);

   suite_add_tcase(testSuite, tc_debug);

   /* Testing functions that remove subtractive notation */
   tc_remove_sub = tcase_create("Remove Subtractive Notation");

   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_in_value);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_single_digit_value);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_simple_subtractive_value);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_with_changing_and_nonchanging_values);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_complex_subtractive_value);
   
   suite_add_tcase(testSuite, tc_remove_sub);

   /* Testing functions that concatinate two values*/
   tc_concat = tcase_create("Concatinate Two Values");

   tcase_add_test(tc_concat, concatinate_all_the_digits_of_two_numbers_into_a_new_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_two_single_digit_values);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_a_single_and_double_digit_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_a_single_and_nonstandard_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_a_multidigit_and_complex_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_two_nonstandard_values);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_two_complex_values);

   suite_add_tcase(testSuite, tc_concat);

   /* Testing functions to sort the digits*/
   tc_sort = tcase_create("Sort Digits");

   tcase_add_test(tc_sort, create_function_to_sort_digits_highest_to_lowest);
   tcase_add_test(tc_sort, sort_test_already_sorted_values_return_themselves);
   tcase_add_test(tc_sort, sort_test_small_simple_value);
   tcase_add_test(tc_sort, sort_test_resulting_in_non_standard_value);
   tcase_add_test(tc_sort, sort_test_multiple_digits_out_of_order);
   tcase_add_test(tc_sort, sort_test_complex_values);

   suite_add_tcase(testSuite, tc_sort);

   /* Testing functions to consolidate like digits*/
   tc_consolidate = tcase_create("Sort Digits");

   tcase_add_test(tc_consolidate, consolidate_like_digits_function);
   tcase_add_test(tc_consolidate, consolidate_five_i_to_v);
   tcase_add_test(tc_consolidate, consolidate_two_v_to_x);
   tcase_add_test(tc_consolidate, consolidate_five_x_to_l);
   tcase_add_test(tc_consolidate, consolidate_two_l_to_c);
   tcase_add_test(tc_consolidate, consolidate_five_c_to_d);
   tcase_add_test(tc_consolidate, consolidate_two_d_to_m);
   tcase_add_test(tc_consolidate, consolidate_complex_number);

   suite_add_tcase(testSuite, tc_consolidate);

   /* Testing functions to rewrite the number using subtractive notation*/
   tc_add_sub_not = tcase_create("Rewrite With Subractive Notation");

   tcase_add_test(tc_add_sub_not, create_function_to_rewrite_in_subtractive_notation);
   tcase_add_test(tc_add_sub_not, reintroduce_subtractive_viiii_should_be_ix);
   tcase_add_test(tc_add_sub_not, reintroduce_subtractive_iiii_should_be_iv);
   tcase_add_test(tc_add_sub_not, reintroduce_subtractive_xxxx_should_be_xl);
   tcase_add_test(tc_add_sub_not, reintroduce_subtractive_lxxxx_should_be_xc);
   tcase_add_test(tc_add_sub_not, reintroduce_subtractive_cccc_should_be_cd);
   tcase_add_test(tc_add_sub_not, reintroduce_subtractive_dcccc_should_be_cm);
   tcase_add_test(tc_add_sub_not, reintroduce_subtractive_complex_number);

   suite_add_tcase(testSuite, tc_add_sub_not);

   /* Testing functions to rewrite the number using subtractive notation*/
   tc_add = tcase_create("Rewrite With Subractive Notation");

   tcase_add_test(tc_add, create_function_to_add_two_numbers);
   tcase_add_test(tc_add, test_add_function_with_simple_math_5_plus_2_equals_7);
   tcase_add_test(tc_add, test_add_function_with_moderately_complex_numbers_15_plus_17_equals_32);
   tcase_add_test(tc_add, test_add_function_with_complex_numbers_143_plus_352_equals_495);

   suite_add_tcase(testSuite, tc_add);

   /* Remove duplicate values between two different values */
   tc_dups = tcase_create("Rewrite With Subractive Notation");

   tcase_add_test(tc_dups, create_function_to_erase_duplicate_digits_between_two_values);
   tcase_add_test(tc_dups, test_eleminate_duplictes_where_both_values_are_the_same);
   tcase_add_test(tc_dups, test_eleminate_duplictes_where_second_is_subset_of_first);
   tcase_add_test(tc_dups, test_eleminate_duplictes_where_only_some_of_second_digits_exist_in_first);
   tcase_add_test(tc_dups, test_eleminate_duplictes_where_no_digits_are_in_common);

   suite_add_tcase(testSuite, tc_dups);

   /* Remove duplicate values between two different values */
   tc_breakdown = tcase_create("Rewrite With Subractive Notation");

   tcase_add_test(tc_breakdown, create_function_to_breakdown_digit);
   tcase_add_test(tc_breakdown, create_function_to_breakdown_digit_first_has_digit_one_larger);
   tcase_add_test(tc_breakdown, create_function_to_breakdown_digit_first_has_digit_multiple_levels_higher);

   suite_add_tcase(testSuite, tc_breakdown);

   /* Subtraction */
   tc_subtract = tcase_create("Rewrite With Subractive Notation");

   tcase_add_test(tc_subtract, create_function_to_subtract_two_numbers);
   tcase_add_test(tc_subtract, subtraction_10_minus_5_equals_5);
   tcase_add_test(tc_subtract, subtraction_10_minus_1_equals_9_subtractive_result);
   tcase_add_test(tc_subtract, subtraction_complex_result);

   suite_add_tcase(testSuite, tc_subtract);

   return testSuite;
}

int main(int argc, char *argv[]) {
   int number_failed;
   Suite *testSuite;
   SRunner *suiteRunner;

   testSuite = roman_number_math_suite();
   suiteRunner = srunner_create(testSuite);

   srunner_run_all(suiteRunner, CK_NORMAL);
   number_failed = srunner_ntests_failed(suiteRunner);
   srunner_free(suiteRunner);
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

