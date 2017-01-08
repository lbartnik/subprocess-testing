// child.cpp : Defines the entry point for the console application.
//

/*
 h <- spawn_process("c:/Users/lbart/Source/subprocess-testing/x64/Debug/child.exe")

 #h <- spawn_process(file.path(R.home("bin"), "R.exe"), "--slave")
 process_send_signal(h, CTRL_C_EVENT)
 process_send_signal(h, CTRL_BREAK_EVENT)
 h

 process_write(h, "x\n")
 process_read(h)
*/


#include "stdafx.h"

#include <csignal>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

namespace
{
  volatile sig_atomic_t quit;

  void signal_handler(int sig)
  {
    signal(sig, signal_handler);
    cout << "signal received" << endl;
    quit = 1;
  }
}

int main()
{
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);
#ifdef SIGBREAK
  signal(SIGBREAK, signal_handler);
#endif
  /* etc */

  cout << "starting" << endl;

  while (!quit)
  {
    string s;
    cin >> s;
    cout << s << endl;
  }
  cout << "quit = " << quit << endl;
}