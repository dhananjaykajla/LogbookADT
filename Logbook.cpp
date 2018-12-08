#include <bits/stdc++.h>
#include <ctime>
#include "Logbook.h"
Logbook::Logbook()
{}
Logbook::Logbook(int month, int year)
{
  logMonth = month;
  logYear = year;
  int no_of_days = getDaysInMonth();
  for(int i=0; i<no_of_days ; i++)
  {
    putEntry(i,0);
  }
}
void Logbook::putEntry(int value)
{
  time_t tt;
  struct tm * ti;
  time(&tt);
  ti = localtime(&tt);
  logYear = ti->tm_year;
  logMonth = ti->tm_mon;
  int day = ti->tm_mday;
  putEntry(day,value);
}
void Logbook::putEntry(int day, int value)
{
  entries[day] = value;
}
int Logbook::getEntry(int day) const
{
  return entries[day];
}
int Logbook::getMonth() const
{
  return logMonth;
}
int Logbook::getYear() const
{
  return logYear;
}
int Logbook::getDaysInMonth() const
{
  switch (logMonth)
  {
    case 1:
    {
      return 31;
      break;
    }
    case 2:
    {
      if(isLeapYear())
      {
        return 29;
      }
      else
      {
        return 28;
      }
      break;
    }
    case 3:
    {
      return 31;
      break;
    }
    case 4:
    {
      return 30;
      break;
    }
    case 5:
    {
      return 31;
      break;
    }
    case 6:
    {
      return 30;
      break;
    }
    case 7:
    {
      return 31;
      break;
    }
    case 8:
    {
      return 31;
      break;
    }
    case 9:
    {
      return 30;
      break;
    }
    case 10:
    {
      return 31;
      break;
    }
    case 11:
    {
      return 30;
      break;
    }
    case 12:
    {
      return 31;
      break;
    }
  }
  return 0;
}
void Logbook::displayCalendar() const
{
  std::cout << "\t\t\t\t " << logMonth << " / " << logYear << '\n';
  std::cout << "  Sun      Mon      Tue      Wed      Thu      Fri      Sat\n";
  int current = getDayOfWeek(1);
  int k;
  for(k=0;k<current;k++)
  {
    std::cout << "         ";
  }
  for (int j = 1; j <= getDaysInMonth(); j++)
  {
    printf("%2d", j);
    std::cout << ' ';
    printf("%4d", getEntry(j));
    std::cout << "  ";
    if (++k > 6)
    {
      k = 0;
      printf("\n");
    }
  }
  if(k)
  {
    std::cout << '\n';
  }
}
int Logbook::getDayOfWeek ( int day ) const
{
  int month = logMonth, year = logYear;
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,4, 6, 2, 4 };
  year -= month < 3;
  return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}
bool Logbook::isLeapYear() const
{
  if(logYear % 100)
  {
    if(logYear % 4)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  else
  {
    if(logYear % 400)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  return false;
}
