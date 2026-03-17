#pragma once
#include<iostream>
#include <chrono>
#include <ctime>
#include<vector>
#include<string>
using namespace std;
class clsDate
{
private:
    int day;
    int month;
    int year;
    //split string function
    vector<string> split_string(string line, string space)
    {
        vector<string> vs;
        int pos = 0;
        string word;
        while ((pos = line.find(space)) != std::string::npos)
        {
            word = line.substr(0, pos);
            if (word != " ")
                vs.push_back(word);
            line.erase(0, pos + space.length());
        }
        if (line != "")
            vs.push_back(line);
        return vs;
    }

public:
    // Getters
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    // Setters
    void setDay(int d) {

        day = d;
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12)
            month = m;
        else month = 1;
    }

    void setYear(int y) {
        year = y;
    }

    //default constructor return system time
    clsDate()
    {

        time_t t = time(nullptr);
        tm now;
        localtime_s(&now, &t);
        year = now.tm_year + 1900;
        month = now.tm_mon + 1;
        day = now.tm_mday;
    }



    //constructor takes date as a string and splits it to day/month/year
    clsDate(string date)
    {
        vector<string>v = split_string(date, "/");
        this->day = stoi(v[0]);
        this->month = stoi(v[1]);
        this->year = stoi(v[2]);
    }

    //constructor takes day month year as int parameter
    clsDate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    //constructor take the order of the day in year and the year
    clsDate(int order, int year)
    {
        if (order > 366)order = 0;
        return;
        this->year = year;
        int month_index = 0;
        while (order > days(month_index, year))
        {
            order -= days(month_index, year);
            month_index++;
        }
        this->month = month_index + 1;
        this->day = order;
    }

    //is leap year function
    bool is_leap()
    {
        return (this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0);
    }

    // static is leap
    static bool is_leap(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    //function to return days in month
    static int days(int i, int year)
    {
        static int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (is_leap(year))
            daysInMonth[1] = 29;
        return daysInMonth[i - 1];

    }


    //normal print function
    void print()
    {
        print(*this);
    }

    static void print(clsDate d)
    {
        cout << "date: " << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << endl;
    }

    //days num in year
    static short days_num_inYear(int year)
    {
        return is_leap(year) ? 366 : 365;
    }

    short days_num_inYear()
    {
        return days_num_inYear(this->year);
    }

    //hours num in year
    static int hours_num_inYear(int year)
    {
        return  days_num_inYear(year) * 24;
    }

    int hours_num_inYear()
    {
        return   hours_num_inYear(year);
    }

    //min num in year
    static int  min_num_inYear(int year)
    {
        return  days_num_inYear(year) * 1440;
    }

    int  min_num_inYear()
    {
        return min_num_inYear(year);
    }

    //seconds num in year
    static  long  sec_num_inYear(int year)
    {
        return  days_num_inYear(year) * 86400;
    }

    long  sec_num_inYear()
    {
        return  sec_num_inYear(year);
    }

    //h,min,sec in month
    int hoursInMonth()
    {
        return hoursInMonth(month, year);
    }

    int minutesInMonth()
    {
        return minutesInMonth(month, year);
    }

    long secondsInMonth()
    {
        return secondsInMonth(month, year);
    }

    static int hoursInMonth(int month, int year)
    {
        return days(month, year) * 24;
    }

    static int minutesInMonth(int month, int year)
    {
        return hoursInMonth(month, year) * 60;
    }

    static  long secondsInMonth(int month, int year)
    {
        return minutesInMonth(month, year) * 60;
    }

    //non static day order function
    short day_order()
    {
        day_order(day, month, year);
    }
    //static day order function
    static short day_order(int day, int month, int year)
    {
        int a, m, y;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    //non static day name
    string day_name()
    {
        return day_name(*this);
    }

    //static day name
    static string day_name(clsDate d)
    {
        int order = day_order(d.day, d.month, d.year);
        string arr[] = { "sun","mon","tue","wed","thu","fri","sat" };
        return arr[order];
    }


    string month_name()
    {
       return month_name(this->month);
    }
    // static month name
    static string month_name(int month_order)
    {
        static string month[12] = { "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec" };
        if (month_order >= 1 && month_order <= 12) {
            return month[month_order - 1];
        }
        return "invalid";
    }


    //non static month calender
    void print_MonthCal()
    {
        print_MonthCal(month, year);
    }

    // static month calender
    static void print_MonthCal(int month, int year)
    {
        int days_num = days(month, year);
        int order_of_day = day_order(1, month, year);
        cout << "________________________" << month_name(month) << "____________________________" << endl;
        cout << "sun" << "   " << "mon" << "   " << "tue" << "   " << "wed" << "   " << "thu" << "   " << "fri" << "   " << "sat" << endl;
        int n = 0;
        for (int i = 0;i < order_of_day;i++)
        {
            cout << "      ";
            n++;
        }
        for (int j = 1;j <= days_num;j++)
        {
            if (j < 10)
                cout << " " << j << "     ";
            else
                cout << j << "     ";


            if (++n == 7)
            {
                n = 0;
                cout << endl;
            }

        }
        cout << endl;
        cout << "____________________________________________________________________________" << endl;
    }

    void print_yearCal()
    {
        print_yearCal(year);
    }

    static void print_yearCal(int year)
    {
        cout << "____________________________________________________________________________" << endl;
        cout << "\t\t\tYEAR: " << year << endl;
        for (int i = 1;i <= 12;i++)
        {
            print_MonthCal(i, year);
            cout << "__________________________________________________________________________" << endl;

        }
    }

    //to know how many days from the start of the year to the date
    int day_in_year()
    {
        day_in_year(*this);
    }

    static int day_in_year(clsDate d)
    {
        int s = 0;
        for (int i = 1;i < d.month;i++)
        {
            s = s + days(i, d.year);
        }
        s = s + d.day;
        return s;
    }


    void add_days(int addition_days)
    {
        add_days(*this, addition_days);

    }

    static void add_days(clsDate& d, int addition_days)
    {
        int total_days_added = day_in_year(d) + addition_days;
        d.month = 1;//منرجع لاول السنة
        int month_days = 0;
        while (true)
        {
            month_days = days(d.month, d.year);
            if (total_days_added > month_days)
            {
                total_days_added -= month_days;
                d.month++;
                if (d.month > 12) {
                    d.month = 1;
                    d.year++;
                }
            }
            else {
                d.day = total_days_added;
                break;
            }
        }

    }

    bool is_before_date(clsDate date2)
    {
        return is_before_date(*this, date2);
        
    }

   static bool is_before_date(clsDate date1,clsDate date2)
    {
        if (date1.year < date2.year)
            return true;//if date1 is before date2 return true
        else if (date1.month < date2.month && date1.year == date2.year)
            return true;
        else if (date1.day < date2.day && date1.month == date2.month && date1.year == date2.year)
            return true;
        else return false;
    }


    bool is_last_day_inMonth()
    {
        return is_last_day_inMonth(*this);
    }
    bool is_last_month()
    {
        return is_last_month(this->month);
    }
    static bool is_last_day_inMonth(clsDate d)
    {
        return d.day == days(d.month, d.year);
    }
    static bool is_last_month(int month)
    {
        return month == 12;
    }

    //int& year, int& month, int& day

    int ageInDays()
    {
        ageInDays(*this);
    }

    static int ageInDays(clsDate birth) {
        int days_num = 0;
        clsDate temp = birth; // نسخة مؤقتة حتى ما نغير الأصل
        clsDate today;
        while (temp.is_before_date(today))
        {
            days_num++;
            temp.increase_day();
        }
        return days_num;
    }

    void swap(clsDate& date1)
    {
        clsDate temp = date1;
        date1 = *this;
        *this = temp;
    }

    int diff_in_days(clsDate& date1)
    {
        int days_num = 0;
        int swapday = 1;
        if (is_before_date(date1))
        {
            swap(date1);
            swapday = -1;
        }
        clsDate temp = date1; // نسخة مؤقتة حتى ما نغير الأصل
        while (temp.is_before_date(*this)) {
            days_num++;
            temp.increase_day();
        }

        return days_num * swapday;

    }

    clsDate increase_day()
    {
        increase_day(*this);
        return *this;
    }
    static clsDate increase_day(clsDate &d)
    {
        if (is_last_day_inMonth(d))
        {
            d.day = 1;
            if (is_last_month(d.month))
            {
                d.month = 1;
                d.year++;
            }
            else d.month++;
        }
        else d.day++;
        return d;
    }

    clsDate increase_xday(int x)
    {
        increase_xday(*this, x);
        return *this;
    }
    static clsDate increase_xday(clsDate &d, int x)
    {
        add_days(d, x);
        return d;
    }

     clsDate increase_oneweek()
    {
          increase_oneweek(*this);
          return *this;
    }
    static clsDate increase_oneweek(clsDate& date)
    {
        increase_xday(date, 7);
        return date;
    }

     clsDate increase_xweek( int x)
    {
         increase_xweek(*this, x);
         return *this;
    }
    static clsDate increase_xweek(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            increase_oneweek(date);
        }
        return date;
    }


     clsDate increase_onemonth()
    {
         increase_onemonth(*this);
         return *this;
    }
    static clsDate increase_onemonth(clsDate& date)
    {
        if (date.month == 12)
        {
            date.month = 1;
            date.year++;
        }
        else date.month++;
        if (date.day > days(date.month, date.year))
        {
            date.day = days(date.month, date.year);
        }
        return date;
    }

     clsDate increase_xmonth( int x)
    {
         increase_xmonth(*this, x);
         return *this;
    }
    static clsDate increase_xmonth(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            increase_onemonth(date);
        }
        return date;
    }

     clsDate increase_oneyear()
    {
         increase_oneyear(*this);
         return *this;
    }
    static clsDate increase_oneyear(clsDate& date)
    {
        date.year++;
        return date;
    }

     clsDate increase_xyear( int x)
    {
         increase_xyear(*this, x);
         return *this;
    }
    static clsDate increase_xyear(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            increase_oneyear(date);
        }
        return date;
    }

     clsDate increase_decade()
    {
         increase_decade(*this);
         return *this;
    }
    static clsDate increase_decade(clsDate& date)
    {
        date.year += 10;
        return date;
    }

     clsDate increase_xDecade( int x)
    {
         increase_xDecade(*this, x);
         return *this;
    }
    static clsDate increase_xDecade(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            increase_decade(date);
        }
        return date;
    }


    //decrease
     clsDate decrease_oneday()
    {
         decrease_oneday(*this);
         return *this;
    }
    static clsDate decrease_oneday(clsDate& date)
    {
        if (date.day == 1)
        {
            date.day = days(date.month-1 , date.year);
            if (date.month == 1)
            {
                date.month = 12;
                date.year--;
            }
            else date.month--;
        }
        date.day--;
        return date;
    }

     clsDate decrease_xday( int x)
    {
         decrease_xday(*this, x);
         return *this;
    }
    static clsDate decrease_xday(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            decrease_oneday(date);
        }
        return date;
    }

    clsDate decrease_oneweek()
    {
        decrease_oneweek(*this);
        return *this;
    }
    static clsDate decrease_oneweek(clsDate& date)
    {
        decrease_xday(date, 7);
        return date;
    }

     clsDate decrease_xweek( int x)
    {
         decrease_xweek(*this, x);
         return *this;
    }
    static clsDate decrease_xweek(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            decrease_oneweek(date);
        }
        return date;
    }

     clsDate decrease_oneMonth()
    {
         decrease_oneMonth(*this);
         return *this;
    }
    static clsDate decrease_oneMonth(clsDate& date)
    {
        if (date.month == 1)
        {
            date.month = 12;
            date.year--;
        }
        else date.month--;
        if (date.day > days(date.month, date.year))
        {
            date.day = days(date.month, date.year);
        }
        return date;
    }

     clsDate decrease_xmonth(int x)
    {
         decrease_xmonth(*this, x);
         return *this;
    }
    static clsDate decrease_xmonth(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            decrease_oneMonth(date);
        }
        return date;
    }
    
     clsDate decrease_oneYear()
    {
         decrease_oneYear(*this);
         return *this;
    }
    static clsDate decrease_oneYear(clsDate& date)
    {
        date.year--;
        return date;
    }


     clsDate decrease_xYear( int x)
    {
         decrease_xYear(*this, x);
         return *this;
    }
    static clsDate decrease_xYear(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            decrease_oneYear(date);
        }
        return date;
    }

    clsDate decrease_oneDecade()
    {
        decrease_oneDecade(*this);
        return *this;
    }
    static clsDate decrease_oneDecade(clsDate& date)
    {
        date.year -= 10;
        return date;
    }

    clsDate decrease_xDecade(int x)
    {
        decrease_xDecade(*this, x);
        return *this;
    }
    static clsDate decrease_xDecade(clsDate& date, int x)
    {
        for (int i = 0;i < x;i++)
        {
            decrease_oneDecade(date);
            return date;
        }
    }

    bool end_of_week()
    {
       return end_of_week(*this);
    }
   static bool end_of_week(clsDate date)
    {
        return day_order(date.day,date.month,date.year) == 6;
    }

    bool is_weekend()
   {
       return is_weekend(*this);
   }
  static bool is_weekend(clsDate date)
    {
        return day_order(date.day,date.month,date.year) == 0 || day_order(date.day, date.month, date.year) == 6;
    }

  bool is_workDay()
  {
      return is_workDay(*this);
  }
   static bool is_workDay(clsDate date)
    {
        return !is_weekend(date);
    }

    //days until end of week
   int days_until_weekend()
   {
       days_until_weekend(*this);
   }
   static int days_until_weekend(clsDate date)
    {
        int order = day_order(date.day, date.month, date.year);
        return 6 - day_order(date.day, date.month, date.year);
    }
    //days until end of month
   int days_until_endMonth()
   {
       return days_until_endMonth(*this);
   }
   static int days_until_endMonth(clsDate date)
    {
        return days(date.month, date.year) - date.day;
    }
    //days until end of year
   int days_until_endYear()
   {
       return days_until_endYear(*this);
   }
   static int days_until_endYear(clsDate date)
    {
        if (is_leap(date.year))
            return 366 - day_in_year(date);
        else return 365 - day_in_year(date);
    }

   static int calculate_vacation_dur(clsDate from, clsDate to)
   {
       int vcay_count = 0;
       while (is_before_date(from, to))
       {
           if (is_workDay(from))
               vcay_count++;
          from= increase_day(from);
       }
       return vcay_count;
  }

   static void vacation_duration(clsDate from, clsDate to)
   {
       cout << "vacation starts: " << day_name(from) << endl;
       cout << "vacation ends: " << day_name(to) << endl;
       cout << "vacation duration is: " << calculate_vacation_dur(from, to) << endl;
   }

   static clsDate return_vacation_end(clsDate &start, int duration)
   {
       int weekend = 0;
       for (int i = 1;i < duration+weekend;i++)
       {
           if (!is_workDay(start)) 
            weekend++;
           start = increase_day(start);
       }
       return start;
   }
   static void vacation_end_day(clsDate start, int duration)
   {
       cout << "vacation starts: "; start.print();
       cout << "vacation duration : " << duration << endl;
       return_vacation_end(start, duration);
       cout << "vacation ends: " << day_name(start) << " ";start.print();
   }

   static void compare_dates(clsDate d1, clsDate d2)
   {
       if (is_before_date(d1, d2)) {
           cout << "date1: ";d1.print(); cout << " is before date2 ";d2.print();
       }
       else if (!is_before_date(d1, d2)) {
           cout << "date1: ";d1.print(); cout << " is after date2 ";d2.print();
       }
       else { cout << "date1: ";d1.print(); cout << " is equal to date2 ";d2.print(); }


   }
};

