# AVP Modificador de Skin del perfil de configuración
Este programa es una herramienta para personalizar la configuración del juego Aliens Vs Predator, forzando la selección de skins específicas para los personajes al modificar los valores correspondientes en los archivos de configuración del juego.

pordefecto este ptograma aplica las skins pre order para todos los personajes del juego.

## Características
1. **Detección de directorio**: Detecta automáticamente el directorio en función del nombre de usuario de Windows actual.
2. **Localización de archivo `.prf`**: Localiza el archivo `.prf` en el directorio del juego *Aliens Vs Predator* del usuario.
3. **Modificación hexadecimal**: Modifica direcciones hexadecimales específicas para cambiar las skins de los personajes del juego.

## Requisitos

- **Sistema Operativo**: Windows
- **Compilador C**: El programa está escrito en C, por lo que se necesita un compilador compatible, como `gcc`, para compilar el código.

## Archivos

- **`main.c`**: Archivo principal de código fuente que contiene las funciones para detectar y localizar el archivo `.prf` para modificar valores hexadecimales.

## Compilación

Para compilar el código, utiliza un compilador de C, como `gcc`. En la línea de comandos, navega al directorio donde se encuentra el archivo `main.c` y ejecuta:

```bash
gcc -o AVPModificadorSkin  main.c

```

Esto creará un archivo ejecutable llamado AVPModifier

## Uso
1. Ejecuta el programa compilado:

    ```bash
    ./AVPModificadorSkin 
    ```
2. El programa realizará las siguientes acciones:
    - Detectará el directorio del juego *Aliens Vs Predator* en función del nombre de usuario de Windows actual.
    - Localizará el archivo `.prf` en el directorio del juego.
    - Modificará las direcciones hexadecimales en el archivo `.prf` para cambiar las skins de los personajes del juego.

## Ejemplo

Supongamos que el usuario actual es `firagon` y el directorio de del archivo de configuración del juego es:

`C:\Users\Firagon\AppData\Local\AliensVsPredator\76561198190973581`

El archivo `.prf` se encuentra en:

`C:\Users\Firagon\AppData\Local\AliensVsPredator\76561198190973581\76561198190973581.prf`

El programa detectará el directorio del juego y localizará el archivo `.prf` en el directorio del juego. Construellendo la ruta completa del archivo `.prf`, el programa obtendrá la siguiente ruta dando como salida:

```bash
Ruta construida: C:\Users\Firagon\AppData\Local\AliensVsPredator\76561198190973581\76561198190973581.prf
```
El programa ha detectado el directorio del juego y ha localizado el archivo `.prf` en el directorio del juego.

Ahora que a encontrado el archivo `.prf`, modificara los valores hexadecimales en el archivo `.prf` para cambiar las skins de los personajes del juego.

```bash
Se modifico la posicion a25 con el valor 7 en el archivo C:\Users\Firagon\AppData\Local\AliensVsPredator\76561198190973581\76561198190973581.prf.
Se modifico la posicion a29 con el valor 2 en el archivo C:\Users\Firagon\AppData\Local\AliensVsPredator\76561198190973581\76561198190973581.prf.
Se modifico la posicion a2d con el valor 4 en el archivo C:\Users\Firagon\AppData\Local\AliensVsPredator\76561198190973581\76561198190973581.prf.
```

## Funciones
- obtener_directorio_AVP: Construye la ruta hacia el directorio de Aliens Vs Predator usando la variable de entorno USERNAME del sistema.

- es_directorio: Verifica si una ruta proporcionada corresponde a un directorio.

- generar_ruta_prf: Localiza el archivo .prf dentro del directorio del juego.

- modificar_archivo_prf: Modifica las direcciones hexadecimales específicas dentro del archivo .prf para cambiar las skins de los personajes.


## Personalización
Los valores y offsets hexadecimales en main() pueden ajustarse según sea necesario para cambiar diferentes configuraciones del juego.

### Direcciones Hexadecimales y Offsets
- Predator: offsets 0x00000A25, Valor 0x07
- Alien: offsets 0x00000A29, Valor 0x02
- Marine: offsets 0x00000A2D, Valor 0x04

Cada valor representa la posicion de skin de un personaje, y los offsets corresponden a la posicion especifica de los personaje.

## Valores de Skins (Hexadecimal)

### Predator
- **Dark**: `0x00`
- **Claw**: `0x01`
- **Stalker**: `0x02`
- **Hunter**: `0x03`
- **Spartan**: `0x04`
- **Wolf**: `0x05`
- **Lord**: `0x06`
- **Alien**: `0x07`

### Alien
- **Warrior**: `0x00`
- **Warrior Dome**: `0x01`
- **Number 6**: `0x02`
- **Warrior Ridged**: `0x03`
- **Praetorian**: `0x04`
- **Nethead**: `0x05`

### Marine
- **Franco**: `0x00`
- **Rookie**: `0x01`
- **Van Zandt**: `0x02`
- **Moss**: `0x03`
- **Kaneko**: `0x04`
- **Connor**: `0x05`
- **Gibson**: `0x06`
- **Johnson**: `0x07`

## Solución de Problemas
Si el programa no puede encontrar el directorio o archivo, asegúrate de que:
- El directorio de Aliens Vs Predator existe en la ubicación especificada. `C:\Users\%USERNAME%\AppData\Local\AliensVsPredator\`
 
 - El archivo `.prf` existane en la ubicaccion.
  `C:\Users\%USERNAME%\AppData\Loca7l\AliensVsPredator\NUMERO\NUMERO.prf.`
  
>si no existe puede modificar cualquier configuracion del juego esto ara que el archvi se cree.

## Aviso Legal

1. **Modificación de Archivos**: Este programa está diseñado para modificar archivos de configuración del juego *Aliens Vs Predator*. Al usar esta herramienta, asumes toda la responsabilidad por los cambios realizados en los archivos del juego.

2. **Copia de Seguridad**: Se recomienda encarecidamente realizar copias de seguridad de los archivos originales antes de utilizar este programa. Los cambios no deseados en los archivos pueden provocar problemas en el funcionamiento del juego.

3. **Uso Personal**: Este software debe utilizarse únicamente con fines personales. La distribución no autorizada de archivos del juego o la modificación de estos sin el consentimiento del titular de los derechos de autor puede ser ilegal.

4. **Limitación de Responsabilidad**: El autor de este programa no se hace responsable de ningún daño, pérdida de datos o problemas que puedan surgir del uso de esta herramienta. Utilizas este software bajo tu propio riesgo.

5. **Derechos de Autor**: *Aliens Vs Predator* y todos los derechos relacionados son propiedad de sus respectivos titulares. Este programa no está asociado ni respaldado por el desarrollador del juego.

## Licencia

Este proyecto está licenciado bajo la Licencia Pública General de GNU (GPL) v3. Para más detalles, consulta el archivo `LICENSE` en la raíz del proyecto o visita [GNU GPL](https://www.gnu.org/licenses/gpl-3.0.html).
