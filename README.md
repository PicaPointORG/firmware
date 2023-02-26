# Requisitos de software
- Python
- Navegador web

# Como flashear el binario

En esta carpeta se ha proporcionado un ejecutable llamado `esptool.exe`. Es el encargado de flashear en el microcontrolador.
Para flashear nuestro binario proporcionado deberás:

- Ejecutar el script `flash.bat` o ejecutar este comando en un terminal:
```
.\esptool.exe --chip esp8266 --port "COM5" --baud "115200" ""  --before default_reset --after hard_reset write_flash 0x0 "PicaPointESP8266.bin"
```

# Manual de uso
- Deberás acceder con tu navegador web preferido a la direccion que aparezca en la terminal Serial.

Para ver el log del Serial, usar Arduino IDE (por ahora).