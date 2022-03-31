
//----- (00009728) --------------------------------------------------------
int __fastcall cvq_open(int a1)
{
  int v2; // r0
  int v3; // r3
  FILE *v4; // r3
  int result; // r0
  int v6; // r5
  char *v7; // r0
  int v8[32]; // [sp+8h] [bp-118h] BYREF
  char v9[132]; // [sp+88h] [bp-98h] BYREF

  qmemcpy(v9, "Enable/Disable Streaming PATH/Endpoint", 0x80u);
  memset(v8, 0, sizeof(v8));
  qmemcpy(v8, "32800", 5);
  _android_log_print(3, "CVQStream", "audio cvq %s", "cvq_open");
  v2 = j_set_value(v9, (const char *)v8);
  v3 = *(_DWORD *)(a1 + 320056);
  if ( v2 )
    _android_log_print(6, "CVQStream", "set streaming failed:%p", v3);
  else
    _android_log_print(3, "CVQStream", "set streaming success:%p", v3);
  v4 = fopen("/dev/adnc2", "rb");
  *(_DWORD *)(a1 + 320056) = v4;
  if ( v4 )
  {
    _android_log_print(3, "CVQStream", "uart_char_dev open success:%p", v4);
    result = 0;
  }
  else
  {
    v6 = *(_DWORD *)_errno(0);
    v7 = strerror(v6);
    _android_log_print(6, "CVQStream", "uart_char_dev open failed:%p %d %s", 0, v6, v7);
    result = -1;
  }
  *(_DWORD *)(a1 + 12) = 0;
  return result;
}
// 2FC0: using guessed type int __fastcall _errno(_DWORD);
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);

//----- (00009848) --------------------------------------------------------
int __fastcall cvq_close(_DWORD *a1)
{
  int v2; // r5
  FILE *v3; // r0

  _android_log_print(3, "CVQStream", "audio cvq %s", "cvq_close");
  a1[80018] = 1;
  a1[4] = 0;
  pthread_join(a1[5], 0);
  pthread_join(a1[8], 0);
  v2 = 0;
  v3 = (FILE *)a1[80014];
  if ( v3 )
  {
    v2 = fclose(v3);
    a1[80014] = 0;
    _android_log_print(3, "CVQStream", "#### uart closed, ret = %d ####", v2);
  }
  a1[3] = 0;
  return v2;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);

//----- (000098C4) --------------------------------------------------------
int __fastcall readdirect(int a1)
{
  if ( *(_DWORD *)(a1 + 8) )
    return 0;
  else
    return (*(int (**)(void))(a1 + 320096))();
}

//----- (000098D8) --------------------------------------------------------
size_t __fastcall cvq_read(_DWORD *a1, char *a2, int a3)
{
  size_t v5; // r6
  int v6; // r7
  unsigned int v7; // r0

  v5 = a3;
  v6 = a1[80013] - a1[80012];
  if ( v6 >= a3 )
    goto LABEL_8;
  if ( a1[2] )
    goto LABEL_6;
  v7 = a1[4];
  a1[4] = v7 + 1;
  if ( v7 >= 0x28 )
  {
    a1[2] = 1;
    _android_log_print(3, "CVQStream", "#### CVQ read timeout, force end ####");
    if ( !a1[2] )
    {
LABEL_7:
      v5 = v6;
LABEL_8:
      a1[4] = 0;
      qmemcpy(a2, (char *)a1 + a1[80012] + 40, v5);
      a1[80012] += v5;
      return v5;
    }
LABEL_6:
    _android_log_print(3, "CVQStream", "#### end of uart data ####");
    goto LABEL_7;
  }
  return 0;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);

//----- (0000996C) --------------------------------------------------------
int __fastcall read_on_thread(int a1)
{
  int *v2; // r9
  int v3; // r0
  int v4; // r7
  int v5; // r0
  int v6; // r5

  _android_log_print(3, "CVQStream", "readonthread called");
  _android_log_print(3, "CVQStream", "audio cvq %s", "read_on_thread");
  if ( !*(_DWORD *)(a1 + 320072) )
  {
    v2 = (int *)(a1 + 320052);
    do
    {
      v3 = *v2;
      v4 = 320;
      if ( *v2 + 320 > 160000 )
        v4 = 160000 - v3;
      if ( *(_DWORD *)(a1 + 320040) + v4 <= *(_DWORD *)(a1 + 320044) )
      {
        v5 = (*(int (__fastcall **)(int, int, int))(a1 + 320088))(a1, a1 + 40 + v3, v4);
        v6 = v5;
        if ( v5 >= 1 )
          *v2 += v5;
        usleep(0x3E8u);
        if ( v6 < v4 )
          return 0;
      }
      else
      {
        if ( *(_DWORD *)(a1 + 8) )
          return 0;
        _android_log_print(
          3,
          "CVQStream",
          "#### read_on_thread: UART data read thread lagging so wait till data is available ... ####");
        usleep(0x3E8u);
      }
    }
    while ( !*(_DWORD *)(a1 + 320072) );
  }
  return 0;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);

//----- (00009A64) --------------------------------------------------------
int __fastcall read_on_raw_data_thread(pthread_t *a1)
{
  int *v2; // r6
  int *v3; // r9
  int v4; // r11
  int v5; // r7
  int v6; // r0
  int wrapper; // r0
  int v8; // r5

  _android_log_print(3, "CVQStream", "#### read_on_raw_data_thread called ####");
  a1[80010] = 0;
  v2 = (int *)(a1 + 80014);
  v3 = (int *)(a1 + 80011);
  v4 = 0;
  do
  {
    if ( a1[80018] )
      break;
    v5 = 4096;
    v6 = *v3;
    if ( *v3 + 4096 > 160000 )
      v5 = 160000 - v6;
    wrapper = j_uart_dev_read_wrapper((int)a1, (int)a1 + v6 + 160040, 1, v5, *v2);
    v8 = wrapper;
    if ( wrapper < 1 )
      break;
    a1[4] = 0;
    *v3 += wrapper;
    if ( !v4 )
    {
      _android_log_print(3, "CVQStream", "#### Start read_on_thread for UART data parsing and decoding ####");
      j_cvq_start_decode(a1);
      v4 = 1;
    }
  }
  while ( v8 >= v5 );
  if ( *v2 )
  {
    fclose((FILE *)*v2);
    *v2 = 0;
    _android_log_print(3, "CVQStream", "#### uart closed ####");
  }
  return 0;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);

//----- (00009B50) --------------------------------------------------------
int __fastcall uart_dev_read_wrapper(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r3
  int v9; // r6

  v7 = *(_DWORD *)(a1 + 320072);
  if ( v7 )
  {
    _android_log_print(6, "CVQStream", "#### cvqStream->exit = %d, skipping UART read ... ####", v7);
    return -1;
  }
  else
  {
    _android_log_print(3, "CVQStream", "#### Before UART read ####");
    v9 = _fread_chk(a2, a3, a4, a5, -1);
    _android_log_print(3, "CVQStream", "#### After  UART read (req, actual) = (%d, %d) ####", a4 * a3, v9);
  }
  return v9;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);
// 30C8: using guessed type int __fastcall _fread_chk(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00009BD4) --------------------------------------------------------
int __fastcall cvq_start_decode(pthread_t *a1)
{
  int result; // r0

  _android_log_print(3, "CVQStream", "#### Start CVQ UART packet and/or data parsing/decoding called ####");
  result = pthread_create(a1 + 8, 0, (void *(*)(void *))read_on_thread, a1);
  if ( result <= -1 )
    return _android_log_print(6, "CVQStream", "#### read_on_thread() thread creation failed ####");
  return result;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);

//----- (00009C24) --------------------------------------------------------
int __fastcall cvq_start(pthread_t *a1)
{
  int result; // r0

  _android_log_print(3, "CVQStream", "#### start CVQ read thread called ####");
  result = pthread_create(a1 + 5, 0, (void *(*)(void *))read_on_raw_data_thread, a1);
  if ( result <= -1 )
    return _android_log_print(6, "CVQStream", "#### read_on_raw_data_thread() thread creation failed ####");
  return result;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);
// 9A64: using guessed type int read_on_raw_data_thread();

//----- (00009C74) --------------------------------------------------------
int __fastcall uart_read_wrapper(_DWORD *a1, char *a2, size_t a3)
{
  size_t v4; // r4
  int v5; // r3
  int v7; // r0

  v4 = a3;
  v5 = a1[80018];
  if ( v5 )
  {
    _android_log_print(6, "CVQStream", "#### cvqStream->exit = %d, skipping UART data decoding ... ####", v5);
  }
  else
  {
    v7 = a1[80010];
    if ( v7 + a3 >= a1[80011] )
    {
      _android_log_print(3, "CVQStream", "#### skipping UART data decoding as UART read thread is lagging ... ####");
      return 0;
    }
    qmemcpy(a2, (char *)a1 + v7 + 160040, a3);
    if ( a2 )
    {
      a1[80010] += v4;
      return v4;
    }
  }
  return -1;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);

//----- (00009D00) --------------------------------------------------------
int __fastcall pcm_read_uart_char_dev(_DWORD *a1, _WORD *a2, int a3)
{
  _WORD *v4; // r4
  int v5; // r10
  char *v6; // r7
  signed int *v7; // r8
  int v8; // r5
  int *v9; // r9
  int v10; // r0
  signed int v11; // r11
  signed int v12; // r2
  int v13; // r0
  int wrapper; // r0
  signed int v15; // r0
  int v16; // r0
  bool v17; // zf
  char *v18; // r1
  _DWORD *v19; // r0
  size_t v20; // r2
  int v21; // r0
  int v22; // r12
  int v23; // lr
  int v24; // r2
  int v25; // r11
  int v26; // r3
  int v27; // r1
  __int16 v28; // r0
  int v29; // r1
  int v30; // lr
  bool v31; // zf
  _DWORD *v32; // r0
  unsigned __int8 *v33; // r0
  int v34; // r2
  int v35; // t1
  _DWORD *v37; // [sp+1Ch] [bp-34h]
  char v38[5]; // [sp+20h] [bp-30h] BYREF
  unsigned __int8 v39; // [sp+25h] [bp-2Bh]
  char v40; // [sp+26h] [bp-2Ah] BYREF
  char v41; // [sp+27h] [bp-29h] BYREF

  v4 = a2;
  v5 = a3 / 2;
  if ( a3 <= 1 )
  {
    v32 = a1 + 3;
    v8 = 0;
  }
  else
  {
    v6 = (char *)a2 + a3 / 2;
    v7 = a1 + 80017;
    v8 = 0;
    v9 = a1 + 80018;
    v37 = a1 + 3;
LABEL_3:
    v10 = *v9;
    v11 = v5 - v8;
    while ( !v10 )
    {
      v12 = *v7;
      if ( *v7 <= v11 )
      {
        if ( v12 < 1 )
          goto LABEL_13;
        wrapper = j_uart_read_wrapper(a1, v6, v12);
        if ( wrapper )
        {
          if ( wrapper == -1 )
            break;
          v15 = *v7;
          *v7 = 0;
          v8 += v15;
          v6 += v15;
LABEL_13:
          if ( a1[2] )
            break;
          v16 = j_uart_read_wrapper(a1, &v40, 2u);
          if ( v16 )
          {
            if ( v16 == -1 )
              break;
            do
            {
              v17 = v40 == 18;
              if ( v40 == 18 )
                v17 = v41 == 52;
              if ( v17 || *v9 )
                break;
              if ( v41 == 18 )
              {
                v18 = &v41;
                v40 = 18;
                v19 = a1;
                v20 = 1;
              }
              else
              {
                v19 = a1;
                v18 = &v40;
                v20 = 2;
              }
            }
            while ( j_uart_read_wrapper(v19, v18, v20) != -1 );
            v21 = j_uart_read_wrapper(a1, v38, 6u);
            if ( v21 )
            {
              if ( v21 == -1 )
                break;
              v22 = v39;
              v23 = (unsigned __int8)v38[0];
              v24 = (unsigned __int8)v38[1];
              v17 = (v39 & 0x40) == 0;
              v25 = v39 & 0x80;
              v26 = (unsigned __int8)(v39 & 0x40) >> 6;
              v27 = (unsigned __int8)v38[2];
              v28 = (unsigned __int8)v38[3];
              a1[2] = v25;
              a1[3] = v26;
              if ( v17 )
              {
                *v9 = 1;
                a1[2] = 1;
                _android_log_print(3, "CVQStream", "#### CVQ read aborted because normal streaming data received ####");
                v8 = 0;
                break;
              }
              v29 = v27 | (__int16)(v28 << 8);
              v30 = v23 | (16 * v24) & 0xF00;
              if ( v29 < 320 )
              {
                if ( v29 != 80 && v29 != 160 )
                  goto LABEL_37;
              }
              else if ( v29 != 320 )
              {
                v31 = v29 == 640;
                if ( v29 != 640 )
                  v31 = v29 == 1280;
                if ( !v31 )
                {
LABEL_37:
                  v25 = 0;
                  v29 = 0;
                  a1[2] = 0;
                }
              }
              *v7 = v29;
              _android_log_print(
                3,
                "CVQStream",
                "#### Frame found - < ID : PKT # : LEN : EOD : MU-Law : EOD_BYTE > = <%5d : %5d : %5d : %5d : %5d : %5d> ####",
                v30,
                v24 & 0xF,
                v29,
                v25,
                v26,
                v22);
            }
          }
LABEL_39:
          if ( v5 > v8 )
            goto LABEL_3;
          break;
        }
      }
      else
      {
        v13 = j_uart_read_wrapper(a1, v6, v5 - v8);
        if ( v13 )
        {
          if ( v13 == -1 )
            break;
          v6 += v11;
          v8 = v5;
          *v7 -= v11;
          goto LABEL_39;
        }
      }
      v10 = *v9;
    }
    v32 = v37;
  }
  if ( *v32 )
  {
    if ( v8 >= 1 )
    {
      v33 = (unsigned __int8 *)v4 + v5;
      v34 = v8;
      do
      {
        v35 = *v33++;
        --v34;
        *v4++ = word_EE88[v35];
      }
      while ( v34 );
    }
    v8 *= 2;
  }
  return v8;
}
// 2FD8: using guessed type int _android_log_print(_DWORD, _DWORD, const char *, ...);
// EE88: using guessed type _WORD word_EE88[256];

//----- (00009F24) --------------------------------------------------------
int __fastcall cvq_init(int a1) // a1 = malloc(0x4E264u);
{
  _QWORD *v1; // r0

  *(_DWORD *)(a1 + 320076) = cvq_open;
  *(_DWORD *)(a1 + 320080) = cvq_close;
  *(_DWORD *)(a1 + 320084) = cvq_start;
  *(_DWORD *)(a1 + 320088) = readdirect;
  *(_DWORD *)(a1 + 320092) = cvq_read;
  *(_DWORD *)(a1 + 320096) = pcm_read_uart_char_dev;
  *(_DWORD *)(a1 + 320068) = 0;
  *(_QWORD *)a1 = 0LL;
  *(_QWORD *)(a1 + 8) = 0LL;
  *(_DWORD *)(a1 + 320072) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 320056) = 0;
  v1 = (_QWORD *)(a1 + 320040);
  *v1 = 0LL;
  v1[1] = 0LL;
  return 0;
}
// 9728: using guessed type int cvq_open();
// 9D00: using guessed type int pcm_read_uart_char_dev();

// nfuncs=396 queued=185 decompiled=185 lumina nreq=0 worse=0 better=0
// ALL OK, 185 function(s) have been successfully decompiled
