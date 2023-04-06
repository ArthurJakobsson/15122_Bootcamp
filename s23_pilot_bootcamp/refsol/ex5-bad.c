#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "lib/contracts.h"

/**
 * @file ex5.c
 * @brief Example (5) demonstrating contracts and test cases (TA example)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * This is a BUGGY implementation.
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
 * @brief creates a pixel based on given argb values
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
 * - blue   remove top 4 bits
 */

/** 
 * @brief updates alpha value based on rules 
 * @param pix pixel to be updated
 * @return updated alpha value in position
 * TODO: fix the bugs in this function, if any
 */
int new_alpha_in_position(pixel pix)
{
    int mask = 0xFF;
    int alpha_val = ((int)pix >> 24) & mask;
    //
    int result = (alpha_val + 1) << 24;
    return result;
}

/** 
 * @brief updates red value based on rules 
 * @param pix pixel to be updated
 * @return updated red value in position
 * TODO: fix the bugs in this function, if any
 */
int new_red_in_position(pixel pix)
{
    int mask = 0x0F;
    int red_val = ((int)pix) & (mask << 16);
    return red_val;
}

/** 
 * @brief updates green value based on rules 
 * @param pix pixel to be updated
 * @return updated green value in position
 * TODO: fix the bugs in this function, if any
 */
int new_green_in_position(pixel pix)
{
    int mask = 0xFF;
    int green_val = ((int)pix) & (mask << 8);
    //divide by two
    return (green_val >> 1);
}

/** 
 * @brief updates blue value based on rules 
 * @param pix pixel to be updated
 * @return updated blue value in position
 * TODO: fix the bugs in this function, if any
 */
int new_blue_in_position(pixel pix)
{
    int mask = 0xF0;
    int blue_val = ((int)pix) & mask;
    return blue_val;
}

/** 
 * @brief remixes pixel based on given rules
 * @param pix pixel to be remixed
 * @return remixed pixel
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
    printf("bleh\n");
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
 * @brief creates a pixel based on given argb values
 * @param a alpha value
 * @param r red value
 * @param g green value
 * @param b blue value
 * @return pixel pixel created
 */
pixel create_pixel(int a, int r, int g, int b)
{
    return (pixel) (a << 24 | r << 16 | g << 8 | b);
}
