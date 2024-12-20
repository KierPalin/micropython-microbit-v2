// Autogenerated C header file for Jacscript Cloud
#ifndef _JACDAC_SPEC_JACSCRIPT_CLOUD_H
#define _JACDAC_SPEC_JACSCRIPT_CLOUD_H 1

#define JD_SERVICE_CLASS_JACSCRIPT_CLOUD  0x14606e9c

// enum CommandStatus (uint32_t)
#define JD_JACSCRIPT_CLOUD_COMMAND_STATUS_OK 0xc8
#define JD_JACSCRIPT_CLOUD_COMMAND_STATUS_NOT_FOUND 0x194
#define JD_JACSCRIPT_CLOUD_COMMAND_STATUS_BUSY 0x1ad

/**
 * Upload a labelled tuple of values to the cloud.
 * The tuple will be automatically tagged with timestamp and originating device.
 */
#define JD_JACSCRIPT_CLOUD_CMD_UPLOAD 0x80
typedef struct jd_jacscript_cloud_upload {
    char label[0];  // string0
    // double value[0];  // f64
} jd_jacscript_cloud_upload_t;


/**
 * Argument: payload bytes. Upload a binary message to the cloud.
 */
#define JD_JACSCRIPT_CLOUD_CMD_UPLOAD_BIN 0x81

/**
 * Should be called by jacscript when it finishes handling a `cloud_command`.
 */
#define JD_JACSCRIPT_CLOUD_CMD_ACK_CLOUD_COMMAND 0x83
typedef struct jd_jacscript_cloud_ack_cloud_command {
    uint32_t seq_no;
    uint32_t status;  // CommandStatus
    double result[0];  // f64
} jd_jacscript_cloud_ack_cloud_command_t;


/**
 * Read-only bool (uint8_t). Indicate whether we're currently connected to the cloud server.
 * When offline, `upload` commands are queued, and `get_twin` respond with cached values.
 */
#define JD_JACSCRIPT_CLOUD_REG_CONNECTED 0x180

/**
 * Read-only string (bytes). User-friendly name of the connection, typically includes name of the server
 * and/or type of cloud service (`"something.cloud.net (Provider IoT)"`).
 */
#define JD_JACSCRIPT_CLOUD_REG_CONNECTION_NAME 0x181

/**
 * Emitted when cloud requests jacscript to run some action.
 */
#define JD_JACSCRIPT_CLOUD_EV_CLOUD_COMMAND 0x81
typedef struct jd_jacscript_cloud_cloud_command {
    uint32_t seq_no;
    char command[0];  // string0
    // double argument[0];  // f64
} jd_jacscript_cloud_cloud_command_t;


/**
 * Emitted when we connect or disconnect from the cloud.
 */
#define JD_JACSCRIPT_CLOUD_EV_CHANGE JD_EV_CHANGE

#endif
