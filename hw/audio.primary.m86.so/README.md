### 对于audio hal 需要重建结构体
   1. struct audio_device
   2. struct stream_out
   3. struct stream_in

### m86 单独差异点
   1. hardware/libhardware/include/hardware/audio.h
      * struct audio_hw_device 中 int (*get_mic_mute)(const struct audio_hw_device *dev, bool *state); 后增加了
      * int (*dumb2);
      * int (*dumb3);
      * int (*set_headphone_volume)(struct audio_hw_device *dev, float volume);   