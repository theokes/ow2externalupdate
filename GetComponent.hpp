#pragma once
#include "IDAdefs.h"
#define ISVALID(x) ((x) && (x) != INVALID_HANDLE_VALUE)
namespace OW {
	class HPComponent
	{
	public:
		char pad_0001[0xDC];
		Vector2 Health;
		char pad_0002[0x21C];
		Vector2 Armor;
		char pad_0003[0x35C];
		Vector2 Barrier;

		Vector2 GetHealth()
		{
			Vector2 HP = SDK->RPM<Vector2>((uint64_t)&this->Health);
			Vector2 Ar = SDK->RPM<Vector2>((uint64_t)&this->Armor);
			Vector2 Br = SDK->RPM<Vector2>((uint64_t)&this->Barrier);
			//	HP.X = Max , HP.Y = Current HP
			return { HP.X + Ar.X + Br.X ,HP.Y + Ar.Y + Br.Y };
		}
	};
	struct health_compo_t {
		union {
			OFF_MEMB(float, health, 0xE0);
			OFF_MEMB(float, health_max, 0xDC);
			OFF_MEMB(float, armor, 0x220);
			OFF_MEMB(float, armor_max, 0x21C);
			OFF_MEMB(float, barrier, 0x360);
			OFF_MEMB(float, barrier_max, 0x35C);
			OFF_MEMB(bool, isImmortal, 0x4A9);
			OFF_MEMB(bool, isBarrierProjected, 0x4A8);
		};
	};
	struct obj_compo_t {
		union {
			OFF_MEMB(XMFLOAT3, obj_pos, 0xE0);
		};
	};
	struct velocity_compo_t {
		union {
			OFF_MEMB(XMFLOAT3, velocity, 0x50);
			OFF_MEMB(XMFLOAT3, location, 0x1B0 + 0x50);
			OFF_MEMB(uint64_t, bonedata, 0x8A0);
		};
	};
	struct hero_compo_t {
		union {
			OFF_MEMB(uint64_t, heroid, 0xD0);
		};
	};
	struct vis_compo_t {
		union {
			OFF_MEMB(uint64_t, key1, 0xA0);
			OFF_MEMB(uint64_t, key2, 0x98);
		};
	};

	inline std::string GetHeroNames(uint64_t HeroID, uint64_t LinkBase) {
		switch (HeroID)
		{
		case eHero::HERO_REAPER:
			return skCrypt(u8"ËÀÉñ").decrypt();
		case eHero::HERO_TRACER:
			return skCrypt(u8"ÁÔ¿Õ").decrypt();
		case eHero::HERO_MERCY:
			return skCrypt(u8"ÌìÊ¹").decrypt();
		case eHero::HERO_HANJO:
			return skCrypt(u8"°ë²Ø").decrypt();
		case eHero::HERO_TORBJORN:
			return skCrypt(u8"ÍÐ±È°º").decrypt();
		case eHero::HERO_REINHARDT:
			return skCrypt(u8"À³Òò¹þÌØ").decrypt();
		case eHero::HERO_PHARAH:
			return skCrypt(u8"·¨ÀÏÖ®Ó¥").decrypt();
		case eHero::HERO_WINSTON:
			return skCrypt(u8"ÎÂË¹¶Ù").decrypt();
		case eHero::HERO_WIDOWMAKER:
			return skCrypt(u8"ºÚ°ÙºÏ").decrypt();
		case eHero::HERO_BASTION:
			return skCrypt(u8"±¤ÀÝ").decrypt();
		case eHero::HERO_SYMMETRA:
			return skCrypt(u8"ÖÈÐòÖ®¹â").decrypt();
		case eHero::HERO_ZENYATTA:
			return skCrypt(u8"ìøÑÅËþ").decrypt();
		case eHero::HERO_GENJI:
			return skCrypt(u8"Ô´ÊÏ").decrypt();
		case eHero::HERO_ROADHOG:
			return skCrypt(u8"Â·°Ô").decrypt();
		case eHero::HERO_MCCREE:
			return skCrypt(u8"Âó¿ËÀ×").decrypt();
		case eHero::HERO_JUNKRAT:
			return skCrypt(u8"¿ñÊó").decrypt();
		case eHero::HERO_ZARYA:
			return skCrypt(u8"²éÀòæ«").decrypt();
		case eHero::HERO_SOLDIER76:
			return skCrypt(u8"Ê¿±ø76").decrypt();
		case eHero::HERO_LUCIO:
			return skCrypt(u8"Â¬Î÷°Â").decrypt();
		case eHero::HERO_DVA:
			if (SDK->RPM<uint16_t>(LinkBase + 0xD4) != SDK->RPM<uint16_t>(LinkBase + 0xD8))
				return skCrypt(u8"D.Va").decrypt();
			else
				return skCrypt(u8"¹þÄÈ").decrypt();
		case eHero::HERO_VENTURE:
			return skCrypt(u8"Â¬Î÷°").decrypt();
		case eHero::HERO_MEI:
			return skCrypt(u8"ÃÀ").decrypt();
		case eHero::HERO_ANA:
			return skCrypt(u8"°²ÄÈ").decrypt();
		case eHero::HERO_SOMBRA:
			return skCrypt(u8"ºÚÓ°").decrypt();
		case eHero::HERO_ORISA:
			return skCrypt(u8"°ÂÀöÉ¯").decrypt();
		case eHero::HERO_DOOMFIST:
			return skCrypt(u8"Ä©ÈÕÌúÈ ").decrypt();
		case eHero::HERO_MOIRA:
			return skCrypt(u8"ÄªÒÁÀ ").decrypt();
		case eHero::HERO_BRIGITTE:
			return skCrypt(u8"²¼Àï¼ªËþ").decrypt();
		case eHero::HERO_WRECKINGBALL:
			return skCrypt(u8"ÆÆ»µÇò").decrypt();
		case eHero::HERO_SOJOURN:
			return skCrypt(u8"Ë÷½Ü¶÷").decrypt();
		case eHero::HERO_ASHE:
			return skCrypt(u8"°¬Ê²").decrypt();
		case eHero::HERO_BAPTISTE:
			return skCrypt(u8"°ÍµÙË¹ÌØ").decrypt();
		case eHero::HERO_KIRIKO:
			return skCrypt(u8"Îí×Ó").decrypt();
		case eHero::HERO_JUNKERQUEEN:
			return skCrypt(u8"Ôü¿ÍÅ®Íõ").decrypt();
		case eHero::HERO_SIGMA:
			return skCrypt(u8"Î÷¸ñÂê").decrypt();
		case eHero::HERO_ECHO:
			return skCrypt(u8"»ØÉù").decrypt();
		case eHero::HERO_RAMATTRA:
			return skCrypt(u8"À ÂêÉ²").decrypt();
		case eHero::HERO_TRAININGBOT1:
			return skCrypt(u8"±ê×¼»úÆ÷ÈË").decrypt();
		case eHero::HERO_TRAININGBOT2:
			return skCrypt(u8"ÖØ×°»úÆ÷ÈË").decrypt();
		case eHero::HERO_TRAININGBOT3:
			return skCrypt(u8"¾Ñ»÷»úÆ÷ÈË").decrypt();
		case eHero::HERO_TRAININGBOT4:
			return skCrypt(u8"ÓÑ·½»úÆ÷ÈË").decrypt();
		case eHero::HERO_TRAININGBOT5:
			return skCrypt(u8"ÓÑ·½ÖØ×°»úÆ÷ÈË").decrypt();
		case eHero::HERO_TRAININGBOT6:
			return skCrypt(u8"»ð¼ý»úÆ÷ÈË").decrypt();
		case eHero::HERO_TRAININGBOT7:
			return skCrypt(u8"ÑµÁ·»úÆ÷ÈË").decrypt();
		case eHero::HERO_LIFEWEAVER:
			return skCrypt(u8"ÉúÃüÖ®Ëó").decrypt();
		case eHero::TOBTERT:
			return skCrypt(u8"ÅÚÌ¨").decrypt();
		case eHero::SYMTERT:
			return skCrypt(u8"ÉãÏñÍ·").decrypt();
		case eHero::HERO_ILLARI:
			return skCrypt(u8"ÒÁÀ Èñ").decrypt();
		case eHero::HERO_MAUGA:
			return skCrypt(u8"Ã«¼Ó").decrypt();
		case eHero::Bob:
			return skCrypt(u8"±«²ª").decrypt();
		default:
			return skCrypt(u8"Î´Öª").decrypt();
		}

	}

	inline uint64_t GetParent(uint64_t encrypted) {
		__try {
			auto result = encrypted;
			result -= 0x401C60913E3B91CE;
			result = (result >> 0x20) | (result << 0x20);
			return result;
		}
		__except (1) {

		}
	}

	inline std::string GetHeroEngNames(uint64_t HeroID, uint64_t LinkBase) {
		switch (HeroID)
		{
		case eHero::HERO_REAPER:
			return skCrypt("Reaper").decrypt();
		case eHero::HERO_TRACER:
			return skCrypt("Tracer").decrypt();
		case eHero::HERO_MERCY:
			return skCrypt("Mercy").decrypt();
		case eHero::HERO_HANJO:
			return skCrypt("Hanzo").decrypt();
		case eHero::HERO_TORBJORN:
			return skCrypt("Torbjorn").decrypt();
		case eHero::HERO_REINHARDT:
			return skCrypt("Reinhardt").decrypt();
		case eHero::HERO_PHARAH:
			return skCrypt("Pharah").decrypt();
		case eHero::HERO_WINSTON:
			return skCrypt("Winston").decrypt();
		case eHero::HERO_WIDOWMAKER:
			return skCrypt("Widowmaker").decrypt();
		case eHero::HERO_BASTION:
			return skCrypt("Bastion").decrypt();
		case eHero::HERO_SYMMETRA:
			return skCrypt("Symmetra").decrypt();
		case eHero::HERO_ZENYATTA:
			return skCrypt("Zenyatta").decrypt();
		case eHero::HERO_GENJI:
			return skCrypt("Genji").decrypt();
		case eHero::HERO_ROADHOG:
			return skCrypt("Roadhog").decrypt();
		case eHero::HERO_MCCREE:
			return skCrypt("McCree").decrypt();
		case eHero::HERO_JUNKRAT:
			return skCrypt("Junkrat").decrypt();
		case eHero::HERO_ZARYA:
			return skCrypt("Zarya").decrypt();
		case eHero::HERO_SOLDIER76:
			return skCrypt("Soldier 76").decrypt();
		case eHero::HERO_LUCIO:
			return skCrypt("Lucio").decrypt();
		case eHero::HERO_DVA:
			if (SDK->RPM<uint16_t>(LinkBase + 0xD4) != SDK->RPM<uint16_t>(LinkBase + 0xD8))
				return skCrypt("D.Va").decrypt();
			else
				return skCrypt("Hana").decrypt();
		case eHero::HERO_MEI:
			return skCrypt("Mei").decrypt();
		case eHero::HERO_ANA:
			return skCrypt("Ana").decrypt();
		case eHero::HERO_SOMBRA:
			return skCrypt("Sombra").decrypt();
		case eHero::HERO_ORISA:
			return skCrypt("Orisa").decrypt();
		case eHero::HERO_DOOMFIST:
			return skCrypt("Doomfist").decrypt();
		case eHero::HERO_MOIRA:
			return skCrypt("Moira").decrypt();
		case eHero::HERO_BRIGITTE:
			return skCrypt("Brigitte").decrypt();
		case eHero::HERO_WRECKINGBALL:
			return skCrypt("Wrecking Ball").decrypt();
		case eHero::HERO_SOJOURN:
			return skCrypt("Sojourn").decrypt();
		case eHero::HERO_ASHE:
			return skCrypt("Ashe").decrypt();
		case eHero::HERO_BAPTISTE:
			return skCrypt("Baptiste").decrypt();
		case eHero::HERO_KIRIKO:
			return skCrypt("Kiriko").decrypt();
		case eHero::HERO_JUNKERQUEEN:
			return skCrypt("Junker Queen").decrypt();
		case eHero::HERO_SIGMA:
			return skCrypt("Sigma").decrypt();
		case eHero::HERO_ECHO:
			return skCrypt("Echo").decrypt();
		case eHero::HERO_RAMATTRA:
			return skCrypt("Ramattra").decrypt();
		case eHero::HERO_TRAININGBOT1:
			return skCrypt("Standard Bot").decrypt();
		case eHero::HERO_TRAININGBOT2:
			return skCrypt("Tank Bot").decrypt();
		case eHero::HERO_TRAININGBOT3:
			return skCrypt("Sniper Bot").decrypt();
		case eHero::HERO_TRAININGBOT4:
			return skCrypt("Friend Bot").decrypt();
		case eHero::HERO_TRAININGBOT5:
			return skCrypt(u8"Friend Tank Bot").decrypt();
		case eHero::HERO_TRAININGBOT6:
			return skCrypt(u8"Rocket Bot").decrypt();
		case eHero::HERO_TRAININGBOT7:
			return skCrypt(u8"Training Bot").decrypt();
		case eHero::HERO_LIFEWEAVER:
			return skCrypt("LifeWeaver").decrypt();
		case eHero::TOBTERT:
			return skCrypt(u8"Tob").decrypt();
		case eHero::SYMTERT:
			return skCrypt(u8"Sym").decrypt();
		case eHero::HERO_ILLARI:
			return skCrypt(u8"Illari").decrypt();
		case eHero::HERO_MAUGA:
			return skCrypt(u8"Mauga").decrypt();
		case eHero::HERO_VENTURE:
			return skCrypt(u8"Venture").decrypt();
		case eHero::Bob:
			return skCrypt(u8"Bob").decrypt();
		default:
			return skCrypt(u8"Unknown").decrypt();
		}
	}

	inline void sub_E8D1A0(_QWORD* a1, __int64* a2, __int64* a3, _DWORD* a4, uint8_t componentid)
	{
		*a1 = (uint64_t)1 << (uint64_t)(componentid & 0x3F);
		*a2 = *a1 - 1;
		*a3 = componentid;
		*a4 = componentid / 0x3F;
	}

	uintptr_t DecryptComponent(uintptr_t parent, uint8_t idx) {
		__try {
			if (parent) {

				uintptr_t v1 = parent;
				uintptr_t v2 = (uintptr_t)1 << (uintptr_t)(idx & 0x3F);
				uintptr_t v3 = v2 - 1;
				uintptr_t v4 = idx & 0x3F;
				uintptr_t v5 = idx / 0x3F;
				uintptr_t v6 = SDK->RPM<uintptr_t>((v1 + 8 * (uint32_t)v5 + 0x110));
				uintptr_t v7 = (v2 & SDK->RPM<uintptr_t>((v1 + 8 * (uint32_t)v5 + 0x110))) >> v4;
				uintptr_t v8 = (v3 & v6) - (((v3 & v6) >> 1) & 0x5555555555555555);
				uintptr_t v9 = SDK->RPM<uintptr_t>((SDK->RPM<uintptr_t>((v1 + 0x80)) + 8 * (SDK->RPM<uint8_t>(((uint32_t)v5 + v1 + 0x130)) + ((0x101010101010101 * (((v8 & 0x3333333333333333) + ((v8 >> 2) & 0x3333333333333333) + (((v8 & 0x3333333333333333) + ((v8 >> 2) & 0x3333333333333333)) >> 4)) & 0xF0F0F0F0F0F0F0F)) >> 0x38))));
				uintptr_t key1 = SDK->GlobalKey1;
				uintptr_t key2 = SDK->GlobalKey2;

				uintptr_t dummy1 = SDK->RPM<uintptr_t>(SDK->dwGameBase + 0x383CB20 + (key1 >> 0x34));
				uintptr_t dummy2 = SDK->RPM<uintptr_t>(SDK->dwGameBase + 0x383CB20 + (key1 & 0xFFF));
				uintptr_t v10 = (unsigned int)v9 | v9 & 0xFFFFFFFF00000000ui64 ^ ((unsigned __int64)(2 * __ROR4__(dummy2, 3) - (unsigned int)v9) << 0x20);;
				uintptr_t v11 = key2 ^ ((unsigned int)v10 | v10 & 0xFFFFFFFF00000000ui64 ^ ((unsigned __int64)(0x837BDC34 - (unsigned int)v10) << 0x20));
				uintptr_t v12 = (unsigned int)v11 | v11 & 0xFFFFFFFF00000000ui64 ^ ((unsigned __int64)(unsigned int)(v11 + __ROL4__(dummy1, 1)) << 0x20);
				uintptr_t v13 = -(int)v7 & ((unsigned int)v12 | v12 & 0xFFFFFFFF00000000ui64 ^ (((unsigned int)v12 ^ HIDWORD(dummy2)) << 0x20));
				return v13;
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
		return NULL;
	}

	inline unsigned __int64 __fastcall DecryptVis(unsigned __int64 a1)
	{
		unsigned __int64 v2 = 0; // rdi
		unsigned __int64 v3 = 0; // r8
		__int64 v4 = 0; // rbx
		unsigned __int64 v5 = 0; // rcx
		unsigned __int64 v6 = 0; // rax
		unsigned __int64 v7 = 0; // rax
		__m128i v8; // xmm1
		__m128i v9; // xmm2
		__m128i v10; // xmm0
		__m128i v11; // xmm1

		v2 = (SDK->dwGameBase + offset::VisFN);
		v3 = v2 + 0x8;
		v4 = SDK->RPM<_QWORD>(SDK->dwGameBase + 0x383DB40 + 8ull * (((uint8_t)a1 + 9) & 0x7F)
			+ (((unsigned __int64)(a1 - offset::Vis_Key) >> 7) & 7)) ^ v2 ^ (a1 - offset::Vis_Key);
		v5 = 0i64;
		v6 = (v3 - v2 + 7) >> 3;
		if (v2 > v3)
			v6 = 0i64;
		if (v6 >= 4)
		{
			v7 = v6 & 0xFFFFFFFFFFFFFFFCui64;
			ZeroMemory(&v8, sizeof(v8));
			ZeroMemory(&v9, sizeof(v9));
			do
			{
				v5 += 4i64;
				v8 = _mm_xor_si128(v8, _mm_loadu_si128((const __m128i*)v2));
				v10 = _mm_loadu_si128((const __m128i*)(v2 + 0x10));
				v2 += 0x20i64;
				v9 = _mm_xor_si128(v9, v10);
			} while (v5 < v7);
			v11 = _mm_xor_si128(v8, v9);
			auto addr = _mm_xor_si128(v11, _mm_srli_si128(v11, 8));
			v4 = *(__int64*)&addr;
		}
		for (; v2 < v3; v2 += 8i64)
			v4 ^= SDK->RPM<_QWORD>(v2);
		return v4 ^ ~v3 ^ 0x0C8EFF42109E0F709i64;
	}

	uintptr_t GetHeapManager(uint8_t index) {
		uintptr_t v0 = SDK->RPM<uintptr_t>(SDK->dwGameBase + offset::HeapManager);
		if (v0 != 0) {
			auto v1 = SDK->RPM<uintptr_t>(v0 + offset::HeapManager_Pointer) ^ (SDK->RPM<uintptr_t>(SDK->dwGameBase + offset::HeapManager_Var) + offset::HeapManager_Key);
			if (v1 != 0) {
				uintptr_t v2 = SDK->RPM<uintptr_t>(v1 + 0x8 * index);
				return v2;
			}
		}
		return NULL;
	}

	inline uintptr_t GetSenstivePTR() {
		uintptr_t heap = GetHeapManager(6);
		if (heap) {
			return heap + offset::SensitivePtr;
		}
		return NULL;
	}

	inline std::vector<std::pair<uint64_t, uint64_t>> get_ow_entities()
	{
		std::vector<std::pair<uint64_t, uint64_t>> result;

		struct Entity {
			uint64_t entity;
			uint64_t pad;
		};

		uintptr_t entity_list = SDK->RPM<uint64_t>(SDK->dwGameBase + offset::Address_entity_base);

		MEMORY_BASIC_INFORMATION mbi{};
		VirtualQueryEx(SDK->hProcess, (LPCVOID)entity_list, &mbi, sizeof(mbi));

		SIZE_T entity_list_size = mbi.RegionSize / sizeof(Entity);
		Entity* raw_list = new Entity[entity_list_size];

		if (ReadProcessMemory(SDK->hProcess, (LPCVOID)entity_list, raw_list, mbi.RegionSize, nullptr))
		{
			for (size_t i = 0; i < entity_list_size; ++i)
			{
				uint64_t cur_entity = raw_list[i].entity;
				if (cur_entity)
				{
					uint64_t common_linker = DecryptComponent(cur_entity, TYPE_LINK);
					//printf("LINK:%llx\n", common_linker);
					if (common_linker)
					{
						uint32_t unique_id = SDK->RPM<uint32_t>(common_linker + 0xD4);
						//printf("unique_id:%llx\n", unique_id);
						for (size_t x = 0; x < entity_list_size; ++x)
						{
							uint64_t possible_common = raw_list[x].entity;
							if (possible_common && SDK->RPM<uint32_t>(possible_common + 0x138) == unique_id)
							{
								//printf("%llx", unique_id);
								result.emplace_back(possible_common, cur_entity);
								break;
							}
							else {
								uint64_t Ptr = SDK->RPM<uint64_t>(possible_common + 0x30) & 0xFFFFFFFFFFFFFFC0;
								if (Ptr < 0xFFFFFFFFFFFFFFEF) {
									uint64_t EntityID = SDK->RPM<uint64_t>(Ptr + 0x10);
									if (EntityID == 0x400000000000060 || EntityID == 0x40000000000480A || EntityID == 0x40000000000005F || EntityID == 0x400000000002533) {
										result.emplace_back(possible_common, cur_entity);
									}
								}
							}
						}
					}
				}
			}
		}
		delete[] raw_list;
		return result;
	}

	inline bool IsSkillActive(uint64_t base, uint16_t index, uint16_t id)
	{
		if (id == 0)
			return false;
		uintptr_t skillList = 0;
		if (index == 0)
		{
			// Use the default skill list for index 0
			skillList = base + 0x570;
		}
		else
		{
			// Get the skill list for the given index
			uint32_t count = SDK->RPM<uint32_t>(base + 0x378);
			if (count <= 0 || count >= 0xFF)
				return false;
			uintptr_t entry = SDK->RPM<uintptr_t>(base + 0x370);
			if (!entry)
				return false;
			for (uint32_t i = 0; i < count; i++, entry += 0x10)
			{
				if (SDK->RPM<uint16_t>(entry + 0x8) == index)
				{
					uintptr_t listStruct = SDK->RPM<uintptr_t>(entry);
					if (!listStruct)
						return false;
					skillList = SDK->RPM<uintptr_t>(listStruct + 0xA8);
					break;
				}
			}
		}
		if (!skillList)
			return false;
		// Get the skill entry from the list using the skill id
		uintptr_t listEntry = skillList + 0x20 * ((id & 0xF) + 1);
		uintptr_t structList = SDK->RPM<uintptr_t>(listEntry);
		if (!structList)
			return false;

		int32_t listIndex = index == 0 ? 0 : SDK->RPM<int32_t>(listEntry + 0x8) - 1;
		if (listIndex < 0 || listIndex >= 0xFF)
			return false;

		uintptr_t skillEntry = structList + 0x10 * listIndex;
		if (SDK->RPM<uint16_t>(skillEntry) == id)
		{
			uintptr_t skill = SDK->RPM<uintptr_t>(skillEntry + 0x8);
			if (!skill)
				return false;

			return  SDK->RPM<uint8_t>(skill + 0x48) == 1;
		}
		return false;
	}

	inline float SkillCD(uint64_t base, uint16_t index, uint16_t id)
	{
		if (id == 0)
			return false;

		uintptr_t skillList = 0;
		if (index == 0)
		{
			// Use the default skill list for index 0
			skillList = base + 0x570;
		}
		else
		{
			// Get the skill list for the given index
			uint32_t count = SDK->RPM<uint32_t>(base + 0x378);
			if (count <= 0 || count >= 0xFF)
				return false;

			uintptr_t entry = SDK->RPM<uintptr_t>(base + 0x370);
			if (!entry)
				return false;

			for (uint32_t i = 0; i < count; i++, entry += 0x10)
			{
				if (SDK->RPM<uint16_t>(entry + 0x8) == index)
				{
					uintptr_t listStruct = SDK->RPM<uintptr_t>(entry);
					if (!listStruct)
						return false;

					skillList = SDK->RPM<uintptr_t>(listStruct + 0xA8);
					break;
				}
			}
		}

		if (!skillList)
			return false;

		// Get the skill entry from the list using the skill id
		uintptr_t listEntry = skillList + 0x20 * ((id & 0xF) + 1);
		uintptr_t structList = SDK->RPM<uintptr_t>(listEntry);
		if (!structList)
			return false;

		int32_t listIndex = SDK->RPM<int32_t>(listEntry + 0x8) - 1;
		if (listIndex < 0 || listIndex >= 0xFF)
			return false;

		uintptr_t skillEntry = structList + 0x10 * listIndex;
		if (SDK->RPM<uint16_t>(skillEntry) == id)
		{
			uintptr_t skill = SDK->RPM<uintptr_t>(skillEntry + 0x8);
			if (!skill)
				return false;

			return  SDK->RPM<float>(skill + 0x60);
		}
		return false;
	}

	inline uintptr_t SkillStructCheck(uint64_t a1, uint16_t a2)
	{
		__int64 v2; // r8
		__int64 i; // rax

		if (SDK->RPM<uint32_t>(a1 + 0x2A8) <= 0)
			return 0i64;
		v2 = 0i64;
		for (i = SDK->RPM<uintptr_t>(a1 + 0x2A0); SDK->RPM<uint16_t>(i + 8) != a2; i += 16i64)
		{
			if (++v2 >= SDK->RPM<uint32_t>(a1 + 0x2A8))
				return 0i64;
		}
		return SDK->RPM<uintptr_t>(i);
	}

	inline uint64_t FnSkillStruct(__m128* a1, uint16_t* a2)
	{

		__int64 v2; // rbx
		uint16_t* v3;
		__int16 v4; // dx
		__int64 v5; // rcx
		__int64 v6; // r9
		__int64 v7; // rax
		unsigned __int16 v8; // r8
		__int64 v9; // rdx
		int v10; // eax
		__int64 v11; // rcx
		__int64 v12; // rax
		__int64 v13; // rdi

		v2 = 0i64;
		v3 = a2;
		if (!a2[1])
			return 0i64;
		v4 = *a2;
		v5 = a1->m128_i64[1];
		if (!v4)
		{
			v6 = v5 + 0x4A0;
			goto LABEL_6;
		}
		v7 = SkillStructCheck(v5, v4);
		if (!v7)
			return 0i64;
		v6 = SDK->RPM<uintptr_t>(v7 + 168);
	LABEL_6:
		v8 = v3[1];
		v9 = 32 * ((v3[1] & 0xF) + 1i64);
		v10 = SDK->RPM<uint32_t>(v9 + v6 + 8) - 1;
		if (v10 < 0)
			return 0x0;
		v11 = v10;
		v12 = SDK->RPM<uintptr_t>(v9 + v6) + 16i64 * v10;
		while (SDK->RPM<uint16_t>(v12) != v8)
		{
			v12 -= 16i64;
			if (--v11 < 0)
				return 0x0;
		}
		v13 = SDK->RPM<uintptr_t>(v12 + 8);
		if (!v13)
			return 0x0;

		if (*((uint32_t*)v3 + 4) <= 0)
			return v13;

		return v13;
	}

	inline bool IsSkillActivate1(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2)
	{
		__m128 skillStruct{};
		uint16_t skillId[15] = { skillIdx, skillIdx2 };
		skillStruct.m128_u64[1] = base + 0xD0;
		uint64_t skill = FnSkillStruct(&skillStruct, skillId);
		bool ret = SDK->RPM<uint8_t>(skill + 0x48) == 1;
		if (!skill)
			return false;
		return ret;
	}

	inline float readskillcd(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2)
	{
		__m128 skillStruct{};
		uint16_t skillId[15] = { skillIdx, skillIdx2 };
		skillStruct.m128_u64[1] = base + 0xD0;
		uint64_t skill = FnSkillStruct(&skillStruct, skillId);
		if (!skill)
			return false;
		float ret = SDK->RPM<float>(skill + 0x48);
		if (!ret) return ret;
		ret = SDK->RPM<float>(skill + 0x60);
		if (ret != 0)
			return ret;
		else return 1;
	}

	inline float readult(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2)
	{
		__m128 skillStruct{};
		uint16_t skillId[15] = { skillIdx, skillIdx2 };
		skillStruct.m128_u64[1] = base + 0xD0;
		uint64_t skill = FnSkillStruct(&skillStruct, skillId);
		if (!skill)
			return false;
		float ret = SDK->RPM<float>(skill + 0x60);
		return ret;
	}

	inline float cdready(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2)
	{
		__m128 skillStruct{};
		uint16_t skillId[15] = { skillIdx, skillIdx2 };
		skillStruct.m128_u64[1] = base + 0xD0;
		uint64_t skill = FnSkillStruct(&skillStruct, skillId);
		if (!skill)
			return false;
		float ret = SDK->RPM<float>(skill + 0x48);
		return ret;
	}


	uintptr_t GetOutlineStruct(uintptr_t a1)
	{
		__try
		{
			uint64_t result = NULL;
			int v1 = SDK->RPM<uint32_t>(a1 + 0x68);
			if (v1 <= 0)
				result = 0;
			else
				result = (uint64_t)(0x20 * v1 + SDK->RPM<uint64_t>(a1 + 0x60) - 0x20);

			return result;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}

		return NULL;
	}

	uint64_t GetThickNessStruct(uint64_t a1)
	{
		__try
		{
			uint64_t result = NULL;
			int v1 = SDK->RPM<uint32_t>(a1 + 0x1C8);
			if (v1 <= 0)
				result = 0;
			else
				result = (uint64_t)(0x14 * v1 + SDK->RPM<uint64_t>(a1 + 0x1C0) - 0x14);

			return result;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}

		return NULL;
	}

	inline uint64_t DecryptOutline(uint64_t a1)
	{
		unsigned __int64 v2 = 0; // rdi
		unsigned __int64 v3 = 0; // r8
		unsigned __int64 v4 = 0; // rax
		__int64 v5 = 0; // rbx
		unsigned __int64 v6 = 0; // rcx
		unsigned __int64 v7 = 0; // rcx
		__m128i v8; // xmm1
		__m128i v9; // xmm2
		__m128i v10; // xmm0
		__m128i v11; // xmm1

		v2 = (SDK->dwGameBase + offset::OutlineFN);
		v3 = v2 + 0x8;
		v4 = 0i64;
		v5 = SDK->RPM<uintptr_t>(SDK->dwGameBase + 0x383DB40 + 8ull * (((uint8_t)a1 - 0x3F) & 0x7F)
			+ (((unsigned __int64)(a1 - offset::Outline_Key) >> 7) & 7)) ^ v2 ^ (a1 - offset::Outline_Key);
		v6 = (v3 - v2 + 7) >> 3;
		if (v2 > v3)
			v6 = 0i64;
		if (v6 >= 4)
		{
			v7 = v6 & 0xFFFFFFFFFFFFFFFCui64;
			ZeroMemory(&v8, sizeof(v8));
			ZeroMemory(&v9, sizeof(v9));
			do
			{
				v4 += 4i64;
				v8 = _mm_xor_si128(v8, _mm_loadu_si128((const __m128i*)v2));
				v10 = _mm_loadu_si128((const __m128i*)(v2 + 0x10));
				v2 += 0x20i64;
				v9 = _mm_xor_si128(v9, v10);
			} while (v4 < v7);
			v11 = _mm_xor_si128(v8, v9);
			auto addr = _mm_xor_si128(v11, _mm_srli_si128(v11, 8));
			v5 = *(__int64*)&addr;
		}
		for (; v2 < v3; v2 += 8i64)
			v5 ^= SDK->RPM<_QWORD>(v2);
		return v5 ^ ~v3 ^ 0x0960E0DB66A0928C1i64;
	}

	inline void SetBorderLine(uint32_t BorderType, DWORD_PTR base)
	{
		uint64_t BorderStruct = GetOutlineStruct((uint64_t)(base + 0x20)); // 0x5A Components + 0x20
		uint64_t DecryptData = DecryptOutline(SDK->RPM<uint64_t>(BorderStruct + 0x18));

		SDK->WPM<uint32_t>(BorderStruct + 0x10, (DecryptData ^ BorderType));
	}
}