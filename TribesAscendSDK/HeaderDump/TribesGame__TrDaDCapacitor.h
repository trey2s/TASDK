#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDaDCapacitor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDaDCapacitor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDaDCapacitor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDaDCapacitor : public TrGameObjective
	{
	public:
			ADD_VAR( ::StrProperty, StringC, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StringB, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StringA, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_CapacitorIndex, 0xFFFFFFFF )
			ADD_OBJECT( TrDaDCore, m_Core )
			ADD_VAR( ::FloatProperty, m_fShieldBarPlacementY, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_ShieldBarMIC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
