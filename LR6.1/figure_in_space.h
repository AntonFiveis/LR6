#pragma once
#include <vector>
#include <iostream>
class figure_in_space
{
protected:
	double height;
	std::vector<double> sides;
	double square_of_triangle(double, double, double);
	double square(double,double,double,double);
public:
	figure_in_space(double height,std::vector<double> sides) :height(height),sides(sides) {};
	figure_in_space() {
		std::cout << "Input height:";
		std::cin >> height;
	};
	virtual double full_square() = 0;
	virtual double volume() = 0;
	virtual void input_sides() = 0;
};
class piramide : public figure_in_space 
{
public:
	void input_sides();
	double full_square();
	double volume();
	piramide(double , std::vector<double> );
	piramide() :figure_in_space() { input_sides(); };
};
class prisma : public figure_in_space
{
public:
	void input_sides();
	prisma(double, std::vector<double>);
	prisma();
	double full_square();
	double volume();
};

class half_piramide : public figure_in_space
{
public:
	void input_sides();
	half_piramide(double , std::vector<double> );
	double full_square();
	double volume();
	half_piramide() :figure_in_space() { input_sides(); };
};
