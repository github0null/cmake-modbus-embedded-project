#ifndef MODBUS_RTU_PORT_H
#define MODBUS_RTU_PORT_H

#include <stddef.h>
#include <stdint.h>

#include "config.h"
#include "modbus.h"

#include "modbus-rtu-private.h"
#include "modbus-tcp-private.h"

/**
 * @brief sleep some us
 * 
 * @param us 
 */
extern void modbus_sleep_us(uint32_t us);

/**
 * @brief open serialport
 * 
 * @param cfg 
 * @return int32_t 
 */
extern int32_t modbus_rtu_port_open(modbus_rtu_t *cfg);

/**
 * @brief close serialport
 * 
 * @param cfg 
 * @return int32_t 
 */
extern int32_t modbus_rtu_port_clos(modbus_rtu_t *cfg);

/**
 * @brief send data to serialport
 * 
 * @param handle 
 * @param buff 
 * @param len 
 * @return int32_t 
 */
extern int32_t modbus_rtu_port_send(serial_handle_t handle, uint8_t *buff, size_t len);

/**
 * @brief recv data from serialport
 * 
 * @param handle 
 * @param buff 
 * @param len 
 * @return int32_t 
 */
extern int32_t modbus_rtu_port_recv(serial_handle_t handle, uint8_t *buff, size_t len);

/**
 * @brief flush send stream
 * 
 * @param cfg 
 * @return int32_t 
 */
extern int32_t modbus_rtu_port_flush(modbus_rtu_t *cfg);

/**
 * @brief Check whether data is ready on the serial_port
 * 
 * @param ctx 
 * @param rset 
 * @param tv 
 * @param msg_length 
 * @return return -1 if timeout, return >= 0 for valid fd, otherwise is error 
 */
extern int32_t modbus_rtu_port_select(modbus_t *ctx, fd_set *rset, struct timeval *tv, int msg_length);

#endif // !MODBUS_RTU_PORT_H
