//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// hash_join_plan.h
//
// Identification: src/include/execution/plans/hash_join_plan.h
//
// Copyright (c) 2015-2021, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include <string>
#include <utility>
#include <vector>

#include "binder/table_ref/bound_join_ref.h"
#include "execution/expressions/abstract_expression.h"
#include "execution/plans/abstract_plan.h"

namespace bustub {

/**
 * Hash join performs a JOIN operation with a hash table.
 */
class HashJoinPlanNode : public AbstractPlanNode {
 public:
  /**
   * Construct a new HashJoinPlanNode instance.
   * @param output_schema The output schema for the JOIN
   * @param children The child plans from which tuples are obtained
   * @param left_key_expression The expression for the left JOIN key
   * @param right_key_expression The expression for the right JOIN key
   */
  HashJoinPlanNode(SchemaRef output_schema, AbstractPlanNodeRef left, AbstractPlanNodeRef right,
<<<<<<< HEAD
                   AbstractExpressionRef left_key_expression, AbstractExpressionRef right_key_expression,
                   JoinType join_type)
      : AbstractPlanNode(std::move(output_schema), {std::move(left), std::move(right)}),
        left_key_expression_{std::move(left_key_expression)},
        right_key_expression_{std::move(right_key_expression)},
=======
                   std::vector<AbstractExpressionRef> left_key_expressions,
                   std::vector<AbstractExpressionRef> right_key_expressions, JoinType join_type)
      : AbstractPlanNode(std::move(output_schema), {std::move(left), std::move(right)}),
        left_key_expressions_{std::move(left_key_expressions)},
        right_key_expressions_{std::move(right_key_expressions)},
>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850
        join_type_(join_type) {}

  /** @return The type of the plan node */
  auto GetType() const -> PlanType override { return PlanType::HashJoin; }

  /** @return The expression to compute the left join key */
<<<<<<< HEAD
  auto LeftJoinKeyExpression() const -> const AbstractExpression & { return *left_key_expression_; }

  /** @return The expression to compute the right join key */
  auto RightJoinKeyExpression() const -> const AbstractExpression & { return *right_key_expression_; }
=======
  auto LeftJoinKeyExpressions() const -> const std::vector<AbstractExpressionRef> & { return left_key_expressions_; }

  /** @return The expression to compute the right join key */
  auto RightJoinKeyExpressions() const -> const std::vector<AbstractExpressionRef> & { return right_key_expressions_; }
>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850

  /** @return The left plan node of the hash join */
  auto GetLeftPlan() const -> AbstractPlanNodeRef {
    BUSTUB_ASSERT(GetChildren().size() == 2, "Hash joins should have exactly two children plans.");
    return GetChildAt(0);
  }

  /** @return The right plan node of the hash join */
  auto GetRightPlan() const -> AbstractPlanNodeRef {
    BUSTUB_ASSERT(GetChildren().size() == 2, "Hash joins should have exactly two children plans.");
    return GetChildAt(1);
  }

  /** @return The join type used in the hash join */
  auto GetJoinType() const -> JoinType { return join_type_; };

  BUSTUB_PLAN_NODE_CLONE_WITH_CHILDREN(HashJoinPlanNode);

  /** The expression to compute the left JOIN key */
<<<<<<< HEAD
  AbstractExpressionRef left_key_expression_;
  /** The expression to compute the right JOIN key */
  AbstractExpressionRef right_key_expression_;
=======
  std::vector<AbstractExpressionRef> left_key_expressions_;
  /** The expression to compute the right JOIN key */
  std::vector<AbstractExpressionRef> right_key_expressions_;
>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850

  /** The join type */
  JoinType join_type_;

 protected:
<<<<<<< HEAD
  auto PlanNodeToString() const -> std::string override {
    return fmt::format("HashJoin {{ type={}, left_key={}, right_key={} }}", join_type_, left_key_expression_,
                       right_key_expression_);
  }
=======
  auto PlanNodeToString() const -> std::string override;
>>>>>>> dfa6cd4e82ef42eb111b889604cbf280771b7850
};

}  // namespace bustub
