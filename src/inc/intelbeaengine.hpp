/*
    This file is part of rp++.

    Copyright (C) 2014, Axel "0vercl0k" Souchet <0vercl0k at tuxfamily.org>
    All rights reserved.

    rp++ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    rp++ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with rp++.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef INTELBEAENGINE_HPP
#define INTELBEAENGINE_HPP

#define BEA_ENGINE_STATIC

#include "beaengine/BeaEngine.h"
#include "disassenginewrapper.hpp"

class IntelBeaEngine : public DisassEngineWrapper
{
    public:
        /*! The different architectures BeaRopGadgetFinder handles */
        enum E_Arch
        {
            x86 = 0,
            x64 = 64
        };

        explicit IntelBeaEngine(E_Arch arch);
        InstructionInformation disass(const uint8_t *data, uint64_t len, uint64_t vaddr, DisassEngineReturn &ret) override;

        bool is_valid_ending_instruction(InstructionInformation &instr) const override;

        bool is_valid_instruction(InstructionInformation &instr) const override;

        uint32_t get_size_biggest_instruction(void) const override;

        uint32_t get_alignement(void) const override;

    private:

		uint32_t m_arch; /*!< architecture the BeaEngine will use to disassemble*/

        DISASM m_disasm;
};

#endif