// The Art of C++ / PostgreSQL
// Copyright (c) 2016-2018 Daniel Frey

#ifndef TAO_POSTGRES_RESULT_TRAITS_HPP
#define TAO_POSTGRES_RESULT_TRAITS_HPP

#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace tao
{
   namespace postgres
   {
      class row;

      template< typename T, typename = void >
      struct result_traits
      {
         static_assert( !std::is_same< T, T >::value, "tao::postgres::result_traits<T> not specialized for T" );
         static T from( const char* value );
      };

      template< typename T, typename = void >
      inline constexpr std::size_t result_traits_size = 1;

      template< typename T >
      inline constexpr std::size_t result_traits_size< T, std::enable_if_t< std::is_same_v< decltype( result_traits< T >::size ), const std::size_t > > > = result_traits< T >::size;

      template< typename T, typename = void >
      inline constexpr bool result_traits_has_null = false;

      template< typename T >
      inline constexpr bool result_traits_has_null< T, decltype( result_traits< T >::null(), void() ) > = true;

      template<>
      struct result_traits< const char* >
      {
         static const char* from( const char* value )
         {
            return value;
         }
      };

      template<>
      struct result_traits< std::string >
      {
         static std::string from( const char* value )
         {
            return value;
         }
      };

      template<>
      struct result_traits< bool >
      {
         static bool from( const char* value );
      };

      template<>
      struct result_traits< char >
      {
         static char from( const char* value );
      };

      template<>
      struct result_traits< signed char >
      {
         static signed char from( const char* value );
      };

      template<>
      struct result_traits< unsigned char >
      {
         static unsigned char from( const char* value );
      };

      template<>
      struct result_traits< short >
      {
         static short from( const char* value );
      };

      template<>
      struct result_traits< unsigned short >
      {
         static unsigned short from( const char* value );
      };

      template<>
      struct result_traits< int >
      {
         static int from( const char* value );
      };

      template<>
      struct result_traits< unsigned >
      {
         static unsigned from( const char* value );
      };

      template<>
      struct result_traits< long >
      {
         static long from( const char* value );
      };

      template<>
      struct result_traits< unsigned long >
      {
         static unsigned long from( const char* value );
      };

      template<>
      struct result_traits< long long >
      {
         static long long from( const char* value );
      };

      template<>
      struct result_traits< unsigned long long >
      {
         static unsigned long long from( const char* value );
      };

      template<>
      struct result_traits< float >
      {
         static float from( const char* value );
      };

      template<>
      struct result_traits< double >
      {
         static double from( const char* value );
      };

      template<>
      struct result_traits< long double >
      {
         static long double from( const char* value );
      };

   }  // namespace postgres

}  // namespace tao

#endif
