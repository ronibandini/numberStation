// Estacion de Numeros
// Taller de Contracultura Maker
// Abril 2024 @RoniBandini
// Seleccionar Heltec WiFi Kit 32


#include <DNSServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"

DNSServer dnsServer;
AsyncWebServer server(80);

String user_name;
String proficiency;
bool name_received = false;
bool proficiency_received = false;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>ESTACION DE NUMEROS</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>

  <audio controls autoplay loop src="data:audio/ogg;base64,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" />
Su navegador no soporta audios.
</audio>
  
  <br><br>Anote los  <font color=red>numeros presentados</font>.

  <form action="/get">
    <br>
    Operador: <input type="text" name="name">    
    <input type="hidden" name = "proficiency" size=15>     
    <br><br>
    <input type="submit" value=">> Continuar">
  </form>

  <br><br><i>Taller de Contracultura Maker</i>
  
</body></html>)rawliteral";

class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request){
    //request->addInterestingHeader("ANY");
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html); 
  }
};

void setupServer(){
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", index_html); 
      Serial.println("Client Connected");
  });
    
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
      String inputMessage;
      String inputParam;
  
      if (request->hasParam("name")) {
        inputMessage = request->getParam("name")->value();
        inputParam = "name";
        user_name = inputMessage;
        Serial.println(inputMessage);
        name_received = true;
      }

      if (request->hasParam("proficiency")) {
        inputMessage = request->getParam("proficiency")->value();
        inputMessage = request->getParam("name")->value();
        inputParam = "proficiency";
        proficiency = inputMessage;
        Serial.println(inputMessage);
        proficiency_received = true;
      }
      request->send(200, "text/html", "<b>Estacion de numeros</b><p>Operador "+inputMessage+". Gracias por haber registrado los numeros. <font color=red>Su colaboracion es muy importante</font><br><br>Contracultura Maker- <a href=\"/\">Regresar</a></p>");
  });
}


void setup(){
  //your other setup stuff...
  Serial.begin(115200);
  Serial.println();
  Serial.println("Setting up AP Mode");
  WiFi.mode(WIFI_AP); 
  WiFi.softAP("Estacion-De-Numeros");
  Serial.print("AP IP address: ");Serial.println(WiFi.softAPIP());
  Serial.println("Setting up Async WebServer");
  setupServer();
  Serial.println("Starting DNS Server");
  dnsServer.start(53, "*", WiFi.softAPIP());
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  //more handlers...
  server.begin();
  Serial.println("All Done!");
}

void loop(){
  dnsServer.processNextRequest();
  if(name_received && proficiency_received){
      Serial.print("Hello ");Serial.println(user_name);
      Serial.print("You have stated your proficiency to be ");Serial.println(proficiency);
      name_received = false;
      proficiency_received = false;
      Serial.println("We'll wait for the next client now");
    }
}
