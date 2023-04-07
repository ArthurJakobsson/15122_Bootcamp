#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "lib/contracts.h"
#include "lib/ex5-helper.h"

/**
 * ex5.c
 * Example (5) demonstrating contracts and test cases (TA example)
 *
 * 15-122: Principles of Imperative Computation
 * Spring 2023 - Debugging in C Pilot Bootcamp
 *
 * This is a BUGGY implementation.
 *
 * @author Arthur Jakobsson <ajakobss@andrew.cmu.edu>
 * @author Liz Chu <echu2@andrew.cmu.edu>
 */

// typedef uint32_t pixel; // NOTE the lack of a star (not a pointer)
// note: defined in header file

/*
 * ---------------------------------------------------------------------------
 *                          SHORT HELPER FUNCTIONS
 * ---------------------------------------------------------------------------
 */

/**
 * this function creates a pixel based on given argb values
 * takes in: a - alpha value; red - red value; g - green value; b - blue value
 * returns: pixel created
 * THIS IS A CORRECT FUNCTION
 */
pixel create_pixel(uint32_t a, uint32_t r, uint32_t g, uint32_t b);

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
uint32_t new_alpha_in_position(pixel pix)
{
    uint32_t mask = 0xFF;
    uint32_t alpha_val = ((int)pix >> 24) & mask;

    uint32_t result = (alpha_val + 1) << 24;
    return result;
}

/**
 * this function updates red value based on rules
 * takes in: pix - pixel to be updated
 * returns: updated red value in position
 * TODO: fix the bugs in this function, if any
 */
uint32_t new_red_in_position(pixel pix)
{
    uint32_t mask = 0x0F;
    uint32_t red_val = ((int)pix) & (mask << 16);
    return red_val;
}

/**
 * this function updates green value based on rules
 * takes in: pix - pixel to be updated
 * returns: updated green value in position
 * TODO: fix the bugs in this function, if any
 */
uint32_t new_green_in_position(pixel pix)
{
    uint32_t mask = 0xFF;
    uint32_t green_val = ((int)pix) & (mask << 8);
    // divide by two
    return (green_val >> 1);
}

/**
 * this function updates blue value based on rules
 * takes in: pix - pixel to be updated
 * returns: updated blue value in position
 * TODO: fix the bugs in this function, if any
 */
uint32_t new_blue_in_position(pixel pix)
{
    uint32_t mask = 0xF0;
    uint32_t blue_val = ((int)pix) & mask;
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
    uint32_t a = new_alpha_in_position(pix);
    uint32_t r = new_red_in_position(pix);
    uint32_t g = new_green_in_position(pix);
    uint32_t b = new_blue_in_position(pix);
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
