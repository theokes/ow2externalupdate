#pragma once

namespace OW {
	namespace offset {
		static constexpr auto Address_viewmatrix_base = 0x36D7160; //viewmatrix xor *
		static constexpr auto Address_viewmatrix_base_test = 0x3D967B8; //viewmatrix *
		static constexpr auto Address_entity_base = 0x36C2650; //entityadmin/list *
		static constexpr auto offset_viewmatrix_ptr = 0x7E0; //pointer
		static constexpr auto offset_viewmatrix_xor_key = 0x1603E7436E47D0CA; //vm key *
		static constexpr auto HeapManager = 0x37902E0; //heapmanagervar *
		static constexpr auto HeapManager_Var = 0x377512B; //heapmanager *
		static constexpr auto HeapManager_Key = 0x6E06BCEBE3CE3478; // *
		static constexpr auto HeapManager_Pointer = 0x160; //
		static constexpr auto changefov = 0x383A7E8; //myFOV *
		static constexpr auto SensitivePtr = 0x205C; //205C? old 2054
		static constexpr auto VisFN = 0x7A4852; // *
		static constexpr auto Vis_Key = 0x5AE142A313A92858; //same for function
		static constexpr auto OutlineFN = 0x7ADE82; // *
		static constexpr auto Outline_Key = 0x6847903E1BDE5A37; //
	}
}