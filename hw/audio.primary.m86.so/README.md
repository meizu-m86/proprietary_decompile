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
sub_427C   set_hifi_volume
sub_7F90   in_read
sub_8BD4   get_next_buffer
sub_8A58   pcm_read_thread
sub_7DF4   in_set_parameters

sub_4424   adev_open
sub_46E0   adev_close
sub_470A   adev_init_check
sub_4B48   adev_set_parameters
sub_41B0   adev_set_headset_volume
sub_4710   adev_set_voice_volume
sub_4824   adev_set_master_volume
sub_482C   adev_set_mode
sub_4B34   adev_set_mic_mute
sub_4B3C   adev_get_mic_mute
sub_4B48   adev_set_parameters
sub_4E6C   adev_get_parameters
sub_4FD0   adev_get_input_buffer_size
sub_5068   adev_open_output_stream
sub_52B8   adev_close_output_stream
sub_52F4   adev_open_input_stream
sub_5520   adev_close_input_stream
sub_55A0   adev_dump
sub_55A4   adev_dumb2
sub_4364   set_mixer_value_by_name






```
