//
//  Created by Alice Robson on 29/11/15.

#ifndef PFParticle_H
#define PFParticle_H

#include "Particle.h"
#include "path.h"
class Track;
class TLorentzVector;

class PFParticle : public Particle {
public:
  bool isElectroMagnetic() const;
  PFParticle() = default;
  PFParticle(long uniqueid, int pdgid, TLorentzVector tlv, TVector3 vertex = TVector3(0., 0., 0.), double field = 0.);
  PFParticle(long uniqueid, const Track& track);
  Path::Ptr path() const { return m_path; }
  TVector3 pathPosition(std::string name) const;
  void setPath(Path::Ptr path) { m_path = path; }
  bool isHelix() const { return m_isHelix; }

private:
  TVector3 m_vertex;
  Path::Ptr m_path;
  bool m_isHelix;
};

#endif  // PFParticle_H