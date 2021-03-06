#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn_Projectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn_Projectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn_Projectile." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn_Projectile : public TrCallIn
	{
	public:
			ADD_STRUCT( ::VectorProperty, m_SavedTargetNormal, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_SavedTargetLocation, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_FiredProjectiles, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, TargetParticleSystem )
			ADD_OBJECT( SoundCue, TargetParticleSound )
			ADD_OBJECT( SoundCue, AreaWarningSound )
			ADD_VAR( ::IntProperty, NumberOfProjectiles, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FireTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CallRadius, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
