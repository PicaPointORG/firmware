#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include "esp8266-picapoint.h"

// Objeto de multi conexion
ESP8266WiFiMulti wifiMulti;

// Servidor web en el puerto 80
ESP8266WebServer server(80);

// Para añadir todas las redes del array
void addAPs() {
  int len = sizeof(APs) / sizeof(APs[0]);
  Serial.printf("\nNumero de redes Wifi guardadas: %d\n", len);
  for (int i = 0; i < len; i++)
    wifiMulti.addAP(APs[i].ssid, APs[i].pwd);
}

// Error 404
void notFound() {
  server.send(404, "text/plain", "404: Not found");
}

// Pagina principal
void cargarPagina() {
  String mainPage = principal2;
  server.send(200, "text/html", mainPage);
}

void setup() { 
  // Inicializar puerto serie
  Serial.begin(115200);

  // Inicializar el PIN 2 a salida y con bajo voltaje
  pinMode(PIN2, OUTPUT);
  digitalWrite(PIN2, LOW_OUTPUT);

  // Añadir la lista de redes a las que conectar
  addAPs();

  while (wifiMulti.run() != WL_CONNECTED) { // Esperar a que se conecte a la red Wifi mas potente de la lista
    delay(250);
  }

  snprintf(principal2, sizeof(principal2), principal, POST_PATH.c_str(), MAC.c_str());

  Serial.print("Conectado a: ");
  Serial.println(WiFi.SSID());
  Serial.print("Direccion IP local: ");
  Serial.println(WiFi.localIP());

  // Configurar Error 404
  server.onNotFound(notFound);

  // Configurar pagina principal a cargar
  server.on("/", cargarPagina);

  // Comenzar el servidor web
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  // Administracion de clientes automatica
  server.handleClient();
}