/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef COMPUTEGRAINCENTERUSEROBJECT_H
#define COMPUTEGRAINCENTERUSEROBJECT_H

#include "ElementPostprocessor.h"
#include "MooseVariableInterface.h"
#include "Coupleable.h"

//Forward Declarations
class ComputeGrainCenterUserObject;

template<>
InputParameters validParams<ComputeGrainCenterUserObject>();

/**
 * This postprocessor computes a volume integral of the specified variable.
 *
 * Note that specializations of this integral are possible by deriving from this
 * class and overriding computeQpIntegral().
 */
class ComputeGrainCenterUserObject :
public ElementUserObject,
public MooseVariableInterface
{
public:
  ComputeGrainCenterUserObject(const std::string & name, InputParameters parameters);

  virtual void initialize();
  virtual void execute();
  virtual void threadJoin(const UserObject & y);
  virtual void finalize();

protected:
  virtual void computeIntegral();

  unsigned int _qp;
  std::vector<MooseVariable> & _var;
  std::vector<VariableValue *> _vals;
  std::vector<Point> _grain_center;
  std::vector<Real> _grain_center_output;

  unsigned int _ncrys;
  unsigned int _ncomp;
};

#endif //COMPUTEGRAINCENTERUSEROBJECT_H
