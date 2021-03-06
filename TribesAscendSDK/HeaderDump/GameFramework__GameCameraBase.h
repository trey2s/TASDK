#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCameraBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCameraBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCameraBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCameraBase : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bResetCameraInterpolation, 0x1 )
			ADD_OBJECT( GamePlayerCamera, PlayerCamera )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
