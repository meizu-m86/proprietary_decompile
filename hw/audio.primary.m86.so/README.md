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

sub_55E8   set_voice_volume
sub_6644   out_standby
sub_6676   in_standby
sub_6D54   set_route_by_array

sub_6E08   out_get_sample_rate
sub_6E0E   out_set_sample_rate
sub_6E16   out_get_buffer_size
sub_6E22   out_get_channels
sub_6E28   out_get_format
sub_6E2E   out_set_format
sub_6E34   out_dump
sub_6E38   out_set_parameters
sub_723C   out_get_parameters
sub_7320   out_add_audio_effect
sub_7324   out_remove_audio_effect
sub_7328   out_get_latency
sub_733E   out_set_volume
sub_7C90   out_get_render_position
sub_7C96   out_get_next_write_timestamp
sub_7C9C   out_get_presentation_position

sub_7DAC   in_get_sample_rate
sub_7DB2   in_set_sample_rate
sub_7DB8   in_get_buffer_size
sub_7DE0   in_get_channels
sub_7DE4   in_get_format
sub_7DE8   in_set_format
sub_7DEE   in_dump
sub_7F78   in_get_parameters
sub_7F84   in_add_audio_effect
sub_7F88   in_remove_audio_effect
sub_7F8C   in_set_gain
sub_8A54   in_get_input_frames_lost




```
