/** @file tcodec.hpp
 * encoder / decoder for text <-> binary
 *
 * @copyright (C) 2016
 * @date 2016.03.07
 * @author amir zamani <azadkuh@live.com>
 *
 */

#ifndef MBEDCRYPTO_TEXT_CODEC_HPP
#define MBEDCRYPTO_TEXT_CODEC_HPP

#include "mbedcrypto/types.hpp"
///////////////////////////////////////////////////////////////////////////////
namespace mbedcrypto {
///////////////////////////////////////////////////////////////////////////////

/// hex represetation
struct hex {

    /// encodes a buffer to hex string
    static buffer_t encode(buffer_view_t src);

    /// decodes froma a hex string
    static buffer_t decode(const char* src, size_t length = 0);

    /// overload
    static buffer_t decode(const buffer_t& src) {
        return decode(src.data(), src.size());
    }

}; // struct hex

///////////////////////////////////////////////////////////////////////////////

/// base64 representation
struct base64 {
    /// encodes a buffer into base64 format
    static buffer_t encode(buffer_view_t src);

    /// decodes a base64-formatted buffer
    static buffer_t decode(buffer_view_t src);

    /// tries to reuse the dest memory, or resizes if there is not enough room
    static void encode(buffer_view_t src, buffer_t& dest);

    /// tries to reuse the dest memory, or resizes if there is not enough room
    static void decode(buffer_view_t src, buffer_t& dest);

    /// returns the required result size of encoding to base64, including
    /// null-terminating byte
    static size_t encode_size(buffer_view_t) noexcept;

    /// returns the required result size of decoding from base64
    static size_t decode_size(buffer_view_t) noexcept;

    // raw overloads
    static int encode(
        const unsigned char* src,
        size_t               src_length,
        unsigned char*       dest,
        size_t&              dest_length) noexcept;

    static int decode(
        const unsigned char* src,
        size_t               src_length,
        unsigned char*       dest,
        size_t&              dest_length) noexcept;

}; // struct base64

///////////////////////////////////////////////////////////////////////////////

inline buffer_t
to_hex(const buffer_t& src) {
    return hex::encode(src);
}

inline buffer_t
from_hex(const buffer_t& src) {
    return hex::decode(src);
}

inline buffer_t
to_base64(const buffer_t& src) {
    return base64::encode(src);
}

inline buffer_t
from_base64(const buffer_t& src) {
    return base64::decode(src);
}

#if defined(QT_CORE_LIB)
inline QByteArray
to_hex(const QByteArray& src) noexcept {
    return src.toHex();
}

inline QByteArray
from_hex(const QByteArray& src) noexcept {
    return QByteArray::fromHex(src);
}

inline QByteArray
to_base64(const QByteArray& src) noexcept {
    return src.toBase64();
}

inline QByteArray
from_base64(const QByteArray& src) noexcept {
    return QByteArray::fromBase64(src);
}
#endif // QT_CORE_LIB
///////////////////////////////////////////////////////////////////////////////
} // namespace mbedcrypto
///////////////////////////////////////////////////////////////////////////////
#endif // MBEDCRYPTO_TEXT_CODEC_HPP
