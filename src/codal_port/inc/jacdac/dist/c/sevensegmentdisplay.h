// Autogenerated C header file for 7-segment display
#ifndef _JACDAC_SPEC_SEVEN_SEGMENT_DISPLAY_H
#define _JACDAC_SPEC_SEVEN_SEGMENT_DISPLAY_H 1

#define JD_SERVICE_CLASS_SEVEN_SEGMENT_DISPLAY  0x196158f7

/**
 * Read-write bytes. Each byte encodes the display status of a digit using,
 * where lowest bit 0 encodes segment `A`, bit 1 encodes segments `B`, ..., bit 6 encodes segments `G`, and bit 7 encodes the decimal point (if present).
 * If incoming `digits` data is smaller than `digit_count`, the remaining digits will be cleared.
 * Thus, sending an empty `digits` payload clears the screen.
 */
#define JD_SEVEN_SEGMENT_DISPLAY_REG_DIGITS JD_REG_VALUE

/**
 * Read-write ratio u0.16 (uint16_t). Controls the brightness of the LEDs. `0` means off.
 */
#define JD_SEVEN_SEGMENT_DISPLAY_REG_BRIGHTNESS JD_REG_INTENSITY

/**
 * Read-write bool (uint8_t). Turn on or off the column LEDs (separating minutes from hours, etc.) in of the segment.
 * If the column LEDs is not supported, the value remains false.
 */
#define JD_SEVEN_SEGMENT_DISPLAY_REG_DOUBLE_DOTS 0x80

/**
 * Constant uint8_t. The number of digits available on the display.
 */
#define JD_SEVEN_SEGMENT_DISPLAY_REG_DIGIT_COUNT 0x180

/**
 * Constant bool (uint8_t). True if decimal points are available (on all digits).
 */
#define JD_SEVEN_SEGMENT_DISPLAY_REG_DECIMAL_POINT 0x181

/**
 * Argument: value f64 (uint64_t). Shows the number on the screen using the decimal dot if available.
 */
#define JD_SEVEN_SEGMENT_DISPLAY_CMD_SET_NUMBER 0x80

#endif
