#include<iostream>
#include <pqxx/pqxx>
#include <Windows.h>


	    //�����, ��������� ��������� ��(�������).
		//�����, ����������� �������� ������ �������.
		//�����, ����������� �������� ������� ��� ������������� �������.
		//�����, ����������� �������� ������ � �������.
		//�����, ����������� ������� ������� � ������������� �������.
		//�����, ����������� ������� ������������� �������.
		//�����, ����������� ����� ������� �� ��� ������ � �����, �������, email ��� ��������.
int main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	try
	{
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=HomeWorkPQXX "
			"user=postgres "
			"password=kotoffski");
		
		pqxx::transaction t(c);

		t.exec("CREATE TABLE IF NOT EXISTS Client (id SERIAL PRIMARY KEY NOT NULL,first_name varchar(60) NOT NULL,last_name varchar(60) NOT NULL);");
		t.exec("CREATE TABLE IF NOT EXISTS Phone (id SERIAL PRIMARY KEY NOT NULL,client_id INTEGER NOT NULL REFERENCES Client(id),phone varchar(60) NOT NULL);");
		t.commit();
			
			
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}