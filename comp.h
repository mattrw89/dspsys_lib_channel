/*
 * comp.h
 *
 *  Created on: Dec 20, 2011
 *      Author: ParallelsWin7
 */

#ifndef COMP_H_
#define COMP_H_
#include <stdint.h>
#include <float.h>
#include "common.h"

typedef struct Comp {
	Enable_enum enable;
	float threshold;
	float ratio;
	float attack;
	float release;
	float gain;
} Comp;


//Constructors
void comp_ctor(Comp *comp, Enable_enum enable, float threshold, float ratio,
               float attack, float release, float gain);

//Getters
uint8_t comp_is_enabled(Comp *comp);
float comp_get_threshold(Comp *comp);
float comp_get_ratio(Comp *comp);
float comp_get_attack(Comp *comp);
float comp_get_release(Comp *comp);
float comp_get_gain(Comp *comp);

//Setters
void comp_enable(Comp *comp);
void comp_disable(Comp *comp);
void comp_set_threshold(Comp *comp, float value);
void comp_set_ratio(Comp *comp, float value);
void comp_set_attack(Comp *comp, float value);
void comp_set_release(Comp *comp, float value);
void comp_set_gain(Comp *comp, float value);

//Inspect
void comp_inspect(Comp *comp);


#endif /* COMP_H_ */