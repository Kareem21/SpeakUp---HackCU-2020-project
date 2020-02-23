#include <Grove_LCD_RGB_Backlight.h>
#include <HttpClient.h>
#include "application.h"

 HttpClient http;  
 http_header_t headers[] = {  
    { "Content-Type", "application/json" },
    { NULL, NULL }   
 };
 
 http_request_t request;  
 http_response_t response;

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 30;

int BUTTON = D6;

void setup()
    { 
        Serial.begin(9600);
        
        request.hostname = "dvqfzo234b6ps.cloudfront.net";
        request.port = 80;
        
        pinMode(BUTTON, INPUT); 

        pinMode(A0,INPUT);
        lcd.begin(16, 2);
    
        lcd.setRGB(colorR, colorG, colorB);
        delay(1000);
    }
    
    
    void printResponse(http_response_t &response) {  
   Particle.publish("HTTP Response: ");
   Particle.publish((String)response.status);
   Particle.publish(response.body);
   
   Serial.println("HTTP Response: ");  
   Serial.println(response.status);  
   Serial.println(response.body);  
 }  
  
   

 
    
void loop() 
    {

        String date = Time.format("%Y-%m-%d");//This is not used
        int value=analogRead(A0);
        
        int buttonState;
        buttonState = digitalRead(BUTTON);
        
  
        
        if (value >= 0 && value <= 1365)
            {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("1. Racial");
                lcd.setCursor(0, 1);
                lcd.print("->");
                
                if(buttonState == HIGH)
                    {
                        lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print("Your incident");
                        lcd.setCursor(0,1);
                        lcd.print("has been logged");
                

                        request.path = "/incident/create";  
                        request.body = "{\"type\":\"Racial\", \"date\": \"2020-02-23\", \"location\": \"40.007965, -105.249142\"}";  
                        http.post(request, response, headers);  
                        printResponse(response);  
                    }
                
            }
            
        if (value >= 1365 && value <= 2730)
            {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("2. Dom. Violence");
                lcd.setCursor(0, 1);
                lcd.print("<- ->");
                
                if(buttonState == HIGH)
                    {
                        lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print("Your incident");
                        lcd.setCursor(0,1);
                        lcd.print("has been logged");
                

                        request.path = "/incident/create";  
                        request.body = "{\"type\":\"Domestic Violence\", \"date\": \"2020-02-23\", \"location\": \"40.007965, -105.249142\"}";  
                        http.post(request, response, headers);  
                        printResponse(response);  
                    }
            }
            
        if (value >= 2731 && value <= 5460)
            {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("3. Bullying");
                lcd.setCursor(0, 1);
                lcd.print("<-");
                
                if(buttonState == HIGH)
                    {
                        lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print("Your incident");
                        lcd.setCursor(0,1);
                        lcd.print("has been logged");
                

                        request.path = "/incident/create";  
                        request.body = "{\"type\":\"Bullying\", \"date\": \"2020-02-23\", \"location\": \"40.007965, -105.249142\"}";  
                        http.post(request, response, headers);  
                        printResponse(response);  
                    }
            } 
    
         


        delay(100);
 }
 
