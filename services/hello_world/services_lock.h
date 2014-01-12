/* 
* Copyright (c) 2013, Nordic Semiconductor ASA
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
* 
* - Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
* 
* - Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
* 
* - The name of Nordic Semiconductor ASA may not be used to endorse or promote
*   products derived from this software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
* This file is autogenerated by nRFgo Studio .3031 
*/

#ifndef SETUP_MESSAGES_H__
#define SETUP_MESSAGES_H__

#include "hal_platform.h" 
#include "aci.h"

// You have now chosen to upload the configuration to OTP on the device.
// This will result in a device that you can not modify afterwards. If this is your intention,
// remove this comment and the #error below
#error Generating configuration for OTP. Please verify usage by removing this error message from include file.

#define SETUP_ID 0
#define SETUP_FORMAT 3 /** nRF8001 D */
#define ACI_DYNAMIC_DATA_SIZE 143

/* Service: Hello World - Characteristic: Greeting - Pipe: TX */
#define PIPE_HELLO_WORLD_GREETING_TX          1
#define PIPE_HELLO_WORLD_GREETING_TX_MAX_SIZE 20

/* Service: Hello World - Characteristic: Greeting - Pipe: SET */
#define PIPE_HELLO_WORLD_GREETING_SET          2
#define PIPE_HELLO_WORLD_GREETING_SET_MAX_SIZE 20

/* Service: Hello World - Characteristic: Count - Pipe: SET */
#define PIPE_HELLO_WORLD_COUNT_SET          3
#define PIPE_HELLO_WORLD_COUNT_SET_MAX_SIZE 1

/* Service: Hello World - Characteristic: Count - Pipe: RX_ACK_AUTO */
#define PIPE_HELLO_WORLD_COUNT_RX_ACK_AUTO          4
#define PIPE_HELLO_WORLD_COUNT_RX_ACK_AUTO_MAX_SIZE 1

/* Service: TX Power - Characteristic: TX Power Level - Pipe: SET */
#define PIPE_TX_POWER_TX_POWER_LEVEL_SET          5
#define PIPE_TX_POWER_TX_POWER_LEVEL_SET_MAX_SIZE 1


#define NUMBER_OF_PIPES 5

#define SERVICES_PIPE_TYPE_MAPPING_CONTENT {\
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_RX_ACK_AUTO},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
}

#define GAP_PPCP_MAX_CONN_INT 0x12 /**< Maximum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_MIN_CONN_INT  0x6 /**< Minimum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_SLAVE_LATENCY 0
#define GAP_PPCP_CONN_TIMEOUT 0xa /** Connection Supervision timeout multiplier as a multiple of 10msec, 0xFFFF means no specific value requested */

#define NB_SETUP_MESSAGES 31
#define SETUP_MESSAGES_CONTENT {\
    {0x00,\
        {\
            0x07,0x06,0x00,0x00,0x03,0x02,0x41,0xfe,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x05,0x01,0x01,0x00,0x00,0x06,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x90,0x01,0xff,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x38,0xff,0xff,0x02,0x58,0x0a,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x05,0x06,0x10,0x54,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x00,0x04,0x04,0x02,0x02,0x00,0x01,0x28,0x00,0x01,0x00,0x18,0x04,0x04,0x05,0x05,0x00,\
            0x02,0x28,0x03,0x01,0x02,0x03,0x00,0x00,0x2a,0x04,0x04,0x14,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x1c,0x0b,0x00,0x03,0x2a,0x00,0x01,0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,\
            0x64,0x63,0x6f,0x6d,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x38,0x05,0x05,0x00,0x04,0x28,0x03,0x01,0x02,0x05,0x00,0x01,0x2a,0x06,0x04,0x03,0x02,\
            0x00,0x05,0x2a,0x01,0x01,0x00,0x00,0x04,0x04,0x05,0x05,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x54,0x06,0x28,0x03,0x01,0x02,0x07,0x00,0x04,0x2a,0x06,0x04,0x09,0x08,0x00,0x07,0x2a,\
            0x04,0x01,0x06,0x00,0x12,0x00,0x00,0x00,0x0a,0x00,0x04,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x70,0x02,0x02,0x00,0x08,0x28,0x00,0x01,0x01,0x18,0x04,0x04,0x10,0x10,0x00,0x09,0x28,\
            0x00,0x01,0x1a,0x6c,0x9a,0x98,0x94,0x41,0x78,0x3e,0x16,0xf3,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x8c,0xaa,0x69,0x00,0x00,0x0a,0x2f,0x04,0x04,0x13,0x13,0x00,0x0a,0x28,0x03,0x01,0x12,\
            0x0b,0x00,0x1a,0x6c,0x9a,0x98,0x94,0x41,0x78,0x3e,0x16,0xf3,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xa8,0xaa,0x69,0x01,0x00,0x0a,0x2f,0x16,0x04,0x15,0x14,0x00,0x0b,0x00,0x01,0x02,0x48,\
            0x65,0x6c,0x6c,0x6f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xc4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x04,0x08,0x07,0x00,0x0c,0x29,0x04,0x01,\
            0x19,0x00,0x00,0x00,0x01,0x00,0x00,0x46,0x14,0x03,0x02,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xe0,0x0d,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x13,0x13,0x00,0x0e,0x28,0x03,0x01,0x0a,\
            0x0f,0x00,0x1a,0x6c,0x9a,0x98,0x94,0x41,0x78,0x3e,0x16,0xf3,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xfc,0xaa,0x69,0x02,0x00,0x0a,0x2f,0x46,0x14,0x02,0x01,0x00,0x0f,0x00,0x02,0x02,0x00,\
            0x04,0x04,0x02,0x02,0x00,0x10,0x28,0x00,0x01,0x04,0x18,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x18,0x04,0x05,0x05,0x00,0x11,0x28,0x03,0x01,0x02,0x12,0x00,0x07,0x2a,0x06,0x04,0x02,\
            0x01,0x00,0x12,0x2a,0x07,0x01,0x00,0x04,0x04,0x02,0x02,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x34,0x13,0x28,0x00,0x01,0x0a,0x18,0x04,0x04,0x05,0x05,0x00,0x14,0x28,0x03,0x01,0x02,\
            0x15,0x00,0x24,0x2a,0x06,0x04,0x09,0x08,0x00,0x15,0x2a,0x24,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x50,0x01,0x30,0x30,0x30,0x31,0x00,0x00,0x00,0x00,0x06,0x04,0x08,0x07,0x00,0x16,0x29,\
            0x04,0x01,0x19,0x00,0x00,0x00,0x01,0x00,0x00,0x04,0x04,0x05,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x6c,0x05,0x00,0x17,0x28,0x03,0x01,0x02,0x18,0x00,0x27,0x2a,0x06,0x04,0x03,0x02,0x00,\
            0x18,0x2a,0x27,0x01,0x30,0x31,0x06,0x04,0x08,0x07,0x00,0x19,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x88,0x29,0x04,0x01,0x19,0x00,0x00,0x00,0x01,0x00,0x00,0x04,0x04,0x05,0x05,0x00,0x1a,\
            0x28,0x03,0x01,0x02,0x1b,0x00,0x26,0x2a,0x06,0x04,0x05,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xa4,0x00,0x1b,0x2a,0x26,0x01,0x30,0x31,0x2e,0x31,0x06,0x04,0x08,0x07,0x00,0x1c,0x29,\
            0x04,0x01,0x19,0x00,0x00,0x00,0x01,0x00,0x00,0x04,0x04,0x05,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xc0,0x05,0x00,0x1d,0x28,0x03,0x01,0x02,0x1e,0x00,0x29,0x2a,0x06,0x04,0x15,0x14,0x00,\
            0x1e,0x2a,0x29,0x01,0x67,0x6e,0x6f,0x73,0x2e,0x75,0x73,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xdc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x04,0x08,0x07,\
            0x00,0x1f,0x29,0x04,0x01,0x19,0x00,0x00,0x00,0x01,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xf8,0x04,0x04,0x05,0x05,0x00,0x20,0x28,0x03,0x01,0x02,0x21,0x00,0x28,0x2a,0x04,0x04,\
            0x14,0x05,0x00,0x21,0x2a,0x28,0x01,0x30,0x2e,0x30,0x2e,0x31,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,\
            0x04,0x08,0x07,0x00,0x22,0x29,0x04,0x01,0x19,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x07,0x06,0x22,0x30,0x01,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x00,0x00,0x01,0x02,0x00,0x82,0x04,0x00,0x0b,0x00,0x0d,0x00,0x02,0x02,0x04,0x80,0x04,\
            0x00,0x0f,0x00,0x00,0x2a,0x07,0x01,0x00,0x80,0x04,0x00,0x12,\
        },\
    },\
    {0x00,\
        {\
            0x05,0x06,0x40,0x1c,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x13,0x06,0x50,0x00,0x1a,0x6c,0x9a,0x98,0x94,0x41,0x78,0x3e,0x16,0xf3,0xaa,0x69,0x00,0x00,0x0a,0x2f,\
        },\
    },\
    {0x00,\
        {\
            0x0c,0x06,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x06,0x06,0xf0,0x00,0x83,0x89,0xd1,\
        },\
    },\
}

#endif
