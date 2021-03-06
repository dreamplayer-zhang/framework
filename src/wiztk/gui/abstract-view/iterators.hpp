/*
 * Copyright 2017 - 2018 The WizTK Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WIZTK_GUI_INTERNAL_ABSTRACT_VIEW_ITERATORS_HPP_
#define WIZTK_GUI_INTERNAL_ABSTRACT_VIEW_ITERATORS_HPP_

#include "wiztk/gui/abstract-view.hpp"
#include "private.hpp"

namespace wiztk {
namespace gui {

/**
 * @brief An iterator class to traverse in the view hierarchy
 */
WIZTK_NO_EXPORT class AbstractView::Iterator {

 public:

  explicit Iterator(AbstractView *view = nullptr)
      : current_(view) {}

  Iterator(const Iterator &) = default;
  Iterator(Iterator &&) = default;
  ~Iterator() = default;
  Iterator &operator=(const Iterator &) = default;
  Iterator &operator=(Iterator &&) = default;

  Iterator &operator=(AbstractView *view) {
    current_ = view;
    return *this;
  }

  /**
   * @brief Move to the next view
   * @return A reference to this iterator
   *
   * @note It's recommended to use this operator
   */
  Iterator &operator++() {
    current_ = current_->p_->next;
    return *this;
  }

  /**
   * @brief Move to the next view
   * @return A new iterator object
   */
  Iterator operator++(int) {
    Iterator it(current_->p_->next);
    return it;
  }

  /**
   * @brief Move to the previous view
   * @return A reference to this iterator
   *
   * @note It's recommended to use this operator
   */
  Iterator &operator--() {
    current_ = current_->p_->previous;
    return *this;
  }

  /**
   * @brief Move to the new previous view
   * @return A new iterator object
   */
  Iterator operator--(int) {
    Iterator it(current_->p_->previous);
    return it;
  }

  AbstractView *parent() const { return current_->p_->parent; }

  AbstractView *previous() const { return current_->p_->previous; }

  AbstractView *next() const { return current_->p_->next; }

  AbstractView *first_child() const { return current_->p_->first_child; }

  AbstractView *last_child() const { return current_->p_->last_child; }

  AbstractView *view() const { return current_; }

  explicit operator bool() const { return nullptr != current_; }

 private:

  AbstractView *current_;

};

/**
 * @brief A const iterator class to traverse in the view hierarchy
 */
class AbstractView::ConstIterator {

 public:

  explicit ConstIterator(const AbstractView *view = nullptr)
      : current_(view) {}

  ConstIterator(const ConstIterator &) = default;
  ConstIterator(ConstIterator &&) = default;
  ~ConstIterator() = default;
  ConstIterator &operator=(const ConstIterator &) = default;
  ConstIterator &operator=(ConstIterator &&) = default;

  ConstIterator &operator=(AbstractView *view) {
    current_ = view;
    return *this;
  }

  /**
   * @brief Move to the next view
   * @return A reference to this iterator
   *
   * @note It's recommended to use this operator
   */
  ConstIterator &operator++() {
    current_ = current_->p_->next;
    return *this;
  }

  /**
   * @brief Move to the next view
   * @return A new iterator object
   */
  ConstIterator operator++(int) {
    ConstIterator it(current_->p_->next);
    return it;
  }

  /**
   * @brief Move to the previous view
   * @return A reference to this iterator
   *
   * @note It's recommended to use this operator
   */
  ConstIterator &operator--() {
    current_ = current_->p_->previous;
    return *this;
  }

  /**
   * @brief Move to the new previous view
   * @return A new iterator object
   */
  ConstIterator operator--(int) {
    ConstIterator it(current_->p_->previous);
    return it;
  }

  const AbstractView *parent() const { return current_->p_->parent; }

  const AbstractView *previous() const { return current_->p_->previous; }

  const AbstractView *next() const { return current_->p_->next; }

  const AbstractView *first_child() const { return current_->p_->first_child; }

  const AbstractView *last_child() const { return current_->p_->last_child; }

  const AbstractView *view() const { return current_; }

  explicit operator bool() const { return nullptr != current_; }

 private:

  const AbstractView *current_;

};

} // namespace gui
} // namespace wiztk

#endif // WIZTK_GUI_INTERNAL_ABSTRACT_VIEW_ITERATORS_HPP_
