#pragma once

namespace OW {
	namespace offset {
		static constexpr auto Address_viewmatrix_base = 0x369AAC0; //viewmatrix xor *
		static constexpr auto Address_viewmatrix_base_test = 0x3D5D618; //viewmatrix  *
		static constexpr auto Address_entity_base = 0x3685F90; //entityadmin/list *
		static constexpr auto offset_viewmatrix_ptr = 0x7E0; //pointer 
		static constexpr auto offset_viewmatrix_xor_key = 0xBBE9AC19BDDDC4B0; //vm key *
		static constexpr auto HeapManager = 0x3753420; //heapmanagervar *
		static constexpr auto HeapManager_Var = 0x3737619; //heapmanager *
		static constexpr auto HeapManager_Key = 0xC364D216A68B6134; // *
		static constexpr auto HeapManager_Pointer = 0x160; // *
		static constexpr auto changefov = 0x37FE348; //myFOV *
		static constexpr auto SensitivePtr = 0x2064; // *
		static constexpr auto VisFN = 0x79DA42; // *
		static constexpr auto Vis_Key = 0x2F8E798891387671; // *
		static constexpr auto OutlineFN = 0x7A6752; // *
		static constexpr auto Outline_Key = 0x6D73243BD7E1019E; // *
	}
}