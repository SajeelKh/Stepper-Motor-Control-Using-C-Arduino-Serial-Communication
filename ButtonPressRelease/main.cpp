#include <windows.h>
#include <iostream>
#include <time.h>
#include <chrono>
//#include <fstream>
using namespace std;

int main1()
{
     int counter = 0;
     clock_t start;
     clock_t tmp;
     clock_t end;
     /*std::chrono::steady_clock::time_point begin;
     std::chrono::steady_clock::time_point end;*/

     //ofstream myfile;
     short prev_left = 0, curr_left = 0;
     short prev_right = 0, curr_right = 0;
     //myfile.open("c:\\example.txt");
     while (true)
     {

          if (GetAsyncKeyState(VK_LEFT)) {
               curr_left = 1;
               if (prev_left == 0) {
                    start = 0;
                    start = clock();
                    std::cout << "Clock Starts: " << start;
                    //begin = std::chrono::steady_clock::now();
               }
          }

          else
               curr_left = 0;

          if (prev_left != curr_left)
          {
               counter++;
               if (curr_left)
               {
                    //myfile << "Escape pressed : " << counter << endl;
                    tmp = clock() - start;
                    tmp = ((float)tmp) / CLOCKS_PER_SEC;
                    cout << endl << tmp << endl;
                    if(tmp > 0.5)
                         cout << "Left pressed !" << endl;
               }
               else
               {
                    /*tmp = clock() - start;
                    printf("It took me %d clicks (%f seconds).\n", tmp, ((float)tmp) / CLOCKS_PER_SEC);

                    end = clock() - start;
                    printf("It took me %d clicks (%f seconds).\n", tmp, ((float)tmp) / CLOCKS_PER_SEC);*/

                    //myfile << "Escape released : " << counter << endl;
                    cout << "Left released !" << endl << endl;
               }
               prev_left = curr_left;
          }

          if (GetAsyncKeyState(VK_RIGHT)) {
               curr_right = 1;
               if (prev_right == 0) {
                    /*t = 0;
                    t = clock();*/
                    /*std::cout << "Clock Starts: " << t;*/
                    //begin = std::chrono::steady_clock::now();
               }
          }
          else
               curr_right = 0;

          if (prev_right != curr_right)
          {
               counter++;
               if (curr_right)
               {
                    //myfile << "Escape pressed : " << counter << endl;
                    cout << "Right pressed !" << endl;
               }
               else
               {
                   /* t = clock() - t;
                    printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);*/
                    //myfile << "Escape released : " << counter << endl;
                    cout << "Right released !" << endl;
               }
               prev_right = curr_right;
          }
     }
     //myfile.close();
     return 0;
}