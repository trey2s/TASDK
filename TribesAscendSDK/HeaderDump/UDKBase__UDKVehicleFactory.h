#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKVehicleFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKVehicleFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKVehicleFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKVehicleFactory : public NavigationPoint
	{
	public:
			ADD_VAR( ::IntProperty, TeamNum, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, HUDLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RespawnProgress, 0xFFFFFFFF )
			ADD_OBJECT( UDKVehicle, ChildVehicle )
			ADD_VAR( ::BoolProperty, bReplicateChildVehicle, 0x2 )
			ADD_VAR( ::BoolProperty, bHasLockedVehicle, 0x1 )
			ADD_VAR( ::StrProperty, VehicleClassPath, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
