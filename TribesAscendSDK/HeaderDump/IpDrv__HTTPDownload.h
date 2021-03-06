#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.HTTPDownload." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.HTTPDownload." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.HTTPDownload." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class HTTPDownload : public Download
	{
	public:
			ADD_VAR( ::StrProperty, ProxyServerHost, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ProxyServerPort, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RedirectToURL, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, UseCompression, 0x1 )
			ADD_VAR( ::BoolProperty, MaxRedirection, 0x1 )
			ADD_VAR( ::FloatProperty, ConnectionTimeout, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
