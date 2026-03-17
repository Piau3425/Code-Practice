#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

inline unsigned char _clamp(float val) {
    if (val < 0.0f) return 0;
    if (val > 255.0f) return 255;
    return (unsigned char)(val+0.5f);
}

void rgb2yuv(const unsigned char &srcR, const unsigned char &srcG, const unsigned char &srcB, unsigned char &dstY, unsigned char &dstU, unsigned char &dstV) {
    float r = srcR, g = srcG, b = srcB;
    float y =  0.299f*r + 0.587f*g + 0.114f*b;
    float u = -0.169f*r - 0.331f*g + 0.500f*b + 128.0f;
    float v =  0.500f*r - 0.419f*g - 0.081f*b + 128.0f;
    dstY = _clamp(y), dstU = _clamp(u), dstV = _clamp(v);
}

void yuv2rgb(const unsigned char &srcY, const unsigned char &srcU, const unsigned char &srcV, unsigned char &dstR, unsigned char &dstG, unsigned char &dstB) {
    float y = srcY, u = srcU-128.0f, v = srcV-128.0f;
    float r = y - 0.000930f*u + 1.401687f*v;
    float g = y - 0.343700f*u - 0.714170f*v;
    float b = y + 1.772160f*u + 0.000990f*v;
    dstR = _clamp(r), dstG = _clamp(g), dstB = _clamp(b);
}

signed main() { WA();
    for (int rIn, gIn, bIn; cin >> rIn >> gIn >> bIn;) {
        unsigned char r = rIn, g = gIn, b = bIn;
        unsigned char y, u, v, nr, ng, nb;
        rgb2yuv(r, g, b, y, u, v), yuv2rgb(y, u, v, nr, ng, nb);
        cout << (int)y << ' ' << (int)u << ' ' << (int)v << " | " << (int)nr << ' ' << (int)ng << ' ' << (int)nb << '\n';
    }
}