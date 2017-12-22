#ifndef _PIC8259_H
#define _PIC8259_H

#include <stdint.h>
#include <arch/io.h>


/* Location of Command and data ports for the Master/Slave PIC */
#define PIC8259_MASTER_CMD      0x20
#define PIC8259_MASTER_DATA     0x21

#define PIC8259_SLAVE_CMD       0xa0
#define PIC8259_SLAVE_DATA      0xa1

#define PIC8259_CMD_FLUSH_ISR   0x20
#define PIC8259_REG_IRR         0x0a
#define PIC8259_REG_ISR         0x0b


/* 
 * Apparently reading and writing to the PIC without regulation can introduce 
 * nasty latency bugs. So, we'll just create this inline to make sure we do not
 * run into such a problem 
 */
static inline uint8_t pic_inb(unsigned int port)
{
    uint8_t value = inb(port);
    //need io delay to PIC
    return value;
}


static inline void pic_outb(uint8_t value, unsigned int port)
{
    outb(value, port);
    //need io delay to PIC
}


void pic8259_mask_irq(unsigned int irq);
void pic8259_unmask_irq(unsigned int irq);
void pic8259_setmask(uint16_t mask);
uint16_t pic8259_getmask(void);
void pic8259_flush(void);


#endif /* _PIC8259_H */
