#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "contracts.h"

typedef int pixel; // NOTE the lack of a star (not a pointer)

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
pixel create_pixel(int a, int r, int g, int b); 
