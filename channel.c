/*
 * channel.c
 *
 *  Created on: Dec 20, 2011
 *      Author: ParallelsWin7
 */

#include "channel.h"

/*////////////////////////////////////////////////////////////////////////
////////////              CHANNEL CONSTRUCTORS             ///////////////
////////////////////////////////////////////////////////////////////////*/

//Configure a channel with basic properties (initialize EQs and Comp)
void Channel_ctor(Channel *chan, uint8_t chan_num, char* name, Active_enum active, Io_enum io) {
    chan-> chan_num = chan_num;
    
    //copy name into Channel struct then add end of line char to end
    strncpy(chan->name, name, 16);
    chan->name[16] = '\0';
    
    chan->io = io;
    chan->active = active;
    
    comp_ctor(&(chan->comp), DISABLED, 0.0, 2.0, 20, 100, 0.0);
    eqband_ctor(&(chan->eq_bands[0]), 1, DISABLED, HPF, 80.0, 2.0, 0.0);
    eqband_ctor(&(chan->eq_bands[1]), 2, DISABLED, BPF, 1000.0, 2.0, 0.0);
    eqband_ctor(&(chan->eq_bands[2]), 3, DISABLED, BPF, 4000.0, 2.0, 0.0);
    eqband_ctor(&(chan->eq_bands[3]), 4, DISABLED, LPF, 10000.0, 2.0, 0.0);
}

/*////////////////////////////////////////////////////////////////////////
////////////                CHANNEL GETTERS                ///////////////
////////////////////////////////////////////////////////////////////////*/

//Get channel name
char* channel_get_name(Channel *chan) {
    return (chan->name);
}

//Return Active_enum type channel active status
Active_enum channel_is_active(Channel *chan) {
    return chan->active;
}

//Get channel IO status
Io_enum channel_get_io(Channel *chan) {
    return chan->io;
}

//Get channel number
uint8_t channel_get_chan_num(Channel *chan) {
    return chan->chan_num;
}

//Get pointer to an eqband given by parameter
EqBand* channel_get_eqband(Channel *chan, uint8_t chan_num) {
    return &(chan->eq_bands[chan_num-1]);
}

//Get pointer to channel compressor
Comp* channel_get_comp(Channel *chan) {
    return &(chan->comp);
}

/*////////////////////////////////////////////////////////////////////////
////////////                CHANNEL SETTERS                ///////////////
////////////////////////////////////////////////////////////////////////*/

//Set the name of a channel
void channel_set_name(Channel *chan, char* name) {
    strncpy(chan->name, name, 16);
    chan->name[16] = '\0';
}

//Make the channel active
void channel_set_active(Channel *chan) {
    chan->active = ACTIVE;
}

//Make the channel inactive
void channel_set_inactive(Channel *chan) {
    chan->active = INACTIVE;
}

//Set the channel's IO status to INPUT or OUTPUT
void channel_set_io(Channel *chan, Io_enum io) {
    chan->io = io;
}

//Set the channel number on a channel (number should be >= 1)
void channel_set_chan_num(Channel *chan, uint8_t chan_num) {
    chan->chan_num = chan_num;
}

/*////////////////////////////////////////////////////////////////////////
////////////           CHANNEL INSPECTION TOOLS            ///////////////
////////////////////////////////////////////////////////////////////////*/

void channel_inspect_basic(Channel *chan) {
    printf("channel name: %s\n", chan->name); 
    printf("active: %d\n", chan->active);
    printf("io status: %d\n", chan->io);
    printf("channel number: %d\n\n", chan->chan_num);
}

void channel_inspect_full(Channel *chan) {
    channel_inspect_basic(chan);
    
    eqband_inspect(&(chan->eq_bands[0]));
    eqband_inspect(&(chan->eq_bands[1]));
    eqband_inspect(&(chan->eq_bands[2]));
    eqband_inspect(&(chan->eq_bands[3]));    
    
    comp_inspect(&(chan->comp));
    printf("END OF CHANNEL %d \n\n\n", chan->chan_num);
}