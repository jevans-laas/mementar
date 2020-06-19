#ifndef MEMENTAR_WORDTABLE_H
#define MEMENTAR_WORDTABLE_H

#include <vector>
#include <string>
#include <unordered_set>
#include <cstdint>

namespace mementar {

class WordTable
{
public:

  inline uint32_t add(const std::string& value)
  {
    table_.push_back(value);
    return table_.size() - 1;
  }

  inline std::string& get(uint32_t index)
  {
    return table_[index];
  }

  inline std::string& operator[] (uint32_t index)
  {
    return table_[index];
  }

  inline const std::string& operator[] (uint32_t index) const
  {
    return table_[index];
  }

  inline void index2string(std::unordered_set<std::string>& res, std::unordered_set<uint32_t>& base)
  {
    for(uint32_t i : base)
      res.insert(table_[i]);
  }
private:
  std::vector<std::string> table_;
};

} // namespace mementar

#endif // MEMENTAR_WORDTABLE_H
