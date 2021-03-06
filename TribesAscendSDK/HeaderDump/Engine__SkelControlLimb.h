#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkelControlLimb." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkelControlLimb." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkelControlLimb." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlLimb : public SkelControlBase
	{
	public:
			ADD_VAR( ::NameProperty, StretchRollBoneName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAllowStretching, 0x20 )
			ADD_VAR( ::BoolProperty, bTakeRotationFromEffectorSpace, 0x10 )
			ADD_VAR( ::BoolProperty, bMaintainEffectorRelRot, 0x8 )
			ADD_VAR( ::BoolProperty, bRotateJoint, 0x4 )
			ADD_VAR( ::BoolProperty, bInvertJointAxis, 0x2 )
			ADD_VAR( ::BoolProperty, bInvertBoneAxis, 0x1 )
			ADD_VAR( ::NameProperty, JointTargetSpaceBoneName, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, JointTargetLocation, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, EffectorSpaceBoneName, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, JointAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, BoneAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, JointTargetLocationSpace, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, EffectorLocationSpace, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EffectorLocation, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
