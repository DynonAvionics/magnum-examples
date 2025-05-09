#ifndef Magnum_Examples_Shadows_ShadowCasterDrawable_h
#define Magnum_Examples_Shadows_ShadowCasterDrawable_h
/*
    This file is part of Magnum.

    Original authors — credit is appreciated but not required:

        2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019,
        2020, 2021, 2022, 2023, 2024, 2025
             — Vladimír Vondruš <mosra@centrum.cz>
        2016 — Bill Robinson <airbaggins@gmail.com>

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or distribute
    this software, either in source code form or as a compiled binary, for any
    purpose, commercial or non-commercial, and by any means.

    In jurisdictions that recognize copyright laws, the author or authors of
    this software dedicate any and all copyright interest in the software to
    the public domain. We make this dedication for the benefit of the public
    at large and to the detriment of our heirs and successors. We intend this
    dedication to be an overt act of relinquishment in perpetuity of all
    present and future rights to this software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <Magnum/GL/Mesh.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/Object.h>

namespace Magnum { namespace Examples {

class ShadowCasterShader;

class ShadowCasterDrawable: public SceneGraph::Drawable3D {
    public:
        explicit ShadowCasterDrawable(SceneGraph::AbstractObject3D& parent, SceneGraph::DrawableGroup3D* drawables);

        /** @brief Mesh to use for this drawable and its bounding sphere radius */
        void setMesh(GL::Mesh& mesh, Float radius) {
            _mesh = &mesh;
            _radius = radius;
        }

        void setShader(ShadowCasterShader& shader) {
            _shader = &shader;
        }

        Float radius() const { return _radius; }

        void draw(const Matrix4& transformationMatrix, SceneGraph::Camera3D& shadowCamera) override;

    private:
        GL::Mesh* _mesh{};
        ShadowCasterShader* _shader{};
        Float _radius;
};

}}

#endif
