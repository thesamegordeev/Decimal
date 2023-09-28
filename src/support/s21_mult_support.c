#include "../s21_decimal.h"

/**
 * @brief Функция умножает на 2 двоичное число посредством побитового сдвига
 * @param value Указатель на Decimal, мантисса которого будет сдвигаться
 * @return 0 - если умножение прошло успешно (старший бит мантиссы вначале не
 * был равен 1), 1 - в противном случае
 */
int s21_mult_2(s21_decimal* value) {
  int err = 0;
  if (s21_get_bit(*value, MANTISSA_LENGTH - 1) == 1) {
    err = 1;
  } else {
    s21_bits_shift_l(*value, value, 1);
  }
  return err;
}

/**
 * @brief Функция умножает на 10 двоичное число посредством побитового сдвига
 * @param value Указатель на Decimal, мантисса которого будет умножаться
 * @return 0 - если умножение прошло успешно (без переполнения), 1 - в противном
 * случае
 */
int s21_mult_10(s21_decimal* value) {
  int err = s21_mult_2(value);
  s21_decimal tmp = s21_copy_dec(*value);
  err += s21_mult_2(value);
  err += s21_mult_2(value);
  s21_sum_binary(*value, tmp, value);
  return err > 0;
}

void s21_decToArray(s21_decimal value, int* array, int size) {
  for (int i = 0; i < size - 96; i++) {
    array[i] = 0;
  }
  for (int i = size - 1; i >= size - 96; i--) {
    array[i] = s21_get_bit(value, size - 1 - i);
  }
}

void s21_decArrayShiftLeft(int* decArray) {
  for (int i = 0; i < 191; i++) {
    decArray[i] = decArray[i + 1];
  }
  decArray[191] = 0;
}

void s21_base10ShiftRight(int* decArray) {
  for (int i = 59; i > 0; i--) {
    decArray[i] = decArray[i - 1];
  }
  decArray[0] = 0;
}

void s21_base10ShiftLeft(int* decArray) {
  for (int i = 0; i < 59; i++) {
    decArray[i] = decArray[i + 1];
  }
  decArray[59] = 0;
}

void s21_decArraySimpleAdd(int* sum, int* toAdd) {
  int carry = 0;
  for (int i = 191; i >= 0; i--) {
    sum[i] += toAdd[i] + carry;
    carry = sum[i] / 2;
    sum[i] %= 2;
  }
}

void s21_reverseIntArray(int* array, int size) {
  for (int i = 0; i < size / 2; i++) {
    int temp = array[i];
    array[i] = array[size - 1 - i];
    array[size - 1 - i] = temp;
  }
}

void s21_binToDec(int* binArray, int* ret, int arrSize) {
  int size = 1;
  for (int i = 0; i < arrSize; i++) {
    for (int j = 0; j < size; j++) {
      ret[j] *= 2;
    }
    ret[0] += binArray[i];
    for (int j = 0; j < size; j++) {
      if (ret[j] > 9) {
        ret[j + 1] += ret[j] / 10;
        ret[j] %= 10;
        if (j == size - 1) size++;
      }
    }
  }
  s21_reverseIntArray(ret, 60);
}

int s21_base10truncate(int* base10arr, int scale, int sign) {
  int ret = 0;
  int digitCount = 0;
  int firstDigit = 0;
  for (; firstDigit < 60; firstDigit++) {
    if (base10arr[firstDigit] != 0) {
      digitCount = 60 - firstDigit;
      break;
    }
  }
  if (digitCount - scale >= 29) {
    if (digitCount - scale == 29) {
      if (s21_comparebase10WithMax(base10arr) == 1) {
        ret = (sign) ? AR_NEG_INF : AR_INF;
      }
    } else {
      ret = (sign) ? AR_NEG_INF : AR_INF;
    }
  }
  if (ret == 0) {
    if (digitCount > 29) {
      if (s21_comparebase10WithMax(base10arr) == 1) {
        s21_bankRound(base10arr, firstDigit + 27);
        for (int i = firstDigit + 27; i < 60; i++)
          s21_base10ShiftRight(base10arr);
      } else {
        s21_bankRound(base10arr, firstDigit + 28);
        for (int i = firstDigit + 28; i < 60; i++)
          s21_base10ShiftRight(base10arr);
      }
    }
  }
  return ret;
}

int s21_comparebase10WithMax(int* base10arr) {
  int ret = 0;
  int i = 0;
  while (i < 60 && base10arr[i] == 0) {
    i++;
  }
  char maxDec[] = "79228162514264337593543950335";
  for (int j = 0; j < 29; j++, i++) {
    if (base10arr[i] > maxDec[j] - '0') {
      ret = 1;
      break;
    } else if (base10arr[i] < maxDec[j] - '0') {
      ret = -1;
      break;
    }
  }
  return ret;
}

void s21_bankRound(int* base10arr, int digit) {
  int toRound = base10arr[digit + 1];
  if (toRound > 5) {
    base10arr[digit] += 1;
  } else if (toRound == 5) {
    if (base10arr[digit] % 2 == 1) {
      base10arr[digit] += 1;
    }
  }
  for (int i = digit + 1; i < 60; i++) {
    base10arr[i] = 0;
  }
}

void s21_base10normalize(int* resBase10, int* scale_result) {
  while (*scale_result > 29) {
    s21_base10ShiftRight(resBase10);
    (*scale_result)--;
  }
  if (*scale_result == 29) {
    s21_bankRound(resBase10, 58);
    s21_base10ShiftRight(resBase10);
    (*scale_result)--;
  }
  while (*scale_result < 0) {
    s21_base10ShiftLeft(resBase10);
    (*scale_result)++;
  }
}

void s21_base10ToDecimal(int* resBase10, int scale_result, int signRes,
                         s21_decimal* result) {
  s21_set_sign(result, signRes);
  s21_set_scale(result, scale_result);
  int firstDigit = 0;
  for (; firstDigit < 60; firstDigit++) {
    if (resBase10[firstDigit] != 0) break;
  }
  int binary[96] = {0};
  int bIndex = 0;
  while (firstDigit <= 59) {
    binary[bIndex] = resBase10[59] % 2;
    bIndex++;
    int carry = 0;
    for (int i = firstDigit; i < 60; i++) {
      int tmp = resBase10[i] % 2;
      resBase10[i] /= 2;
      if (carry) resBase10[i] += 5;
      carry = tmp;
    }
    if (resBase10[firstDigit] == 0) firstDigit++;
  }
  for (int i = 0; i < 96; i++) {
    s21_set_bit(result, i, binary[i]);
  }
}

int s21_signifLength(s21_decimal divisor) {
  int i = 95;
  for (; i >= 0; i--) {
    if (s21_get_bit(divisor, i)) break;
  }
  return i + 1;
}

void s21_fillString(int* string, int* value1, int dividend, int divisor) {
  if (dividend >= divisor) {
    for (int i = 95 - dividend + divisor; i > 95 - dividend; i--) {
      string[i + dividend - divisor + 1] = value1[i];
    }
  } else {
    for (int i = 95; i >= dividend; i--) {
      string[i + 1] = value1[i];
    }
  }
}

int s21_divBy2ToPow(int* res) {
  int ret = 0;
  for (int i = 191; i >= 0; i--) {
    if (res[i] == -1) {
      ret = 191 - i;
      for (; i >= 1; i--) {
        res[i] = res[i - 1];
      }
      break;
    }
  }
  return ret;
}

int s21_stringComp(int* left, int* right) {
  int ret = 0;
  for (int i = 0; i < 96; i++) {
    if (left[i + 1] > right[i]) {
      ret = 1;
      break;
    } else if (left[i + 1] < right[i]) {
      ret = -1;
      break;
    }
  }
  if (left[0] == 1) ret = 1;
  return ret;
}

void s21_appendString(int* string, int* value, int currPos) {
  for (int i = 0; i < 96; i++) {
    string[i] = string[i + 1];
  }
  if (currPos <= 95) {
    string[96] = value[currPos];
  } else {
    string[96] = 0;
  }
}

int s21_isEmpty(int* string) {
  int ret = 1;
  for (int i = 0; i < 97; i++) {
    if (string[i] == 1) {
      ret = 0;
      break;
    }
  }
  return ret;
}

void s21_decArraySimpleSub(int* string1, int* string2) {
  int carry = 0;
  for (int i = 96; i > 0; i--) {
    int tmp = string1[i] - string2[i - 1] - carry;
    if (tmp < 0) {
      carry = 1;
      string1[i] = tmp + 2;
    } else {
      string1[i] = tmp;
      carry = 0;
    }
  }
  string1[0] -= carry;
}

void s21_resLoop(int* res, int len) {
  for (int i = 191; i > 191 - len; i--) {
    res[i] = res[i - 192 + len];
  }
  for (int i = 0; i < 192 - len; i++) {
    res[i] = 0;
  }
}

void s21_divByPowerTwo(int* res, int pow, int* decPoint, int* length) {
  int signif = 0;
  for (int i = 0; i < 60; i++) {
    if (res[i] != 0) {
      signif = i;
      break;
    }
  }
  int len = 60 - signif;
  int resExpanded[120] = {0};
  for (int i = 0; signif + i < 60; i++) {
    resExpanded[i] = res[signif + i];
  }
  for (int i = 0; i < pow; i++) {
    int carry = 0;
    for (int j = 0; j < 120; j++) {
      int tmp = resExpanded[j] % 2;
      resExpanded[j] = resExpanded[j] / 2 + carry * 5;
      carry = tmp;
      if ((j == len - 1) && carry != 0) len++;
    }
  }
  int decpt = 59 - signif;
  int countStart = 0;
  for (int i = 0; i < 60; i++) res[i] = 0;
  for (int i = 0; i < 120; i++) {
    if (resExpanded[i] != 0 && countStart == 0) {
      countStart = 1;
      *decPoint = decpt - i;
    }
    if (countStart >= 1 && countStart <= 30) {
      res[countStart - 1] = resExpanded[i];
      countStart++;
    } else if (countStart > 30)
      break;
  }
  if (len > 30) len = 30;
  *length = len;
}
