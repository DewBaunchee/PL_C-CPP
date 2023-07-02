#include <windows.h>
#include <stdio.h>

int main()
{
    float x, y;
    int scale = 10;
    HDC hDC = GetDC( GetConsoleWindow( ) );
    HPEN Pen = CreatePen( PS_SOLID, 2, RGB(255, 255, 255));
    SelectObject( hDC, Pen );

    TextOutA(hDC, 130, 10, "y(x) = 1/(x^2 + 2x + 1)", 23);

    int centerX = 100, centerY = 85;
    int axisLen = 85;
    MoveToEx( hDC, centerX - axisLen, centerY, NULL );
    LineTo( hDC, centerX + axisLen, centerY );
    MoveToEx( hDC, centerX, centerY - axisLen, NULL );
    LineTo( hDC, centerX, centerY + axisLen );

    for ( x = -4.0f; x <= 4.0f; x += 0.001f )
    {
        y = 1 / (x * x + 2 * x + 1);
        SetPixel(hDC, scale * x + centerX, -scale * y + centerY, RGB(255, 255, 255));
    }

    TextOutA(hDC, 130, 160, "y(x) = 3x^2", 11);

    centerY = 285;
    MoveToEx( hDC, centerX - axisLen, centerY, NULL );
    LineTo( hDC, centerX + axisLen, centerY );
    MoveToEx( hDC, centerX, centerY - axisLen, NULL );
    LineTo( hDC, centerX, centerY + axisLen );

    for ( x = -2.0f; x <= 2.0f; x += 0.001f )
    {
        y = 3 * x * x;
        SetPixel(hDC, scale * x + centerX, -scale * y + centerY, RGB(255, 255, 255));
    }
    getchar();
}