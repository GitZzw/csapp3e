/*
 * CS:APP Data Lab
 *
 * <zzw>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {

  // 排除同为0和同为1
  // 同为0 ~x&~y  同为1 x&y
  // 排除 取反再与即可
  return ~(~x&~y)&~(x&y);
}
/*
 * tmin - return minimum two's complement integer
   *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 0x0001<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    //Tmax 01111111
    int i = x+1;//Tmin,10000000...
    x=x+i;//-1,0xffffffff
    x=~x;//0,0x00000000
    i=!i;//exclude x=0xffffffff
    x=x+i;
    return !x;
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int i = 0xAAAAAAAA
  //(x&i)=i
  return ~((x&i)^i);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    int sign = 0x01<<31;
    //~0x39 + 1 = -0x39
    //~0x30 + 1 = -0x30
    int upperBound = sign&(~0x39+x+1); //当x>0x39该值为0 当x<=0x39该值为Tmin
    int lowerBound = sign&(~(~0x30+x+1)); //当x<0x30该值为0 当x>=0x30该值为Tmin
    upperBound = upperBound>>31; //-1
    lowerBound = lowerBound>>31; //-1
    return (upperBound+2)&(lowerBound+2); //-1+2=1
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  sign = 0x1;
  add = 0xfffffffe
  //sign&x = 1 or 0
  x2 = ((sign&x)+add) >> 31 //x=11111... or x=000000...
  return (x2 & y) | (~x2 & z);
}
int conditional(int x, int y, int z) {
  x = !!x;
  x = ~x+1;
  // x = 0 时全变为0000....
  // x = 1 时全变为1111....
  return (x&y)|(~x&z);
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // y > 0 & x > 0；y > 0 & x < 0；y < 0 & x > 0;y < 0 & x < 0
  // y>=x : ~x+y+1>=0
  // y<x : ~x+y+1<0
  res = (~x + y + 1)>>31;
  one = 0x01;
  return one+res;
}
//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  //除了0之外其他数或自己相反数最高位(符号位)肯定为1
  return ((x|(~x+1))>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
 int howManyBits(int x) {
   //如果是一个正数，则需要找到它最高的一位（假设是n）是1的，再加上符号位，结果为n+1；
   //如果是一个负数，则需要知道其最高的一位是0的
   //例如4位的1101和三位的101补码表示的是一个值：-3，最少需要3位来表示。
   int b16,b8,b4,b2,b1,b0;
   int sign=x>>31;
   x = (sign&~x)|(~sign&x);
   //如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）
   // 不断缩小范围
   b16 = !!(x>>16)<<4;//高十六位是否有1 <<4表示乘16   b16 = 0 or 16
   x = x>>b16;//如果有（至少需要16位），则将原数右移16位
   b8 = !!(x>>8)<<3;//剩余位高8位是否有1
   x = x>>b8;//如果有（至少需要16+8=24位），则右移8位
   b4 = !!(x>>4)<<2;//同理
   x = x>>b4;
   b2 = !!(x>>2)<<1;
   x = x>>b2;
   b1 = !!(x>>1);
   x = x>>b1;
   b0 = x;
   return b16+b8+b4+b2+b1+b0+1;//+1表示加上符号位
 }
//float
/*求2乘一个浮点数(unsigned表示)
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int exp = (uf&0x7f800000)>>23; //uf&0x7f800000
  int sign = uf&(1<<31);
  if(exp==0) return uf<<1|sign; //exp = 0乘以2
  if(exp==255) return uf; //exp = infinity 返回原数
  exp++;  //乘以2
  if(exp==255) return 0x7f800000|sign; //如果乘以二溢出 返回 无穷大
  return (exp<<23)|(uf&0x807fffff); //返回乘以2
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int exp = (uf&0x7f800000)>>23 - 127; //指数的真实位数
  int sign = uf&0x80000000; //符号位
  if(!(uf&0x7fffffff)) return 0; //如果指数位和fruc位全为0 返回0
  if(exp >= 31) return 0x80000000; //如果指数位数大于等于31位(int 一共32位，第一位符号位，指数大于31则溢出)
  if(exp < 0 ) return 0; //如果指数位小于0，则所有数小于1，取整为0
  //其他情况
  int frac = uf&0x007fffff|0x00800000; //加上隐含1
  if(exp>23) frac = frac << (exp-23); //将小数转化为整数
  else frac = frac >> (23-exp);

  if(!sign) return frac; //如果为正直接返回
  return ~frac+1;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
 //求2的x次方
unsigned floatPower2(int x) {
  int INF = 0xff<<23; //+INF
  int exp = x + 127; //exp为实际+127
  if(exp <= 0) return 0;
  if(exp >= 255) return INF;
  return exp << 23; //移到exp位置即为2的次方
  }
}
