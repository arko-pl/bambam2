#ifndef PIMPL_HPP
#define PIMPL_HPP

#include <experimental/propagate_const>
#include <memory>

/**
 * @brief Pointer to implemenation template.
 *
 */
template <typename T>
using PImpl = std::experimental::propagate_const<std::unique_ptr<T>>;

#endif // PIMPL_HPP
