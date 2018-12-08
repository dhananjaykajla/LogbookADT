#include<bits/stdc++.h>
#include"Logbook.h"
using namespace std;
int main()
{
  Logbook coffee(1,2003);
  coffee.putEntry(1,5);
  coffee.putEntry(15,2);
  std::cout << "Month/Year : " << coffee.getMonth() << '/' << coffee.getYear() << '\n';
  coffee.displayCalendar();
}
