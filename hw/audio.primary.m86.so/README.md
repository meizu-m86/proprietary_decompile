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


### 反编译函数对照
```
sub_7D2C   get_output_buffer_size
sub_7344   out_write
sub_66B0   audio_test
sub_62E0   set_hifi_gain
sub_629C   stop_backend
sub_61B8   do_out_standby
sub_6164   stop_amplifier
sub_605C   do_in_standby
sub_4B48   adev_set_parameters
sub_4424   adev_open
sub_427C   set_hifi_volume
sub_41B0   adev_set_headset_volume
sub_52F4   adev_open_input_stream
sub_7F90   in_read


```