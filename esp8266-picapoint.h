// Estructura de los datos de las redes a almacenar
struct structAPs {
  const char* ssid;
  const char* pwd;
};

/* Credenciales de las redes wifi a las que se quiere conectar
 * Para añadir una nueva, se copia esta estructura de datos abajo de la ultima:
 *   {
 *   .ssid = "SSID de la red",
 *   .pwd = "contraseña de la red",
 *   },
*/
const structAPs APs[] = {
  {
    .ssid = "Nombre de una red",
    .pwd = "Contraseña de una red",
  },
};

// Constantes para inicializacion del GPIO
const int PIN2 = 2;
const int HIGH_OUTPUT = 0;
const int LOW_OUTPUT = 1;

// Constantes de conexion
String MAC = WiFi.macAddress();
String POST_PATH = "http://192.168.95.190:8080/maquina/update"; // Direccion IP del servidor con la base de datos

// HTML Constantes
const char principal[] = R"=====(
<!DOCTYPE html>
<html>
	<head>
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css">
	</head>
	<body style="text-align:center;">
    <br>
		<h1>PicaPoint <small class="text-muted">ESP8266 Web Server</small></h1>
    <br><br>
    <div>
      <label for="idProducto" style="font-weight: bold;">Especifica el ID del producto:</label>
      <br>
      <input type="text" id="idProducto" placeholder="ID"/>
    </div>
    <br><br>
    <button onClick="peticion()" class="btn btn-primary">Notificar</button>
	</body>
  <script>
    function peticion() {
      id = document.getElementById('idProducto').value
      if(id != "") {
        fetch("%s", {method: "POST", headers: {'Content-Type':'application/x-www-form-urlencoded'}, body: "mac=%s&idProducto=" + id, mode: 'no-cors'})
          .then(res => alert("Peticion correcta"))
          .catch(err => alert(err));
      } else {
        alert("Rellena el campo ID!")
      }
    }
  </script>
</html>
)=====";

char principal2[sizeof(principal)/sizeof(principal[0]) + sizeof(MAC)/sizeof(MAC[0]) + sizeof(POST_PATH)/sizeof(POST_PATH[0]) + 30] = {};
