#pragma once


#include <gl/GLU.h>
#include <gl/GL.h>
#include <string>

#include "SOIL/SOIL.h"


class SOILHelper {
public:
	//Functions modified and taken from https://www.gamedev.net/forums/topic/514669-soil-issues-images-that-arnt-power-of-2/
	static int RoundPower(int value)
	{
		int powValue = 1;

		while (powValue < value)
			powValue = powValue << 1;
		return powValue;
	}

	static GLuint LoadImage(const std::string& fileName, int &imageWidth, int &imageHeight, int &imageUpperWidth, int &imageUpperHeight)
	{
		int width, height, channels;
		unsigned char *ht_map = SOIL_load_image
		(
			fileName.c_str(),
			&width, &height, &channels,
			SOIL_LOAD_AUTO
		);

		if (ht_map)
		{
			unsigned char* imageData = ht_map;
			int upperWidth = RoundPower(width);
			int upperHeight = RoundPower(height);

			if (upperWidth != width || upperHeight != height)
			{
				unsigned char* newImageData = new unsigned char[upperWidth * upperHeight * channels];

				for (int y = 0; y < height; ++y)
					memcpy(&newImageData[y * upperWidth * channels], &ht_map[y * width * channels], width * channels);

				free(imageData);
				imageData = newImageData;
			}

			GLuint texture = SOIL_create_OGL_texture
			(
				imageData,
				upperWidth, upperHeight, channels,
				SOIL_CREATE_NEW_ID,
				0
			);

			free(imageData);

			imageWidth = width;
			imageHeight = height;
			imageUpperWidth = upperWidth;
			imageUpperHeight = upperHeight;

			return texture;
		}
		return NULL;
	}
};