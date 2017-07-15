#include "RungeKuta45.h"
#include <iostream>
#include <assert.h>

VectorXd&  RungeKuta45::integrate(double& t, VectorXd& y0, VectorXd& dy, const VectorXd& otherPara)
{
	if (!fun_)
	{
		std::cout << "WARNING: The fun_ of the RungeKunta45 has not been defined and the program is aborted!" << std::endl;
	}
	assert(fun_);

	VectorXd k1 = h_ * fun_(t, y0, dy, otherPara);

	t += h_ / 2;
	VectorXd y1 = y0 + k1 / 2;
	VectorXd k2 = h_ * fun_(t, y1, dy, otherPara);
	
	VectorXd y2 = y0 + k2 / 2;
	VectorXd k3 = h_ * fun_(t, y2, dy, otherPara);

	t += h_ / 2;
	VectorXd y3 = y0 + k3;
	VectorXd k4 = h_ * fun_(t, y3, dy, otherPara);

	y0 = y0 + 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);

	return y0;
}
