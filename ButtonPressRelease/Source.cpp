#include<iostream>
#include<Windows.h>
#include"SerialPort.h"

#define _SECURE_SCL_DEPRECATE 0

using namespace std;

char *port_name1 = "COM5";
char *port_name2 = "COM5";

int main()
{
     //SerialPort arduino1(port_name1);
     SerialPort arduino2(port_name2);

    /* if (arduino1.isConnected()) cout << "Connection Established To Arduino 1" << endl;
     else cout << "ERROR, check port name 1";*/
     if (arduino2.isConnected()) cout << "Connection Established To Arduino 2" << endl;
     else cout << "ERROR, check port name 2";

     int counter = 0;
     short prev_left = 0, curr_left = 0;
     short prev_right = 0, curr_right = 0;
     short prev_stop = 0, curr_stop = 0;

     //while(true)
     while (arduino2.isConnected())
     {
          if (GetAsyncKeyState(VK_LEFT))
               curr_left = 1;
          else
               curr_left = 0;
          if (prev_left != curr_left)
          {
               counter++;
               if (curr_left)
               {
                    //arduino1.writeSerialPort("1", MAX_DATA_LENGTH);
                    arduino2.writeSerialPort("1", MAX_DATA_LENGTH);
                    //cout << "Left pressed !" << endl;
               }
               else
               {
                    //arduino1.writeSerialPort("0", MAX_DATA_LENGTH);
                    arduino2.writeSerialPort("0", MAX_DATA_LENGTH);
                    //cout << "Left released !" << endl;
               }
               prev_left = curr_left;
          }

          if (GetAsyncKeyState(VK_RIGHT))
               curr_right = 1;
          else
               curr_right = 0;
          if (prev_right != curr_right)
          {
               counter++;
               if (curr_right)
               {
                    //arduino1.writeSerialPort("2", MAX_DATA_LENGTH);
                    arduino2.writeSerialPort("2", MAX_DATA_LENGTH);
                    //cout << "Right pressed !" << endl;
               }
               else
               {
                    //arduino1.writeSerialPort("0", MAX_DATA_LENGTH);
                    arduino2.writeSerialPort("0", MAX_DATA_LENGTH);
                    //cout << "Right released !" << endl;
               }
               prev_right = curr_right;
          }

          if (GetAsyncKeyState(VK_UP))
               curr_stop = 1;
          else
               curr_stop = 0;

          if (prev_stop != curr_stop)
          {
               counter++;
               if (curr_stop)
               {
                    //arduino1.writeSerialPort("2", MAX_DATA_LENGTH);
                    arduino2.writeSerialPort("3", MAX_DATA_LENGTH);
                    //cout << "Stopped!" << endl;
               }
               prev_stop = curr_stop;
          }

          if (GetAsyncKeyState(VK_DOWN)) {
               arduino2.writeSerialPort("0", MAX_DATA_LENGTH);
          }
     }
     return 0;
}