#pragma once
#pragma warning(disable: 4244) 
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include "fmod.hpp"
#include "fmod_errors.h"
#include <string>
#include <vector>

// display width, height and apsect ratio
extern int WIDTH, HEIGHT;
extern int PREV_WIDTH, PREV_HEIGHT;
extern GLfloat ASPECT;

// corner position of display
struct Rect {
	GLfloat lx, ly, rx, ry;
};
extern Rect rect;

// GPU vendor name and vendor print option
extern std::string GPU_Vendor;

// global scope shader
extern GLuint ImageShader;
extern GLuint TextShader;

void SetBackColor(GLfloat R, GLfloat G, GLfloat B);
extern glm::vec3 BackColor;

struct ImageInfo {
	std::string Name;
	const char* FileName;
};

struct FileNameAndOption {
	std::string Name;
	const char* FileName;
	FMOD_MODE Option;
};

extern std::vector<ImageInfo> ImageList;
extern std::vector<FileNameAndOption> SoundList;

// 트레드밀 라인 별 오브젝트 움직이는 각도
constexpr GLfloat FIRST_LINE_DEGREE = 79.4;
constexpr GLfloat SECOND_LINE_DEGREE = 85.0;
constexpr GLfloat THIRD_LINE_DEGREE = 90;
constexpr GLfloat FOURTH_LINE_DEGREE = 95.0;
constexpr GLfloat FIFTH_LINE_DEGREE = 100.6;

// 트레드밀 라인 별 오브젝트 초기 x 위치
constexpr GLfloat FIRST_LINE_POSITION = -0.54;
constexpr GLfloat SECOND_LINE_POSITION = -0.265;
constexpr GLfloat THIRD_LINE_POSITION = 0.0;
constexpr GLfloat FOURTH_LINE_POSITION = 0.265;
constexpr GLfloat FIFTH_LINE_POSITION = 0.54;

// window name
constexpr const char* WindowName = "Erpin Game";

// window size
constexpr int WindowWidth = 1200;
constexpr int WindowHeight = 800;

// fullscreen option
constexpr bool StartWithFullScreen = false;

// boundbox option
constexpr bool ShowBoundBox = true;

// console window option
constexpr bool ShowConsole = true;

// vendor print option
constexpr bool PrintGPU_VendorInfoOpt = false;