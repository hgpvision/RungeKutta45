#ifndef _DYNAMIC_MODEL_H
#define _DYNAMIC_MODEL_H
#include <Eigen/core>
using namespace Eigen;

VectorXd& stateModel(double& t, VectorXd& y0, VectorXd& dy, const VectorXd& otherPara);

VectorXd& stateModel(double& t, VectorXd& y0, VectorXd& dy, const VectorXd& otherPara)
{
	//dy(0) = y0(0) + 2 * y0(1);
	//dy(1) = 3 * y0(0) + 2 * y0(1);
	//return dy;

	dy(0) = 10 * t * (1 - y0(0));
	return dy;
}

#endif // !_DYNAMICMODEL_H
