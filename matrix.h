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

#define max_num_input_channels 14
#define max_num_output_channels 10

typedef struct Matrix {
    Channel* channels_in[max_num_input_channels]; // input 1 starts at index 0
    Channel* channels_out[max_num_output_channels]; // output 1 starts at index 0
    uint8_t routing[max_num_output_channels]; // indexed by output channel # -1; 
        //uint8_t corresponds to input channel number (NOT input channel index)
    uint8_t num_input_channels;
    uint8_t num_output_channels;
} Matrix;


uint8_t matrix_get_max_num_input_channels();
uint8_t matrix_get_max_num_output_channels();

uint8_t matrix_get_num_input_channels(Matrix* matrix);

uint8_t matrix_get_num_output_channels(Matrix* matrix);

uint8_t* matrix_get_routing(Matrix* matrix);

void matrix_set_input_channels(Matrix* matrix, Channel* start, uint8_t num_channels);
void matrix_set_output_channels(Matrix* matrix, Channel* start, uint8_t num_channels);

void matrix_change_output_routing(Matrix* matrix, uint8_t channel_num_out, uint8_t channel_num_in);


#endif
