#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "lib/contracts.h"

/**
 * ex5-correct.c
 * Example (5) demonstrating contracts and test cases (TA example)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * This is a CORRECT implementation.
 *
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */

typedef int pixel; // NOTE the lack of a star (not a pointer)

/*
 * ---------------------------------------------------------------------------
 *                 SHORT HELPER FUNCTIONS (Defined in full below)
 * ---------------------------------------------------------------------------
 */

/** 
 * this function creates a pixel based on given argb values
 * takes in: a - alpha value; red - red value; g - green value; b - blue value
 * returns: pixel created
 * THIS IS A CORRECT FUNCTION
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
 * - blue:  remove top 4 bits
 */

/** 
 * this function updates alpha value based on rules 
 * takes in: pix - pixel to be updated
 * returns: updated alpha value in position
 * TODO: fix the bugs in this function, if any
 */
int new_alpha_in_position(pixel pix)
{
    int mask = 0xFF;
    int alpha_val = ((int)pix >> 24) & mask;
    if (alpha_val == mask) // add this "if"
    {
        return alpha_val << 24;
    }
    int result = (alpha_val + 1) << 24;
    return result;
}

/** 
 * this function updates red value based on rules 
 * takes in: pix - pixel to be updated
 * returns: updated red value in position
 * TODO: fix the bugs in this function, if any
 */
int new_red_in_position(pixel pix)
{
    int mask = 0x0F;
    int red_val = ((int)pix) & (mask << 16);
    return red_val;
}

/** 
 * this function updates green value based on rules 
 * takes in: pix - pixel to be updated
 * returns: updated green value in position
 * TODO: fix the bugs in this function, if any
 */
int new_green_in_position(pixel pix)
{
    int mask = 0xFF;
    int green_val = ((int)pix) & (mask << 8);
    // divide by two
    return (green_val >> 1) & (mask << 8); //add mask
}

/** 
 * this function updates blue value based on rules 
 * takes in: pix - pixel to be updated
 * returns: updated blue value in position
 * TODO: fix the bugs in this function, if any
 */
int new_blue_in_position(pixel pix)
{
    int mask = 0xF0;
    int blue_val = ((int)pix) & mask;
    return blue_val;
}

/** 
 * this function remixes pixel based on given rules
 * takes in: pix - pixel to be remixed
 * returns: remixed pixel
 * TODO: fix the bugs in the other functions above to ensure this one's correct
 */
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
    pixel test_1 = create_pixel(0xFF, 0xFF, 0xFF, 0xFF);
    assert((int)remix_pixel(test_1) == (int)0xFF0F7FF0);
    // should catch alpha
    pixel test_2 = create_pixel(0x78, 0x78, 0x78, 0x78);
    assert((int)remix_pixel(test_2) == (int)0x79083C70);
    // shouldn't catch anything
    pixel test_3 = create_pixel(0x7F, 0x7F, 0x7F, 0x7F);
    assert((int) remix_pixel(test_3) == (int)0x800F3F70);
    // should catch green
}

int main()
{
    test();
    return 0;
}

/*
 * ---------------------------------------------------------------------------
 *                 DON'T WORRY ABOUT ANYTHING BELOW HERE
 * ---------------------------------------------------------------------------
 */

/** 
 * this function creates a pixel based on given argb values
 * takes in: a - alpha value; red - red value; g - green value; b - blue value
 * returns: pixel created
 * THIS IS A CORRECT FUNCTION
 */
pixel create_pixel(int a, int r, int g, int b)
{
    return (pixel) (a << 24 | r << 16 | g << 8 | b);
}
