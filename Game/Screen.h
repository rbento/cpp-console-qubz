// Copyright (c) Rodrigo Bento

#pragma once

class Screen
{
public:

	Screen() : Canvas(Canvas::Instance())
	{
	}

	virtual ~Screen()
	{
	}

	virtual void Initialize() = 0;
	virtual void Cleanup() = 0;

	virtual void Reset() = 0;

	virtual void Input() = 0;
	virtual void Update(ULONGLONG TimeDiff) = 0;
	virtual void Paint() = 0;

	void Clear()
	{
		Canvas.Clear();
	}

	void Merge(Shape* Shape)
	{
		Canvas.Merge(Shape);
	}

	void Flush()
	{
		Canvas.Flush();
	}

private:

	Canvas& Canvas;
};
