#include "MATA_HEADER.h"

std::vector<ImageInfo> ImageList
{
	// MATA_ENGINE resources
	{"BOUNDBOX", "MATA_ENGINE_RES//Image//Collision//Square.png"},
	{"BOUNDBOXCOLLISION", "MATA_ENGINE_RES//Image//Collision//Square Inside.png"},
	{"CIRCLE", "MATA_ENGINE_RES//Image////Collision//Circle.png"},
	{"CIRCLECOLLISION", "MATA_ENGINE_RES//Image////Collision//Circle Inside.png"},
	{"FMOD_LOGO", "MATA_ENGINE_RES//Image//Common//FMOD Logo.png"},
	{"MATA_ENGINE_LOGO", "MATA_ENGINE_RES//Image//Common//MATA_ENGINE Logo.png"},
	////////

	///// playmode image
	// 트레드밀 이미지
	{"treadmil", "res//sprite//treadmil//treadmil.png"},
	{"treadmil_debug", "res//sprite//treadmil//treadmil_debug.png"},
	{"treadmil_prop", "res//sprite//treadmil//treadmil_prop.png"},

	// 에르핀 이미지
	{"erpin", "res//sprite//erpin//erpin.png"},
	{"erpin_wing", "res//sprite//erpin//erpin_wing.png"},
	{"erpin_face_normal", "res//sprite//erpin//erpin_face_normal.png"},
	{"erpin_face_blink", "res//sprite//erpin//erpin_face_blink.png"},
	{"erpin_face_eat_1", "res//sprite//erpin//erpin_face_eat_1.png"},
	{"erpin_face_eat_2", "res//sprite//erpin//erpin_face_eat_2.png"},

	// 음식 이미지
	// 초콜릿 이미지
	{"chocolate_outside", "res//sprite//food//chocolate_outside.png"},
	{"chocolate_inside", "res//sprite//food//chocolate_inside.png"},

	// 음식 파편 이미지
	{"debris", "res//sprite//food//debris.png"},
	/////
};

std::vector<FileNameAndOption> SoundList
{
	// MATA_ENGINE resource
	{"MATA_ENGINE_LOGO_SOUND", "MATA_ENGINE_RES//Sound//MATA_ENGINE Logo Sound.wav", FMOD_DEFAULT},
	//////////

};