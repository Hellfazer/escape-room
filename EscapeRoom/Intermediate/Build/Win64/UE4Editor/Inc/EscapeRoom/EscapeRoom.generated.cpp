// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "EscapeRoom.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1EscapeRoom() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AGameModeBase();
	ENGINE_API class UClass* Z_Construct_UClass_UActorComponent();

	ESCAPEROOM_API class UClass* Z_Construct_UClass_AEscapeRoomGameModeBase_NoRegister();
	ESCAPEROOM_API class UClass* Z_Construct_UClass_AEscapeRoomGameModeBase();
	ESCAPEROOM_API class UClass* Z_Construct_UClass_UPositionReport_NoRegister();
	ESCAPEROOM_API class UClass* Z_Construct_UClass_UPositionReport();
	ESCAPEROOM_API class UPackage* Z_Construct_UPackage__Script_EscapeRoom();
	void AEscapeRoomGameModeBase::StaticRegisterNativesAEscapeRoomGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AEscapeRoomGameModeBase_NoRegister()
	{
		return AEscapeRoomGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AEscapeRoomGameModeBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_EscapeRoom();
			OuterClass = AEscapeRoomGameModeBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900288;


				static TCppClassTypeInfo<TCppClassTypeTraits<AEscapeRoomGameModeBase> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("EscapeRoomGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("EscapeRoomGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEscapeRoomGameModeBase, 241258082);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEscapeRoomGameModeBase(Z_Construct_UClass_AEscapeRoomGameModeBase, &AEscapeRoomGameModeBase::StaticClass, TEXT("/Script/EscapeRoom"), TEXT("AEscapeRoomGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEscapeRoomGameModeBase);
	void UPositionReport::StaticRegisterNativesUPositionReport()
	{
	}
	UClass* Z_Construct_UClass_UPositionReport_NoRegister()
	{
		return UPositionReport::StaticClass();
	}
	UClass* Z_Construct_UClass_UPositionReport()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_EscapeRoom();
			OuterClass = UPositionReport::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;


				static TCppClassTypeInfo<TCppClassTypeTraits<UPositionReport> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PositionReport.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PositionReport.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPositionReport, 1734765726);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPositionReport(Z_Construct_UClass_UPositionReport, &UPositionReport::StaticClass, TEXT("/Script/EscapeRoom"), TEXT("UPositionReport"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPositionReport);
	UPackage* Z_Construct_UPackage__Script_EscapeRoom()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/EscapeRoom")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xA0E2691F;
			Guid.B = 0x96A5D4BF;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
