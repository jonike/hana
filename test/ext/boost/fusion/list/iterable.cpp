/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/ext/boost/fusion/list.hpp>

#include <boost/hana/tuple.hpp>

#include <laws/foldable.hpp>
#include <laws/iterable.hpp>
#include <laws/traversable.hpp>

#include <boost/fusion/container/generation/make_list.hpp>
#include <boost/fusion/container/list.hpp>
using namespace boost::hana;
namespace fusion = boost::fusion;


template <int i>
using eq = test::ct_eq<i>;

int main() {
    //////////////////////////////////////////////////////////////////////////
    // Setup for the laws below
    //////////////////////////////////////////////////////////////////////////
    auto eq_lists = make<Tuple>(
          fusion::make_list()
        , fusion::make_list(eq<0>{})
        , fusion::make_list(eq<0>{}, eq<1>{})
        , fusion::make_list(eq<0>{}, eq<1>{}, eq<2>{})
    );

    //////////////////////////////////////////////////////////////////////////
    // Foldable, Iterable, Traversable
    //////////////////////////////////////////////////////////////////////////
    test::TestFoldable<ext::boost::fusion::List>{eq_lists};
    test::TestIterable<ext::boost::fusion::List>{eq_lists};
    test::TestTraversable<ext::boost::fusion::List>{};
}
