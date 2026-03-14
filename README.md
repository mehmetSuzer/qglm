
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

Homogeneous coordinates

Projection, view, and viewport transformation matrices

Optional safe math modes


## 📦 Fixed-Point Types

QGLM provides the following signed fixed-point number formats:

|   TYPE   | INTEGER BITS | FRACTION BITS | MIN VALUE |      MAX VALUE     |
|----------|--------------|---------------|-----------|--------------------|
| q4_12_t  |       4      |       12      |  $-2^{3}$ |  $2^{4} - 2^{-12}$ |
| q8_8_t   |       8      |        8      |  $-2^{7}$ |  $2^{7} - 2^{-8}$  |
| q12_4_t  |      12      |        4      | $-2^{11}$ | $2^{11} - 2^{-4}$  |
| q8_24_t  |       8      |       24      |  $-2^{7}$ |  $2^{7} - 2^{-24}$ |
| q16_16_t |      16      |       16      | $-2^{15}$ | $2^{15} - 2^{-16}$ |
| q24_8_t  |      24      |        8      | $-2^{23}$ | $2^{23} - 2^{-8}$  |

These form the numeric foundation for all higher-level types.


## 🛠️ Core Data Types

### Fixed-Point
- `Q_TYPE`

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
- `Q_AABB`
- `Q_PLANE`
- `Q_SPHERE`
- `Q_TRIANGLE`
- `Q_COLLISION`


## 📐 Transformation Matrices

QGLM includes common transformation matrix constructors:

- Translation Matrix
- Rotation Matrix
- Scale Matrix
- View Matrix
- Orthographic Projection Matrix
- Perspective Projection Matrix
- Viewport Matrix


## ⚙️ Configuration Macros

QGLM allows build-time options:

**QGLM_SAFE_MATH**

- Enables the safe math mode.
- Activates slower but more precise functions with additional safety checks.
- Saturates results and prevents overflowing.
- Does not assume that computed values fall within the minimum and maximum limits.

**QGLM_DEPTH_ZERO_TO_ONE**

- When defined, the viewport transform maps depth values to [Q_ZERO, Q_ONE].
- Otherwise, it maps them to [Q_M_ONE, Q_ONE].


## 📁 Integration

Each fixed-point format has a header file providing all features.
Only one of these headers MUST be included:
- q4_12.h
- q8_8.h
- q12_4.h
- q8_24.h
- q16_16.h
- q24_8.h

Including more than one results in redefinition warnings/errors.
Therefore, you should select one fixed-point type based on the requirements of your project and never include the header files of other fixed-point types.
Here is a code snippet that computes the model matrix for q16_16_t:

```c
#define QGLM_SAFE_MATH // enables the safe math mode, must be defined before including
#define QGLM_DEPTH_ZERO_TO_ONE // depth values are mapped to [Q_ZERO, Q_ONE], must be defined before including
#include <qglm/q16_16.h>

const Q_VEC3 position = {{Q_FROM_INT(4), Q_FROM_FLOAT(-5.3f), Q_TWO}}; // Q_VEC3 is a macro alias for q16_16_vec3_t
const Q_QUAT rotation = q_quat_angle_axis(Q_HALFPI, Q_VEC3_FORWARD);   // Q_QUAT is a macro alias for q16_16_quat_t
const Q_VEC3 scale    = {{Q_TWO, Q_ONE, Q_HALF}};
 
Q_MAT4 model = Q_MAT4_IDENTITY; // Q_MAT4 is a macro alias for q16_16_mat4_t
q_translate_3d(&model, position);
q_rotate_3d_quat(&model, rotation);
q_scale_3d(&model, scale);
```

## ⚠️ Notes

The library is still under active development and testing, so some bugs may still be present.


## 📄 License
This project is licensed under the MIT License.  
See the [LICENSE](LICENSE) file for details.

