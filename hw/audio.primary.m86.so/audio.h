/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef ANDROID_AUDIO_HAL_INTERFACE_H
#define ANDROID_AUDIO_HAL_INTERFACE_H


/**
 * The id of this module
 */
#define AUDIO_HARDWARE_MODULE_ID "audio"

/**
 * Name of the audio devices to open
 */
#define AUDIO_HARDWARE_INTERFACE "audio_hw_if"


/* Use version 0.1 to be compatible with first generation of audio hw module with version_major
 * hardcoded to 1. No audio module API change.
 */
#define AUDIO_MODULE_API_VERSION_0_1 HARDWARE_MODULE_API_VERSION(0, 1)
#define AUDIO_MODULE_API_VERSION_CURRENT AUDIO_MODULE_API_VERSION_0_1

/* First generation of audio devices had version hardcoded to 0. all devices with versions < 1.0
 * will be considered of first generation API.
 */
#define AUDIO_DEVICE_API_VERSION_0_0 HARDWARE_DEVICE_API_VERSION(0, 0)
#define AUDIO_DEVICE_API_VERSION_1_0 HARDWARE_DEVICE_API_VERSION(1, 0)
#define AUDIO_DEVICE_API_VERSION_2_0 HARDWARE_DEVICE_API_VERSION(2, 0)
#define AUDIO_DEVICE_API_VERSION_3_0 HARDWARE_DEVICE_API_VERSION(3, 0)
#define AUDIO_DEVICE_API_VERSION_CURRENT AUDIO_DEVICE_API_VERSION_3_0
/* Minimal audio HAL version supported by the audio framework */
#define AUDIO_DEVICE_API_VERSION_MIN AUDIO_DEVICE_API_VERSION_2_0

/**
 * List of known audio HAL modules. This is the base name of the audio HAL
 * library composed of the "audio." prefix, one of the base names below and
 * a suffix specific to the device.
 * e.g: audio.primary.goldfish.so or audio.a2dp.default.so
 */

#define AUDIO_HARDWARE_MODULE_ID_PRIMARY "primary"
#define AUDIO_HARDWARE_MODULE_ID_A2DP "a2dp"
#define AUDIO_HARDWARE_MODULE_ID_USB "usb"
#define AUDIO_HARDWARE_MODULE_ID_REMOTE_SUBMIX "r_submix"
#define AUDIO_HARDWARE_MODULE_ID_CODEC_OFFLOAD "codec_offload"

/**************************************/

/**
 *  standard audio parameters that the HAL may need to handle
 */

/**
 *  audio device parameters
 */

/* BT SCO Noise Reduction + Echo Cancellation parameters */
#define AUDIO_PARAMETER_KEY_BT_NREC "bt_headset_nrec"
#define AUDIO_PARAMETER_VALUE_ON "on"
#define AUDIO_PARAMETER_VALUE_OFF "off"

/* TTY mode selection */
#define AUDIO_PARAMETER_KEY_TTY_MODE "tty_mode"
#define AUDIO_PARAMETER_VALUE_TTY_OFF "tty_off"
#define AUDIO_PARAMETER_VALUE_TTY_VCO "tty_vco"
#define AUDIO_PARAMETER_VALUE_TTY_HCO "tty_hco"
#define AUDIO_PARAMETER_VALUE_TTY_FULL "tty_full"

/* Hearing Aid Compatibility - Telecoil (HAC-T) mode on/off
   Strings must be in sync with CallFeaturesSetting.java */
#define AUDIO_PARAMETER_KEY_HAC "HACSetting"
#define AUDIO_PARAMETER_VALUE_HAC_ON "ON"
#define AUDIO_PARAMETER_VALUE_HAC_OFF "OFF"

/* A2DP sink address set by framework */
#define AUDIO_PARAMETER_A2DP_SINK_ADDRESS "a2dp_sink_address"

/* A2DP source address set by framework */
#define AUDIO_PARAMETER_A2DP_SOURCE_ADDRESS "a2dp_source_address"

/* Screen state */
#define AUDIO_PARAMETER_KEY_SCREEN_STATE "screen_state"

/* Bluetooth SCO wideband */
#define AUDIO_PARAMETER_KEY_BT_SCO_WB "bt_wbs"


/* Device state*/
#define AUDIO_PARAMETER_KEY_DEV_SHUTDOWN "dev_shutdown"

/* Get a new HW synchronization source identifier.
 * Return a valid source (positive integer) or AUDIO_HW_SYNC_INVALID if an error occurs
 * or no HW sync is available. */
#define AUDIO_PARAMETER_HW_AV_SYNC "hw_av_sync"

/**
 *  audio stream parameters
 */

#define AUDIO_PARAMETER_STREAM_ROUTING "routing"             /* audio_devices_t */
#define AUDIO_PARAMETER_STREAM_FORMAT "format"               /* audio_format_t */
#define AUDIO_PARAMETER_STREAM_CHANNELS "channels"           /* audio_channel_mask_t */
#define AUDIO_PARAMETER_STREAM_FRAME_COUNT "frame_count"     /* size_t */
#define AUDIO_PARAMETER_STREAM_INPUT_SOURCE "input_source"   /* audio_source_t */
#define AUDIO_PARAMETER_STREAM_SAMPLING_RATE "sampling_rate" /* uint32_t */

#define AUDIO_PARAMETER_DEVICE_CONNECT "connect"            /* audio_devices_t */
#define AUDIO_PARAMETER_DEVICE_DISCONNECT "disconnect"      /* audio_devices_t */

/* Query supported formats. The response is a '|' separated list of strings from
 * audio_format_t enum e.g: "sup_formats=AUDIO_FORMAT_PCM_16_BIT" */
#define AUDIO_PARAMETER_STREAM_SUP_FORMATS "sup_formats"
/* Query supported channel masks. The response is a '|' separated list of strings from
 * audio_channel_mask_t enum e.g: "sup_channels=AUDIO_CHANNEL_OUT_STEREO|AUDIO_CHANNEL_OUT_MONO" */
#define AUDIO_PARAMETER_STREAM_SUP_CHANNELS "sup_channels"
/* Query supported sampling rates. The response is a '|' separated list of integer values e.g:
 * "sup_sampling_rates=44100|48000" */
#define AUDIO_PARAMETER_STREAM_SUP_SAMPLING_RATES "sup_sampling_rates"

/* Set the HW synchronization source for an output stream. */
#define AUDIO_PARAMETER_STREAM_HW_AV_SYNC "hw_av_sync"

/* Enable mono audio playback if 1, else should be 0. */
#define AUDIO_PARAMETER_MONO_OUTPUT "mono_output"

/**
 * audio codec parameters
 */

#define AUDIO_OFFLOAD_CODEC_PARAMS "music_offload_codec_param"
#define AUDIO_OFFLOAD_CODEC_BIT_PER_SAMPLE "music_offload_bit_per_sample"
#define AUDIO_OFFLOAD_CODEC_BIT_RATE "music_offload_bit_rate"
#define AUDIO_OFFLOAD_CODEC_AVG_BIT_RATE "music_offload_avg_bit_rate"
#define AUDIO_OFFLOAD_CODEC_ID "music_offload_codec_id"
#define AUDIO_OFFLOAD_CODEC_BLOCK_ALIGN "music_offload_block_align"
#define AUDIO_OFFLOAD_CODEC_SAMPLE_RATE "music_offload_sample_rate"
#define AUDIO_OFFLOAD_CODEC_ENCODE_OPTION "music_offload_encode_option"
#define AUDIO_OFFLOAD_CODEC_NUM_CHANNEL  "music_offload_num_channels"
#define AUDIO_OFFLOAD_CODEC_DOWN_SAMPLING  "music_offload_down_sampling"
#define AUDIO_OFFLOAD_CODEC_DELAY_SAMPLES  "delay_samples"
#define AUDIO_OFFLOAD_CODEC_PADDING_SAMPLES  "padding_samples"

/**************************************/

typedef struct {
#if defined(__LP64__)
  int32_t __private[10];
#else
  int32_t __private[1];
#endif
} pthread_mutex_t;

typedef uint32_t audio_channel_mask_t;

typedef enum {
    /* All of these are in native byte order */
    AUDIO_FORMAT_PCM_SUB_16_BIT          = 0x1, /* DO NOT CHANGE - PCM signed 16 bits */
    AUDIO_FORMAT_PCM_SUB_8_BIT           = 0x2, /* DO NOT CHANGE - PCM unsigned 8 bits */
    AUDIO_FORMAT_PCM_SUB_32_BIT          = 0x3, /* PCM signed .31 fixed point */
    AUDIO_FORMAT_PCM_SUB_8_24_BIT        = 0x4, /* PCM signed 8.23 fixed point */
    AUDIO_FORMAT_PCM_SUB_FLOAT           = 0x5, /* PCM single-precision floating point */
    AUDIO_FORMAT_PCM_SUB_24_BIT_PACKED   = 0x6, /* PCM signed .23 fixed point packed in 3 bytes */
} audio_format_pcm_sub_fmt_t;

typedef enum {
    AUDIO_FORMAT_AAC_SUB_MAIN            = 0x1,
    AUDIO_FORMAT_AAC_SUB_LC              = 0x2,
    AUDIO_FORMAT_AAC_SUB_SSR             = 0x4,
    AUDIO_FORMAT_AAC_SUB_LTP             = 0x8,
    AUDIO_FORMAT_AAC_SUB_HE_V1           = 0x10,
    AUDIO_FORMAT_AAC_SUB_SCALABLE        = 0x20,
    AUDIO_FORMAT_AAC_SUB_ERLC            = 0x40,
    AUDIO_FORMAT_AAC_SUB_LD              = 0x80,
    AUDIO_FORMAT_AAC_SUB_HE_V2           = 0x100,
    AUDIO_FORMAT_AAC_SUB_ELD             = 0x200,
} audio_format_aac_sub_fmt_t;

typedef enum {
    AUDIO_FORMAT_INVALID             = 0xFFFFFFFFUL,
    AUDIO_FORMAT_DEFAULT             = 0,
    AUDIO_FORMAT_PCM                 = 0x00000000UL, /* DO NOT CHANGE */
    AUDIO_FORMAT_MP3                 = 0x01000000UL,
    AUDIO_FORMAT_AMR_NB              = 0x02000000UL,
    AUDIO_FORMAT_AMR_WB              = 0x03000000UL,
    AUDIO_FORMAT_AAC                 = 0x04000000UL,
    AUDIO_FORMAT_HE_AAC_V1           = 0x05000000UL, /* Deprecated, Use AUDIO_FORMAT_AAC_HE_V1*/
    AUDIO_FORMAT_HE_AAC_V2           = 0x06000000UL, /* Deprecated, Use AUDIO_FORMAT_AAC_HE_V2*/
    AUDIO_FORMAT_VORBIS              = 0x07000000UL,
    AUDIO_FORMAT_OPUS                = 0x08000000UL,
    AUDIO_FORMAT_AC3                 = 0x09000000UL,
    AUDIO_FORMAT_E_AC3               = 0x0A000000UL,
    AUDIO_FORMAT_DTS                 = 0x0B000000UL,
    AUDIO_FORMAT_DTS_HD              = 0x0C000000UL,
    // IEC61937 is encoded audio wrapped in 16-bit PCM.
    AUDIO_FORMAT_IEC61937            = 0x0D000000UL,
    AUDIO_FORMAT_EVRC                = 0x10000000UL,
    AUDIO_FORMAT_QCELP               = 0x11000000UL,
    AUDIO_FORMAT_WMA                 = 0x12000000UL,
    AUDIO_FORMAT_WMA_PRO             = 0x13000000UL,
    AUDIO_FORMAT_AAC_ADIF            = 0x14000000UL,
    AUDIO_FORMAT_EVRCB               = 0x15000000UL,
    AUDIO_FORMAT_EVRCWB              = 0x16000000UL,
    AUDIO_FORMAT_AMR_WB_PLUS         = 0x17000000UL,
    AUDIO_FORMAT_MP2                 = 0x18000000UL,
    AUDIO_FORMAT_EVRCNW              = 0x19000000UL,
    AUDIO_FORMAT_PCM_OFFLOAD         = 0x1A000000UL,
    AUDIO_FORMAT_FLAC                = 0x1B000000UL,
    AUDIO_FORMAT_ALAC                = 0x1C000000UL,
    AUDIO_FORMAT_APE                 = 0x1D000000UL,
    AUDIO_FORMAT_AAC_ADTS            = 0x1E000000UL,
    AUDIO_FORMAT_DSD                 = 0x1F000000UL,
    AUDIO_FORMAT_SBC                 = 0x20000000UL,
    AUDIO_FORMAT_APTX                = 0x21000000UL,
    AUDIO_FORMAT_APTX_HD             = 0x22000000UL,

    AUDIO_FORMAT_DOLBY_TRUEHD        = 0x0E000000UL,
    AUDIO_FORMAT_MAIN_MASK           = 0xFF000000UL, /* Deprecated. Use audio_get_main_format() */
    AUDIO_FORMAT_SUB_MASK            = 0x00FFFFFFUL,

    /* Aliases */
    /* note != AudioFormat.ENCODING_PCM_16BIT */
    AUDIO_FORMAT_PCM_16_BIT          = (AUDIO_FORMAT_PCM |
                                        AUDIO_FORMAT_PCM_SUB_16_BIT),
    /* note != AudioFormat.ENCODING_PCM_8BIT */
    AUDIO_FORMAT_PCM_8_BIT           = (AUDIO_FORMAT_PCM |
                                        AUDIO_FORMAT_PCM_SUB_8_BIT),
    AUDIO_FORMAT_PCM_32_BIT          = (AUDIO_FORMAT_PCM |
                                        AUDIO_FORMAT_PCM_SUB_32_BIT),
    AUDIO_FORMAT_PCM_8_24_BIT        = (AUDIO_FORMAT_PCM |
                                        AUDIO_FORMAT_PCM_SUB_8_24_BIT),
    AUDIO_FORMAT_PCM_FLOAT           = (AUDIO_FORMAT_PCM |
                                        AUDIO_FORMAT_PCM_SUB_FLOAT),
    AUDIO_FORMAT_PCM_24_BIT_PACKED   = (AUDIO_FORMAT_PCM |
                                        AUDIO_FORMAT_PCM_SUB_24_BIT_PACKED),
    AUDIO_FORMAT_AAC_MAIN            = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_MAIN),
    AUDIO_FORMAT_AAC_LC              = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_LC),
    AUDIO_FORMAT_AAC_SSR             = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_SSR),
    AUDIO_FORMAT_AAC_LTP             = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_LTP),
    AUDIO_FORMAT_AAC_HE_V1           = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_HE_V1),
    AUDIO_FORMAT_AAC_SCALABLE        = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_SCALABLE),
    AUDIO_FORMAT_AAC_ERLC            = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_ERLC),
    AUDIO_FORMAT_AAC_LD              = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_LD),
    AUDIO_FORMAT_AAC_HE_V2           = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_HE_V2),
    AUDIO_FORMAT_AAC_ELD             = (AUDIO_FORMAT_AAC |
                                        AUDIO_FORMAT_AAC_SUB_ELD),
    AUDIO_FORMAT_AAC_ADTS_MAIN       = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_MAIN),
    AUDIO_FORMAT_AAC_ADTS_LC         = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_LC),
    AUDIO_FORMAT_AAC_ADTS_SSR        = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_SSR),
    AUDIO_FORMAT_AAC_ADTS_LTP        = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_LTP),
    AUDIO_FORMAT_AAC_ADTS_HE_V1      = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_HE_V1),
    AUDIO_FORMAT_AAC_ADTS_SCALABLE   = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_SCALABLE),
    AUDIO_FORMAT_AAC_ADTS_ERLC       = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_ERLC),
    AUDIO_FORMAT_AAC_ADTS_LD         = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_LD),
    AUDIO_FORMAT_AAC_ADTS_HE_V2      = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_HE_V2),
    AUDIO_FORMAT_AAC_ADTS_ELD        = (AUDIO_FORMAT_AAC_ADTS |
                                        AUDIO_FORMAT_AAC_SUB_ELD),
    /*Offload PCM formats*/
    AUDIO_FORMAT_PCM_16_BIT_OFFLOAD  = (AUDIO_FORMAT_PCM_OFFLOAD |
                                        AUDIO_FORMAT_PCM_SUB_16_BIT),
    AUDIO_FORMAT_PCM_24_BIT_OFFLOAD  = (AUDIO_FORMAT_PCM_OFFLOAD |
                                        AUDIO_FORMAT_PCM_SUB_8_24_BIT),
} audio_format_t;

typedef uint32_t audio_devices_t;

struct effect_interface_s {};
typedef struct effect_interface_s **effect_handle_t;


struct hw_module_t;
struct hw_module_methods_t;
struct hw_device_t;

/**
 * Every hardware module must have a data structure named HAL_MODULE_INFO_SYM
 * and the fields of this data structure must begin with hw_module_t
 * followed by module specific information.
 */
typedef struct hw_module_t {
    /** tag must be initialized to HARDWARE_MODULE_TAG */
    uint32_t tag;

    /**
     * The API version of the implemented module. The module owner is
     * responsible for updating the version when a module interface has
     * changed.
     *
     * The derived modules such as gralloc and audio own and manage this field.
     * The module user must interpret the version field to decide whether or
     * not to inter-operate with the supplied module implementation.
     * For example, SurfaceFlinger is responsible for making sure that
     * it knows how to manage different versions of the gralloc-module API,
     * and AudioFlinger must know how to do the same for audio-module API.
     *
     * The module API version should include a major and a minor component.
     * For example, version 1.0 could be represented as 0x0100. This format
     * implies that versions 0x0100-0x01ff are all API-compatible.
     *
     * In the future, libhardware will expose a hw_get_module_version()
     * (or equivalent) function that will take minimum/maximum supported
     * versions as arguments and would be able to reject modules with
     * versions outside of the supplied range.
     */
    uint16_t module_api_version;
#define version_major module_api_version
    /**
     * version_major/version_minor defines are supplied here for temporary
     * source code compatibility. They will be removed in the next version.
     * ALL clients must convert to the new version format.
     */

    /**
     * The API version of the HAL module interface. This is meant to
     * version the hw_module_t, hw_module_methods_t, and hw_device_t
     * structures and definitions.
     *
     * The HAL interface owns this field. Module users/implementations
     * must NOT rely on this value for version information.
     *
     * Presently, 0 is the only valid value.
     */
    uint16_t hal_api_version;
#define version_minor hal_api_version

    /** Identifier of module */
    const char *id;

    /** Name of this module */
    const char *name;

    /** Author/owner/implementor of the module */
    const char *author;

    /** Modules methods */
    struct hw_module_methods_t* methods;

    /** module's dso */
    void* dso;

#ifdef __LP64__
    uint64_t reserved[32-7];
#else
    /** padding to 128 bytes, reserved for future use */
    uint32_t reserved[32-7];
#endif

} hw_module_t;

typedef struct hw_module_methods_t {
    /** Open a specific device */
    int (*open)(const struct hw_module_t* module, const char* id,
            struct hw_device_t** device);

} hw_module_methods_t;

/**
 * Every device data structure must begin with hw_device_t
 * followed by module specific public methods and attributes.
 */
typedef struct hw_device_t {
    /** tag must be initialized to HARDWARE_DEVICE_TAG */
    uint32_t tag;

    /**
     * Version of the module-specific device API. This value is used by
     * the derived-module user to manage different device implementations.
     *
     * The module user is responsible for checking the module_api_version
     * and device version fields to ensure that the user is capable of
     * communicating with the specific module implementation.
     *
     * One module can support multiple devices with different versions. This
     * can be useful when a device interface changes in an incompatible way
     * but it is still necessary to support older implementations at the same
     * time. One such example is the Camera 2.0 API.
     *
     * This field is interpreted by the module user and is ignored by the
     * HAL interface itself.
     */
    uint32_t version;

    /** reference to the module this device belongs to */
    struct hw_module_t* module;

    /** padding reserved for future use */
#ifdef __LP64__
    uint64_t reserved[12];
#else
    uint32_t reserved[12];
#endif

    /** Close this device */
    int (*close)(struct hw_device_t* device);

} hw_device_t;

typedef enum {
    AUDIO_MODE_INVALID          = -2,
    AUDIO_MODE_CURRENT          = -1,
    AUDIO_MODE_NORMAL           = 0,
    AUDIO_MODE_RINGTONE         = 1,
    AUDIO_MODE_IN_CALL          = 2,
    AUDIO_MODE_IN_COMMUNICATION = 3,

    AUDIO_MODE_CNT,
    AUDIO_MODE_MAX              = AUDIO_MODE_CNT - 1,
} audio_mode_t;

typedef int audio_io_handle_t;
typedef enum {
    AUDIO_PATCH_HANDLE_NONE = 0,
} audio_patch_handle_t;

typedef enum {
    AUDIO_OUTPUT_FLAG_NONE = 0x0,       // no attributes
    AUDIO_OUTPUT_FLAG_DIRECT = 0x1,     // this output directly connects a track
                                        // to one output stream: no software mixer
    AUDIO_OUTPUT_FLAG_PRIMARY = 0x2,    // this output is the primary output of
                                        // the device. It is unique and must be
                                        // present. It is opened by default and
                                        // receives routing, audio mode and volume
                                        // controls related to voice calls.
    AUDIO_OUTPUT_FLAG_FAST = 0x4,       // output supports "fast tracks",
                                        // defined elsewhere
    AUDIO_OUTPUT_FLAG_DEEP_BUFFER = 0x8, // use deep audio buffers
    AUDIO_OUTPUT_FLAG_COMPRESS_OFFLOAD = 0x10,  // offload playback of compressed
                                                // streams to hardware codec
    AUDIO_OUTPUT_FLAG_NON_BLOCKING = 0x20, // use non-blocking write
    AUDIO_OUTPUT_FLAG_HW_AV_SYNC = 0x40,   // output uses a hardware A/V synchronization source
    AUDIO_OUTPUT_FLAG_TTS = 0x80,          // output for streams transmitted through speaker
                                           // at a sample rate high enough to accommodate
                                           // lower-range ultrasonic playback
    AUDIO_OUTPUT_FLAG_RAW = 0x100,         // minimize signal processing
    AUDIO_OUTPUT_FLAG_SYNC = 0x200,        // synchronize I/O streams

    AUDIO_OUTPUT_FLAG_IEC958_NONAUDIO = 0x400, // Audio stream contains compressed audio in
                                               // SPDIF data bursts, not PCM.
    AUDIO_OUTPUT_FLAG_VOIP_RX = 0x800,  // use this flag in combination with DIRECT to
                                         // start voip over voice path.
    AUDIO_OUTPUT_FLAG_COMPRESS_PASSTHROUGH = 0x1000, // flag for HDMI compressed passthrough
    AUDIO_OUTPUT_FLAG_DIRECT_PCM = 0x2000, // flag for Direct PCM
} audio_output_flags_t;

/* The audio input flags are analogous to audio output flags.
 * Currently they are used only when an AudioRecord is created,
 * to indicate a preference to be connected to an input stream with
 * attributes corresponding to the specified flags.
 */
typedef enum {
    AUDIO_INPUT_FLAG_NONE       = 0x0,  // no attributes
    AUDIO_INPUT_FLAG_FAST       = 0x1,  // prefer an input that supports "fast tracks"
    AUDIO_INPUT_FLAG_HW_HOTWORD = 0x2,  // prefer an input that captures from hw hotword source
    AUDIO_INPUT_FLAG_RAW        = 0x4,  // minimize signal processing
    AUDIO_INPUT_FLAG_SYNC       = 0x8,  // synchronize I/O streams

} audio_input_flags_t;

typedef enum {
    AUDIO_SOURCE_DEFAULT             = 0,
    AUDIO_SOURCE_MIC                 = 1,
    AUDIO_SOURCE_VOICE_UPLINK        = 2,
    AUDIO_SOURCE_VOICE_DOWNLINK      = 3,
    AUDIO_SOURCE_VOICE_CALL          = 4,
    AUDIO_SOURCE_CAMCORDER           = 5,
    AUDIO_SOURCE_VOICE_RECOGNITION   = 6,
    AUDIO_SOURCE_VOICE_COMMUNICATION = 7,
    AUDIO_SOURCE_REMOTE_SUBMIX       = 8, /* Source for the mix to be presented remotely.      */
                                          /* An example of remote presentation is Wifi Display */
                                          /*  where a dongle attached to a TV can be used to   */
                                          /*  play the mix captured by this audio source.      */
    AUDIO_SOURCE_UNPROCESSED         = 9, /* Source for unprocessed sound.
                                             Usage examples include level measurement and raw
                                             signal analysis. */
    AUDIO_SOURCE_CNT,
    AUDIO_SOURCE_MAX                 = AUDIO_SOURCE_CNT - 1,
    AUDIO_SOURCE_FM_TUNER            = 1998,
    AUDIO_SOURCE_HOTWORD             = 1999, /* A low-priority, preemptible audio source for
                                                for background software hotword detection.
                                                Same tuning as AUDIO_SOURCE_VOICE_RECOGNITION.
                                                Used only internally to the framework. Not exposed
                                                at the audio HAL. */
} audio_source_t;

/* common audio stream parameters and operations */
struct audio_stream {

    /**
     * Return the sampling rate in Hz - eg. 44100.
     */
    uint32_t (*get_sample_rate)(const struct audio_stream *stream);

    /* currently unused - use set_parameters with key
     *    AUDIO_PARAMETER_STREAM_SAMPLING_RATE
     */
    int (*set_sample_rate)(struct audio_stream *stream, uint32_t rate);

    /**
     * Return size of input/output buffer in bytes for this stream - eg. 4800.
     * It should be a multiple of the frame size.  See also get_input_buffer_size.
     */
    size_t (*get_buffer_size)(const struct audio_stream *stream);

    /**
     * Return the channel mask -
     *  e.g. AUDIO_CHANNEL_OUT_STEREO or AUDIO_CHANNEL_IN_STEREO
     */
    audio_channel_mask_t (*get_channels)(const struct audio_stream *stream);

    /**
     * Return the audio format - e.g. AUDIO_FORMAT_PCM_16_BIT
     */
    audio_format_t (*get_format)(const struct audio_stream *stream);

    /* currently unused - use set_parameters with key
     *     AUDIO_PARAMETER_STREAM_FORMAT
     */
    int (*set_format)(struct audio_stream *stream, audio_format_t format);

    /**
     * Put the audio hardware input/output into standby mode.
     * Driver should exit from standby mode at the next I/O operation.
     * Returns 0 on success and <0 on failure.
     */
    int (*standby)(struct audio_stream *stream);

    /** dump the state of the audio input/output device */
    int (*dump)(const struct audio_stream *stream, int fd);

    /** Return the set of device(s) which this stream is connected to */
    audio_devices_t (*get_device)(const struct audio_stream *stream);

    /**
     * Currently unused - set_device() corresponds to set_parameters() with key
     * AUDIO_PARAMETER_STREAM_ROUTING for both input and output.
     * AUDIO_PARAMETER_STREAM_INPUT_SOURCE is an additional information used by
     * input streams only.
     */
    int (*set_device)(struct audio_stream *stream, audio_devices_t device);

    /**
     * set/get audio stream parameters. The function accepts a list of
     * parameter key value pairs in the form: key1=value1;key2=value2;...
     *
     * Some keys are reserved for standard parameters (See AudioParameter class)
     *
     * If the implementation does not accept a parameter change while
     * the output is active but the parameter is acceptable otherwise, it must
     * return -ENOSYS.
     *
     * The audio flinger will put the stream in standby and then change the
     * parameter value.
     */
    int (*set_parameters)(struct audio_stream *stream, const char *kv_pairs);

    /*
     * Returns a pointer to a heap allocated string. The caller is responsible
     * for freeing the memory for it using free().
     */
    char * (*get_parameters)(const struct audio_stream *stream,
                             const char *keys);
    int (*add_audio_effect)(const struct audio_stream *stream,
                             effect_handle_t effect);
    int (*remove_audio_effect)(const struct audio_stream *stream,
                             effect_handle_t effect);
};
typedef struct audio_stream audio_stream_t;

/* type of asynchronous write callback events. Mutually exclusive */
typedef enum {
    STREAM_CBK_EVENT_WRITE_READY, /* non blocking write completed */
    STREAM_CBK_EVENT_DRAIN_READY,  /* drain completed */
    STREAM_CBK_EVENT_ERROR, /* stream hit some error, let AF take action */
} stream_callback_event_t;

typedef int (*stream_callback_t)(stream_callback_event_t event, void *param, void *cookie);

/* type of drain requested to audio_stream_out->drain(). Mutually exclusive */
typedef enum {
    AUDIO_DRAIN_ALL,            /* drain() returns when all data has been played */
    AUDIO_DRAIN_EARLY_NOTIFY    /* drain() returns a short time before all data
                                   from the current track has been played to
                                   give time for gapless track switch */
} audio_drain_type_t;

/**
 * audio_stream_out is the abstraction interface for the audio output hardware.
 *
 * It provides information about various properties of the audio output
 * hardware driver.
 */

struct audio_stream_out {
    /**
     * Common methods of the audio stream out.  This *must* be the first member of audio_stream_out
     * as users of this structure will cast a audio_stream to audio_stream_out pointer in contexts
     * where it's known the audio_stream references an audio_stream_out.
     */
    struct audio_stream common;

    /**
     * Return the audio hardware driver estimated latency in milliseconds.
     */
    uint32_t (*get_latency)(const struct audio_stream_out *stream);

    /**
     * Use this method in situations where audio mixing is done in the
     * hardware. This method serves as a direct interface with hardware,
     * allowing you to directly set the volume as apposed to via the framework.
     * This method might produce multiple PCM outputs or hardware accelerated
     * codecs, such as MP3 or AAC.
     */
    int (*set_volume)(struct audio_stream_out *stream, float left, float right);

    /**
     * Write audio buffer to driver. Returns number of bytes written, or a
     * negative status_t. If at least one frame was written successfully prior to the error,
     * it is suggested that the driver return that successful (short) byte count
     * and then return an error in the subsequent call.
     *
     * If set_callback() has previously been called to enable non-blocking mode
     * the write() is not allowed to block. It must write only the number of
     * bytes that currently fit in the driver/hardware buffer and then return
     * this byte count. If this is less than the requested write size the
     * callback function must be called when more space is available in the
     * driver/hardware buffer.
     */
    ssize_t (*write)(struct audio_stream_out *stream, const void* buffer,
                     size_t bytes);

    /* return the number of audio frames written by the audio dsp to DAC since
     * the output has exited standby
     */
    int (*get_render_position)(const struct audio_stream_out *stream,
                               uint32_t *dsp_frames);

    /**
     * get the local time at which the next write to the audio driver will be presented.
     * The units are microseconds, where the epoch is decided by the local audio HAL.
     */
    int (*get_next_write_timestamp)(const struct audio_stream_out *stream,
                                    int64_t *timestamp);

    /**
     * set the callback function for notifying completion of non-blocking
     * write and drain.
     * Calling this function implies that all future write() and drain()
     * must be non-blocking and use the callback to signal completion.
     */
    int (*set_callback)(struct audio_stream_out *stream,
            stream_callback_t callback, void *cookie);

    /**
     * Notifies to the audio driver to stop playback however the queued buffers are
     * retained by the hardware. Useful for implementing pause/resume. Empty implementation
     * if not supported however should be implemented for hardware with non-trivial
     * latency. In the pause state audio hardware could still be using power. User may
     * consider calling suspend after a timeout.
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
    int (*pause)(struct audio_stream_out* stream);

    /**
     * Notifies to the audio driver to resume playback following a pause.
     * Returns error if called without matching pause.
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
    int (*resume)(struct audio_stream_out* stream);

    /**
     * Requests notification when data buffered by the driver/hardware has
     * been played. If set_callback() has previously been called to enable
     * non-blocking mode, the drain() must not block, instead it should return
     * quickly and completion of the drain is notified through the callback.
     * If set_callback() has not been called, the drain() must block until
     * completion.
     * If type==AUDIO_DRAIN_ALL, the drain completes when all previously written
     * data has been played.
     * If type==AUDIO_DRAIN_EARLY_NOTIFY, the drain completes shortly before all
     * data for the current track has played to allow time for the framework
     * to perform a gapless track switch.
     *
     * Drain must return immediately on stop() and flush() call
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
    int (*drain)(struct audio_stream_out* stream, audio_drain_type_t type );

    /**
     * Notifies to the audio driver to flush the queued data. Stream must already
     * be paused before calling flush().
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
   int (*flush)(struct audio_stream_out* stream);

    /**
     * Return a recent count of the number of audio frames presented to an external observer.
     * This excludes frames which have been written but are still in the pipeline.
     * The count is not reset to zero when output enters standby.
     * Also returns the value of CLOCK_MONOTONIC as of this presentation count.
     * The returned count is expected to be 'recent',
     * but does not need to be the most recent possible value.
     * However, the associated time should correspond to whatever count is returned.
     * Example:  assume that N+M frames have been presented, where M is a 'small' number.
     * Then it is permissible to return N instead of N+M,
     * and the timestamp should correspond to N rather than N+M.
     * The terms 'recent' and 'small' are not defined.
     * They reflect the quality of the implementation.
     *
     * 3.0 and higher only.
     */
    int (*get_presentation_position)(const struct audio_stream_out *stream,
                               uint64_t *frames, struct timespec *timestamp);

};
typedef struct audio_stream_out audio_stream_out_t;

struct audio_stream_in {
    /**
     * Common methods of the audio stream in.  This *must* be the first member of audio_stream_in
     * as users of this structure will cast a audio_stream to audio_stream_in pointer in contexts
     * where it's known the audio_stream references an audio_stream_in.
     */
    struct audio_stream common;

    /** set the input gain for the audio driver. This method is for
     *  for future use */
    int (*set_gain)(struct audio_stream_in *stream, float gain);

    /** Read audio buffer in from audio driver. Returns number of bytes read, or a
     *  negative status_t. If at least one frame was read prior to the error,
     *  read should return that byte count and then return an error in the subsequent call.
     */
    ssize_t (*read)(struct audio_stream_in *stream, void* buffer,
                    size_t bytes);

    /**
     * Return the amount of input frames lost in the audio driver since the
     * last call of this function.
     * Audio driver is expected to reset the value to 0 and restart counting
     * upon returning the current value by this function call.
     * Such loss typically occurs when the user space process is blocked
     * longer than the capacity of audio driver buffers.
     *
     * Unit: the number of input audio frames
     */
    uint32_t (*get_input_frames_lost)(struct audio_stream_in *stream);

    /**
     * Return a recent count of the number of audio frames received and
     * the clock time associated with that frame count.
     *
     * frames is the total frame count received. This should be as early in
     *     the capture pipeline as possible. In general,
     *     frames should be non-negative and should not go "backwards".
     *
     * time is the clock MONOTONIC time when frames was measured. In general,
     *     time should be a positive quantity and should not go "backwards".
     *
     * The status returned is 0 on success, -ENOSYS if the device is not
     * ready/available, or -EINVAL if the arguments are null or otherwise invalid.
     */
    int (*get_capture_position)(const struct audio_stream_in *stream,
                                int64_t *frames, int64_t *time);
};
typedef struct audio_stream_in audio_stream_in_t;

/**
 * return the frame size (number of bytes per sample).
 *
 * Deprecated: use audio_stream_out_frame_size() or audio_stream_in_frame_size() instead.
 */

static inline size_t audio_stream_frame_size(const struct audio_stream *s)
{
    size_t chan_samp_sz;
    audio_format_t format = s->get_format(s);

    if (audio_has_proportional_frames(format)) {
        chan_samp_sz = audio_bytes_per_sample(format);
        return popcount(s->get_channels(s)) * chan_samp_sz;
    }

    return sizeof(int8_t);
}

typedef enum {
    AUSAGE_DEFAULT               = -1,
    AUSAGE_MIN                   = 0,

    AUSAGE_PLAYBACK_PRIMARY      = 0,  // For Primary Output Profile
    AUSAGE_PLAYBACK_LOW_LATENCY,       // For Fast Output Profile
    AUSAGE_PLAYBACK_DEEP_BUFFER,       // For Deep Buffer Profile
    AUSAGE_PLAYBACK_COMPR_OFFLOAD,     // For Compress Offload Profile
    AUSAGE_PLAYBACK_AUX_DIGITAL,       // For HDMI Profile


    AUSAGE_CAPTURE_LOW_LATENCY,        // For Primary Input Profile

    AUSAGE_MAX,
    AUSAGE_CNT                   = AUSAGE_MAX
} audio_usage_id_t;

/**
 ** Stream Status
 **/
typedef enum {
    STATE_STANDBY   = 0,  // Stream is opened, but Device(PCM or Compress) is not opened yet.
    STATE_IDLE,           // Stream is opened & Device(PCM or Compress) is opened.
    STATE_PLAYING,        // Stream is opened & Device(PCM or Compress) is opened & Device is working.
    STATE_PAUSED,         // Stream is opened & Device(Compress) is opened & Device is pausing.(only available for Compress Offload Stream)
} stream_state_type_t;

/* Bit formats */
enum pcm_format {
    PCM_FORMAT_INVALID = -1,
    PCM_FORMAT_S16_LE = 0,  /* 16-bit signed */
    PCM_FORMAT_S32_LE,      /* 32-bit signed */
    PCM_FORMAT_S8,          /* 8-bit signed */
    PCM_FORMAT_S24_LE,      /* 24-bits in 4-bytes */
    PCM_FORMAT_S24_3LE,     /* 24-bits in 3-bytes */

    PCM_FORMAT_MAX,
};

/* Configuration for a stream */
struct pcm_config {
    unsigned int channels;
    unsigned int rate;
    unsigned int period_size;
    unsigned int period_count;
    enum pcm_format format;

    /* Values to use for the ALSA start, stop and silence thresholds, and
     * silence size.  Setting any one of these values to 0 will cause the
     * default tinyalsa values to be used instead.
     * Tinyalsa defaults are as follows.
     *
     * start_threshold   : period_count * period_size
     * stop_threshold    : period_count * period_size
     * silence_threshold : 0
     * silence_size      : 0
     */
    unsigned int start_threshold;
    unsigned int stop_threshold;
    unsigned int silence_threshold;
#ifndef IGNORE_SILENCE_SIZE
    unsigned int silence_size;
#endif

    /* Minimum number of frames available before pcm_mmap_write() will actually
     * write into the kernel buffer. Only used if the stream is opened in mmap mode
     * (pcm_open() called with PCM_MMAP flag set).   Use 0 for default.
     */
    int avail_min;
};

struct compr_config {
	__u32 fragment_size;
	__u32 fragments;
	struct snd_codec *codec;
};
struct compr_gapless_mdata {
	__u32 encoder_delay;
	__u32 encoder_padding;
};
struct listnode
{
    struct listnode *next;
    struct listnode *prev;
};

/**
 * return the frame size (number of bytes per sample) of an output stream.
 */
static inline size_t audio_stream_out_frame_size(const struct audio_stream_out *s)
{
    size_t chan_samp_sz;
    audio_format_t format = s->common.get_format(&s->common);

    if (audio_has_proportional_frames(format)) {
        chan_samp_sz = audio_bytes_per_sample(format);
        return audio_channel_count_from_out_mask(s->common.get_channels(&s->common)) * chan_samp_sz;
    }

    return sizeof(int8_t);
}

/**
 * return the frame size (number of bytes per sample) of an input stream.
 */
static inline size_t audio_stream_in_frame_size(const struct audio_stream_in *s)
{
    size_t chan_samp_sz;
    audio_format_t format = s->common.get_format(&s->common);

    if (audio_has_proportional_frames(format)) {
        chan_samp_sz = audio_bytes_per_sample(format);
        return audio_channel_count_from_in_mask(s->common.get_channels(&s->common)) * chan_samp_sz;
    }

    return sizeof(int8_t);
}

/**********************************************************************/

/**
 * Every hardware module must have a data structure named HAL_MODULE_INFO_SYM
 * and the fields of this data structure must begin with hw_module_t
 * followed by module specific information.
 */
struct audio_module {
    struct hw_module_t common;
};

struct audio_hw_device {
    /**
     * Common methods of the audio device.  This *must* be the first member of audio_hw_device
     * as users of this structure will cast a hw_device_t to audio_hw_device pointer in contexts
     * where it's known the hw_device_t references an audio_hw_device.
     */
    struct hw_device_t common;

    /**
     * used by audio flinger to enumerate what devices are supported by
     * each audio_hw_device implementation.
     *
     * Return value is a bitmask of 1 or more values of audio_devices_t
     *
     * NOTE: audio HAL implementations starting with
     * AUDIO_DEVICE_API_VERSION_2_0 do not implement this function.
     * All supported devices should be listed in audio_policy.conf
     * file and the audio policy manager must choose the appropriate
     * audio module based on information in this file.
     */
    uint32_t (*get_supported_devices)(const struct audio_hw_device *dev);

    /**
     * check to see if the audio hardware interface has been initialized.
     * returns 0 on success, -ENODEV on failure.
     */
    int (*init_check)(const struct audio_hw_device *dev);

    /** set the audio volume of a voice call. Range is between 0.0 and 1.0 */
    int (*set_voice_volume)(struct audio_hw_device *dev, float volume);

    /**
     * set the audio volume for all audio activities other than voice call.
     * Range between 0.0 and 1.0. If any value other than 0 is returned,
     * the software mixer will emulate this capability.
     */
    int (*set_master_volume)(struct audio_hw_device *dev, float volume);

    /**
     * Get the current master volume value for the HAL, if the HAL supports
     * master volume control.  AudioFlinger will query this value from the
     * primary audio HAL when the service starts and use the value for setting
     * the initial master volume across all HALs.  HALs which do not support
     * this method may leave it set to NULL.
     */
    int (*get_master_volume)(struct audio_hw_device *dev, float *volume);

    /**
     * set_mode is called when the audio mode changes. AUDIO_MODE_NORMAL mode
     * is for standard audio playback, AUDIO_MODE_RINGTONE when a ringtone is
     * playing, and AUDIO_MODE_IN_CALL when a call is in progress.
     */
    int (*set_mode)(struct audio_hw_device *dev, audio_mode_t mode);

    /* mic mute */
    int (*set_mic_mute)(struct audio_hw_device *dev, bool state);
    int (*get_mic_mute)(const struct audio_hw_device *dev, bool *state);

    int (*dumb2);
    int (*dumb3);
    int (*set_headphone_volume)(struct audio_hw_device *dev, float volume);

    /* set/get global audio parameters */
    int (*set_parameters)(struct audio_hw_device *dev, const char *kv_pairs);

    /*
     * Returns a pointer to a heap allocated string. The caller is responsible
     * for freeing the memory for it using free().
     */
    char * (*get_parameters)(const struct audio_hw_device *dev,
                             const char *keys);

    /* Returns audio input buffer size according to parameters passed or
     * 0 if one of the parameters is not supported.
     * See also get_buffer_size which is for a particular stream.
     */
    size_t (*get_input_buffer_size)(const struct audio_hw_device *dev,
                                    const struct audio_config *config);

    /** This method creates and opens the audio hardware output stream.
     * The "address" parameter qualifies the "devices" audio device type if needed.
     * The format format depends on the device type:
     * - Bluetooth devices use the MAC address of the device in the form "00:11:22:AA:BB:CC"
     * - USB devices use the ALSA card and device numbers in the form  "card=X;device=Y"
     * - Other devices may use a number or any other string.
     */

    int (*open_output_stream)(struct audio_hw_device *dev,
                              audio_io_handle_t handle,
                              audio_devices_t devices,
                              audio_output_flags_t flags,
                              struct audio_config *config,
                              struct audio_stream_out **stream_out,
                              const char *address);

    void (*close_output_stream)(struct audio_hw_device *dev,
                                struct audio_stream_out* stream_out);

    /** This method creates and opens the audio hardware input stream */
    int (*open_input_stream)(struct audio_hw_device *dev,
                             audio_io_handle_t handle,
                             audio_devices_t devices,
                             struct audio_config *config,
                             struct audio_stream_in **stream_in,
                             audio_input_flags_t flags,
                             const char *address,
                             audio_source_t source);

    void (*close_input_stream)(struct audio_hw_device *dev,
                               struct audio_stream_in *stream_in);

    /** This method dumps the state of the audio hardware */
    int (*dump)(const struct audio_hw_device *dev, int fd);

    /**
     * set the audio mute status for all audio activities.  If any value other
     * than 0 is returned, the software mixer will emulate this capability.
     */
    int (*set_master_mute)(struct audio_hw_device *dev, bool mute);

    /**
     * Get the current master mute status for the HAL, if the HAL supports
     * master mute control.  AudioFlinger will query this value from the primary
     * audio HAL when the service starts and use the value for setting the
     * initial master mute across all HALs.  HALs which do not support this
     * method may leave it set to NULL.
     */
    int (*get_master_mute)(struct audio_hw_device *dev, bool *mute);

    /**
     * Routing control
     */

    /* Creates an audio patch between several source and sink ports.
     * The handle is allocated by the HAL and should be unique for this
     * audio HAL module. */
    int (*create_audio_patch)(struct audio_hw_device *dev,
                               unsigned int num_sources,
                               const struct audio_port_config *sources,
                               unsigned int num_sinks,
                               const struct audio_port_config *sinks,
                               audio_patch_handle_t *handle);

    /* Release an audio patch */
    int (*release_audio_patch)(struct audio_hw_device *dev,
                               audio_patch_handle_t handle);

    /* Fills the list of supported attributes for a given audio port.
     * As input, "port" contains the information (type, role, address etc...)
     * needed by the HAL to identify the port.
     * As output, "port" contains possible attributes (sampling rates, formats,
     * channel masks, gain controllers...) for this port.
     */
    int (*get_audio_port)(struct audio_hw_device *dev,
                          struct audio_port *port);

    /* Set audio port configuration */
    int (*set_audio_port_config)(struct audio_hw_device *dev,
                         const struct audio_port_config *config);

#ifdef AUDIO_LISTEN_ENABLED
    /** This method creates the listen session and returns handle */
    int (*open_listen_session)(struct audio_hw_device *dev,
                              listen_open_params_t *params,
                              struct listen_session** handle);

    /** This method closes the listen session  */
    int (*close_listen_session)(struct audio_hw_device *dev,
                                struct listen_session* handle);

    /** This method sets the mad observer callback  */
    int (*set_mad_observer)(struct audio_hw_device *dev,
                            listen_callback_t cb_func);

    /**
     *   This method is used for setting listen hal specfic parameters.
     *  If multiple paramets are set in one call and setting any one of them
     *  fails it will return failure.
     */
    int (*listen_set_parameters)(struct audio_hw_device *dev,
                                 const char *kv_pairs);
#endif
};
typedef struct audio_hw_device audio_hw_device_t;

/** convenience API for opening and closing a supported device */

static inline int audio_hw_device_open(const struct hw_module_t* module,
                                       struct audio_hw_device** device)
{
    return module->methods->open(module, AUDIO_HARDWARE_INTERFACE,
                                 (struct hw_device_t**)device);
}

static inline int audio_hw_device_close(struct audio_hw_device* device)
{
    return device->common.close(&device->common);
}

typedef enum {
    AUSAGE_MODE_NORMAL               = 0,
    AUSAGE_MODE_VOICE_CALL,
    AUSAGE_MODE_VOIP_CALL,
    AUSAGE_MODE_LTE_CALL,
    AUSAGE_MODE_WIFI_CALL,

    AUSAGE_MODE_NONE,
    AUSAGE_MODE_MAX,
    AUSAGE_MODE_CNT            = AUSAGE_MODE_MAX
} audio_usage_mode_t;

typedef enum {
    CALL_OFF   = 0,
    CP_CALL,
    LTE_CALL,
    WIFI_CALL,
} call_state_type_t;



union ctl_values {
    int *enumerated;
    long *integer;
    void *ptr;
    unsigned char *bytes;
};

struct param_values {
    unsigned int num_bytes;
    unsigned char *bytes;
};

struct mixer_state {
    struct mixer_ctl *ctl;
    unsigned int num_values;
    union ctl_values old_value;
    union ctl_values new_value;
    union ctl_values reset_value;
};

struct mixer_setting {
    unsigned int ctl_index;
    unsigned int num_values;
    unsigned int type;
    union ctl_values value;
};

struct mixer_value {
    unsigned int ctl_index;
    int index;
    long value;
};

struct mixer_path {
    char *name;
    unsigned int size;
    unsigned int length;
    struct mixer_setting *setting;
};

struct audio_route {
    struct mixer *mixer;
    unsigned int num_mixer_ctls;
    struct mixer_state *mixer_state;

    unsigned int mixer_path_size;
    unsigned int num_mixer_paths;
    struct mixer_path *mixer_path;
};

/**
 ** Structure for Audio Output Stream
 ** Implement audio_stream_out structure
 **/
// size : 0xD8 -> 216 
struct stream_out {
    struct audio_stream_out stream;
    pthread_mutex_t lock; // *out + 25  // out + 100

    void *v_104; // *out + 26 // out + 104
    void *v_108; // *out + 27 // out + 108
    void *v_112; // *out + 28 // out + 112
    void *v_116; // *out + 29 // out + 116
    
    void *v_120; // *out + 30 // out + 120
    void *v_124; // *out + 31 // out + 124
    void *v_128; // *out + 32 // out + 128
    void *v_132; // *out + 33 // out + 132
    
    void *v_136; // *out + 34 // out + 136
    void *v_140; // *out + 35 // out + 140
    void *v_144; // *out + 36 // out + 144
    void *v_148; // *out + 37 // out + 148
    
    void *v_152; // *out + 38 // out + 152
    void *v_156; // *out + 39 // out + 156
    void *v_160; // *out + 40 // out + 160
    void *v_164; // *out + 41 // out + 164
    
    int channel_mask; // *out + 42 // out + 168
    void *v_172; // *out + 43 // out + 172
    void *v_176; // *out + 44 // out + 176
    void *v_180; // *out + 45 // out + 180
    
    int sample_rate; // *out + 46 // out + 184
    int format; // *out + 47 // out + 188
    void *v_192; // *out + 48 // out + 192
    void *v_196; // *out + 49 // out + 196
    void *v_200; // *out + 50 // out + 200

    struct audio_device *adev; // *out + 51 // out + 204
    void *v_208; // *out + 52 // out + 208
    void *v_212; // *out + 53 // out + 212
};

/**
 ** Structure for Audio Input Stream
 ** Implement audio_stream_in structure
 **/
// size : 0xB0 -> 176
struct stream_in {
    struct audio_stream_in stream;
    pthread_mutex_t lock;// *in + 29  //  in + 116

    /* These variables are needed to save Android Request becuase pcm_config
         and audio_config are different */
    audio_io_handle_t handle;
    audio_devices_t devices;
    audio_source_t source;
    audio_input_flags_t flags;
    unsigned int sample_rate;
    audio_channel_mask_t channel_mask;
    audio_format_t format;

    audio_usage_id_t ausage;
    stream_state_type_t sstate;
    bool mixer_path_setup;

    /* PCM specific */
    struct pcm *pcminfo;
    struct pcm_config pcmconfig;

    unsigned long err_count;
    
    bool b_124; // *in + 31 // in + 124
    bool b_125;             // in + 125
    bool b_126;             // in + 126
    bool b_127;             // in + 127
    
    struct audio_config *config; // *in + 32 // in + 128
    
    
    struct audio_device *adev; // *in + 43 // in + 172
};

// size : 0x140 -> 320 
struct audio_device {
    struct audio_hw_device hw_device;
    pthread_mutex_t lock;// *+ 41 //  adev + 164 /* see note below on mutex acquisition order */
    audio_mode_t amode; // *+ 42 // adev + 168
    audio_devices_t out_device; // out_device; // *+ 43 // adev + 172
    // audio_devices_t :/system/media/audio/include/system/audio.h  844: typedef uint32_t audio_devices_t;
    audio_devices_t in_device; // *+ 44 // adev + 176
    bool mic_mute_state; // adev + 180
    bool screen_state; // adev + 181
    bool bt_headset_nrec; // adev + 182
    bool voice_call_wb; // adev + 183

    bool mic_nr_off; // adev + 184
    bool b_185; // adev + 185
    bool b_186; // adev + 186
    bool b_187; // adev + 187

    struct audio_route* audio_route;// *+ 47 // adev + 188
    struct mixer *mixer;// * +48 // adev + 192
    struct mixer *hifi_mixer;// * + 49 // adev + 196

    void *v_50;// * + 50 // adev + 200
    void *v_51;// * + 51 // adev + 204
    void *v_52;// * + 52 // adev + 208
    void *v_53;// * + 53 // adev + 212
    void *v_54;// * + 54 // adev + 216

    struct pcm *pcm_voice_out;// * + 55 // adev + 220 // VOICE_OUT
    struct pcm *pcm_voice_in;// * + 56 // adev + 224 // VOICE_IN

    struct pcm *pcm_be_out;// * + 57 // adev + 228 // VOICE_BE_OUT
    struct pcm *pcm_be_in;// * + 58 // adev + 232 // VOICE_BE_IN

    /* BT-SCO */
    struct pcm *pcm_btsco_out;// * + 59 // adev + 236      // SCO_OUT
    struct pcm *pcm_btsco_in;// * + 60 // adev + 240     // SCO_IN

    struct pcm *pcm_pa_out;// * + 61 // adev + 244      // PA_OUT
    struct pcm *pcm_pa_in;// * + 62 // adev + 248     // PA_IN

    void *v_63;      // * + 63 // adev + 252 
    struct audio_stream_out **stream_out;      // * + 64 // adev + 256 

    bool tfa_power_state; // adev + 260
    bool mute_state; // adev + 261
    bool b_262; // adev + 262
    bool b_263; // adev + 263
    
    int sample_rate; // * + 66 //  adev + 264
    
    bool b_268; // * + 67 // adev + 268
    bool output_stream_state; // adev + 269
    bool b_270;  // adev + 270
    bool b_271;  // adev + 271

    int headset_volume;      // * + 68 // adev + 272 
    int headphone_volume;    // * + 69 // adev + 276
    void *v_70;      // * + 70 // adev + 280
    void *v_71;      // * + 71 // adev + 284

    bool hifi_state; // * + 72 // adev + 288
    bool b_289; //  adev + 289
    bool b_290; // adev + 290
    bool b_291; // adev + 291
    
    int hifi_gain_state; // * + 73 // adev + 292
    int hifi_gain; // * + 74 // adev + 296
    int hifi_volume; // * + 75 // adev + 300
    
    bool is_oversea; // * + 76 // adev + 304
    bool b_305; // adev + 305
    bool b_306; // adev + 306
    bool b_307; // adev + 307
    
    int hifi_impedance; // * + 77 // adev + 308
    bool messagerecord_state; // * + 78 // adev + 312
    bool asr_ready; // adev + 313
    bool b_314; // adev + 314
    bool b_315; // adev + 315
    
    void *v_79; // * + 79 // adev + 316
};


#endif  // ANDROID_AUDIO_INTERFACE_H
