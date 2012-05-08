#ifndef PoolShader_h
#define PoolShader_h

#include <AbstractShaderProgram.h>
#include <Texture.h>

class PoolShader: public Magnum::AbstractShaderProgram {
    public:
        PoolShader();

        inline void setTransformationMatrixUniform(const Magnum::Matrix4& matrix) {
            setUniform(transformationMatrixUniform, matrix);
        }

        inline void setProjectionMatrixUniform(const Magnum::Matrix4& matrix) {
            setUniform(projectionMatrixUniform, matrix);
        }

        inline void setCameraDirectionUniform(const Magnum::Vector3& position) {
            setUniform(cameraDirectionUniform, position);
        }

        inline void setDiffuseTextureUniform(const Magnum::Texture2D* texture) {
            setUniform(diffuseTextureUniform, texture);
        }

        inline void setLightPositionUniform(const Magnum::Vector3& light) {
            setUniform(lightUniform, light);
        }

    private:
        GLint transformationMatrixUniform,
            projectionMatrixUniform,
            cameraDirectionUniform,
            diffuseTextureUniform,
            lightUniform;
};

#endif