#include "modbus_port.h"

#ifndef __ARMEB__
#define LITTLE_ENDIAN
#endif // !__ARMEB__

/////////////////////////////// modbus port apis ///////////////////////////////////

int32_t modbus_rtu_port_open(modbus_rtu_t *cfg)
{
    //TODO
}

int32_t modbus_rtu_port_clos(modbus_rtu_t *cfg)
{
    //TODO
}

int32_t modbus_rtu_port_send(serial_handle_t handle, uint8_t *buff, size_t len)
{
    //TODO
}

int32_t modbus_rtu_port_recv(serial_handle_t handle, uint8_t *buff, size_t len)
{
    //TODO
}

int32_t modbus_rtu_port_flush(modbus_rtu_t *cfg)
{
    //TODO
}

int32_t modbus_rtu_port_select(modbus_t *ctx, fd_set *rset, struct timeval *tv, int msg_length)
{
    //TODO
}

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
