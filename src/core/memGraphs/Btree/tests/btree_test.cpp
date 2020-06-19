#include <iostream>
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "mementar/core/memGraphs/DoublyLinkedList/DllNode.h"
#include "mementar/core/memGraphs/Btree/BtreeLeaf.h"
#include "mementar/core/memGraphs/Btree/Btree.h"

using namespace std::chrono;

int main()
{
  mementar::BtreeLeaf<int, int, mementar::DllNode<int>> leaf1(0, 2);
  mementar::BtreeLeaf<int, int, mementar::DllNode<int>> leaf2(1, 3);

  if(leaf1.operator<(&leaf2))
    std::cout << "inf" << std::endl;
  else
    std::cout << "sup" << std::endl;

  std::vector<size_t> sizes = {50};
  std::vector<double> times;
  for(auto nb : sizes)
  {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    mementar::Btree<int, int> tree(3);
    for(size_t i = 0; i < nb; i++)
      tree.insert(i, i);

    //tree.display();

    auto res = tree.find(10);
    if(res) std::cout << res->getKey() << std::endl; else std::cout << "-" << std::endl;
    res = tree.find(28);
    if(res) std::cout << res->getKey() << std::endl; else std::cout << "-" << std::endl;
    res = tree.find(74);
    if(res) std::cout << res->getKey() << std::endl; else std::cout << "-" << std::endl;
    res = tree.find(53);
    if(res) std::cout << res->getKey() << std::endl; else std::cout << "-" << std::endl;
    res = tree.findNear(59);
    if(res) std::cout << res->getKey() << std::endl; else std::cout << "-" << std::endl;
    res = tree.getFirst();
    if(res) std::cout << res->getKey() << std::endl; else std::cout << "-" << std::endl;

    tree.remove(49, 49);
    tree.insert(50, 0);
    tree.display();

    std::cout << "estimation = " << tree.estimateMinLeaves() << std::endl;
    std::cout << "level = " << tree.estimateMaxLevel(nb) << ">=" << tree.getCurrentLevel() << std::endl;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "took " << time_span.count() << std::endl;
    times.push_back(time_span.count());

    for(size_t i = 0; i < times.size(); i++)
      std::cout << sizes[i] << ";";
    std::cout << std::endl;
    for(size_t i = 0; i < times.size(); i++)
      std::cout << times[i] << ";";
    std::cout << std::endl;
  }

  return 0;
}
