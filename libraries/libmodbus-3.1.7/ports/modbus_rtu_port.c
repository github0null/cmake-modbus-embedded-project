#include <stdint.h>

#include "config.h"
#include "modbus.h"

#include "modbus_port.h"
#include "modbus-rtu-private.h"

#ifndef __ARMEB__
#define LITTLE_ENDIAN
#endif // !__ARMEB__

/////////////////////////////// modbus port apis ///////////////////////////////////



/////////////////////////////// other utils port ///////////////////////////////////

static inline uint16_t _swap16(uint16_t x)
{
    return (x >> 8) | (x << 8);
}

static inline uint32_t _swap32(uint32_t x)
{
    return (_swap16(x & 0xffff) << 16) | (_swap16(x >> 16));
}

uint16_t htons(uint16_t hs)
{
#ifdef LITTLE_ENDIAN
    return _swap16(hs);
#else
    return hs;
#endif
}

uint32_t htonl(uint32_t hl)
{
#ifdef LITTLE_ENDIAN
    return _swap32(hl);
#else
    return hl;
#endif
}

uint16_t ntohs(uint16_t ns)
{
#ifdef LITTLE_ENDIAN
    return _swap16(ns);
#else
    return ns;
#endif
}

uint32_t ntohl(uint32_t nl)
{
#ifdef LITTLE_ENDIAN
    return _swap32(nl);
#else
    return nl;
#endif
}

static int32_t _err_id = 0;

int *_errno(void)
{
    return &_err_id;
}
