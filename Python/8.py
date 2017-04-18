import calendar

def input_date():
    year = int(input('년도를 입력하세요 : '))
    month = int(input('월을 입력하세요 : '))
    day = int(input('일을 입력하세요 : '))
    return year, month, day

class DayName(object):
    def __init__(self, year, month, day):
        self._year = year
        self._month = month
        self._day = day
        self._name = None
        self._year_month_days = [0,31,28,31,30,31,30,31,31,30,31,30,31]
        self._day_names = ['일요일', '월요일', '화요일', '수요일', '목요일', '금요일', '토요일']

        self._calculate_day_name()

    def _is_leap(self, year):
        leap = year % 4 == 0    # 4로 나누어지면 윤년이다.

        if leap and year % 100 == 0:    # 100으로 나누어지면 평년이다.
            leap = False

            if year % 400 == 0:         # 400으로 나누어지면 윤년이다.
                leap = True
        
        return leap

    def _calculate_day_name(self):
        total_days = 0

        for item in range(1, self._year):
            total_days += item * 366 if self._is_leap(self._year) else 365
        
        for item in range(1, self._month):
            total_days += item * self._year_month_days[item]
            
        if self._is_leap(self._year) and self._month >= 3:
            total_days += 1
             

        total_days += self._day
        remainder = total_days % 7
        self._name = self._day_names[remainder]

    def get_name(self):
        return self._name

if __name__ == '__main__':
    year, month, day = input_date()
    day_name = DayName(year, month, day)
    print(day_name.get_name())

     