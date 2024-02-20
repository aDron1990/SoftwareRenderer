
#include <Windows.h>
#include <gdiplus.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <chrono>

#include "Renderer.h"
#include "LinMath.hpp"

bool run = true;
const int32_t WIDTH = 800;
const int32_t HEIGHT = 600;
HWND window;

LRESULT WINAPI WindowProc(HWND window, UINT msg, WPARAM wp, LPARAM lp)
{
	if (msg == WM_CLOSE) run = false;
	else if (msg == WM_KEYDOWN)
	{
		switch (wp)
		{
		case VK_ESCAPE: run = false;
		}
	}
	return DefWindowProc(window, msg, wp, lp);
}

int main()
{
	Matrix4f mat, rot, proj;

	std::vector<Vector3f> vertices =
	{
		{0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{1.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},

		{0.0, 0.0, 1.0},
		{0.0, 1.0, 1.0},
		{1.0, 1.0, 1.0},
		{1.0, 0.0, 1.0},
	};
	std::transform(vertices.begin(), vertices.end(), vertices.begin(), [](Vector3f& vec)
	{
		vec.x -= 0.5;
		vec.y -= 0.5;
		vec.z -= 0.5;
		return vec;
	});
	std::vector<Vector2i> indices =
	{
		{0, 1}, {1, 2}, {2, 3}, {3, 0},
		{4, 5}, {5, 6}, {6, 7}, {7, 4},
		{0, 4}, {1, 5}, {2, 6}, {3, 7},
	};

	scale(proj, { (float) 600 / 800, 1, 1});
	scale(mat, { 0.1, 0.1, 0.1 });
	translate(mat, { 5.0, 0.0, 0.0 });

	WNDCLASSEX wcx = { 0 };
	wcx.cbSize = sizeof(WNDCLASSEX);
	wcx.hInstance = GetModuleHandle(NULL);
	wcx.lpszClassName = L"wndclass";
	wcx.lpfnWndProc = WindowProc;

	RegisterClassEx(&wcx);

	RECT rect = {0, 0, WIDTH, HEIGHT};
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME, NULL);
	window = CreateWindowEx
	(
		NULL, wcx.lpszClassName, L"Software Renderer",
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME,
		CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top,
		NULL, NULL, wcx.hInstance, NULL
	);

	if (window == NULL)
	{
		std::cerr << "Failed to create window" << std::endl;
		return -1;
	}
	ShowWindow(window, SW_SHOWNORMAL);

	{
		Renderer renderer{ window };
		auto last = std::chrono::high_resolution_clock::now();
		while (run)
		{
			auto now = std::chrono::high_resolution_clock::now();
			float dt = (float)std::chrono::duration_cast<std::chrono::microseconds>(last - now).count() / 1000;
			last = now;

			MSG msg = { 0 };
			while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			rotateZ(rot, 0.001 * dt);
			rotateZ(mat, 0.0015 * dt);
			rotateX(mat, 0.001 * dt);
			rotateY(mat, 0.001 * -dt);
			
			renderer.startFrame();

			for (auto&& line : indices)
			{
				auto p1 = renderer.deviceToPixelCoords(proj * rot * mat * Vector4f{ vertices[line.x] });
				auto p2 = renderer.deviceToPixelCoords(proj * rot * mat * Vector4f{ vertices[line.y] });
				renderer.drawLine(p1, p2);
			}

			renderer.endFrame();
		}
	}
	
	DestroyWindow(window);
}
