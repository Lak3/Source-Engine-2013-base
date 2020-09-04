#pragma once
#include <math.h>
#include <cmath>		//std::isfinite std::remainder
#include <cfloat>		//FLT_EPSILON
#include <algorithm>	//std::min std::max

#define M_RADPI		57.295779513082
#define PI			3.14159265358979323846
#define DEG2RAD(x)	((float)(x) * (float)((float)(PI) / 180.0f))
#define RAD2DEG(x)	((float)(x) * (float)(180.0f / (float)(PI)))

#pragma warning (disable : 26495)
#pragma warning (disable : 26451)
#pragma warning (disable : 4244)

class Vec2
{
public:
	Vec2(void)
	{
		x = y = 0.0f;
	}

	Vec2(float X, float Y)
	{
		x = X; y = Y;
	}

	Vec2(float *v)
	{
		x = v[0]; y = v[1];
	}

	Vec2(const float *v)
	{
		x = v[0]; y = v[1];
	}

	Vec2(const Vec2 &v)
	{
		x = v.x; y = v.y;
	}

	Vec2 &operator=(const Vec2 &v)
	{
		x = v.x; y = v.y; return *this;
	}

	float &operator[](int i)
	{
		return ((float *)this)[i];
	}

	float operator[](int i) const
	{
		return ((float *)this)[i];
	}

	Vec2 &operator+=(const Vec2 &v)
	{
		x += v.x; y += v.y; return *this;
	}

	Vec2 &operator-=(const Vec2 &v)
	{
		x -= v.x; y -= v.y; return *this;
	}

	Vec2 &operator*=(const Vec2 &v)
	{
		x *= v.x; y *= v.y; return *this;
	}

	Vec2 &operator/=(const Vec2 &v)
	{
		x /= v.x; y /= v.y; return *this;
	}

	Vec2 &operator+=(float v)
	{
		x += v; y += v; return *this;
	}

	Vec2 &operator-=(float v)
	{
		x -= v; y -= v; return *this;
	}

	Vec2 &operator*=(float v)
	{
		x *= v; y *= v; return *this;
	}

	Vec2 &operator/=(float v)
	{
		x /= v; y /= v; return *this;
	}

	Vec2 operator+(const Vec2 &v) const
	{
		return Vec2(x + v.x, y + v.y);
	}

	Vec2 operator-(const Vec2 &v) const
	{
		return Vec2(x - v.x, y - v.y);
	}

	Vec2 operator*(const Vec2 &v) const
	{
		return Vec2(x * v.x, y * v.y);
	}

	Vec2 operator/(const Vec2 &v) const
	{
		return Vec2(x / v.x, y / v.y);
	}

	Vec2 operator+(float v) const
	{
		return Vec2(x + v, y + v);
	}

	Vec2 operator-(float v) const
	{
		return Vec2(x - v, y - v);
	}

	Vec2 operator*(float v) const
	{
		return Vec2(x * v, y * v);
	}

	Vec2 operator/(float v) const
	{
		return Vec2(x / v, y / v);
	}

	void Set(float X = 0.0f, float Y = 0.0f)
	{
		x = X; y = Y;
	}

	float Lenght(void) const
	{
		return sqrtf(x * x + y * y);
	}

	float LenghtSqr(void) const
	{
		return (x * x + y * y);
	}

	float DistTo(const Vec2 &v) const
	{
		return (*this - v).Lenght();
	}

	float DistToSqr(const Vec2 &v) const
	{
		return (*this - v).LenghtSqr();
	}

	float Dot(const Vec2 &v) const
	{
		return (x * v.x + y * v.y);
	}

	bool IsZero(void) const
	{
		return (x > -0.01f && x < 0.01f &&
			y > -0.01f && y < 0.01f);
	}

public:
	float x, y;
};

class Vec3
{
public:
	Vec3(void)
	{
		x = y = z = 0.0f;
	}

	void Zero()
	{
		x = y = z = 0.f;
	}

	Vec3(float X, float Y, float Z)
	{
		x = X; y = Y; z = Z;
	}

	Vec3(float *v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vec3(const float *v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vec3(const Vec3 &v)
	{
		x = v.x; y = v.y; z = v.z;
	}

	Vec3(const Vec2 &v)
	{
		x = v.x; y = v.y; z = 0.0f;
	}

	Vec3 &operator=(const Vec3 &v)
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}

	Vec3 &operator=(const Vec2 &v)
	{
		x = v.x; y = v.y; z = 0.0f; return *this;
	}

	float &operator[](int i)
	{
		return ((float *)this)[i];
	}

	float operator[](int i) const
	{
		return ((float *)this)[i];
	}

	Vec3 &operator+=(const Vec3 &v)
	{
		x += v.x; y += v.y; z += v.z; return *this;
	}

	Vec3 &operator-=(const Vec3 &v)
	{
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	Vec3 &operator*=(const Vec3 &v)
	{
		x *= v.x; y *= v.y; z *= v.z; return *this;
	}

	Vec3 &operator/=(const Vec3 &v)
	{
		x /= v.x; y /= v.y; z /= v.z; return *this;
	}

	Vec3 &operator+=(float v)
	{
		x += v; y += v; z += v; return *this;
	}

	Vec3 &operator-=(float v)
	{
		x -= v; y -= v; z -= v; return *this;
	}

	Vec3 &operator*=(float v)
	{
		x *= v; y *= v; z *= v; return *this;
	}

	Vec3 &operator/=(float v)
	{
		x /= v; y /= v; z /= v; return *this;
	}

	Vec3 operator+(const Vec3 &v) const
	{
		return Vec3(x + v.x, y + v.y, z + v.z);
	}

	Vec3 operator-(const Vec3 &v) const
	{
		return Vec3(x - v.x, y - v.y, z - v.z);
	}

	Vec3 operator*(const Vec3 &v) const
	{
		return Vec3(x * v.x, y * v.y, z * v.z);
	}

	Vec3 operator/(const Vec3 &v) const
	{
		return Vec3(x / v.x, y / v.y, z / v.z);
	}

	Vec3 operator+(float v) const
	{
		return Vec3(x + v, y + v, z + v);
	}

	Vec3 operator-(float v) const
	{
		return Vec3(x - v, y - v, z - v);
	}

	Vec3 operator*(float v) const
	{
		return Vec3(x * v, y * v, z * v);
	}

	Vec3 operator/(float v) const
	{
		return Vec3(x / v, y / v, z / v);
	}

	void Set(float X = 0.0f, float Y = 0.0f, float Z = 0.0f)
	{
		x = X; y = Y; z = Z;
	}

	float Lenght(void) const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float LenghtSqr(void) const
	{
		return (x * x + y * y + z * z);
	}

	float Normalize()
	{
		float fl_lenght = Lenght();
		float fl_lenght_normal = 1.f / (FLT_EPSILON + fl_lenght);

		x = x * fl_lenght_normal;
		y = y * fl_lenght_normal;
		z = z * fl_lenght_normal;

		return fl_lenght;
	}

	float NormalizeInPlace()
	{
		return Normalize();
	}

	float Lenght2D(void) const
	{
		return sqrtf(x * x + y * y);
	}

	float Lenght2DSqr(void) const
	{
		return (x * x + y * y);
	}

	float DistTo(const Vec3 &v) const
	{
		return (*this - v).Lenght();
	}

	float DistToSqr(const Vec3 &v) const
	{
		return (*this - v).LenghtSqr();
	}

	float Dot(const Vec3 &v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	Vec3 Cross(const Vec3 &v) const
	{
		return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	bool IsZero(void) const
	{
		return (x > -0.01f && x < 0.01f &&
			y > -0.01f && y < 0.01f &&
			z > -0.01f && z < 0.01f);
	}

	void Init(float ix, float iy, float iz)
	{
		x = ix; y = iy; z = iz;
	}

public:
	float x, y, z;
};

class __declspec(align(16))VectorAligned : public Vec3
{
public:
	inline VectorAligned(void) { };

	inline VectorAligned(float x, float y, float z) {
		Set(x, y, z);
	}

	explicit VectorAligned(const Vec3 &othr) {
		Set(othr.x, othr.y, othr.z);
	}

	VectorAligned &operator=(const Vec3 &othr) {
		Set(othr.x, othr.y, othr.z);
		return *this;
	}

	float w;
};

typedef float matrix3x4[3][4];

namespace Math
{
	inline double __declspec (naked) __fastcall FastSqrt(double n)
	{
		_asm fld qword ptr[esp + 4]
		_asm fsqrt
		_asm ret 8
	}

	inline void SinCos(float radians, float *sine, float *cosine)
	{
		_asm
		{
			fld		DWORD PTR[radians]
			fsincos

			mov edx, DWORD PTR[cosine]
			mov eax, DWORD PTR[sine]

			fstp DWORD PTR[edx]
			fstp DWORD PTR[eax]
		}
	}

	inline float NormalizeAngle(float ang)
	{
		if (!std::isfinite(ang))
			return 0.0f;

		return std::remainder(ang, 360.0f);
	}

	inline void ClampAngles(Vec3 &v)
	{
		v.x = std::max(-89.0f, std::min(89.0f, NormalizeAngle(v.x)));
		v.y = NormalizeAngle(v.y);
		v.z = 0.0f;
	}

	inline void VectorTransform(const Vec3 &input, const matrix3x4 &matrix, Vec3 &output)
	{
		for (auto i = 0; i < 3; i++)
			output[i] = input.Dot((Vec3 &)matrix[i]) + matrix[i][3];
	}

	inline void AngleVectors(const Vec3 &angles, Vec3 *forward)
	{
		float sp, sy, cp, cy;

		SinCos(DEG2RAD(angles.x), &sp, &cp);
		SinCos(DEG2RAD(angles.y), &sy, &cy);

		if (forward)
		{
			forward->x = cp * cy;
			forward->y = cp * sy;
			forward->z = -sp;
		}
	}

	inline void AngleNormalize(Vec3 &vector)
	{
		for (auto i = 0; i < 3; i++)
		{
			if (vector[i] < -180.0f) vector[i] += 360.0f;
			if (vector[i] > 180.0f) vector[i] -= 360.0f;
		}
	}

	inline float VectorNormalize(Vec3 &vector)
	{
		float lenght = vector.Lenght();

		if (!lenght)
			vector.Set();
		else
			vector /= lenght;

		return lenght;
	}

	inline Vec3 CalcAngle(const Vec3 &source, const Vec3 &destination)
	{
		Vec3 angles = Vec3(0.0f, 0.0f, 0.0f);
		Vec3 delta = (source - destination);
		float fHyp = FastSqrt((delta.x * delta.x) + (delta.y * delta.y));

		angles.x = (atanf(delta.z / fHyp) * M_RADPI);
		angles.y = (atanf(delta.y / delta.x) * M_RADPI);
		angles.z = 0.0f;

		if (delta.x >= 0.0f)
			angles.y += 180.0f;

		return angles;
	}

	inline float CalcFov(const Vec3 &src, const Vec3 &dst)
	{
		Vec3 v_src = Vec3();
		AngleVectors(src, &v_src);

		Vec3 v_dst = Vec3();
		AngleVectors(dst, &v_dst);

		float result = RAD2DEG(acos(v_dst.Dot(v_src) / v_dst.LenghtSqr()));

		if (!isfinite(result) || isinf(result) || isnan(result))
			result = 0.0f;

		return result;
	}

	inline void CreateVector(const Vec3 &angle, Vec3 &vector)
	{
		float pitch, yaw, tmp;

		pitch = float(angle[0] * PI / 180);
		yaw = float(angle[1] * PI / 180);
		tmp = float(cos(pitch));

		vector[0] = float(-tmp * -cos(yaw));
		vector[1] = float(sin(yaw) * tmp);
		vector[2] = float(-sin(pitch));
	}

	inline void VectorAngles(const Vec3 &forward, Vec3 &angles)
	{
		float tmp, yaw, pitch;

		if (forward.y == 0 && forward.x == 0)
		{
			yaw = 0;

			if (forward.z > 0)
				pitch = 270;
			else
				pitch = 90;
		}

		else
		{
			yaw = RAD2DEG(atan2f(forward.y, forward.x));

			if (yaw < 0)
				yaw += 360;

			tmp = forward.Lenght2D();
			pitch = RAD2DEG(atan2f(-forward.z, tmp));

			if (pitch < 0)
				pitch += 360;
		}

		angles[0] = pitch;
		angles[1] = yaw;
		angles[2] = 0;
	}

	inline float GetFov(const Vec3 &angle, const Vec3 &source, const Vec3 &destination)
	{
		Vec3 ang, aim;
		float mag, u_dot_v;
		ang = CalcAngle(source, destination);

		CreateVector(angle, aim);
		CreateVector(ang, ang);

		mag = sqrtf(pow(aim.x, 2) + pow(aim.y, 2) + pow(aim.z, 2));
		u_dot_v = aim.Dot(ang);

		return RAD2DEG(acos(u_dot_v / (pow(mag, 2))));
	}
}