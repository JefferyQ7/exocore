#include "exocore/console.h"
#include "exocore/interrupts.h"
#include "exocore/io.h"
#include "exocore/pit.h"
#include "exocore/timer.h"

static ui64 current_ticks;

void initialize_pit(void)
{
    INFO("Initializing interrupt timer... ");

    // Firstly, register our timer callback.
    set_interrupt_handler(INTERRUPT_IRQ_TIMER, ^(const interrupt_info_t* const info attr(unused))
    {
        current_ticks++;
    });

    // The PIT operates at 315/265 MHz. The value we send it is the value
    // it should divide its input clock (approximately 1193182 Hz) by. The
    // value we send must fit in 16 bits.
    const ui32 divisor = 1193182 / TIMER_FREQUENCY;

    // Send the command byte.
    io_write_ui8(PIT_COMMAND_MODE, 0x36);
    io_wait();

    // Divisor has to be sent byte-wise, so split it into upper/lower bytes.
    const ui8 low = divisor & 0xff;
    const ui8 high = (divisor >> 8) & 0xff;

    // Send the frequency divisor.
    io_write_ui8(PIT_CHANNEL_0_DATA, low);
    io_wait();
    io_write_ui8(PIT_CHANNEL_0_DATA, high);
    io_wait();

    SUCCESS("OK.\n");
}

ui64 get_ticks(void)
{
    return current_ticks;
}
