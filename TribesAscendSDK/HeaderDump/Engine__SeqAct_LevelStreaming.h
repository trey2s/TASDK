#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_LevelStreaming." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_LevelStreaming." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_LevelStreaming." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_LevelStreaming : public SeqAct_LevelStreamingBase
	{
	public:
			ADD_VAR( ::BoolProperty, bStatusIsOk, 0x1 )
			ADD_VAR( ::NameProperty, LevelName, 0xFFFFFFFF )
			ADD_OBJECT( LevelStreaming, Level )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
