#include "figure_in_space.h"
void piramide::input_sides()
{
	std::cout << "Input sides:" << std::endl;
	sides.resize(6);
	for (int i = 0; i < 6; i++) {
		std::cin >> sides[i];
	}
}
double piramide::full_square() {
	double s = 0;
	s+= square_of_triangle(sides[0], sides[1], sides[2]);
	s+= square_of_triangle(sides[1], sides[3], sides[4]);
	s+= square_of_triangle(sides[2], sides[3], sides[5]);
	s+= square_of_triangle(sides[0], sides[4], sides[5]);
	
	return s;
}
double piramide::volume()
{
	return height*square_of_triangle(sides[0],sides[1],sides[2])/3;
}
piramide::piramide(double height, std::vector<double> sides) :
	figure_in_space(height, sides) {
}

double half_piramide::full_square()
{
	double s = square_of_triangle(sides[0], sides[1], sides[2]);
	s += square_of_triangle(sides[3], sides[4], sides[5]);
	s += square(sides[0], sides[6], sides[3], sides[7]);
	s += square(sides[1], sides[7], sides[4], sides[8]);
	s += square(sides[2], sides[8], sides[5], sides[6]);
	return s;
}
double half_piramide::volume()
{
	double s1 = square_of_triangle(sides[0], sides[1], sides[2]);
	double s2 = square_of_triangle(sides[3], sides[4], sides[5]);
	return height * (s1 + s2 + sqrt(s1 * s2))/3;
}
void half_piramide::input_sides() {
	std::cout << "Input sides:" << std::endl;
	sides.resize(9);
	for (int i = 0; i < 9; i++) {
		std::cin >> sides[i];
	}
}
half_piramide::half_piramide(double height, std::vector<double> sides) :
	figure_in_space(height, sides) {
}


double prisma::full_square()
{
	double ans = 2 * square_of_triangle(sides[0], sides[1], sides[2]);
	for (int i = 0; i < 3; i++) {
		ans += square(sides[i], sides[3], sides[i], sides[3]);
	}
	return ans;
}
double prisma::volume()
{
	return height * square_of_triangle(sides[0], sides[1], sides[2]);
}
void prisma::input_sides() {
	std::cout << "Input sides:" << std::endl;
	sides.resize(4);
	for (int i = 0; i < 4; i++) {
		std::cin >> sides[i];
	}
}
prisma::prisma(double height, std::vector<double> sides) :
	figure_in_space(height, sides) {
}
prisma::prisma() : figure_in_space() { 	input_sides(); };


double figure_in_space::square_of_triangle(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
double figure_in_space::square(double a, double b,double c,double d)
{
	double p = (a + b + c + d) / 2;
	return sqrt((p - a) * (p - b) * (p - c) * (p - d));
}
