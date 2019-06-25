// Copyright 2019 Arunabh Sharma

#ifndef ROOM_EMULATOR_CPU_H_
#define ROOM_EMULATOR_CPU_H_

#include <cstdint>

namespace room
{
enum LLbit
{
    LOAD = 0,
    LINK = 1
};

class Cpu
{
   public:
   private:
    uint64_t[NUM_REG] reg_gpr_;
    uint64_t[NUM_REG] reg_fpr_;
    uint64_t reg_pc_;
    uint64_t reg_hi;
    uint64_t reg_lo;
    LLbit ll_inst_;
    uint32_t reg_fcr0;
    uint32_t reg_fcr31;

    static constexpr std::size_t NUM_REG = 32;
};  // class cpu
}  // namespace room

#endif  // ROOM_EMULATOR_CPU_H_