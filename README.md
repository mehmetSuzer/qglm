
# QGLM

*A lightweight, header-only mathematics library for embedded graphics.*

QGLM is a header-only, fixed-point, graphics-focused math library designed specifically for embedded systems where floating-point hardware may be limited or unavailable.
It provides a compact but complete set of types and operations commonly needed for real-time graphics, geometry, and transformation pipelines.


## ✨ Features

Header-only — easy integration, no linking required

Designed for low-resource, deterministic, and real-time applications

Fixed-point numeric types optimised for embedded hardware

Vector, matrix, quaternion, and geometry primitives

Translation, rotation, and scaling matrices

Projection, view, and viewport transformation matrices

Optional safe math modes


## 📦 Fixed-Point Types

QGLM provides the following signed fixed-point number formats:

|    TYPE   | INTEGER BITS | FRACTION BITS |
|-----------|--------------|---------------|
| q_16_16_t |      16      |       16      |
| q_24_8_t  |      24      |        8      |
| q_8_24_t  |       8      |       24      |

These form the numeric foundation for all higher-level types.


## 🛠️ Core Data Types

### Vectors
- `Q_VEC2`
- `Q_VEC3`
- `Q_VEC4`

### Quaternion
- `Q_QUAT`

### Matrices
-   `Q_MAT2`, `Q_MAT2X3`, `Q_MAT2X4`
- `Q_MAT3X2`,   `Q_MAT3`, `Q_MAT3X4`
- `Q_MAT4X2`, `Q_MAT4X3`,   `Q_MAT4`

### Geometry
- `Q_RAY`
- `Q_PLANE`
- `Q_SPHERE`
- `Q_TRIANGLE`


## 📐 Transformation Matrices

QGLM includes common transformation matrix constructors:

- Translation
- Rotation
- Scaling
- Orthographic Projection
- View Matrix
- Perspective Projection
- Viewport Matrix


## ⚙️ Configuration Macros

QGLM allows one build-time option to trade safety for speed or vice-versa:

**QGLM_SAFE_MATH**

Enables slower and more precise functions with additional safety checks.


## 📁 Integration

Each fixed-point format has a header file providing all features.
Only one of these header files MUST be included:
- q16_16_glm.h
- q24_8_glm.h
- q8_24_glm.h

Including more than one results in redefinition warnings.
Therefore, you should select one fixed-point type based on the requirements of your project and never include the header files of other fixed-point types.

```c
#include "q16_16_glm.h"

const Q_VEC3 position = {{Q_FROM_INT(4), Q_FROM_FLOAT(-5.3f), Q_TWO}}; // You can use q16_16_vec3_t instead of Q_VEC3
const Q_QUAT rotation = q_quat_angle_axis(Q_HALFPI, Q_VEC3_FORWARD);   // You can use q16_16_quat_t instead of Q_QUAT
const Q_VEC3 scale    = {{Q_TWO, Q_ONE, Q_HALF}};
 
Q_MAT4 model = Q_MAT4_IDENTITY; // You can use q16_16_mat4_t instead of Q_MAT4
q_translate_3d(&model, position);
q_rotate_3d_quat(&model, rotation);
q_scale_3d(&model, scale);
```

```c
#include "q24_8_glm.h"

const Q_VEC3 position = {{Q_FROM_INT(4), Q_FROM_FLOAT(-5.3f), Q_TWO}}; // You can use q24_8_vec3_t instead of Q_VEC3
const Q_QUAT rotation = q_quat_angle_axis(Q_HALFPI, Q_VEC3_FORWARD);   // You can use q24_8_quat_t instead of Q_QUAT
const Q_VEC3 scale    = {{Q_TWO, Q_ONE, Q_HALF}};
 
Q_MAT4 model = Q_MAT4_IDENTITY; // You can use q24_8_mat4_t instead of Q_MAT4
q_translate_3d(&model, position);
q_rotate_3d_quat(&model, rotation);
q_scale_3d(&model, scale);
```

```c
#include "q8_24_glm.h"

const Q_VEC3 position = {{Q_FROM_INT(4), Q_FROM_FLOAT(-5.3f), Q_TWO}}; // You can use q8_24_vec3_t instead of Q_VEC3
const Q_QUAT rotation = q_quat_angle_axis(Q_HALFPI, Q_VEC3_FORWARD);   // You can use q8_24_quat_t instead of Q_QUAT
const Q_VEC3 scale    = {{Q_TWO, Q_ONE, Q_HALF}};
 
Q_MAT4 model = Q_MAT4_IDENTITY; // You can use q8_24_mat4_t instead of Q_MAT4
q_translate_3d(&model, position);
q_rotate_3d_quat(&model, rotation);
q_scale_3d(&model, scale);
```


## ⚠️ Notes

Currently no arithmetic saturation is implemented.
Large multiplications or divisions by very small numbers may overflow.
Use with caution when performing operations on extreme values.

The library is still under active development and testing, so some bugs may still be present.


## 📄 License
This project is licensed under the MIT License.  
See the [LICENSE](LICENSE) file for details.

