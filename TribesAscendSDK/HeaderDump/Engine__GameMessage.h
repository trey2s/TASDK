#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameMessage : public LocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, MaxedOutMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SpecEnteredMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NewSpecMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KickWarning, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NewPlayerMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BecameSpectator, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CantBePlayer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CantBeSpectator, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MustHaveStats, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, VotePassed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, VoteStarted, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NoNameChange, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NewTeamMessageTrailer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NewTeamMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GlobalNameChange, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OvertimeMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ArbitrationMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnteredMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FailedSpawnMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FailedPlaceMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FailedTeamMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, LeftMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SwitchLevelMessage, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
