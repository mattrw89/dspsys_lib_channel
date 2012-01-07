/*
 * channel.h
 *
 *  Created on: Dec 20, 2011
 *      Author: ParallelsWin7
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_
#include <stdint.h>
#include <string.h>
#include "APICommand.h"
#include "eq.h"
#include "comp.h"
#include "common.h"


typedef struct ChannelType {
	char name[17];
	Active_enum active;
	Io_enum io;
	uint8_t chan_num;
	EqBand eq_bands[4];
	Comp comp;
} Channel;

void Channel_ctor(Channel *chan, uint8_t chan_num, char* name, Active_enum active, Io_enum io);

//Getters

char* channel_get_name(Channel *chan);
Active_enum channel_is_active(Channel *chan);
Io_enum channel_get_io(Channel *chan);
uint8_t channel_get_chan_num(Channel *chan);
EqBand* channel_get_eqband(Channel *chan, uint8_t band_num);
Comp* channel_get_comp(Channel *chan);

//Setters

void channel_set_name(Channel *chan, char* name);
void channel_set_active(Channel *chan);
void channel_set_inactive(Channel *chan);
void channel_set_io(Channel *chan, Io_enum io);
void channel_set_chan_num(Channel *chan, uint8_t chan_num);

//Inspect

void channel_inspect_basic(Channel *chan);
void channel_inspect_full(Channel *chan);
#endif /* CHANNEL_H_ */
