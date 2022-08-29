#include <bits/stdc++.h>
#include <fstream>
using namespace std;

double pi {3.141592653};

double surfaceArray[5001][5001];

double intensityMap[601][401];
double realamplitudeMap[601][401];
double imaginaryamplitudeMap[601][401];

class Surface{
public:

    void defineSurface(){
        for (int i{0}; i < 401; i++){
            for (int i2{0}; i2 < 401; i2++){
                realamplitudeMap[i][i2] = 0.0;
                imaginaryamplitudeMap[i][i2] = 0.0;
                intensityMap[i][i2] = 0.0;
            }
        }
        for (int x{0}; x < 5001; x++){
            for (int y{0}; y < 5001; y++){
                surfaceArray[x][y] = (tan(((rand() % 45)) / 180.0 * pi)) * surfaceRoughness;
//                cout << surfaceArray[x][y] << endl;
                }}}

    void SubjectiveSpeckle(){
    for (int x{0}; x < 5000; x++){
        for (int y{0}; y < 5000; y++){
            definezx_normalAngle(x,y);
            definezy_normalAngle(x,y);

//            cout << zx_normalAngle / pi * 180 << " " << zy_normalAngle / pi * 180 << endl;

            definezx_lightFinalAngle(zx_lightInitialAngle, zx_normalAngle);
            definezy_lightFinalAngle(zy_lightInitialAngle, zy_normalAngle);

//            cout << zx_lightFinalAngle / pi * 180 << " " << zy_lightFinalAngle / pi * 180 << endl;

            if ( -( 89.0 / 180.0 * pi) < zx_lightFinalAngle &&  zx_lightFinalAngle < ( 89.0 / 180.0 * pi) && -( 89.0 / 180.0 * pi) < zy_lightFinalAngle && zy_lightFinalAngle < ( 89.0 / 180.0 * pi) ) {

//            cout << zx_lightFinalAngle / pi * 180 << " " << zy_lightFinalAngle / pi * 180 << endl;

            definezx_length((lensFromSurface - surfaceArray[x][y]), zx_lightFinalAngle);
            definezy_length((lensFromSurface - surfaceArray[x][y]), zy_lightFinalAngle);

            definez_length(zx_length, zy_length, (lensFromSurface - surfaceArray[x][y]));

            definex_Coordinate(x, zx_length);
            definey_Coordinate(y, zy_length);

//            cout << z_length << " " << x_Coordinate << " " << y_Coordinate << endl;


            if (pow((x_Coordinate - lensXCoordinate),2) + pow((y_Coordinate - lensYCoordinate),2) <= pow((0.5 * lensHeight),2)){


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            definex_Coordinate4(zx_lightFinalAngle, x_Coordinate);
            definey_Coordinate4(zy_lightFinalAngle, y_Coordinate);

            definelensThickness(x_Coordinate4, lensXCoordinate, y_Coordinate4, lensYCoordinate, lensRadius);

//            cout << x_Coordinate4 << " " << y_Coordinate4 << " " << lensThickness << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            definezx_lensNormalEnterAngle(x_Coordinate4, lensXCoordinate, lensRadius);
            definezy_lensNormalEnterAngle(y_Coordinate4, lensYCoordinate, lensRadius);

            definezx_lensEnterAngle(zx_lightFinalAngle, zx_lensNormalEnterAngle, lensRefractiveIndex, airRefractiveIndex);// a is lens final angle, b is lens normal angle, c lens refractive index, d is air refractive index
            definezy_lensEnterAngle(zy_lightFinalAngle, zy_lensNormalEnterAngle, lensRefractiveIndex, airRefractiveIndex);

//            cout << zx_lensEnterAngle << " " << zy_lensEnterAngle << endl;

//            definezx_lensThickness(lensXCoordinate, x_Coordinate4, lensRadius);
//            definezy_lensThickness(lensYCoordinate, y_Coordinate4, lensRadius);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            definex_Coordinate3(zx_lensEnterAngle, x_Coordinate4, zx_lensNormalEnterAngle);// a is light final angle and b is x coordinate 4, c is light enter normal angle and d is lens thickness
            definey_Coordinate3(zy_lensEnterAngle, y_Coordinate4, zy_lensNormalEnterAngle);

//            cout << x_Coordinate3 << " " << y_Coordinate3 << endl;

            definezx_lensNormalExitAngle(x_Coordinate3, lensXCoordinate, lensRadius);// a is x coordinate3, b is lens x coordinate, c is lens radius
            definezy_lensNormalExitAngle(y_Coordinate3, lensYCoordinate, lensRadius);


            definezx_lensExitAngle(zx_lensEnterAngle, zx_lensNormalEnterAngle, lensRefractiveIndex, airRefractiveIndex);// a is lens enter angle, b is lens normal angle, c lens refractive index, d is air refractive index
            definezy_lensExitAngle(zy_lensEnterAngle, zy_lensNormalEnterAngle, lensRefractiveIndex, airRefractiveIndex);

//            definezx_lensEnterAngleandExitAngle(x_Coordinate, lensRadius, zx_lightFinalAngle, lensRefractiveIndex, airRefractiveIndex);
            definezx_length2(lensFromScreen, zx_lensExitAngle, zx_lensNormalExitAngle);  // x is total distance and y is exit angle and z is normal angle
//
//            definezy_lensEnterAngleandExitAngle(y_Coordinate, lensRadius, zy_lightFinalAngle, lensRefractiveIndex, airRefractiveIndex);
            definezy_length2(lensFromScreen, zy_lensExitAngle, zy_lensNormalExitAngle);
//
            definez_length2(x_Coordinate, x_Coordinate3, y_Coordinate, y_Coordinate3, lensFromScreen);
//
            definex_Coordinate2(x_Coordinate, zx_length2);
            definey_Coordinate2(y_Coordinate, zy_length2);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            defineextraLength(arraySpacing, x, zx_lightInitialAngle, y, zy_lightInitialAngle);
            definelensDistance(x_Coordinate4, x_Coordinate3, y_Coordinate4, y_Coordinate3, lensThickness);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            definerealAmplitude(z_length + z_length2 + extraLength + lensRefractiveIndex * lensThickness);
            defineimaginaryAmplitude(z_length + z_length2 + extraLength + lensRefractiveIndex * lensThickness);
//            cout << x_Coordinate2 << " " << y_Coordinate2 << endl;
//            cout << z_length + z_length2 + extraLength + lensRefractiveIndex * lensThickness << endl;

            if(x_Coordinate2 > -0.1 && x_Coordinate2 < 0.1){
                a = (int)(((x_Coordinate2 + 0.1)*2000));
            } else {
                x_Coordinate2 = -0.1;
                a = (int)(((x_Coordinate2 + 0.1)*2000));
            }

            if(y_Coordinate2 > -0.1 && x_Coordinate2 < 0.1){
                b = (int)(((y_Coordinate2 + 0.1)*2000));
            } else {
                y_Coordinate2 = -0.1;
                b = (int)(((y_Coordinate2 + 0.1)*2000));
            }

//            cout << x_Coordinate2 << " " << y_Coordinate2 << endl;
//            cout << a << " " << b << endl;
//            maximum = max(maximum, y_Coordinate2);
//            minimum = min(minimum, y_Coordinate2);

            realamplitudeMap[a][b] = realamplitude + realamplitudeMap[a][b];
            imaginaryamplitudeMap[a][b] = imaginaryamplitude + imaginaryamplitudeMap[a][b];

//            cout << a << " " << b << " " << realamplitudeMap[a][b] << " " << imaginaryamplitudeMap[a][b] << endl;

//            cout << a << endl;

//            cout << a << " " << b << " " << intensityMap[a][b] << endl;

                }
            }
        }
    }

//    cout << maximum << " " << minimum;

}

    void defineintensityMap(){

        for (int x{0}; x < 601; x++ ){
            for (int y{0}; y < 401; y++){

                intensityMap [x][y] = defineIntensity(realamplitudeMap[x][y], imaginaryamplitudeMap[x][y]);

//                if (intensityMap[x][y] != 0){
//                    intensityMap[x][y] = 1;
//                }
//
//
//                if(intensityMap[x][y] != 0){
//                    intensityMap[x][y] = 1;
//
//                cout << "{" << x << "," << y << "," << intensityMap[x][y] << "}" << ",";
//                }
//            cout << intensityMap [x][y] << endl;
//            cout << endl;
        }
    }



private:
    int a{};
    int b{};

// Surface Variables and Fucout << x_Coordinate2 << " " << y_Coordinate2 << endl;nctions
    double surfaceRoughness {pow(10,-7)};
    double zx_normalAngle{};
    double zy_normalAngle{};
    double zx_length{};
    double zy_length{};
    double zx_lightFinalAngle{};
    double zy_lightFinalAngle{};
    double zx_lightInitialAngle{0}; // angle of illumination wrt to positive z axis in x direction
    double zy_lightInitialAngle{0}; // angle of illumination wrt to positive z axis in y direction
    double extraLength{};
    double z_length{};

    double definezx_normalAngle(int x, int y){
        zx_normalAngle = atan((surfaceArray[x + 1][y] - surfaceArray[x][y])/(arraySpacing));
        return zx_normalAngle;
}

    double definezy_normalAngle(int x, int y){
        zy_normalAngle = atan((surfaceArray[x][y + 1] - surfaceArray[x][y])/(arraySpacing));
        return zy_normalAngle;
}

    double definezx_lightFinalAngle(double x, double y){ // x is initial angle and y is normal angle
        zx_lightFinalAngle = x + 2 * y;
        return zx_lightFinalAngle;
    }

    double definezy_lightFinalAngle(double x, double y){ // x is initial angle and y is normal angle
        zy_lightFinalAngle = x + 2 * y;
        return zy_lightFinalAngle;
    }

    double definezx_length(double x, double y){ // x is total distance and y is final angle
        zx_length = x * tan(y);
        return zx_length;
}

    double definezy_length(double x, double y){ // x is total distance and y is final angle
        zy_length = x * tan(y);
        return zy_length;
}

    double definez_length(double x, double y, double z){// zx length, zy length, total distance
        z_length = pow((x*x + y*y + z*z),0.5);
        return z_length;

}

    double defineextraLength(double a, double b, double c, double d, double e){// arrray spacing, x coordinate, zx lightinitial angle, y cooridnate, zy light initial angle
        extraLength = pow((pow(((a * b) * sin(c)),2) + pow(((a * d) * sin(e)),2)),0.5);
        return extraLength;

    }


// Light variables and Functions
    double wavelength {680.0 * pow(10,-9)};
    double realamplitude{};
    double imaginaryamplitude{};
    double intensity{};


    double definerealAmplitude(double x){ // x is z_length
        realamplitude = cos(x /wavelength*2.0*pi);
        return realamplitude;
    }

    double defineimaginaryAmplitude(double x){ // x is z_length
        imaginaryamplitude = sin(x /wavelength*2.0*pi);
        return imaginaryamplitude;
    }

    double defineIntensity(double x, double y){// x is amplitude
        intensity = pow(pow(x,2) + pow(y,2), 0.5);
        return intensity;

    }

// Lens and GeomOptics variables and Functions
    double lensFromSurface {0.25}; // distance of screen from surface (Zo + Zr)
    double lensFromScreen {0.1};
    double lensFocalLength {7.33 / 100.0};
    double lensHeight {6.11 * pow(10,-2)};
    double limitingAngle{};
    double lensRefractiveIndex {1.655};
    double airRefractiveIndex {1.0003};
    double lensRadius{2 * (lensFocalLength) * (lensRefractiveIndex - 1.0)};

    double zx_lensNormalEnterAngle{};
    double zx_lensNormalExitAngle{};
    double zy_lensNormalEnterAngle{};
    double zy_lensNormalExitAngle{};
    double zx_lensEnterAngle{};
    double zy_lensEnterAngle{};
    double zx_lensExitAngle{};
    double zy_lensExitAngle{};
    double zx_lensThickness{};
    double zy_lensThickness{};
    double lensThickness{};
    double x_Coordinate3{};
    double y_Coordinate3{};
    double lensDistance{};

    double zx_length2{};
    double zy_length2{};
    double z_length2{};

    double lensXCoordinate{0.0};
    double lensYCoordinate{0.0};

//    double definelimitingAngle(double x, double y, double z){// x is distance of lens from surface, y is lensHeight, z is array length
//        limitingAngle = atan((y - z) / x);
//        return limitingAngle;
//    }
//
//    double definelensRadius (double x, double y){// x is refractive index and y is focal length
//        double lensRadius = y * 2.0 * (x - 1.0);
//        return lensRadius;
//
//    }

    double definezx_lensNormalEnterAngle(double a, double b, double c){// a is x coordinate, b is lens x coordinate, c is lens radius
        zx_lensNormalEnterAngle = atan((a - b)/c);
        return zx_lensNormalEnterAngle;

    }

    double definezy_lensNormalEnterAngle(double a, double b, double c){// a is y coordinate, b is lens y coordinate, c is lens radius
        zy_lensNormalEnterAngle = atan((a - b)/c);
        return zy_lensNormalEnterAngle;

    }

    double definezx_lensEnterAngle(double a, double b, double c, double d){// a is lens final angle, b is lens normal angle, c lens refractive index, d is air refractive index
        zx_lensEnterAngle = asin( d / c * sin(a - b));
        return zx_lensEnterAngle;

    }

    double definezy_lensEnterAngle(double a, double b, double c, double d){// a is lens final angle, b is lens normal angle, c lens refractive index, d is air refractive index
        zy_lensEnterAngle = asin( d / c * sin(a - b));
        return zy_lensEnterAngle;
    }

//    double definezx_lensThickness(double a, double b, double c){// a is lens coordinate, b is coordinate, c is lens radius
//        zx_lensThickness = c - pow((-pow((a - b),2) + pow(c,2)),0.5);
//        return zx_lensThickness;
//
//    }
//
//    double definezy_lensThickness(double a, double b, double c){// a is lens coordinate, b is coordinate, c is lens radius
//        zy_lensThickness = c - pow((-pow((a - b),2) + pow(c,2)),0.5);
//        return zy_lensThickness;
//
//    }

    double definex_Coordinate3(double a, double b, double c){// a is light final angle and b is x coordinate 4, c is light enter normal angle and d is lens thickness

    double c1 {pow(pow(lensRadius, 2) - pow(0.5 * lensHeight,2),0.5)};
    double c2 {1.0/(tan(a - c) + b)};

    double aa = 1.0 + c2*c2;
    double ba = -2.0*c1*c2;
    double ca = c1*c1 - lensRadius*lensRadius;

    pair <double, double> Solution1;
    pair <double, double> Solution2;

    Solution1.first = (-ba + pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;
    Solution2.first = (-ba - pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;

    Solution1.second = c2 * Solution1.first;
    Solution2.second = c2 * Solution2.first;

    if (Solution2.second > Solution1.second){
        x_Coordinate3 = Solution1.first;
    } else {
        x_Coordinate3 = Solution2.first;

    }

    return x_Coordinate3;
}

    double definey_Coordinate3(double a, double b, double c){// a is light final angle and b is x coordinate 4, c is light enter normal angle and d is lens thickness

    double c1 {pow(pow(lensRadius, 2) - pow(0.5 * lensHeight,2),0.5)};
    double c2 {1.0/(tan(a - c) + b)};

    double aa = 1.0 + c2*c2;
    double ba = -2.0*c1*c2;
    double ca = c1*c1 - lensRadius*lensRadius;

    pair <double, double> Solution1;
    pair <double, double> Solution2;

    Solution1.first = (-ba + pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;
    Solution2.first = (-ba - pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;

    Solution1.second = c2 * Solution1.first;
    Solution2.second = c2 * Solution2.first;

    if (Solution2.second > Solution1.second){
        y_Coordinate3 = Solution1.first;
    } else {
        y_Coordinate3 = Solution2.first;

    }

    return y_Coordinate3;

}

//    double definex_Coordinate3(double a, double b, double c, double d){// a is lens thickness, b is lensenternormalangle, c is lensenterangle, d is coordinate1
//        x_Coordinate3 = a * tan (b-c) + d;
//        return x_Coordinate3;
//    }
//
//    double definey_Coordinate3(double a, double b, double c, double d){// a is lens thickness, b is lensenternormalangle, c is lensenterangle, d is coordinate1
//        y_Coordinate3 = a * tan (b-c) + d;
//        return y_Coordinate3;
//    }

//    double definelensDistance (double a, double b, double c, double d, double e, double f){// a is x coordinate 3, b is x coordinate 1, c is y coordinate 3, d is y coordinate 1, e is lens thickness, f is lens refractive index
//        lensDistance = pow((pow((a - b),2) + pow((c - d),2) + pow((e),2)),0.5) * f;
//        return lensDistance;
//    }

    double definezx_lensNormalExitAngle(double a, double b, double c){// a is x coordinate3, b is lens x coordinate, c is lens radius
        zx_lensNormalExitAngle = atan((a - b)/c);
        return zx_lensNormalExitAngle;

    }

    double definezy_lensNormalExitAngle(double a, double b, double c){// a is y coordinate3, b is lens y coordinate, c is lens radius
        zy_lensNormalExitAngle = atan((a - b)/c);
        return zy_lensNormalExitAngle;

    }

    double definezx_lensExitAngle(double a, double b, double c, double d){// a is lens enter angle, b is lens normal angle, c lens refractive index, d is air refractive index
        zx_lensExitAngle = asin( c / d * sin(a - b));
        return zx_lensExitAngle;

    }

    double definezy_lensExitAngle(double a, double b, double c, double d){// a is lens enter angle, b is lens normal angle, c lens refractive index, d is air refractive index
        zy_lensExitAngle = asin( c / d * sin(a - b));
        return zy_lensExitAngle;
    }

    double definelensThickness (double a, double b, double c, double d, double e){// a is x_Coordinate4, lensXCoordinate, y_Coordinate4, lensYCoordinate, lensRadius

    lensThickness = pow((-pow((a-b),2) - pow((c-d),2) + e*e ),0.5) - pow(pow(lensRadius, 2) - pow(0.5 * lensHeight,2),0.5);
    return lensThickness;

    }


//    double definezx_lensEnterAngleandExitAngle(double f, double b, double c, double d, double e){ // a is x coordinate and b is lensradius and c is lightFinalAngle and d is lensRefractiveIndex and e is air refractive index
//        double a = f - (0 * arraySpacing);
//        zx_lensEnterAngle = asin(e / d * sin(c - atan(a/b)));
//        zx_lensExitAngle = asin(d / e * sin(2 * atan(a/b) - zx_lensEnterAngle)) - atan(a/b);
//        return zx_lensExitAngle;
//    }
//
//    double definezy_lensEnterAngleandExitAngle(double f, double b, double c, double d, double e){ // a is y coordinate and b is lensradius and c is lightFinalAngle and d is lensRefractiveIndex and e is air refractive index
//        double a = f - (0 * arraySpacing);
//        zy_lensEnterAngle = asin(e / d * sin(c - atan(a/b)));
//        zy_lensExitAngle = asin(d / e * sin(2 * atan(a/b) - zx_lensEnterAngle)) - atan(a/b);
//        return zy_lensExitAngle;
//    }

    double definezx_length2(double x, double y, double z){ // x is total distance and y is exit angle and z is normal angle
        zx_length2 = x * tan(y+z);
        return zx_length2;
}

    double definezy_length2(double x, double y, double z){ // x is total distance and y is exit angle and z is normal angle
        zy_length2 = x * tan(y+z);
        return zy_length2;
}

    double definez_length2(double a, double b, double c, double d, double e){// a is x coordinate 2, b is x coordinate 3 ...
        z_length2 = pow((pow((a - b),2) + pow((c - d),2) + pow((e),2)),0.5);
        return z_length2;
}


// Coordinate system (Cartesian)
    double x_Coordinate{};
    double y_Coordinate{};
    double arraySpacing {pow(10,-6)};
    double definex_Coordinate(int x, double y){// y is zx_length
        x_Coordinate = x * arraySpacing + y;
        return x_Coordinate;

    }

    double definey_Coordinate(int x, double y){// y is zy_length
        y_Coordinate = x * arraySpacing + y;
        return y_Coordinate;

    }

    double x_Coordinate2{};
    double y_Coordinate2{};

    double definex_Coordinate2(double x, double y){
        x_Coordinate2 = x + y;
        return x_Coordinate2;

    }

    double definey_Coordinate2(double x, double y){
        y_Coordinate2 = x + y;
        return y_Coordinate2;

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double x_Coordinate4{};
double y_Coordinate4{};

//double definex_Coordinate4(double a, double b){// a is light final angle and b is x coordinate
//
//    double c1 {1.0 / tan(a)};
//    double c2 {lensRadius - pow(pow(lensRadius, 2) - pow(0.5 * lensHeight,2),0.5) + b / tan(a)};
//    double c3 {lensRadius};
//
//    pair <double, double> Solution1;
//    pair <double, double> Solution2;
//
//    Solution1.first = 2 * c1 * c2 + pow((pow((2 * c1 * c2 ),2) - 4.0 * (c1 + 1.0) * (c2 * c2 - c3 * c3 )),0.5);
//    Solution2.first = 2 * c1 * c2 - pow((pow((2 * c1 * c2 ),2) - 4.0 * (c1 + 1.0) * (c2 * c2 - c3 * c3 )),0.5);
//
//    Solution1.second = a * Solution1.first - a * b;
//    Solution2.second = a * Solution2.first - a * b;
//
//    if (Solution2.second > Solution1.second){
//        x_Coordinate4 = Solution1.first;
//    } else {
//        x_Coordinate4 = Solution2.first;
//
//    }
//
//    return x_Coordinate4;
//
//}
//
//double definey_Coordinate4(double a, double b){// a is light final angle and b is y coordinate
//
//    double c1 {1.0 / tan(a)};
//    double c2 {lensRadius - pow(pow(lensRadius, 2) - pow(0.5 * lensHeight,2),0.5) + b / tan(a)};
//    double c3 {lensRadius};
//
//    pair <double, double> Solution1;
//    pair <double, double> Solution2;
//
//    Solution1.first = 2 * c1 * c2 + pow((pow((2 * c1 * c2 ),2) - 4.0 * (c1 + 1.0) * (c2 * c2 - c3 * c3 )),0.5);
//    Solution2.first = 2 * c1 * c2 - pow((pow((2 * c1 * c2 ),2) - 4.0 * (c1 + 1.0) * (c2 * c2 - c3 * c3 )),0.5);
//
//    Solution1.second = a * Solution1.first - a * b;
//    Solution2.second = a * Solution2.first - a * b;
//
//    if (Solution2.second > Solution1.second){
//        y_Coordinate4 = Solution1.first;
//    } else {
//        y_Coordinate4 = Solution2.first;
//
//    }
//
//    return y_Coordinate4;
//
//}


double definex_Coordinate4(double a, double b){// a is light final angle and b is x coordinate

    double c1 {pow(pow(lensRadius, 2) - pow(0.5 * lensHeight,2),0.5)};
    double c2 {1.0/(tan(a) + b)};

    double aa = 1.0 + c2*c2;
    double ba = -2.0*c1*c2;
    double ca = c1*c1 - lensRadius*lensRadius;

    pair <double, double> Solution1;
    pair <double, double> Solution2;

    Solution1.first = (-ba + pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;
    Solution2.first = (-ba - pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;

    Solution1.second = c2 * Solution1.first;
    Solution2.second = c2 * Solution2.first;

    if (Solution2.second > Solution1.second){
        x_Coordinate4 = Solution1.first;
    } else {
        x_Coordinate4 = Solution2.first;

    }

    return x_Coordinate4;

}

double definey_Coordinate4(double a, double b){// a is light final angle and b is y coordinate

    double c1 {pow(pow(lensRadius, 2) - pow(0.5 * lensHeight,2),0.5)};
    double c2 {1.0/(tan(a) + b)};

    double aa = 1.0 + c2*c2;
    double ba = -2.0*c1*c2;
    double ca = c1*c1 - lensRadius*lensRadius;

    pair <double, double> Solution1;
    pair <double, double> Solution2;

    Solution1.first = (-ba + pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;
    Solution2.first = (-ba - pow(ba*ba - 4.0 * aa * ca,0.5)) / 2 / aa;

    Solution1.second = c2 * Solution1.first;
    Solution2.second = c2 * Solution2.first;

    if (Solution2.second > Solution1.second){
        y_Coordinate4 = Solution1.first;
    } else {
        y_Coordinate4 = Solution2.first;

    }

    return y_Coordinate4;

}


double definelensDistance(double a, double b, double c, double d, double e){// xcoordinate 4, xcoordinate3, ycoordinate4, ycoordinate3, lensthickness
        lensDistance = pow(pow(a-b,2) + pow(c-d,2) + e*e,0.5);
        return lensDistance;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    double maximum{0};
//    double minimum{0};

    friend int main();

};

// lens height is 6.11 cm

int main()
{
    return 0;
}











