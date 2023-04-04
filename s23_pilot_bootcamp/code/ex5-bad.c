#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @file ex5-bad.c
 * @brief Example (5) demonstrating contracts and test cases (TA example)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 *
 * This is a BUGGY implementation.
 *
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */


typedef int pixel; //NOTE the lack of a star (not a pointer)


/*
 * ---------------------------------------------------------------------------
 *                 SHORT HELPER FUNCTIONS (Defined in full below)
 * ---------------------------------------------------------------------------
 */

/**
 * @brief Don't worry about this, it's correct.
 *
 * @param a alpha value
 * @param r red value
 * @param g green value
 * @param b blue value
 * @return pixel pixel created
 */
pixel create_pixel(int a, int r, int g, int b);



/*
 * ---------------------------------------------------------------------------
 *                                   BUGS!
 * ---------------------------------------------------------------------------
 */

/**
 * RULES:
 * - alpha: add 1 unless it is max (max = 0xFF)
 * - red:   remove bottom 4 bits
 * - green: divide by two
 * - blue   remove top 4 bits
 */

int new_alpha_in_position(pixel pix)
{
  int mask = 0xFF;
  int alpha_val = ((int)pix>>24) & mask;
  //
  int result = (alpha_val + 1)<<24;
  return result;
}


int new_red_in_position(pixel pix)
{
  int mask = 0x0F;
  int red_val = ((int)pix) & (mask<<16);
  return red_val;
}

int new_green_in_position(pixel pix)
{
  int mask = 0xFF;
  int green_val = ((int)pix) & (mask<<8);
  //divide by two
  return (green_val>>1);
}

int new_blue_in_position(pixel pix)
{
  int mask = 0xF0;
  int blue_val = ((int)pix) & mask;
  return blue_val;
}

//We want to test this
pixel remix_pixel(pixel pix)
{
  int a = new_alpha_in_position(pix);
  int r = new_red_in_position(pix);
  int g = new_green_in_position(pix);
  int b = new_blue_in_position(pix);
  return a | r | g | b;
}

/*
 * ---------------------------------------------------------------------------
 *                                Test Cases
 * ---------------------------------------------------------------------------
 */


void test()
{
  printf("bleh\n");
}

int main()
{
  test();
  return 1;
}


/*
 * ---------------------------------------------------------------------------
 *                 DON'T WORRY ABOUT ANYTHING BELOW HERE
 * ---------------------------------------------------------------------------
 */


pixel create_pixel(int a, int r, int g, int b)
{
  return (pixel) (a<<24 | r<<16 | g << 8 | b);
}
