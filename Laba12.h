#ifndef Laba12
#define Laba12 

class DataAndTime{
private:
	int hour;
	int min;
	int sec;
	int year;
	int month;
	int day;
	const int month_array[12] = { 32,29,32,31,32,31,32,32,31,32,31,32 }; //массив дней в 12ти месяцах
	bool flag_year;	//високосный или нет
public:
	DataAndTime(); 
	DataAndTime(const DataAndTime& different);
	~DataAndTime(); 
	DataAndTime& operator=(const DataAndTime& different);
	DataAndTime& operator+(const DataAndTime& different);
	DataAndTime& operator-(const DataAndTime& different);
	void SetDay(int value);
	void SetMonth(int value);
	void SetYear(int value);
	void SetHour(int value);
	void SetMin(int value);
	void SetSec(int value);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const ;
	int GetHour() const;
	int GetMin() const;
	int GetSec() const;
	void output();
	int Input();
	void Checking();
	int k = 0;
};

#endif 
