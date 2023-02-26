@ECHO OFF
.\esptool.exe --chip esp8266 --port "COM5" --baud "115200"  --before default_reset --after hard_reset write_flash 0x0 "PicaPointESP8266.bin"
PAUSE