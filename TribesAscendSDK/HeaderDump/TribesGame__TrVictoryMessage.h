#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVictoryMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVictoryMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVictoryMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVictoryMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, TrainingComplete, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DrawGame, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PlayerWonRound, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DiamondSwordVictory, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BloodEagleVictory, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NormalDefeat, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NormalVictory, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DominantDefeat, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DominantVictory, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, BloodEagleSounds )
			ADD_OBJECT( SoundCue, DiamondSwordSounds )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
