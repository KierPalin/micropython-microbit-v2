// Autogenerated C header file for Magnetometer
#ifndef _JACDAC_SPEC_MAGNETOMETER_H
#define _JACDAC_SPEC_MAGNETOMETER_H 1

#define JD_SERVICE_CLASS_MAGNETOMETER  0x13029088

/**
 * Indicates the current magnetic field on magnetometer.
 * For reference: `1 mgauss` is `100 nT` (and `1 gauss` is `100 000 nT`).
 */
#define JD_MAGNETOMETER_REG_FORCES JD_REG_READING
typedef struct jd_magnetometer_forces {
    int32_t x; // nT
    int32_t y; // nT
    int32_t z; // nT
} jd_magnetometer_forces_t;


/**
 * Read-only nT int32_t. Absolute estimated error on the readings.
 */
#define JD_MAGNETOMETER_REG_FORCES_ERROR JD_REG_READING_ERROR

/**
 * No args. Forces a calibration sequence where the user/device
 * might have to rotate to be calibrated.
 */
#define JD_MAGNETOMETER_CMD_CALIBRATE JD_CMD_CALIBRATE

#endif
