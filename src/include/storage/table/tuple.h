//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// tuple.h
//
// Identification: src/include/storage/table/tuple.h
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include <string>
#include <vector>

#include "catalog/schema.h"
#include "common/rid.h"
#include "type/value.h"

namespace bustub {

<<<<<<< HEAD
=======
static constexpr size_t TUPLE_META_SIZE = 12;

struct TupleMeta {
  /**
   * @brief txn id that inserts this tuple. INVALID_TXN if the insertion is completed.
   * No need to use it in project 3 (as of Spring 2023).
   */
  txn_id_t insert_txn_id_;
  /**
   * @brief txn id that deletes this tuple. INVALID_TXN if the deletion is completed.
   * No need to use it in project 3 (as of Spring 2023).
   */
  txn_id_t delete_txn_id_;
  /**
   * @brief marks whether this tuple is marked removed from table heap.
   */
  bool is_deleted_;
};

static_assert(sizeof(TupleMeta) == TUPLE_META_SIZE);

>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850
/**
 * Tuple format:
 * ---------------------------------------------------------------------
 * | FIXED-SIZE or VARIED-SIZED OFFSET | PAYLOAD OF VARIED-SIZED FIELD |
 * ---------------------------------------------------------------------
 */
class Tuple {
  friend class TablePage;
  friend class TableHeap;
  friend class TableIterator;

 public:
  // Default constructor (to create a dummy tuple)
  Tuple() = default;

  // constructor for table heap tuple
  explicit Tuple(RID rid) : rid_(rid) {}

  // constructor for creating a new tuple based on input value
  Tuple(std::vector<Value> values, const Schema *schema);

<<<<<<< HEAD
  // copy constructor, deep copy
  Tuple(const Tuple &other);

  // assign operator, deep copy
  auto operator=(const Tuple &other) -> Tuple &;

  ~Tuple() {
    if (allocated_) {
      delete[] data_;
    }
    allocated_ = false;
    data_ = nullptr;
  }
=======
  Tuple(const Tuple &other) = default;

  // move constructor
  Tuple(Tuple &&other) noexcept = default;

  // assign operator, deep copy
  auto operator=(const Tuple &other) -> Tuple & = default;

  // move assignment
  auto operator=(Tuple &&other) noexcept -> Tuple & = default;

>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850
  // serialize tuple data
  void SerializeTo(char *storage) const;

  // deserialize tuple data(deep copy)
  void DeserializeFrom(const char *storage);

  // return RID of current tuple
  inline auto GetRid() const -> RID { return rid_; }

  // Get the address of this tuple in the table's backing store
<<<<<<< HEAD
  inline auto GetData() const -> char * { return data_; }

  // Get length of the tuple, including varchar legth
  inline auto GetLength() const -> uint32_t { return size_; }
=======
  inline auto GetData() const -> const char * { return data_.data(); }

  // Get length of the tuple, including varchar legth
  inline auto GetLength() const -> uint32_t { return data_.size(); }
>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850

  // Get the value of a specified column (const)
  // checks the schema to see how to return the Value.
  auto GetValue(const Schema *schema, uint32_t column_idx) const -> Value;

  // Generates a key tuple given schemas and attributes
  auto KeyFromTuple(const Schema &schema, const Schema &key_schema, const std::vector<uint32_t> &key_attrs) -> Tuple;

  // Is the column value null ?
  inline auto IsNull(const Schema *schema, uint32_t column_idx) const -> bool {
    Value value = GetValue(schema, column_idx);
    return value.IsNull();
  }
<<<<<<< HEAD
  inline auto IsAllocated() -> bool { return allocated_; }
=======
>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850

  auto ToString(const Schema *schema) const -> std::string;

 private:
  // Get the starting storage address of specific column
  auto GetDataPtr(const Schema *schema, uint32_t column_idx) const -> const char *;

<<<<<<< HEAD
  bool allocated_{false};  // is allocated?
  RID rid_{};              // if pointing to the table heap, the rid is valid
  uint32_t size_{0};
  char *data_{nullptr};
=======
  RID rid_{};  // if pointing to the table heap, the rid is valid
  std::vector<char> data_;
>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850
};

}  // namespace bustub
