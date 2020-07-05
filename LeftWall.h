
struct Color
{
	float r;
	float g;
	float b;
};

struct Point
{
	float x;
	float y;
	float z = 0.0f;
};

typedef struct Color Color;
typedef struct Point Point;

/**
  shade of difference. Commonly defined.
**/
const float shade = 30.0f / 255.0f;	// add/subtract 50 to each r, g, b value

/**
  Draws LeftWall
**/
void Draw_LeftWall()
{
	// Function prototypes
	void Draw(Color);

	// variable declarations
	Color gold = {1.0f, 0.843f, 0.0f};

	glBegin(GL_QUADS);
	{
		Draw(gold);
	}
	glEnd();
}

void Draw(Color color)
{
	// Function Declarations
	Color Dark_Shade();
	Color Light_Shade();
	void Draw_Vertex_2D(Color, Point);

	// Variable declarations
	Point ceilingLeft;
	Point ceilingRight;
	Point floorLeft;
	Point floorRight;

	// Coordinates
	// Top Left Ceiling coord
	float ceilingLeftX = -1.0;
	float ceilingLeftY = 1.0;

	// Top Right Ceiling coord
	float ceilingRightX = ceilingLeftX + (2.0f * 0.2f);     // 20%
	float ceilingRightY = 0.85f;     // 15%

	// Bottom Left Floor coord
	float floorRightX = ceilingLeftX;
	float floorRightY = -1.0f;

	// Bottom Left Floor coord
	float floorLeftX = ceilingRightX;	// 20%
	float floorLeftY = 1.0 - (2.0f * 0.6f);	// 60%

	Color lightColor = Light_Shade();
	Color darkColor = Dark_Shade();

	//Color debugColor = {1.0f, 0.0f, 0.0f};
	//Color debugColor2 = {1.0f, 0.0f, 1.0f};

	// Top Left Ceiling coord
	ceilingLeft = {ceilingLeftX, ceilingLeftY, 0.0f};
	Draw_Vertex_2D(darkColor, ceilingLeft);

	// Top Right Ceiling coord
	ceilingRight = {ceilingRightX, ceilingRightY, 0.0f};
	Draw_Vertex_2D(lightColor, ceilingRight);
	//Draw_Vertex_2D(debugColor2, ceilingRight);

	// Bottom Left Floor coord
	floorLeft = {floorLeftX, floorLeftY, 0.0f};
	Draw_Vertex_2D(darkColor, floorLeft);

	// Bottom Right Floor coord
	floorRight = {floorRightX, floorRightY, 0.0f};
	Draw_Vertex_2D(lightColor, floorRight);
	//Draw_Vertex_2D(debugColor, floorRight);

	return;
}

/**
  Draws vertex
  Color color : color of the vertex
  Point pos : Actual point coordinates (x, y, z) (for now z = 0 as its 2D)
**/
void Draw_Vertex_2D(const Color color, Point point)
{
	glColor3f(color.r, color.g, color.b);
	glVertex3f(point.x, point.y, point.z);
}

/**
  Gives Darker shade
**/
Color Dark_Shade()
{
	Color c = { 1.0f, 1.0f, 0.8f };
	return c;
}

/**
  Gives Lighter shade
**/
Color Light_Shade()
{
	Color c = { 0.92f, 0.92f, 0.75f };

	return c;
}
