#pragma once

namespace OW {
	namespace offset {
		static constexpr auto Address_viewmatrix_base = 0x379AB38; //viewmatrix xor
		static constexpr auto Address_viewmatrix_base_test = 0x3E58E58; //viewmatrix
		static constexpr auto Address_entity_base = 0x3785FD0; //entityadmin/list
		static constexpr auto offset_viewmatrix_ptr = 0x7E0; //pointer
		static constexpr auto offset_viewmatrix_xor_key = 0x309215E24ABB580A; //vm key
		static constexpr auto HeapManager = 0x3858A10; //heapmanagervar
		static constexpr auto HeapManager_Var = 0x383D48A; //heapmanager
		static constexpr auto HeapManager_Key = 0xFFCA423AE840244C; //same
		static constexpr auto HeapManager_Pointer = 0x160; // same
		static constexpr auto changefov = 0x39020E8; //myFOV
		static constexpr auto GetKeyAdd = 0x1EC7A5B; //same
		static constexpr auto GetKeyAddRIP = 0x5;
		static constexpr auto GlowESP = 0x237B296; //
		static constexpr auto Silent = 0xF909A5; //
		static constexpr auto SensitivePtr = 0x2054;
		static constexpr auto VisFN = 0x78BE12; //same
		static constexpr auto VisRead = 0x383DB40; //
		static constexpr auto Vis_Key = 0x37100BDEF61F08F7; //same
		static constexpr auto OutlineFN = 0x794912; //same
		static constexpr auto OutlineRead = 0x383DB40; //this is under decryptoutline function dwgamebase+, add offset::OutlineRead or leave alone
		static constexpr auto Outline_Key = 0x69F1F24995F6D73F; //same
	}
}