#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "contracts.h"

typedef uint32_t pixel; // NOTE the lack of a star (not a pointer)

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
pixel create_pixel(uint32_t a, uint32_t r, uint32_t g, uint32_t b);
