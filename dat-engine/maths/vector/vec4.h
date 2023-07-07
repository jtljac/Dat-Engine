//
// Created by jacob on 04/07/23.
//

#pragma once

#include "vec-forward.h"

#include <compare>

#include <maths/numbers.h>
#include <maths/common-maths.h>

// TODO: Create unit tests for each function
namespace DatMaths {
    template<typename componentType>
    /**
     * A struct representing a 4 component vector
     * @tparam componentType The type of the components of the vector
     */
    struct Vector<4, componentType> {
        typedef Vector<4, componentType> vecType;

        /** The components of the vector */
        componentType x, y, z, w;

        /* -------------------------------------------- */
        /*  Initialisation                              */
        /* -------------------------------------------- */

        /**
         * Initialises all components to 0
         */
        Vector() : x(0), y(0), z(0), w(0) {}

        /**
         * Initialises all components to the same value
         * @param scalar The value to initialise the components to
         */
        explicit Vector(componentType scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}

        /**
         * Initialises each component to their given value
         * @param x The value to initialise the x component to
         * @param y The value to initialise the y component to
         * @param z The value to initialise the z component to
         * @param w The value to initialise the w component to
         */
        Vector(componentType x, componentType y, componentType z, componentType w) : x(x), y(y), z(z), w(w)  {}

        /* -------------------------------------------- */

        // Copy
        // Vec2
        /**
         * Initialise using just a Vec2, the Z and W components will be initialised to 0
         * @tparam otherType The type of the Vec2
         * @param otherVec The Vec2 to source the values of the X and Y components from
         */
        template<typename otherType>
        Vector(const Vector<2, otherType>& otherVec) : x(static_cast<componentType>(otherVec.x)),
                                                                                         y(static_cast<componentType>(otherVec.y)),
                                                                                         z(0),
                                                                                         w(0) {}

        /**
         * Initialise using a Vec2, a Z component and a W component
         * @tparam otherType The type of the Vec2
         * @param otherVec The Vec2 to source the values of the X and Y components from
         * @param z The value of the Z component
         * @param w The value of the W component
         */
        template<typename otherType>
        Vector(const Vector<2, otherType>& otherVec, componentType z, componentType w) : x(static_cast<componentType>(otherVec.x)),
                                                                                         y(static_cast<componentType>(otherVec.y)),
                                                                                         z(z),
                                                                                         w(w) {}

        /**
         * Initialise using 2 Vec2
         * @tparam otherType The type of the Vec2
         * @param otherVec The Vec2 to source the values of the X and Y components from
         * @param otherVec2 The Vec2 to source the values of the Z and W components from
         */
        template<typename otherType>
        Vector(const Vector<2, otherType>& otherVec, const Vector<2, otherType>& otherVec2)
              : x(static_cast<componentType>(otherVec.x)),
                y(static_cast<componentType>(otherVec.y)),
                z(static_cast<componentType>(otherVec2.x)),
                w(static_cast<componentType>(otherVec2.y)) {}

        // Vec3
        /**
         * Initialise using just a Vec3, The W component will be initialised to 0
         * @tparam otherType The type of the Vec3
         * @param otherVec The Vec3 to source the values of the X, Y, and Z components from
         */
        template<typename otherType>
        explicit Vector(const Vector<3, otherType>& otherVec) : x(static_cast<componentType>(otherVec.x)),
                                                                y(static_cast<componentType>(otherVec.y)),
                                                                z(static_cast<componentType>(otherVec.z)),
                                                                w(0) {}
        /**
         * Initialise using the values from a Vec3
         * @tparam otherType The type of the Vec3
         * @param otherVec The Vec3 to source the values of the X, Y, and Z components from
         * @param w The value of the W component
         */
        template<typename otherType>
        Vector(const Vector<3, otherType>& otherVec, componentType w) : x(static_cast<componentType>(otherVec.x)),
                                                                        y(static_cast<componentType>(otherVec.y)),
                                                                        z(static_cast<componentType>(otherVec.z)),
                                                                        w(w) {}

        // Vec4
        /**
         * Initialise using the values from another Vec4
         * @tparam otherType The type of the other Vec4
         * @param otherVec The other Vec4 to source the values of the X, Y, Z and W components from
         */
        template<typename otherType>
        explicit Vector(const Vector<4, otherType>& otherVec) : x(static_cast<componentType>(otherVec.x)),
                                                       y(static_cast<componentType>(otherVec.y)),
                                                       z(static_cast<componentType>(otherVec.z)),
                                                       w(static_cast<componentType>(otherVec.w)) {}

        /* -------------------------------------------- */

        // Assignment operator
        template<typename otherType>
        vecType& operator=(const Vector<4, otherType>& otherVec);

        /* -------------------------------------------- */
        /*  Maths                                       */
        /* -------------------------------------------- */

        // Add Vector
        template<typename otherType>
        vecType operator+(const Vector<4, otherType>& rhs) const;

        // Add Scalar
        template<typename otherType>
        vecType operator+(otherType rhs) const;

        // Add Vector In-Place
        template<typename otherType>
        vecType& operator+=(const Vector<4, otherType>& rhs) const;

        // Add Scalar In-Place
        template<typename otherType>
        vecType& operator+=(otherType rhs) const;

        /* -------------------------------------------- */

        // Minus Vector
        template<typename otherType>
        vecType operator-(const Vector<4, otherType>& rhs) const;

        // Minus Scalar
        template<typename otherType>
        vecType operator-(otherType rhs) const;

        // Minus Vector In-Place
        template<typename otherType>
        vecType& operator-=(const Vector<4, otherType>& rhs) const;

        // Minus Scalar In-Place
        template<typename otherType>
        vecType& operator-=(otherType rhs) const;

        /* -------------------------------------------- */

        //   Negation
        vecType operator-();

        /* -------------------------------------------- */

        // Multiply by Components
        template<typename otherType>
        vecType operator*(const Vector<4, otherType>& rhs) const;

        // Multiply by Scalar
        template<typename otherType>
        vecType operator*(otherType rhs) const;

        // Multiply by Components In-Place
        template<typename otherType>
        vecType& operator*=(const Vector<4, otherType>& rhs) const;

        // Multiply by Scalar In-Place
        template<typename otherType>
        vecType& operator*=(otherType rhs) const;

        /* -------------------------------------------- */

        // Divide by Components
        template<typename otherType>
        vecType operator/(const Vector<4, otherType>& rhs) const;

        // Divide by Scalar
        template<typename otherType>
        vecType operator/(otherType rhs) const;

        // Divide by Components In-Place
        template<typename otherType>
        vecType& operator/=(const Vector<4, otherType>& rhs) const;

        // Divide by Scalar In-Place
        template<typename otherType>
        vecType& operator/=(otherType rhs) const;

        /* -------------------------------------------- */

        /**
         * Get the dot product of this vector and a given vector
         * @tparam otherType The type of the other vector
         * @param otherVec The other vector
         * @return the dot product of this vector and the given vector
         */
        template<typename otherType>
        componentType dotProduct(Vector<4, otherType> otherVec) const;

        /* -------------------------------------------- */

        /**
         * Get the magnitude of the vector
         * @return the magnitude of the vector
         */
        componentType length() const;

        /**
         * Get the magnitude squared of the vector
         * <br>
         * This saves an expensive sqrt operation so is preferable for some comparisons
         * @return The magnitude squared of the vector
         */
        componentType lengthSquared() const;

        /* -------------------------------------------- */

        /**
         * Normalise the vector in place
         */
        void normalise();

        /**
         * Get the normalised copy of this vector
         * @return a normalised copy of this vector
         */
        vecType normalised() const;

        /* -------------------------------------------- */
        /*  Comparison                                  */
        /* -------------------------------------------- */

        // Equals
        template<typename otherType>
        bool operator==(const Vector<4, otherType>& rhs) const;

        /**
         * Check if this vector is equal to another within a small tolerances
         * @tparam otherType The type of the other vector
         * @param rhs The other vector to compare to
         * @param tolerance How close the two vectors needs to be to be regarded as equal
         * @return true if equal within a tolerance
         */
        template<typename otherType>
        bool equal(const Vector<4, otherType>& rhs, componentType tolerance = static_cast<componentType>(numbers::tinyNumber)) const;

        // Not Equal
        template<typename otherType>
        bool operator!=(const Vector<4, otherType>& rhs) const;

        /* -------------------------------------------- */

        // Less than
        template<typename otherType>
        bool operator<(const Vector<4, otherType>& rhs) const;

        // Greater Than
        template<typename otherType>
        bool operator>(const Vector<4, otherType>& rhs) const;

        // Less than or equal
        template<typename otherType>
        bool operator<=(const Vector<4, otherType>& rhs) const;

        // Greater than or equal
        template<typename otherType>
        bool operator>=(const Vector<4, otherType>& rhs) const;

        /* -------------------------------------------- */

        // UFO Operator
        template<typename otherType>
        std::strong_ordering operator<=>(const Vector<4, otherType>& rhs) const;
    };

#include "source/vec4.inl"
}