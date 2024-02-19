#include "Renderer.h"

#include <cmath>

Renderer::Renderer(const HWND window) : mem_dc{ NULL }, bitmap{ NULL }, mem_bitmap{ NULL }
{
	dc = GetDC(window);
	RECT rect = { 0 };
	GetClientRect(window, &rect);
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
}

Renderer::~Renderer()
{
	ReleaseDC(NULL, dc);
}

void Renderer::startFrame()
{
	mem_dc = CreateCompatibleDC(NULL);
	mem_bitmap = CreateCompatibleBitmap(dc, width, height);
	bitmap = (HBITMAP)SelectObject(mem_dc, mem_bitmap);
}

void Renderer::endFrame()
{
	BitBlt(dc, 0, 0, width, height, mem_dc, 0, 0, SRCCOPY);
	SelectObject(mem_dc, bitmap);
	DeleteObject(mem_bitmap);
	DeleteDC(mem_dc);
}

void Renderer::setPixel(const int x, const int y)
{
	SetPixel(mem_dc, x, y, RGB(255, 255, 255));
}

void Renderer::drawLine(const Vector2i a, const Vector2i b)
{
	const int dx = abs(b.x - a.x);
	const int dy = abs(b.y - a.y);
	const int d = (dy << 1) - dx;
	const int sx = b.x >= a.x ? 1 : -1;
	const int sy = b.y >= a.y ? 1 : -1;

	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		int x = a.x + sx;
		int y = a.y;
		setPixel(a.x, a.y);
		for (int i = 1; i <= dx; i++, x += sx)
		{
			if (d > 0)
			{
				d += d2;
				y += sy;
			}
			else
			{
				d += d1;
			}
			setPixel(x, y);
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		int x = a.x;
		int y = a.y + sy;
		setPixel(a.x, a.y);
		for (int i = 1; i <= dy; i++, y += sy)
		{
			if (d > 0)
			{
				d += d2;
				x += sx;
			}
			else
			{
				d += d1;
			}
			setPixel(x, y);
		}
	}
}

Vector2i Renderer::deviceToPixelCoords(const Vector2f point)
{
	Vector2i result;
	result.x = (point.x + 1) * width / 2;
	result.y = (-point.y + 1) * height / 2;
	return result;
}