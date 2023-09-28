#include "../s21_decimal.h"

/**
 * @brief Делит два Decimal
 * @param value_1 Делимое decimal
 * @param value_2 Делитель decimal
 * @return Код ошибки при вычислении: 0 - ОК, 1 - Результат слишком велик или
 * равен бесконечности, 2 - Результат слишком мал или равен отрицательной
 * бесконечности, 3 - Деление на 0
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return -1;
  int err_indicator = AR_OK;
  *result = ZERO_DECIMAL;
  if (!s21_is_zero(value_2)) {
    err_indicator = 3;
  } else if (s21_is_zero(value_1)) {
    err_indicator = s21_functional_div(value_1, value_2, result);
  }
  return err_indicator;
}

int s21_functional_div(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result) {
  *result = ZERO_DECIMAL;
  s21_decimal tmp_1 = s21_copy_dec(value_1);
  s21_decimal tmp_2 = s21_copy_dec(value_2);
  s21_normalize_dec(&tmp_1);
  s21_normalize_dec(&tmp_2);
  int scale_1 = s21_get_scale(tmp_1), scale_2 = s21_get_scale(tmp_2);
  int scale_result = scale_1 - scale_2;
  int sign_1 = s21_get_sign(tmp_1), sign_2 = s21_get_sign(tmp_2);
  int signRes = sign_1 ^ sign_2;
  s21_set_sign(result, signRes);
  int err_indicator = AR_OK;
  int res[192] = {0};
  int value1[96] = {0};
  int value2[96] = {0};
  int currResLength = 0;
  int divisorLength = s21_signifLength(tmp_2);
  int dividendLength = s21_signifLength(tmp_1);
  s21_decToArray(tmp_1, value1, 96);
  s21_decToArray(tmp_2, value2, 96);
  int currString[97] = {0};
  s21_fillString(currString, value1, dividendLength, divisorLength);
  int currDividendPos = 95 - dividendLength + divisorLength + 1;
  if (currDividendPos >= 97) currDividendPos = 96;
  while (currResLength < 100 &&
         !(s21_isEmpty(currString) && currDividendPos > 95)) {
    while (s21_stringComp(currString, value2) == -1) {
      s21_appendString(currString, value1, currDividendPos);
      if (currDividendPos != 96) {
        res[currResLength] = 0;
        currResLength++;
      } else {
        res[currResLength] = 0;
        currResLength++;
        res[currResLength] = -1;
        currResLength++;
      }
      currDividendPos++;
    }
    s21_decArraySimpleSub(currString, value2);
    res[currResLength] = 1;
    currResLength++;
    if (currDividendPos == 96 && !s21_isEmpty(currString)) {
      s21_appendString(currString, value1, currDividendPos);
      currDividendPos++;
      res[currResLength] = -1;
      currResLength++;
    } else {
      s21_appendString(currString, value1, currDividendPos);
      currDividendPos++;
    }
    if (currDividendPos == 96 && s21_isEmpty(currString)) {
      res[currResLength] = 0;
      currResLength++;
    }
  }
  if (currResLength < 192) s21_resLoop(res, currResLength);
  int resBase10[60] = {0};
  int divBy = s21_divBy2ToPow(res);
  s21_binToDec(res, resBase10, 192);
  int decPoint = 0;
  int length = 0;
  s21_divByPowerTwo(resBase10, divBy, &decPoint, &length);
  for (int i = 59; i > 59 - length; i--) {
    resBase10[i] = resBase10[i - 60 + length];
  }
  for (int i = 0; i < 60 - length; i++) {
    resBase10[i] = 0;
  }
  scale_result -= (decPoint - length + 1);
  s21_base10normalize(resBase10, &scale_result);
  err_indicator = s21_base10truncate(resBase10, scale_result, signRes);
  if (!err_indicator) {
    s21_base10ToDecimal(resBase10, scale_result, signRes, result);
  }
  return err_indicator;
}
