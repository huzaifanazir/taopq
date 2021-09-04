// Copyright (c) 2016-2021 Daniel Frey and Dr. Colin Hirsch
// Please see LICENSE for license or visit https://github.com/taocpp/taopq/

#ifndef TAO_PQ_NULL_HPP
#define TAO_PQ_NULL_HPP

namespace tao::pq
{
   struct null_t final
   {
      explicit constexpr null_t( int /*unused*/ ) {}
   };

   inline constexpr null_t null{ 0 };

}  // namespace tao::pq

#endif
