<h1>PROYECTO THEREMIN CON ESP32</h1>

<h2>¡CREA TU PROPIO THEREMIN EN CASA!</h2>

<p>¿Alguna vez soñaste con tocar un instrumento musical sin siquiera tocarlo? ¡Pues ahora puedes! Con este proyecto, podrás construir tu propio theremin utilizando un ESP32. Este instrumento único no solo te permitirá crear música sin contacto físico, sino que también te sumergirá en el fascinante mundo de la electrónica y la programación.</p>

<h3>REQUISITOS</h3>

<ul>
  <li><strong>Hardware:</strong>
    <ul>
      <li>ESP32</li>
      <li>Sensor de distancia (ej. HC-SR04)</li>
      <li>Altavoz</li>
      <li>Resistores y condensadores</li>
      <li>Protoboard y cables</li>
    </ul>
  </li>
  <li><strong>Software:</strong>
    <ul>
      <li>IDE de Arduino</li>
      <li>Biblioteca ESP32 para Arduino</li>
      <li>Biblioteca I2S para manejo de audio</li>
    </ul>
  </li>
</ul>

<h3>INSTRUCCIONES</h3>

<h4>1. CONFIGURACIÓN DEL ENTORNO</h4>

<ol>
  <li>Descarga e instala el <a href="https://www.arduino.cc/en/software">IDE de Arduino</a>.</li>
  <li>Añade la <strong>biblioteca ESP32</strong> a tu IDE de Arduino siguiendo <a href="https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/">estas instrucciones</a>.</li>
</ol>

<h4>2. CONFIGURACIÓN DE HARDWARE</h4>

<p>Conecta el <strong>sensor de distancia</strong> al ESP32:</p>

<ul>
  <li>VCC a 5V</li>
  <li>GND a GND</li>
  <li>Trig a GPIO XX (especificar pin)</li>
  <li>Echo a GPIO XX (especificar pin)</li>
</ul>

<p>Conecta el <strong>altavoz</strong> al ESP32 utilizando la biblioteca I2S.</p>

<h4>3. PROGRAMACIÓN</h4>

<ol>
  <li>Abre el archivo <code>Theremin_ESP32.ino</code> en el IDE de Arduino.</li>
  <li>Modifica los pines y funciones para adaptarlos al ESP32.</li>
  <li>Sube el código al ESP32.</li>
</ol>

<h4>4. PRUEBAS Y AJUSTES</h4>

<ol>
  <li>Ajusta el código según sea necesario para asegurar la funcionalidad del theremin.</li>
  <li>Prueba el theremin y realiza ajustes de calibración.</li>
</ol>

<h3>5. ¡DISFRUTA!</h3>

<p>¡Ahora puedes disfrutar tocando tu theremin hecho en casa! Experimenta con los sonidos, ajusta los parámetros y ¡sorprende a tus amigos con este increíble proyecto DIY!</p>

