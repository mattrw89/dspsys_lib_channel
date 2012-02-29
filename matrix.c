//
//  matrix.c
//  dspsys_xcode_dev
//
//  Created by Matt Webb on 2/6/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "matrix.h"

uint8_t matrix_get_max_num_input_channels() {
    return max_num_input_channels;
}
uint8_t matrix_get_max_num_output_channels() {
    return max_num_output_channels;
}

uint8_t matrix_get_num_input_channels(Matrix* matrix) {
    return matrix->num_input_channels;
}

uint8_t matrix_get_num_output_channels(Matrix* matrix) {
    return matrix->num_output_channels;
}

void matrix_set_input_channels(Matrix* matrix, Channel* start, uint8_t num_channels) {
    //set number of input channels to num_channels passed in
    matrix->num_input_channels = num_channels;
    
    Channel* temp = start;
    uint8_t i=0;
    for( i=0; i < num_channels; i++) {
        matrix->channels_in[i] = temp;
        temp += sizeof(Channel*);
    }
}


void matrix_set_output_channels(Matrix* matrix, Channel* start, uint8_t num_channels) {
    //set number of output channels to num_channels passed in
    matrix->num_output_channels = num_channels;
    
    Channel* temp = start;
    uint8_t i=0;
    for( i=0; i < num_channels; i++) {
        matrix->channels_out[i] = temp;
        temp += sizeof(Channel*);
    }
    
}


void matrix_change_output_routing(Matrix* matrix, uint8_t channel_num_out,
                                  uint8_t channel_num_in) {
    //get the previous input channel number
    uint8_t previous_input_number = matrix->routing[channel_num_out-1];
    //get a pointer to the previous input channel so you can make it inactive
    Channel* previous_input = matrix->channels_in[previous_input_number-1];
    //set output to now point to new input channel in memory
    matrix->routing[channel_num_out-1] = channel_num_in;
    
    //set previous input as INACTIVE
    channel_set_inactive(previous_input);
    
    //TODO: Add a change matrix command to the transmit SPI stack? 
}