//
//  Helix.hpp
//  papas
//
//  Created by Alice Robson on 11/05/16.
//
//

#ifndef Helix_h
#define Helix_h

#include "Path.h"

namespace papas {

class Helix : public Path {
public:
  Helix();
  ~Helix() = default;
  Helix(TLorentzVector p4, TVector3 origin, double field, double charge);
  std::vector<double> polarAtTime(double time) const;
  double timeAtPhi(double phi) const;
  double phi(double x, double y) const;
  double rho() const { return m_rho; }
  double pathLength(double deltat) const;
  TVector3 pointFromPolar(const std::vector<double>& polar) const;
  TVector3 pointAtTime(double time) const override;
  TVector3 pointAtZ(double z) const;
  TVector3 pointAtPhi(double phi) const;
  TVector3 extremePointXY() const { return m_extremePointXY; }
  TVector3 centerXY() const { return m_centerXY; }
  double maxTime() const;

private:
  double m_rho;  /// Radius of Helix
  double m_omega;
  double m_phi0;
  double m_phiMin;  /// Minimum angle of ARC
  double m_phiMax;
  TVector3 m_vOverOmega;
  TVector3 m_centerXY;
  TVector3 m_extremePointXY;
};

}  // end namespace papas

#endif /* Helix_h */
