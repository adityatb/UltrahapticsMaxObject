
#pragma once

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

#include "UltrahapticsVector3.hpp"

namespace Ultrahaptics
{
   /** \brief A 4x4 transformation matrix.
    */
   struct Matrix4x4
   {
     /** Create a zero matrix
      *
      * @return A zero matrix */
     static Matrix4x4 zero()
     {
       return Matrix4x4();
     }
   
     /** Create an identity matrix
      *
      * @return An identity matrix */
     static Matrix4x4 identity()
     {
       Matrix4x4 m;
     
       m.element[ 0] = 1.0;
       m.element[ 1] = 0.0;
       m.element[ 2] = 0.0;
       m.element[ 3] = 0.0;

       m.element[ 4] = 0.0;
       m.element[ 5] = 1.0;
       m.element[ 6] = 0.0;
       m.element[ 7] = 0.0;

       m.element[ 8] = 0.0;
       m.element[ 9] = 0.0;
       m.element[10] = 1.0;
       m.element[11] = 0.0;

       m.element[12] = 0.0;
       m.element[13] = 0.0;
       m.element[14] = 0.0;
       m.element[15] = 1.0;
       
       return m;
     }
     
     /** Create a new translation matrix
      *
      * @param tx Units to translate in x-axis direction
      *
      * @param ty Units to translate in y-axis direction
      *
      * @param tz Units to translate in z-axis direction
      *
      * @return New matrix for translation */
     static Matrix4x4 translation(double tx, double ty, double tz)
     {
       Matrix4x4 m;

       m.element[ 0] = 1.0;
       m.element[ 1] = 0.0;
       m.element[ 2] = 0.0;
       m.element[ 3] = tx;
       
       m.element[ 4] = 0.0;
       m.element[ 5] = 1.0;
       m.element[ 6] = 0.0;
       m.element[ 7] = ty;

       m.element[ 8] = 0.0;
       m.element[ 9] = 0.0;
       m.element[10] = 1.0;
       m.element[11] = tz;

       m.element[12] = 0.0;
       m.element[13] = 0.0;
       m.element[14] = 0.0;
       m.element[15] = 1.0;
       
       return m;
     }
     
     /** Create a new scaling matrix
      *
      * @param sx Scaling factor to apply in the x-axis direction
      *
      * @param sy Scaling factor to apply in the y-axis direction
      *
      * @param sz Scaling factor to apply in the z-axis direction
      *
      * @return New matrix for scaling */
     static Matrix4x4 scale(double sx, double sy, double sz)
     {
       Matrix4x4 m;

       m.element[ 0] = sx;
       m.element[ 1] = 0.0;
       m.element[ 2] = 0.0;
       m.element[ 3] = 0.0;

       m.element[ 4] = 0.0;
       m.element[ 5] = sy;
       m.element[ 6] = 0.0;
       m.element[ 7] = 0.0;

       m.element[ 8] = 0.0;
       m.element[ 9] = 0.0;
       m.element[10] = sz;
       m.element[11] = 0.0;

       m.element[12] = 0.0;
       m.element[13] = 0.0;
       m.element[14] = 0.0;
       m.element[15] = 1.0;
       
       return m;
     }
     
     /** Create a new rotation matrix
      *
      * @param n Unit vector describing the axis to rotate around
      *
      * @param theta Angle through which to rotate around the axis
      *
      * @return New matrix for rotation */
     static Matrix4x4 rotate(Vector3 n, double theta)
     {
       double c_theta = cos(theta);
       
       // Return the identity matrix
       if (c_theta >= 1.)
         return identity();

       double s_theta = sin(theta);
       double one_m_c = 1. - c_theta;
     
       Matrix4x4 m;
       
       m.element[ 0] = n.x * n.x * one_m_c + c_theta;
       m.element[ 1] = n.x * n.y * one_m_c - n.z * s_theta;
       m.element[ 2] = n.x * n.z * one_m_c + n.y * s_theta;
       m.element[ 3] = 0.0;

       m.element[ 4] = n.y * n.x * one_m_c + n.z * s_theta;
       m.element[ 5] = n.y * n.y * one_m_c + c_theta;
       m.element[ 6] = n.y * n.z * one_m_c - n.x * s_theta;
       m.element[ 7] = 0.0;

       m.element[ 8] = n.z * n.x * one_m_c - n.y * s_theta;
       m.element[ 9] = n.z * n.y * one_m_c + n.x * s_theta;
       m.element[10] = n.z * n.z * one_m_c + c_theta;
       m.element[11] = 0.0;

       m.element[12] = 0.0;
       m.element[13] = 0.0;
       m.element[14] = 0.0;
       m.element[15] = 1.0;
       
       return m;
     }
     
     /** Create a rotation matrix that rotates one vector onto another
      *
      * @param p Unit direction vector to rotate from
      *
      * @param q Unit direction vector to rotate onto
      *
      * @return Rotation matrix that rotates p onto q */
     static Matrix4x4 rotateOntoVector(Vector3 p, Vector3 q)
     {
       Vector3 cross_pq = p.cross(q);
       double dot_pq = p.dot(q);
       
       if (dot_pq <= -1.)
         return rotate(Vector3(1.0f, 0.0f, 0.0f), M_PI);
       
       double rcp_1p_dot_pq = 1. / (1. + dot_pq);
       
       Matrix4x4 m;
       
       m.element[ 0] = cross_pq.x * cross_pq.x * rcp_1p_dot_pq + dot_pq;
       m.element[ 1] = cross_pq.x * cross_pq.y * rcp_1p_dot_pq - cross_pq.z;
       m.element[ 2] = cross_pq.x * cross_pq.z * rcp_1p_dot_pq + cross_pq.y;
       m.element[ 3] = 0.0;

       m.element[ 4] = cross_pq.y * cross_pq.x * rcp_1p_dot_pq + cross_pq.z;
       m.element[ 5] = cross_pq.y * cross_pq.y * rcp_1p_dot_pq + dot_pq;
       m.element[ 6] = cross_pq.y * cross_pq.z * rcp_1p_dot_pq - cross_pq.x;
       m.element[ 7] = 0.0;

       m.element[ 8] = cross_pq.z * cross_pq.x * rcp_1p_dot_pq - cross_pq.y;
       m.element[ 9] = cross_pq.z * cross_pq.y * rcp_1p_dot_pq + cross_pq.x;
       m.element[10] = cross_pq.z * cross_pq.z * rcp_1p_dot_pq + dot_pq;
       m.element[11] = 0.0;

       m.element[12] = 0.0;
       m.element[13] = 0.0;
       m.element[14] = 0.0;
       m.element[15] = 1.0;
       
       return m;
     }
     
     /** Default constructor */
     Matrix4x4() : element{}
     {
     }
     
     /** No-sign-change operator
      *
      * @return A new copy of the matrix without changing the sign of the matrix */
     Matrix4x4 operator+() const
     {
       return *this;
     }
     
     /** Addition operator
      *
      * @param rhs The right hand side of the addition operation
      *
      * @return The addition of the two operands */
     Matrix4x4 operator+(const Matrix4x4 &rhs) const
     {
       Matrix4x4 m;

       m.element[ 0] = element[ 0] + rhs.element[ 0];
       m.element[ 1] = element[ 1] + rhs.element[ 1];
       m.element[ 2] = element[ 2] + rhs.element[ 2];
       m.element[ 3] = element[ 3] + rhs.element[ 3];

       m.element[ 4] = element[ 4] + rhs.element[ 4];
       m.element[ 5] = element[ 5] + rhs.element[ 5];
       m.element[ 6] = element[ 6] + rhs.element[ 6];
       m.element[ 7] = element[ 7] + rhs.element[ 7];

       m.element[ 8] = element[ 8] + rhs.element[ 8];
       m.element[ 9] = element[ 9] + rhs.element[ 9];
       m.element[10] = element[10] + rhs.element[10];
       m.element[11] = element[11] + rhs.element[11];
       
       m.element[12] = element[12] + rhs.element[12];
       m.element[13] = element[13] + rhs.element[13];
       m.element[14] = element[14] + rhs.element[14];
       m.element[15] = element[15] + rhs.element[15];
       
       return m;
     }
     
     /** Summation operator
      *
      * @param rhs The right hand side to add to the existing matrix
      *
      * @return The summation of this with the right hand side */
     Matrix4x4 &operator+=(const Matrix4x4 &rhs)
     {
       element[ 0] += rhs.element[ 0];
       element[ 1] += rhs.element[ 1];
       element[ 2] += rhs.element[ 2];
       element[ 3] += rhs.element[ 3];

       element[ 4] += rhs.element[ 4];
       element[ 5] += rhs.element[ 5];
       element[ 6] += rhs.element[ 6];
       element[ 7] += rhs.element[ 7];

       element[ 8] += rhs.element[ 8];
       element[ 9] += rhs.element[ 9];
       element[10] += rhs.element[10];
       element[11] += rhs.element[11];

       element[12] += rhs.element[12];
       element[13] += rhs.element[13];
       element[14] += rhs.element[14];
       element[15] += rhs.element[15];
       
       return *this;
     }
     
     /** Sign change operator, negate
      *
      * @return A new negated copy of the matrix */
     Matrix4x4 operator-() const
     {
       Matrix4x4 m;
       
       m.element[ 0] = -element[ 0];
       m.element[ 1] = -element[ 1];
       m.element[ 2] = -element[ 2];
       m.element[ 3] = -element[ 3];
       
       m.element[ 4] = -element[ 4];
       m.element[ 5] = -element[ 5];
       m.element[ 6] = -element[ 6];
       m.element[ 7] = -element[ 7];
       
       m.element[ 8] = -element[ 8];
       m.element[ 9] = -element[ 9];
       m.element[10] = -element[10];
       m.element[11] = -element[11];
       
       m.element[12] = -element[12];
       m.element[13] = -element[13];
       m.element[14] = -element[14];
       m.element[15] = -element[15];
       
       return m;
     }
     
     /** Subtraction operator
      *
      * @param rhs The right hand side of the subtraction operation
      *
      * @return The subtraction of the right hand side */
     Matrix4x4 operator-(const Matrix4x4 &rhs) const
     {
       Matrix4x4 m;

       m.element[ 0] = element[ 0] - rhs.element[ 0];
       m.element[ 1] = element[ 1] - rhs.element[ 1];
       m.element[ 2] = element[ 2] - rhs.element[ 2];
       m.element[ 3] = element[ 3] - rhs.element[ 3];

       m.element[ 4] = element[ 4] - rhs.element[ 4];
       m.element[ 5] = element[ 5] - rhs.element[ 5];
       m.element[ 6] = element[ 6] - rhs.element[ 6];
       m.element[ 7] = element[ 7] - rhs.element[ 7];

       m.element[ 8] = element[ 8] - rhs.element[ 8];
       m.element[ 9] = element[ 9] - rhs.element[ 9];
       m.element[10] = element[10] - rhs.element[10];
       m.element[11] = element[11] - rhs.element[11];
       
       m.element[12] = element[12] - rhs.element[12];
       m.element[13] = element[13] - rhs.element[13];
       m.element[14] = element[14] - rhs.element[14];
       m.element[15] = element[15] - rhs.element[15];
       
       return m;
     }

     /** Subtract-accumulate operator
      *
      * @param rhs The right hand side to subtract from the existing matrix
      *
      * @return The subtraction with accumulation of this with the right hand side */
     Matrix4x4 &operator-=(const Matrix4x4 &rhs)
     {
       element[ 0] -= rhs.element[ 0];
       element[ 1] -= rhs.element[ 1];
       element[ 2] -= rhs.element[ 2];
       element[ 3] -= rhs.element[ 3];

       element[ 4] -= rhs.element[ 4];
       element[ 5] -= rhs.element[ 5];
       element[ 6] -= rhs.element[ 6];
       element[ 7] -= rhs.element[ 7];

       element[ 8] -= rhs.element[ 8];
       element[ 9] -= rhs.element[ 9];
       element[10] -= rhs.element[10];
       element[11] -= rhs.element[11];

       element[12] -= rhs.element[12];
       element[13] -= rhs.element[13];
       element[14] -= rhs.element[14];
       element[15] -= rhs.element[15];
       
       return *this;
     }
     
     /** Multiplication operator
      *
      * @param rhs The right hand side to multiply with the matrix
      *
      * @return The multiplication of the matrices */
     Matrix4x4 operator*(const Matrix4x4 &rhs) const
     {
       Matrix4x4 m;
     
       for (int j = 0; j < 4; j++)
         for (int i = 0; i < 4; i++)
           m.element[j*4 + i] =
             element[j*4 + 0] * rhs.element[0*4 + i] +
             element[j*4 + 1] * rhs.element[1*4 + i] +
             element[j*4 + 2] * rhs.element[2*4 + i] +
             element[j*4 + 3] * rhs.element[3*4 + i];

       return m;
     }
     
     /** Product-accumulate operator
      *
      * @param rhs The right hand side to multiply and accumulate with the matrix
      *
      * @return The product of the matrices */
     Matrix4x4 &operator*=(const Matrix4x4 &rhs)
     {
       Matrix4x4 m((*this) * rhs);

       element[ 0] = m.element[ 0];
       element[ 1] = m.element[ 1];
       element[ 2] = m.element[ 2];
       element[ 3] = m.element[ 3];

       element[ 4] = m.element[ 4];
       element[ 5] = m.element[ 5];
       element[ 6] = m.element[ 6];
       element[ 7] = m.element[ 7];

       element[ 8] = m.element[ 8];
       element[ 9] = m.element[ 9];
       element[10] = m.element[10];
       element[11] = m.element[11];

       element[12] = m.element[12];
       element[13] = m.element[13];
       element[14] = m.element[14];
       element[15] = m.element[15];
       
       return *this;
     }
     
     /** Right vector product as a position.
      *
      * @param v Position vector to transform
      *
      * @return Transformed resulting position vector */
     Vector3 transformPosition(const Vector3 &v) const
     {
       Vector3 v_out(
         v.x * element[ 0] + v.y * element[ 1] + v.z * element[ 2] + element[ 3],
         v.x * element[ 4] + v.y * element[ 5] + v.z * element[ 6] + element[ 7],
         v.x * element[ 8] + v.y * element[ 9] + v.z * element[10] + element[11]);
       
       return v_out;
     }
     
     /** Rotate a vector.
      * 
      * This assumes this matrix is a valid rotation matrix, e.g. one created by Matrix4x4::rotate().
      *
      * @param v The vector to rotate.
      *
      * @return Transformed resulting direction vector */
     Vector3 transformDirection(const Vector3 &v) const
     {
       // For rotation matrices only the 3x3 subset is significant. See rotate().
       Vector3 v_out(
         v.x * element[ 0] + v.y * element[ 1] + v.z * element[ 2],
         v.x * element[ 4] + v.y * element[ 5] + v.z * element[ 6],
         v.x * element[ 8] + v.y * element[ 9] + v.z * element[10]);
       
       return v_out;
     }
     
     /** Scale-accumulate operator
      *
      * @param scale The scaling factor to apply
      *
      * @return The existing matrix after scaling */
     Matrix4x4 &operator*=(double scale)
     {
       element[ 0] *= scale;
       element[ 1] *= scale;
       element[ 2] *= scale;
       element[ 3] *= scale;
       
       element[ 4] *= scale;
       element[ 5] *= scale;
       element[ 6] *= scale;
       element[ 7] *= scale;
       
       element[ 8] *= scale;
       element[ 9] *= scale;
       element[10] *= scale;
       element[11] *= scale;
       
       element[12] *= scale;
       element[13] *= scale;
       element[14] *= scale;
       element[15] *= scale;
       
       return *this;
     }
     
     /** Elements of the matrix, stored in row major format.
      * These can be freely specified as this is a struct. */
     double element[16];
   };
}

