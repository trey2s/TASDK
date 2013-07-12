#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrPawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrPawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrPawn." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPawn : public UTPawn
	{
	public:
			ADD_OBJECT( TrVehicle, m_RidingVehicle )
			ADD_VAR( ::FloatProperty, m_fCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fHeadShotDamageMultiple, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentAccuracy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnViewForwardAmount, 0xFFFFFFFF )
			ADD_OBJECT( TrAnimNodeBlendByRidingPassenger, m_RidingPassengerBlendNode )
			ADD_OBJECT( TrAnimNodeAimOffset, m_AimOffsetNode )
			ADD_OBJECT( TrAnimNodeAimOffset, m_1pBodyAimOffsetNode )
			ADD_STRUCT( ::VectorProperty, r_FlashNormal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShowObjectThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bIsStealthed, 0x4 )
			ADD_VAR( ::BoolProperty, r_bIsInvulnerable, 0x100000 )
			ADD_VAR( ::BoolProperty, r_bIsSkiing, 0x800 )
			ADD_VAR( ::BoolProperty, r_bIsJetting, 0x8000 )
			ADD_VAR( ::FloatProperty, m_TerrainWalkableFloorZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSwapSkinDistSq, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNetViewPitchCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_PitchInterpRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nTargetRemoteViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPreviousReceivedRemoteViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nSmoothedRemoteViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNetRotationCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RotationInterpRate, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_TargetNetReceiveRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_PreviousNetReceiveRotation, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, m_GibMesh )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_VAR( ::FloatProperty, m_fInventoryStationLockoutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastInventoryStationVisitTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nDetectedByEnemyScannerCount, 0xFFFFFFFF )
			ADD_OBJECT( UDKCarriedObject, m_GameObjCheckTimer )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_HealthBarMIC )
			ADD_OBJECT( UTWeaponAttachment, m_InHandWeaponAttachmentFromAutoFire )
			ADD_VAR( ::FloatProperty, m_fLastTakeClotheslineDamageTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineSpeedDifferenceMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineSpeedDifferenceMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineDamageMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineDamageMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatSpeedMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatSpeedMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromWallMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromWallMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromLandMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromLandMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_bJustLandedSpeedSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fGroundSkiEffectDist, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_InvulnerableOverlayMIC )
			ADD_OBJECT( Material, m_InvulnerableOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_RageOverlayMIC )
			ADD_OBJECT( Material, m_RageOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_JammerPackOverlayMIC )
			ADD_OBJECT( Material, m_JammerPackOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_RegenPackPackOverlayMIC )
			ADD_OBJECT( Material, m_RegenPackOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_RegenOverlayMIC )
			ADD_OBJECT( Material, m_RegenOverlayMaterial )
			ADD_VAR( ::FloatProperty, m_fShieldPackMaterialHitRampDownSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOverlayMaterialDeactivateSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOverlayMaterialActivateSpeed, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_ShieldPackOverlayMIC )
			ADD_OBJECT( Material, m_ShieldPackOverlayMaterial )
			ADD_VAR( ::FloatProperty, m_fForwardJettingPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxJetpackBoostGroundspeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nEnemyDropJammerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nFriendlyDropJammerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nEnemyJamCount, 0xFFFFFFFF )
			ADD_OBJECT( TrPlayerReplicationInfo, r_FriendJammingPRI )
			ADD_VAR( ::IntProperty, m_JammingFriendTeam, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fJamEffectRadius, 0xFFFFFFFF )
			ADD_OBJECT( TrPawnCollisionProxy, m_JammingCollisionProxy )
			ADD_OBJECT( Material, r_ReplicatedWeaponAttachmentMat )
			ADD_VAR( ::FloatProperty, m_OldSpeed, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_avMultiShotLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fEnemyShowDistanceThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFriendlyShowDistanceThreshold, 0xFFFFFFFF )
			ADD_OBJECT( MorphNodeWeight, m_OverlayMorphNode )
			ADD_OBJECT( TrAnimNodeBlendByVehicle, m_VehicleBlendNode )
			ADD_VAR( ::FloatProperty, m_fFallVelocityTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastDamagerTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastVehicleDamagerTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_AssistDamagePercentQualifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiAccelPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiAccelCapSpeedThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAirAccelSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAirAccelCapSpeedThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTerminalSkiSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSkiSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiSlopeGravityBoost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSkiControlPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiControlSigmaSquare, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPeakSkiControlSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nSensorAlertLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDecelerationRateWithFlag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSpeedWithFlag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPreserveVelocityZNormalThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPreserveVelocityThresholdMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPreserveVelocityThresholdMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSpeedDecelerationRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTerminalJettingSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxJettingSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccelRateAtMaxThrustSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxJetpackThrustSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxStoppingDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fStoppingDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fHeadShotFudge, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTickedRegenDecimal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSecondsBeforeAutoHeal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fPowerPoolRechargeRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastUntargetByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastTargetByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastUnseenByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastSeenByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, s_fVE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShieldMultiple, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fFasterWeaponSwitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthIgnoreTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthIgnoreTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fPulseStealthSpeedThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthFadeInInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthVisibleTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthVisibleTimestamp, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_StealthMIC )
			ADD_OBJECT( Material, m_StealthMaterial )
			ADD_VAR( ::FloatProperty, m_fMinStealthVisibilityParamValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDisableStealthVisibilityInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fEnableStealthVisibilityInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LastFXOverlay, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nWhiteOut, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_RemoteViewYaw, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PhysType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nFactionId, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nBlinked, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nPulseStealth, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_MissileLock, 0xFFFFFFFF )
			ADD_OBJECT( Actor, r_LockedTarget )
			ADD_VAR( ::BoolProperty, m_bUseSmoothNetReceiveRotation, 0x1000000 )
			ADD_VAR( ::BoolProperty, r_bDetectedByEnemyScanner, 0x800000 )
			ADD_VAR( ::BoolProperty, m_bSplattedAgainstWall, 0x400000 )
			ADD_VAR( ::BoolProperty, m_bIsInConduit, 0x200000 )
			ADD_VAR( ::BoolProperty, m_bUpdateStickyGrenades, 0x80000 )
			ADD_VAR( ::BoolProperty, m_bLoadoutReset, 0x40000 )
			ADD_VAR( ::BoolProperty, r_bIsJamming, 0x20000 )
			ADD_VAR( ::BoolProperty, m_bIsJetEffectsPlaying, 0x10000 )
			ADD_VAR( ::BoolProperty, r_bAimingMode, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bIsPlayingSkiEffectsSounds, 0x2000 )
			ADD_VAR( ::BoolProperty, m_bIsPlayingSkiEffects, 0x1000 )
			ADD_VAR( ::BoolProperty, bInDeployModeClient, 0x400 )
			ADD_VAR( ::BoolProperty, r_bInDeployMode, 0x200 )
			ADD_VAR( ::BoolProperty, bInFireLockClient, 0x100 )
			ADD_VAR( ::BoolProperty, r_bInFireLock, 0x80 )
			ADD_VAR( ::BoolProperty, r_bIsHealthRecharging, 0x40 )
			ADD_VAR( ::BoolProperty, r_bIsShielded, 0x20 )
			ADD_VAR( ::BoolProperty, r_bIsRaged, 0x10 )
			ADD_VAR( ::BoolProperty, m_bStealthVisible, 0x8 )
			ADD_VAR( ::BoolProperty, m_bRefreshInventoryWasRespawn, 0x2 )
			ADD_VAR( ::BoolProperty, m_bInitialized, 0x1 )
			ADD_VAR( ::NameProperty, m_nmMakeVisible, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT