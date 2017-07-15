#include <iostream>
#include <vector>
#include <map>
#include "DynamicModel.h"
#include "RungeKuta45.h"

int main()
{
	//double t = 0;
	//VectorXd y0(2);
	//y0 << 6, 4;
	//VectorXd dy(2);
	//
	//RungeKuta45 rk45(stateModel, 0.02);
	//
	//VectorXd y(0.1);

	//VectorXd otherPara(1);
	//otherPara << 0.0;
	//
	//y << 0, 0;
	////std::cout << y0 << std::endl;
	//while (t <= 0.1)
	//{
	//	y = rk45.integrate(t, y0, dy, otherPara);
	//	std::cout << "y = " << std::endl << y << std::endl;
	//}

	// 初始积分点
	double t = 0;

	// 变量维度为1
	VectorXd y0(1);

	// 初始变量值
	y0 << 0;

	// 变量一阶导数值
	VectorXd dy(1);

	// 定义四阶五步RK积分器，积分步长为0.05
	RungeKuta45 rk45(stateModel, 0.05);

	// 每一步迭代得到的变量值
	VectorXd y(1);

	// 如果一阶微分方程中需要用到其他的常数系数（此示例中不需要，故设为0.0）
	VectorXd otherPara(1);
	otherPara << 0.0;

	std::cout << "x\t真实解\t\t数值解" << std::endl;
	while (t <= 1)
	{
		y = rk45.integrate(t, y0, dy, otherPara);
		std::cout << t << "\t" << 1- exp(-5.0 * t * t) << "\t" << y << std::endl;
	}

	system("pause");
}