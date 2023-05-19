#pragma once
#include <glm/glm.hpp>

class Graphics
{
public:
	Graphics();
	~Graphics();

	void CreateWindow(const char* title, int x, int y);
	void Clear();
	void Present();
	inline void SetColor(const glm::vec4& color);

	void DrawPoint(const glm::ivec2& point, const glm::vec4& color);
	void DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color);
	void DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color);
	void DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color);

	static glm::ivec4 ConvertColor(const glm::vec4& color);

private:
	struct SDL_Window* m_window{ nullptr };
	struct SDL_Renderer* m_renderer = nullptr;
};