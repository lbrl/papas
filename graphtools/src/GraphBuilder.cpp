


#include "GraphBuilder.h"
#include "Id.h"
#include "Edge.h"
#include "directedacyclicgraph.h"
#include "FloodFill.h"

//Allow optional parameters where construction arguments are references

Edges emptyEdges;

GraphBuilder::GraphBuilder(Ids ids,
                           Edges& edges) :
m_edges(edges),
m_elementIds(ids)
{
  
  //create local nodes ready to use to make the blocks
  for (auto id : ids)
    m_localNodes.emplace(id, PFNode(id));
  
  //use the edge information to say what is linked and add this into the local blocks
  for (const auto& edge : m_edges){
    const Edge& e = edge.second;
    if  (e.isLinked())  //note this is an undirected link - OK for undirected searches
      m_localNodes[e.id1()].addChild(m_localNodes[e.id2()]);
  }
  
  DAG::FloodFill<longId> FFill;
  
  //traverse does the work and returns a vector of connected node groups
  for (auto & group : FFill.traverse(m_localNodes)) {
    
    //each of the nodevectors is about to become a separate block
    //we need the vector of ids and the map of edges in order to make the block
    Ids subgraph;
    for (auto& node : group) {
      subgraph.push_back(node->value());
    }
    m_subGraphs.push_back(subgraph);
  }
  
}


/*GraphBuilder::GraphBuilder() :
m_edges(emptyEdges),
m_localNodes(emptyNodes)
{
  
}*/


GraphBuilder& GraphBuilder::operator=(const GraphBuilder& b)
{
  m_elementIds=b.m_elementIds;
  m_edges = b.m_edges;
  m_subGraphs = b.m_subGraphs;
  return *this;
}

void GraphBuilder::sortIds(std::vector<longId>& ids)
{
  std::sort(ids.begin(), ids.end(), [](longId a, longId b) -> bool
            { return Id::typeShortCode(a) < Id::typeShortCode(b); } );
}


/*std::ostream& operator<<(std::ostream& os, const GraphBuilder& builder) {
  //TODO move to helper
  for (auto graph : builder.m_subGraphs) {
    os  << graph << std::endl;
  }
  return os;
}*/

/*void GraphBuilder::sortIds(std::vector<longId>& ids) // sorts by type and energy
 {//TODO move to helper
 std::sort( ids.begin(), ids.end(), [this] (longId a, longId b) { return this->m_pfEvent.compare(a,b);});
 }*/



/*bool GraphBuilder::compareEdges(long long key1, long long key2, longId uniqueid) const//TODO check direction of sort
 {
 //sort by the type eg ecal hcal
 // and then in order of decreasing energy
 Edge e1 = m_edges.find(key1)->second; // should part of this be a static function in Edges?
 Edge e2 = m_edges.find(key2)->second;
 if (e1.distance() < e2.distance())
 return true;
 else if (e1.distance() > e2.distance())
 return false;
 // the distance for edge1 and edge 2 is same
 // so return based on edgetype and end energy comparison for the items
 // at the other end from uniqueId
 double energy1 = m_pfEvent.energy(e1.otherid(uniqueid));
 double energy2 = m_pfEvent.energy(e2.otherid(uniqueid));
 
 return (energy1 > energy2) ;
 }*/





