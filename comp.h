/*
 * comp.c
 *
 *  Created on: Dec 20, 2011
 *      Author: ParallelsWin7
 */

#include "comp.h"

/*////////////////////////////////////////////////////////////////////////
////////////                COMP CONSTRUCTORS              ///////////////
////////////////////////////////////////////////////////////////////////*/

//Setup a compressor based on the input parameters
void comp_ctor(Comp *comp, Enable_enum enable, float threshold, float ratio,
               float attack, float release, float gain) {
    
    comp->enable = enable;
    comp->threshold = threshold;
    comp->ratio = ratio;
    comp->attack = attack;
    comp->release = release;
    comp->gain = gain;
}

/*/////////////////////////////////////////////////////////////////////////
////////////                   COMP GETTERS                  //////////////
/////////////////////////////////////////////////////////////////////////*/

//Returns 1 if enabled, 0 if disabled
uint8_t comp_is_enabled(Comp *comp) {
    return (int) comp->enable;
}

//Returns the threshold of the compressor
float comp_get_threshold(Comp *comp) {
    return comp->threshold;
}

//Returns the ratio of the compressor (Always greater than 1)
float comp_get_ratio(Comp *comp) {
    return comp->ratio;
}

//Returns attack time in milliseconds (Always greater than 0)
float comp_get_attack(Comp *comp) {
    return comp->attack;
}

//Returns release time in milliseconds (Always greater than 0)
float comp_get_release(Comp *comp) {
    return comp->release;
}

//Returns make-up gain
float comp_get_gain(Comp *comp) {
    return comp->gain;
}

/*/////////////////////////////////////////////////////////////////////////
////////////                   COMP SETTERS                  //////////////
/////////////////////////////////////////////////////////////////////////*/

//set comp to enable status
void comp_enable(Comp *comp) {
    comp->enable = ENABLED;
}

//set comp to disabled status
void comp_disable(Comp *comp) {
    comp->enable = DISABLED;
}

//set comp threshold
void comp_set_threshold(Comp *comp, float value) {
    comp->threshold = value;
}

//set comp ratio
void comp_set_ratio(Comp *comp, float value) {
    comp->ratio = value;
}

//set comp attack
void comp_set_attack(Comp *comp, float value) {
    comp->attack = value;
}

//set comp release
void comp_set_release(Comp *comp, float value) {
    comp->release = value;
}
//set comp gain
void comp_set_gain(Comp *comp, float value) {
    comp->gain = value;
}


/*/////////////////////////////////////////////////////////////////////////
////////////              COMP INSPECTION TOOLS              //////////////
/////////////////////////////////////////////////////////////////////////*/

void comp_inspect(Comp *comp) {
    printf("enable: %d\n", comp->enable);
    printf("threshold: %lf\n", comp->threshold);
    printf("ratio: %lf\n", comp->ratio);
    printf("attack: %lf\n", comp->attack);
    printf("release: %lf\n", comp->release);
    printf("gain: %lf\n\n", comp->gain);
}
