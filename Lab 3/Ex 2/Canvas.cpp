#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) {
	Canvas::width = width, Canvas::height = height;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			matrix[i][j] = ' ';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++) {
			double distance = std::sqrt((i - y) * (i - y) + (j - x) * (j - x));
			if (std::abs(distance - ray) < 0.5)
				matrix[i][j] = ch;
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++) {
			double distance = std::sqrt((i - y) * (i - y) + (j - x) * (j - x));
			if (distance <= ray)
				matrix[i][j] = ch;
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = left; i <= right; i++)
		matrix[top][i] = ch;
	for (int i = left; i <= right; i++)
		matrix[bottom][i] = ch;
	for (int i = top; i <= bottom; i++)
		matrix[i][left] = ch;
	for (int i = top; i <= bottom; i++)
		matrix[i][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			Canvas::matrix[j][i] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) {
	matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = std::abs(x2 - x1);
	int dy = std::abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	while (x1 != x2 || y1 != y2) {
		matrix[y1][x1] = ch;
		int err2 = 2 * err;
		if (err2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
	matrix[y2][x2] = ch;
}

void Canvas::Print() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << '\n';
	}
}

void Canvas::Clear() {
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			matrix[i][j] = ' ';
}