//
//  matrix.h
//  dspsys_xcode_dev
//
//  Created by Matt Webb on 2/6/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef dspsys_xcode_dev_matrix_h
#define dspsys_xcode_dev_matrix_h
#include <stdint.h>
#include "channel.h"

#define num_input_channels 14
#define num_output_channels 10

typedef struct Matrix {
    Channel* channels_in[num_input_channels];
    Channel* channels_out[num_output_channels];
    uint8_t routing[num_output_channels];
} Matrix;

#endif
