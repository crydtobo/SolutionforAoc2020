
#ifndef INCLUDE_ASN1_H_
#define INCLUDE_ASN1_H_

#include <iostream>
#include <vector>
#include <string>
 

template<typename T>
inline constexpr T expand_top_bit(T a)
   {
   return static_cast<T>(0) - (a >> (sizeof(T)*8-1));
   }

template<typename T>
inline constexpr T ct_is_zero(T x)
   {
   return expand_top_bit<T>(~x & (x - 1));
   }


template<typename T>
inline constexpr size_t high_bit(T n)
   {
   size_t hb = 0;

   for(size_t s = 8*sizeof(T) / 2; s > 0; s /= 2)
      {
      const size_t z = s * ((~ct_is_zero(n >> s)) & 1);
      hb += z;
      n >>= z;
      }

   hb += n;

   return hb;
   }

template<typename T>
inline constexpr T check(T x)
   {
   return (~x & (x - 1));
   }

template<typename T>
inline constexpr T high_bit_my(T n)
   {
   T hb = 1;
   while (n >>= 1) {
       hb++;
   }
   return hb;
   }

template<typename T>
inline constexpr size_t significant_bytes(T n)
   {
   size_t b = 0;

   for(size_t s = 8*sizeof(n) / 2; s >= 8; s /= 2)
      {
      const size_t z = s * (~ct_is_zero(n >> s) & 1);
      b += z/8;
      n >>= z;
      }

   b += (n != 0);

   return b;
   }

template<typename T, typename Alloc, typename L>
std::vector<T, Alloc>& operator+=(std::vector<T, Alloc>& out, const std::pair<const T*, L>& in)
   {
   out.reserve(out.size() + in.second);
   out.insert(out.end(), in.first, in.first + in.second);
   return out;
   }

enum class ASN1_Tag : uint32_t {
   UNIVERSAL        = 0x00,
   APPLICATION      = 0x40,
   CONTEXT_SPECIFIC = 0x80,

   CONSTRUCTED      = 0x20,

   PRIVATE          = CONSTRUCTED | CONTEXT_SPECIFIC,

   EOC              = 0x00,
   BOOLEAN          = 0x01,
   INTEGER          = 0x02,
   BIT_STRING       = 0x03,
   OCTET_STRING     = 0x04,
   NULL_TAG         = 0x05,
   OBJECT_ID        = 0x06,
   ENUMERATED       = 0x0A,
   SEQUENCE         = 0x10,
   SET              = 0x11,

   UTF8_STRING      = 0x0C,
   NUMERIC_STRING   = 0x12,
   PRINTABLE_STRING = 0x13,
   T61_STRING       = 0x14,
   IA5_STRING       = 0x16,
   VISIBLE_STRING   = 0x1A,
   UNIVERSAL_STRING = 0x1C,
   BMP_STRING       = 0x1E,

   UTC_TIME                = 0x17,
   GENERALIZED_TIME        = 0x18,
   UTC_OR_GENERALIZED_TIME = 0x19,

   NO_OBJECT        = 0xFF00,
   DIRECTORY_STRING = 0xFF01
};

#endif /* INCLUDE_ASN1_H_ */