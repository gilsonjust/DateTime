#ifndef _DATE_TIME_HPP
#define _DATE_TIME_HPP

#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>

#define EMPTY_SPACE " "
#define DATE_SEP "/"
#define HOUR_SEP ":"

#define FORMATED_TWO_DIGITS(x) std::setw(2) << std::setfill('0') << (x)

class DateTime
{
public:

    /*
        Get formated date and/or time as string - "hh:mm DD/MM/YYYY WW"
        hh = Hour
        mm = minute
        ss = second
        WW = Weekday
        DD = Day
        MM = Month
        YYYY = Year
    */
    std::string getFormatedStr(std::string format)
    {
        updateDateTime();

        std::ostringstream oss;
        std::string result;

        for (size_t i = 0; i < format.length(); ++i)
        {
            if (format.substr(i, 2) == "hh") 
            {
                oss.str(""); oss.clear();
                oss << FORMATED_TWO_DIGITS(m_hour);
                result += oss.str();
                i++;
            }
            else if (format.substr(i, 2) == "mm") 
            {

                oss.str(""); oss.clear();
                oss << FORMATED_TWO_DIGITS(m_min);
                result += oss.str();
                i++;
            }
            else if (format.substr(i, 2) == "ss") 
            {
                oss.str(""); oss.clear();
                oss << FORMATED_TWO_DIGITS(m_sec);
                result += oss.str();
                i++;
            }
            else if (format.substr(i, 2) == "DD")
            {
                oss.str(""); oss.clear();
                oss << FORMATED_TWO_DIGITS(m_day);
                result += oss.str();
                i++;
            }
            else if (format.substr(i, 2) == "MM") 
            {
                oss.str(""); oss.clear();
                oss << FORMATED_TWO_DIGITS(m_month);
                result += oss.str();
                i++;
            }
            else if (format.substr(i, 4) == "YYYY") 
            {
                oss.str(""); oss.clear();
                result += std::to_string(m_year);
                i += 3;
            }
            else if (format.substr(i, 2) == "WW") 
            {
                oss.str(""); oss.clear();
                result += getWeekDayAsStr(m_weekDay);
                i++;
            }
            else if (format[i] == ':' || format[i] == '/' || format[i] == ' ')
                result += format[i];
        }

        return result;
    }

    int getDay()
    {
        updateDate();
        return m_day;
    }

    int getMonth()
    {
        updateDate();
        return m_month;
    }

    int getYear()
    {
        updateDate();
        return m_year;
    }

    int getHour()
    {
        updateTime();
        return m_hour;
    }

    int getMinute()
    {
        updateTime();
        return m_min;
    }

    int getSecond()
    {
        updateTime();
        return m_sec;
    }

    std::time_t getCurrentTimestamp()
    {
        return std::time(nullptr);
    }

private:
    int m_day;
    int m_month;
    int m_year;
    int m_hour;
    int m_min;
    int m_sec;
    int m_weekDay;

    void updateDateTime()
    {
        updateDate();
        updateTime();
    }

    void updateDate()
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm time;
        localtime_s(&time, &currentTime);

        /* Get Date from OS and save it */
        m_day = time.tm_mday;
        m_month = time.tm_mon + 1;
        m_year = time.tm_year + 1900;
        m_weekDay = time.tm_wday;
    }

    void updateTime()
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm time;
        localtime_s(&time, &currentTime);

        /* Get Time from OS and save it */
        m_hour = time.tm_hour;
        m_min = time.tm_min;
        m_sec = time.tm_sec;
    }

    enum weekDay
    {
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    };

    std::string getWeekDayAsStr(int weekDay)
    {
        switch (weekDay)
        {
            case weekDay::SUNDAY:    return "Sunday";
            case weekDay::MONDAY:    return "Monday";
            case weekDay::TUESDAY:   return "Tuesday";
            case weekDay::WEDNESDAY: return "Wednesday";
            case weekDay::THURSDAY:  return "Thursday";
            case weekDay::FRIDAY:    return "Friday";
            case weekDay::SATURDAY:  return "Saturday";
        }

        return "Invalid weekday!";
    }
};

#endif