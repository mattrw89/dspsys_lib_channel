/*
 * eq.c
 *
 *  Created on: Dec 20, 2011
 *      Author: ParallelsWin7
 */

#include "eq.h"

/*////////////////////////////////////////////////////////////////////////
////////////                 EQ CONSTRUCTORS               ///////////////
////////////////////////////////////////////////////////////////////////*/

//setup an EQ band based on input parameters
void eqband_ctor(EqBand *eq, uint8_t band_num, Enable_enum enable, Eq_type_enum type,
                 float freq, float bw, float gain) {
    
    eq->band_num = band_num;
    eq->enable = enable;
    eq->type = type;
    eq->freq = freq;
    eq->bw = bw;
    eq->gain = gain;
}


/*/////////////////////////////////////////////////////////////////////////
////////////                    EQ GETTERS                   //////////////
/////////////////////////////////////////////////////////////////////////*/

//get the band number
uint8_t eqband_get_band_num(EqBand *eq) {
    return eq->band_num;
}

//check if EQ Band is enabled.  returns 0 for disabled, 1 for enabled
Enable_enum eqband_is_enabled(EqBand *eq) {
    return eq->enable;
}

//get EQ Band type. LPF, BPF, or HPF
Eq_type_enum eqband_get_type(EqBand *eq) {
    return eq->type;
}

//get EQ Band frequency
float eqband_get_freq(EqBand *eq) {
    return eq->freq;
}

//get EQ Band bandwidth
float eqband_get_bw(EqBand *eq) {
    return eq->bw;
}

//get EQ Band gain
float eqband_get_gain(EqBand *eq) {
    return eq->gain;
}

/*/////////////////////////////////////////////////////////////////////////
////////////                    EQ SETTERS                   //////////////
/////////////////////////////////////////////////////////////////////////*/

//set band number on an EQ Band
void eqband_set_band_num(EqBand *eq, uint8_t num) {
    eq->band_num = num;
}

//enable an EQ Band
void eqband_enable(EqBand *eq) {
    eq->enable = ENABLED;
}

//disable an EQ Band
void eqband_disable(EqBand *eq) {
    eq->enable = DISABLED;
}

//set EQ Band type
void eqband_set_type(EqBand *eq, Eq_type_enum type) {
    eq->type = type;
}

//set frequency on an EQ Band
void eqband_set_freq(EqBand *eq, float value) {
    eq->freq = value; 
}

//set bandwidth on an EQ Band
void eqband_set_bw(EqBand *eq, float value) {
    eq->bw = value;
}

//set gain on an EQ Band
void eqband_set_gain(EqBand *eq, float value) {
    eq->gain = value;
}

/*/////////////////////////////////////////////////////////////////////////
////////////               EQ INSPECTION TOOLS              ///////////////
/////////////////////////////////////////////////////////////////////////*/

void eqband_inspect(EqBand *eq) {
    printf("band_num: %d\n", eq->band_num);
    printf("enable: %d\n", eq->enable);
    printf("type: %d\n", eq->type);
    printf("frequency: %lf\n", eq->freq);
    printf("bandwidth: %lf\n", eq->bw);
    printf("gain: %lf\n\n", eq->gain);
}

