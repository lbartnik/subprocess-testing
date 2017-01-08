// child.cpp : Defines the entry point for the console application.
//

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

  while (!quit)
  {
    string s;
    cin >> s;
    cout << s << endl;
  }
  cout << "quit = " << quit << endl;
}