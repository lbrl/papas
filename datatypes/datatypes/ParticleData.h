//
//  particledata.h
//  fastsim
//
//  Created by Alice Robson on 13/01/16.
//
//

#ifndef particledata_h
#define particledata_h

#include <unordered_map>
#include <utility>

namespace papas {
class ParticleData {
public:
  static const double m_e;   // = 0.000511;
  static const double m_mu;  //= 0.105;
  static const double m_pi;  //= 0.139;
  static const double m_K0;  //= 0.498;
  static const double m_n;   //= 1.;
  static const double m_p;   //= 1.;

  static double particleMass(int pid) { return particleData(pid).first; };
  static double particleCharge(int pid) { return particleData(pid).second; };
  static std::pair<double, int>& particleData(int pid) { return m_datamap[pid]; };
  static std::unordered_map<int, std::pair<double, int>> m_datamap;
};
} //end namespace papas
#endif /* particledata_h */