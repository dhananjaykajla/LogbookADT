class Logbook
{
private:
public:
  Logbook();
  Logbook(int month, int year);
  void putEntry(int value);
  void putEntry(int day, int value);
  int getEntry(int day) const;
  int getMonth() const;
  int getYear() const;
  int getDaysInMonth() const;
  void displayCalendar() const;
protected:
  int getDayOfWeek ( int day ) const;
  bool isLeapYear() const;
  int logMonth,logYear,entries[31];
};
