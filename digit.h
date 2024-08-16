#ifndef _DIGIT_H_
#define _DIGIT_H_ 1

/* UINT2 defines a two byte word */
typedef unsigned short int UINT2;

/* UINT4 defines a four byte word */
typedef unsigned int UINT4;

/* Define NN_DIGIT as a 4-byte (32-bit) word */
typedef UINT4 NN_DIGIT;

/* Define NN_HALF_DIGIT as a 2-byte (16-bit) word */
typedef UINT2 NN_HALF_DIGIT;

/* Constants.

   Note: MAX_NN_DIGITS is long enough to hold any RSA modulus, plus
   one more digit as required by R_GeneratePEMKeys (for n and phiN,
   whose lengths must be even). All natural numbers have at most
   MAX_NN_DIGITS digits, except for double-length intermediate values
   in NN_Mult (t), NN_ModMult (t), NN_ModInv (w), and NN_Div (c).
 */
/* Length of a digit in bits */
#define NN_DIGIT_BITS 32

/* Length of a half digit in bits */
#define NN_HALF_DIGIT_BITS 16

/* Length of a digit in bytes */
#define NN_DIGIT_LEN (NN_DIGIT_BITS / 8)

/* Maximum length in digits */
#define MAX_NN_DIGITS \
  ((MAX_RSA_MODULUS_LEN + NN_DIGIT_LEN - 1) / NN_DIGIT_LEN + 1)

/* Maximum value of a digit */
#define MAX_NN_DIGIT 0xffffffff

/* Maximum value of a half digit */
#define MAX_NN_HALF_DIGIT 0xffff

/* Macros for digit manipulation */

/* LOW_HALF returns the lower half of a digit */
#define LOW_HALF(x) ((x) & MAX_NN_HALF_DIGIT)

/* HIGH_HALF returns the upper half of a digit */
#define HIGH_HALF(x) (((x) >> NN_HALF_DIGIT_BITS) & MAX_NN_HALF_DIGIT)

/* TO_HIGH_HALF shifts a half digit to the higher half of a digit */
#define TO_HIGH_HALF(x) (((NN_DIGIT)(x)) << NN_HALF_DIGIT_BITS)

/* DIGIT_MSB returns the most significant bit of a digit */
#define DIGIT_MSB(x) (unsigned int)(((x) >> (NN_DIGIT_BITS - 1)) & 1)

/* DIGIT_2MSB returns the two most significant bits of a digit */
#define DIGIT_2MSB(x) (unsigned int)(((x) >> (NN_DIGIT_BITS - 2)) & 3)

#endif /* end _DIGIT_H_ */
