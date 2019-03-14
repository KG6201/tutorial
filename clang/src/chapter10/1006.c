/* 点を表す構造体 */
struct point {
    double x; /* ｘ座標 */
    double y; /* ｙ座標 */
};

/* 線分を表す構造体(1) */
struct line1 {
    double x1; /* 始点のｘ座標 */
    double y1; /* 始点のｙ座標 */
    double x2; /* 終点のｘ座標 */
    double y2; /* 終点のｙ座標 */
};

/* 線分を表す構造体(2) */
struct line2 {
    struct point start; /* 始点 */
    struct point end;   /* 終点 */
};

/* 長方形を表す構造体(1) */
struct rectangle1 {
    double x1; /* 点１のｘ座標 */
    double y1; /* 点１のｙ座標 */
    double x2; /* 点２のｘ座標 */
    double y2; /* 点２のｙ座標 */
};

/* 長方形を表す構造体(2) */
struct rectangle2 {
    struct point p1; /* 点１ */
    struct point p2; /* 点２ */
};
