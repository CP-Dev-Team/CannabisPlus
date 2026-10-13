modded class ParticleList
{
	// JOINT_SMOKE kept as alias for backward compatibility.
	// Don't write ParticleList.AC_SMOKE here: naming ParticleList inside a modded ParticleList gives
	// "Circle inheritance" as soon as another mod's modded ParticleList loads after this one.
	static int JOINT_SMOKE = AC_SMOKE;
}