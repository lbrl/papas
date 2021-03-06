#ifndef EventRuler_h
#define EventRuler_h

#include "papas/datatypes/Definitions.h"
#include "papas/graphtools/Ruler.h"

namespace papas {

class Distance;
class Event;

/// The EventRuler measures distances/links between items(ids) that belong to a papasevent
/// It can find the distance between two objects (eg cluster-cluster) given the object ids.
/// It is a "wrapper" for the Ruler (distance measuring class)
/// It contains a reference to the papas event, which allows location of the underlying
/// element (cluster, track) from the id.

class EventRuler {

public:
  EventRuler(const Event& event);
  /**
   *   @brief  distance between id1 and id2
   *
   *   @param[in]  id1 : element identifier generated from IdCoder class. Must exist in Event
   *   @param[in]  id2 : element2 identifier generated from IdCoder class. Must exist in Event
   *   @return  Distance (ie isLinked : boolean T/F and distance value)
   */
  Distance distance(Identifier id1, Identifier id2) const;

private:
  Distance clusterClusterDistance(Identifier id1, Identifier id2) const;
  Distance clusterTrackDistance(Identifier id1, Identifier id2) const;
  Ruler m_ruler;         ///<finds distance once the underlying tracks/clusters have been found
  const Event& m_event;  ///< papasevent holds the collections of tracks and clusters
};
}  // end namespace papas

#endif /* EventRuler_h */
