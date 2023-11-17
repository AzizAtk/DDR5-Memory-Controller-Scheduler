#ifndef __COMMON_H__
#define __COMMON_H__

/*** includes ***/
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** macro(s) ***/
#ifdef DEBUG
#define LOG_DEBUG(format, ...) printf("%s:%d: " format, __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG(format, ...) printf(format, ##__VA_ARGS__)
#else
#define LOG_DEBUG(...) /*** expands to nothing ***/
#define LOG(...)       /*** expands to nothing ***/
#endif

/*** enum(s) ***/
enum Operation {
  DATA_READ = 0,
  DATA_WRITE = 1,
  INSTRUCTION_FETCH = 2
};

/*** struct(s) ***/
typedef struct MemoryRequest {
  unsigned long long time;
  uint8_t core;
  uint8_t operation;
  // unsigned long long address;
  uint8_t byte_select;  // 2 bits
  uint8_t column_low;   // 4 bits (column[3:0])
  uint8_t channel;      // 1 bit
  uint8_t bank_group;   // 3 bits
  uint8_t bank;         // 2 bits
  uint8_t column_high;  // 6 bits (column[9:4])
  uint32_t row;         // 16 bits
  bool is_complete;
} MemoryRequest_t;

#endif