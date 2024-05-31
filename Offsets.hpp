#pragma once

namespace OW {
	namespace offset {
		static constexpr auto Address_viewmatrix_base = 0x37F7618; //viewmatrix xor
		static constexpr auto Address_viewmatrix_base_test = 0x3EB6278; //viewmatrix
		static constexpr auto Address_entity_base = 0x37E2AC0; //entityadmin/list
		static constexpr auto offset_viewmatrix_ptr = 0x7E0; //pointer
		static constexpr auto offset_viewmatrix_xor_key = 0x544A3BA5BE911EE7; //vm key
		static constexpr auto HeapManager = 0x38B55F0; //heapmanagervar
		static constexpr auto HeapManager_Var = 0x3899DD5; //heapmanager
		static constexpr auto HeapManager_Key = 0xE7E1F898E11B68B1; //
		static constexpr auto HeapManager_Pointer = 0x160; //
		static constexpr auto changefov = 0x395EDB8; //myFOV
		static constexpr auto Silent = 0xF909A5; //
		static constexpr auto SensitivePtr = 0x2054; 
		static constexpr auto VisFN = 0x79E722; //
		static constexpr auto Vis_Key = 0x1AAC46FF0D473EBA; //
		static constexpr auto OutlineFN = 0x7A7AD2; //
		static constexpr auto Outline_Key = 0x6F3C13FEBA1E4DFE; //
	}
}