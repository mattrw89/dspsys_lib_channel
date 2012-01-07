/*
 * common.h
 *
 *  Created on: Dec 20, 2011
 *      Author: ParallelsWin7
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>

typedef enum Enable_enum {
	DISABLED = 0,
	ENABLED = 1
} Enable_enum;

typedef enum Active_enum {
	INACTIVE = 0,
	ACTIVE   = 1
} Active_enum;

typedef enum Io_enum {
	INPUT = 0,
	OUTPUT = 1
} Io_enum;

typedef union {
    float value;
    char stored[4];
} CONVERTER;

#endif /* COMMON_H_ */
