#pragma once

#include <Windows.h>
#include <gdiplus.h>

#include "LinMath.hpp"

class Renderer
{
private:

	HDC dc, mem_dc;
	HBITMAP bitmap, mem_bitmap;
	int width, height;

public:

	Renderer(const HWND window);
	~Renderer();

	void startFrame();
	void endFrame();

	void setPixel(const int x, const int y);
	void drawLine(const Vector2i a, const Vector2i b);

	Vector2i deviceToPixelCoords(const Vector2f point);

};

