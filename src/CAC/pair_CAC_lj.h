/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(CAC/lj,PairCACLJ)

#else

#ifndef LMP_PAIR_LJ_CAC_H
#define LMP_PAIR_LJ_CAC_H

//#include "asa_user.h"
#include "pair.h"
#include "pair_CAC.h"


namespace LAMMPS_NS {

class PairCACLJ : public PairCAC {
 public:
  PairCACLJ(class LAMMPS *);
  virtual ~PairCACLJ();
 
  
  void coeff(int, char **);
  virtual void init_style();
  virtual double init_one(int, int);

  //double LJEOS(int);


 protected:

             
    int neigh_nodes_per_element;

    


    
  double **cut;
  double **epsilon,**sigma;
  double **lj1,**lj2,**lj3,**lj4,**offset;
  
  double **inner_neighbor_coords;
 
  int *inner_neighbor_types;
  
	
  void allocate();
  //double density_map(double);
 
  
  
  void force_densities(int,double,double,double, double,double
                                &fx, double &fy, double &fz);
  virtual void settings(int, char **);
};

}

#endif
#endif
