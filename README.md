# Number Station

Este es un pequeño proyecto del Taller de Introducción a la Contracultura Maker

Los Number Stations son estaciones de onda corta caracterizadas por transmitir secuencias de números. Siempre están rodeados de un halo de misterio y suele ser dificil comprobar quienes son los responsables aunque se presupone que son agencias de seguridad. Sus origenes datan desde fines de la primera guerra mundial y en algunos casos transmiten morse también.

Si bien es posible transmitir radio a corta distancia con Arduino o bien conectar un Arduino a un emisor de radio, la idea es hacer un Captive Portal con ESP32, ponerle un nombre tentador y lograr que alguien se conecte. Ahí se reproducirá el audio de los números o una imagen con los números. Pueden incluso alimentar el ESP con un panel solar y dejarlo andando los días de sol o bien ponerle un power bank y llevarlo de paseo.

El primer ejemplo es con imagenes y el segundo con audio, ambos en base64.

# Herramientas para convertir a base 64

Audios a base 64 https://base64.guru/converter/encode/audio/mp3
Imagenes https://www.base64-image.de/  

Para audios, bajar a 16k y 32kbps
Para imagenes, usar width 200px

# Contacto

Roni Bandini
@ronibandini
