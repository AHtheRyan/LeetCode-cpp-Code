### 一年中的第几天
### Day of the Year

> 给你一个字符串 `date`，按 `YYYY-MM-DD` 格式表示一个 `现行公元纪年法` 日期。请你计算并返回该日期是当年的第几天。  
> 通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。  

> Given a string `date` representing a `Gregorian calendar` date formatted as `YYYY-MM-DD`, return the day number of the year.  

----------

#### I 耿直计算

没啥难度，直接按照每个月的天数累加就行了

```cpp
class Solution 
{
public:
    vector<int> month_to_days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dayOfYear(string& date) 
    {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + date[3] - '0';
        int month = (date[5] - '0') * 10 + date[6] - '0';
        int day = (date[8] - '0') * 10 + date[9] - '0';
        int ret = 0;
        for(int i = 1; i < month; ++i)
            ret += month_to_days[i];
        return (isLeap(year) && month > 2) ? ret + day + 1 : ret + day;
    }

    bool isLeap(int& year)
    {
        if(year % 400 == 0)
            return true;
        if(year % 4 == 0 && year % 100)
            return true;
        return false;
    }
};
```
