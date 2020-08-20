#ifndef MEMENTAR_FACTGRAPH_H
#define MEMENTAR_FACTGRAPH_H

#include "mementar/core/memGraphs/Graphs/Graph.h"
#include "mementar/core/memGraphs/Branchs/ContextualizedFact.h"

#include "mementar/core/memGraphs/ExtendedBtree/EventLinkedLeaf.h"

namespace mementar {

class FactGraph : public Graph<ContextualizedFact>
{
  using ElBTree = Btree<SoftPoint::Ttime, EventLinkedLeaf<SoftPoint::Ttime, ContextualizedFact*>, 10>;
public:

  ~FactGraph();

  void add(ContextualizedFact* fact);

  std::vector<ContextualizedFact*> get()
  {
    return all_facts_;
  }

  std::vector<ContextualizedFact*> getSafe()
  {
    std::shared_lock<std::shared_timed_mutex> lock(Graph<ContextualizedFact>::mutex_);

    return all_facts_;
  }

  ElBTree* getTimeline() { return &timeline; }

private:
  std::vector<ContextualizedFact*> all_facts_;
  ElBTree timeline;
};

} // namespace mementar

#endif // MEMENTAR_FACTGRAPH_H
