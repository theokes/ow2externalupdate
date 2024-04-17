#pragma once

namespace OW {
	namespace offset {
		static constexpr auto Address_viewmatrix_base = 0x3862A78; //viewmatrix xor
		static constexpr auto Address_viewmatrix_base_test = 0x3F20DE8; //viewmatrix
		static constexpr auto Address_entity_base = 0x384DF20; //entityadmin
		static constexpr auto offset_viewmatrix_ptr = 0x7E0; //pointer
		static constexpr auto offset_viewmatrix_xor_key = 0x93FA2AB893EE3B83; //vm key
		static constexpr auto HeapManager = 0x3920960; //heapmanagervar
		static constexpr auto HeapManager_Var = 0x3904EE0; //heapmanager
		static constexpr auto HeapManager_Key = 0x58395EACFB1E63FE; //same
		static constexpr auto HeapManager_Pointer = 0x160; // same
		static constexpr auto changefov = 0x39CA008; //myFOV
		static constexpr auto GetKeyAdd = 0x1F6CC4B; //same
		static constexpr auto GetKeyAddRIP = 0x5;
		static constexpr auto GlowESP = 0x243B396; //
		static constexpr auto Silent = 0xF909A5; //
		static constexpr auto SensitivePtr = 0x2054;
		static constexpr auto VisFN = 0x7AA102; //same
		static constexpr auto VisRead = 0x3905A80; //
		static constexpr auto Vis_Key = 0x1182BF85DB98F1A2; //same
		static constexpr auto OutlineFN = 0x7B3C52; //same
		static constexpr auto OutlineRead = 0x3905A80; //this is under decryptoutline function dwgamebase+, add offset::OutlineRead or leave alone
		static constexpr auto Outline_Key = 0x3CE1EE718DFBBC4B; //same
	}
}