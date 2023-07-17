canvas("test.png", height(1000), width(1000), color(255, 255, 255)) {
  r1 = rectangle(                \
                height(100),     \
                thickness(10),   \
                width(100),      \
                point(250, 250), \
                color(255, 0, 0) \
                )
  r2 = rectangle(                \
                height(100),     \
                thickness(10),   \
                width(100),      \
                point(500, 250), \
                color(0, 255, 0) \
                )
  r3 = rectangle(                \
                height(100),     \
                thickness(10),   \
                width(100),      \
                point(750, 250), \
                color(0, 0, 255) \
                )
  r4 = rectangle(                  \
                height(100),       \
                thickness(20),     \
                width(100),        \
                point(250, 500),   \
                color(255, 255, 0) \
                )
  r5 = rectangle(                  \
                height(100),       \
                thickness(15),     \
                width(100),        \
                point(500, 500),   \
                color(255, 0, 255) \
                )
  r6 = rectangle(                  \
                height(100),       \
                thickness(5),     \
                width(100),        \
                point(750, 500),   \
                color(0, 255, 255) \
                )
  r7 = rectangle(                    \
                height(50),          \
                thickness(10),       \
                width(50),           \
                point(250, 750),     \
                color(15, 255, 255) \
                )
  r8 = rectangle(                 \
                height(250),      \
                width(250),       \
                thickness(10),    \
                point(500, 750),  \
                color(0, 23, 42)  \
                )
  r9 = rectangle(                    \
                height(200),         \
                width(200),          \
                thickness(10),       \
                point(750, 750),     \
                color(106, 13, 173)  \
                )
  l1 = line(from(r1), to(r5))
  l2 = line(from(r2), to(r5))
  l3 = line(from(r3), to(r5))
  l4 = line(from(r4), to(r5))
  l5 = line(from(r6), to(r5))
  l6 = line(from(r7), to(r5))
  l7 = line(from(r8), to(r5))
  l8 = line(from(r9), to(r5))
  write(l1)
  write(l2)
  write(l3)
  write(l4)
  write(l5)
  write(l6)
  write(l7)
  write(l8)
  write(r1)
  write(r2)
  write(r3)
  write(r4)
  write(r5)
  write(r6)
  write(r7)
  write(r8)
  write(r9)
}
