#include "rasterization.h"

namespace egc {


	struct bounding_box {
		int minX, minY, maxX, maxY;
	};

	float fbc(const std::vector<egc::vec4>& triangleVertices, vec2 point) {
		return (triangleVertices[1].y - triangleVertices[2].y) * point.x + (triangleVertices[2].x - triangleVertices[1].x) * point.y + triangleVertices[1].x * triangleVertices[2].y - triangleVertices[2].x * triangleVertices[1].y;
	}

	float fab(const std::vector<egc::vec4>& triangleVertices, vec2 point) {
		return (triangleVertices[0].y - triangleVertices[1].y) * point.x + (triangleVertices[1].x - triangleVertices[0].x) * point.y + triangleVertices[0].x * triangleVertices[1].y - triangleVertices[1].x * triangleVertices[0].y;
	}

	float fca(const std::vector<egc::vec4>& triangleVertices, vec2 point) {
		return (triangleVertices[2].y - triangleVertices[0].y) * point.x + (triangleVertices[0].x - triangleVertices[2].x) * point.y + triangleVertices[2].x * triangleVertices[0].y - triangleVertices[0].x * triangleVertices[2].y;
	}


	void computeAlphaBetaGamma(const std::vector<egc::vec4>& triangleVertices, vec2 pixel, float& alpha, float& beta, float& gamma)
	{
		//TO DO - Compute alfa, beta and gamma => we use the function's input parameters as the return mechanism
		//Store the final results in the input parameters
		alpha = fbc(triangleVertices, pixel) / fbc(triangleVertices, vec2((float)triangleVertices[0].x, (float)triangleVertices[0].y));
		beta = fca(triangleVertices, pixel) / fca(triangleVertices, vec2((float)triangleVertices[1].x, (float)triangleVertices[1].y));
		gamma = fab(triangleVertices, pixel) / fab(triangleVertices, vec2((float)triangleVertices[2].x, (float)triangleVertices[2].y));
	}

	void rasterizeTriangle(SDL_Renderer* renderer, const std::vector<egc::vec4>& triangleVertices, const std::vector<egc::vec4>& triangleColors) {
		//TODO - Implement the triangle rasterization algorithm with the Z-Buffer algorithm
		//depthBuffer is declared as an external global variable in main.cpp and thus can be accessed here as depthBuffer[i][j]

		bounding_box boundingBox = bounding_box();
		boundingBox.minX = triangleVertices[0].x;
		boundingBox.minY = triangleVertices[0].y;
		boundingBox.maxX = triangleVertices[0].x;
		boundingBox.maxY = triangleVertices[0].y;

		for (int i = 1; i < 3; i++) {
			if (triangleVertices[i].x < boundingBox.minX) {
				boundingBox.minX = triangleVertices[i].x;
			}
			else if (triangleVertices[i].x > boundingBox.maxX) {
				boundingBox.maxX = triangleVertices[i].x;
			}

			if (triangleVertices[i].y < boundingBox.minY) {
				boundingBox.minY = triangleVertices[i].y;
			}
			else if (triangleVertices[i].y > boundingBox.maxY) {
				boundingBox.maxY = triangleVertices[i].y;
			}
		}

		for (int i = boundingBox.minX; i <= boundingBox.maxX; i++) {
			for (int j = boundingBox.minY; j <= boundingBox.maxY; j++) {
				vec2 pixel = vec2((float)i, (float)j);

				float alpha, beta, gamma;
				computeAlphaBetaGamma(triangleVertices, pixel, alpha, beta, gamma);

				if (alpha > 0.0f && alpha < 1.0f && beta > 0.0f && beta < 1.0f && gamma > 0.0f && gamma < 1.0f) {
					float z = triangleVertices[0].z * alpha + triangleVertices[1].z * beta + triangleVertices[2].z * gamma;

					if (z > depthBuffer[i][j]) {
						depthBuffer[i][j] = z;
						vec4 finalColor = triangleColors[0] * alpha + triangleColors[1] * beta + triangleColors[2] * gamma;
						SDL_SetRenderDrawColor(renderer, finalColor.x, finalColor.y, finalColor.z, finalColor.w);
						SDL_RenderDrawPoint(renderer, pixel.x, pixel.y);
					}
				}
			}
		}
	}

	void clearDepthBuffer() {
		//TODO - Implement clearing the depth buffer
		//depthBuffer is declared as an external global variable in main.cpp and thus can be accessed here as depthBuffer[i][j]
		int width = WINDOW_WIDTH;
		int height = WINDOW_HEIGHT;
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				depthBuffer[i][j] = -1.0f;
			}
		}
	}

}