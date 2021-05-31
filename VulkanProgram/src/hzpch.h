#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <optional>
#include <set>
#include <unordered_map>
#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>
#ifdef G_MAC
    #include <math.h>
#elif G_WIN
    #include <cmath.h>
#endif
