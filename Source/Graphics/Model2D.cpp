//-----------------------------------------------------------
// File: Model2D.cpp
//-----------------------------------------------------------

#include "STD.h"
#include "Model2D.h"

Model2D::Model2D()
{
	line.Initialize(ColorRGBA( 255, 255, 255, 255 ));
}

Model2D::~Model2D()
{
}

void Model2D::Render( Camera& camera, const World& world )
{
	line.Render( &camera, points, world );
}

void Model2D::Render( MyVector2& screenPos, MyVector2& scale, float rot )
{
	// Object already in screen pos so no need for a camera
	line.Render( NULL, points, World( screenPos, scale, rot ) );
}

void Model2D::CalculateModelStats()
{
	MyVector2 centerTotal = MyVector2(0, 0);
	float averageRadius = 0;

	// Calculate the average radius from the center
	int i = 0;
	for( auto begin = points.begin(), end = points.end();
		begin != end; ++begin )
	{
		averageRadius += distanceBetween( MyVector2(0,0), *begin );
		i++;
	}
	averageRadius /= i;

	modelRadius = averageRadius;
}