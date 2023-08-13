// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ------- //
// encoder //
// ------- //

#define encoder_wrap_target 0
#define encoder_wrap 31

static const uint16_t encoder_program_instructions[] = {
            //     .wrap_target
    0x0010, //  0: jmp    16
    0x0016, //  1: jmp    22
    0x0018, //  2: jmp    24
    0x0010, //  3: jmp    16
    0x0018, //  4: jmp    24
    0x0010, //  5: jmp    16
    0x0010, //  6: jmp    16
    0x0016, //  7: jmp    22
    0x0016, //  8: jmp    22
    0x0010, //  9: jmp    16
    0x0010, // 10: jmp    16
    0x0018, // 11: jmp    24
    0x0010, // 12: jmp    16
    0x0018, // 13: jmp    24
    0x0016, // 14: jmp    22
    0x0010, // 15: jmp    16
    0xa0e6, // 16: mov    osr, isr
    0xa0c1, // 17: mov    isr, x
    0x8000, // 18: push   noblock
    0x60c2, // 19: out    isr, 2
    0x4002, // 20: in     pins, 2
    0xa0a6, // 21: mov    pc, isr
    0x0057, // 22: jmp    x--, 23
    0x0010, // 23: jmp    16
    0xa029, // 24: mov    x, !x
    0x005a, // 25: jmp    x--, 26
    0xa029, // 26: mov    x, !x
    0x0010, // 27: jmp    16
    0x0010, // 28: jmp    16
    0x0010, // 29: jmp    16
    0x0010, // 30: jmp    16
    0x0010, // 31: jmp    16
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program encoder_program = {
    .instructions = encoder_program_instructions,
    .length = 32,
    .origin = 0,
};

static inline pio_sm_config encoder_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + encoder_wrap_target, offset + encoder_wrap);
    return c;
}

static inline void encoder_program_init(PIO pio, uint sm, uint offset, uint base_pin) {
    pio_sm_config c = encoder_program_get_default_config(offset);
    sm_config_set_in_pins(&c, base_pin);
    sm_config_set_in_shift(&c, false, false, 32);
    sm_config_set_out_shift(&c, true, false, 32);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

#endif