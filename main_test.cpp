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

	// ��ʼ���ֵ�
	double t = 0;

	// ����ά��Ϊ1
	VectorXd y0(1);

	// ��ʼ����ֵ
	y0 << 0;

	// ����һ�׵���ֵ
	VectorXd dy(1);

	// �����Ľ��岽RK�����������ֲ���Ϊ0.05
	RungeKuta45 rk45(stateModel, 0.05);

	// ÿһ�������õ��ı���ֵ
	VectorXd y(1);

	// ���һ��΢�ַ�������Ҫ�õ������ĳ���ϵ������ʾ���в���Ҫ������Ϊ0.0��
	VectorXd otherPara(1);
	otherPara << 0.0;

	std::cout << "x\t��ʵ��\t\t��ֵ��" << std::endl;
	while (t <= 1)
	{
		y = rk45.integrate(t, y0, dy, otherPara);
		std::cout << t << "\t" << 1- exp(-5.0 * t * t) << "\t" << y << std::endl;
	}

	system("pause");
}