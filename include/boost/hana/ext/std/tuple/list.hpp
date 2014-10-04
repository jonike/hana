/*!
@file
Defines the instance of `boost::hana::Functor` for `std::tuple`s.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_STD_TUPLE_LIST_HPP
#define BOOST_HANA_EXT_STD_TUPLE_LIST_HPP

#include <boost/hana/detail/std/forward.hpp>
#include <boost/hana/ext/std/tuple/tuple.hpp>
#include <boost/hana/list/mcd.hpp>

// Mcd
#include <boost/hana/ext/std/tuple/foldable.hpp>
#include <boost/hana/ext/std/tuple/iterable.hpp>
#include <boost/hana/ext/std/tuple/monad.hpp>

#include <tuple>


namespace boost { namespace hana {
    template <>
    struct List::instance<StdTuple> : List::mcd<StdTuple> {
        static constexpr auto nil_impl()
        { return std::tuple<>{}; }

        template <typename X, typename Xs>
        static constexpr decltype(auto) cons_impl(X&& x, Xs&& xs) {
            return std::tuple_cat(
                std::make_tuple(detail::std::forward<X>(x)),
                detail::std::forward<Xs>(xs)
            );
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_EXT_STD_TUPLE_LIST_HPP
