// Autogenerated C header file for bit:radio
#ifndef _JACDAC_SPEC_BIT_RADIO_H
#define _JACDAC_SPEC_BIT_RADIO_H 1

#define JD_SERVICE_CLASS_BIT_RADIO  0x1ac986cf

/**
 * Read-write bool (uint8_t). Turns on/off the radio antenna.
 */
#define JD_BIT_RADIO_REG_ENABLED JD_REG_INTENSITY

/**
 * Read-write uint8_t. Group used to filter packets
 */
#define JD_BIT_RADIO_REG_GROUP 0x80

/**
 * Read-write uint8_t. Antenna power to increase or decrease range.
 */
#define JD_BIT_RADIO_REG_TRANSMISSION_POWER 0x81

/**
 * Read-write uint8_t. Change the transmission and reception band of the radio to the given channel.
 */
#define JD_BIT_RADIO_REG_FREQUENCY_BAND 0x82

/**
 * Argument: message string (bytes). Sends a string payload as a radio message, maximum 18 characters.
 */
#define JD_BIT_RADIO_CMD_SEND_STRING 0x80

/**
 * Argument: value f64 (uint64_t). Sends a double precision number payload as a radio message
 */
#define JD_BIT_RADIO_CMD_SEND_NUMBER 0x81

/**
 * Sends a double precision number and a name payload as a radio message
 */
#define JD_BIT_RADIO_CMD_SEND_VALUE 0x82
typedef struct jd_bit_radio_send_value {
    double value;  // f64
    char name[0];  // string
} jd_bit_radio_send_value_t;


/**
 * Argument: data bytes. Sends a payload of bytes as a radio message
 */
#define JD_BIT_RADIO_CMD_SEND_BUFFER 0x83

/**
 * Raised when a string packet is received
 */
#define JD_BIT_RADIO_CMD_STRING_RECEIVED 0x90
typedef struct jd_bit_radio_string_received_report {
    uint32_t time; // ms
    uint32_t device_serial_number;
    int8_t rssi; // dB
    uint8_t padding;  // u8[1]
    char message[0];  // string
} jd_bit_radio_string_received_report_t;


/**
 * Raised when a number packet is received
 */
#define JD_BIT_RADIO_CMD_NUMBER_RECEIVED 0x91
typedef struct jd_bit_radio_number_received_report {
    uint32_t time; // ms
    uint32_t device_serial_number;
    int8_t rssi; // dB
    uint8_t padding[3];  // u8[3]
    double value;  // f64
    char name[0];  // string
} jd_bit_radio_number_received_report_t;


/**
 * Raised when a buffer packet is received
 */
#define JD_BIT_RADIO_CMD_BUFFER_RECEIVED 0x92
typedef struct jd_bit_radio_buffer_received_report {
    uint32_t time; // ms
    uint32_t device_serial_number;
    int8_t rssi; // dB
    uint8_t padding;  // u8[1]
    uint8_t data[0];
} jd_bit_radio_buffer_received_report_t;


#endif
