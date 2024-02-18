#include<iostream>

//Родительский класс Транспортное средство 
class Vehicle
{
protected:
	std::string name;
	int speed;
public:
	virtual double totalRacingTime(double distance_length)
	{
		return 0;
	}
};
 //Класс НАЗЕМНОЕ наследник от ТС 
class GroundVehicle : public Vehicle
{
protected:
	int driving_time_before_rest;
public:
};

//Класс ВОЗДУШНОЕ  наследник от ТС   
class AirVehicle : public Vehicle
{

};

//Класс ВЕРБЛЮД  наследник от НАЗЕМНОЕ 
class Camel : public GroundVehicle
{
protected:
	int duration_of_rest_1 = 5;
	int duration_of_rest_2 = 8;
public:
	Camel()
	{
		name = "Верблюд";
		speed = 10;
		driving_time_before_rest = 30;
		this-> duration_of_rest_1 = duration_of_rest_1;
		this->duration_of_rest_2 = duration_of_rest_2;
	}
	// времяпрохождения дистанции с учетом всех отдыхов  .
	double totalRacingTime(double distance_length) override
	{
		double total_time = (distance_length / speed);
		if (total_time > driving_time_before_rest)
		{
			int number_of_pit_stops = total_time / driving_time_before_rest;// кол-во остановок

			if (number_of_pit_stops < 2)
			{
				total_time = total_time + duration_of_rest_1;
				return total_time;
			}
			else
			{
				total_time = total_time + duration_of_rest_1 + ((number_of_pit_stops - 1) * duration_of_rest_2);
				return total_time;
			}
		}
		else
		{
			return total_time;
		}
	}
};/*
class Race
{
private:
	double distance_length;
public:
	void setDistanceLength()
	{
		std::cout << "Введите длину дистанции : ";
		std::cin >> distance_length;
	}
	double getDistanceLength()
	{
		return distance_length;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	Camel camel;
	Race race;
	race.setDistanceLength();
	std::cout << camel.totalRacingTime(race.getDistanceLength());
	return 0;
}*/
