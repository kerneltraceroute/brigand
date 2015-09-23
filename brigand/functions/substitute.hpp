/*==================================================================================================
  Copyright (c) 2015 Edouard Alligan and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/at.hpp>

namespace brigand
{
  template<std::size_t Index> struct placeholders;

  namespace detail
  {
    template<typename T, typename List> struct substitute_impl { using type = T; };

    template<std::size_t Index, typename List>
    struct substitute_impl<placeholders<Index>,List>
    {
      using type = brigand::at_c<List,Index>;
    };
  }

  template<typename T, typename List>
  using substitute = typename detail::substitute_impl<T,List>::type;
}
