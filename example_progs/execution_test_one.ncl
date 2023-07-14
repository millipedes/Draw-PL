canvas("test.png", height(1000), width(1000), color(0, 23, 42)) {
  x = 1 + 2 * 4 - 3
  rect = rectangle(                                        \
                  height(10),                              \
                  thickness(1 * 15),                       \
                  width(10),                               \
                  point(30 + 1 + 2 * 4 - 3, 1 + 2 * 4 - 3) \
                  )
  ell = ellipse(         \
    minor_axis(15 + 15), \
    major_axis(17),      \
    point(1, 1 + 35),    \
    thickness(1 * 15)    \
  )
  the_point = point(15 + 35, 35 + 35)
  the_color = color(15 + 35, 35 + 35, 255)
  the_line = line(                 \
    from(point(15 + 35, 35 + 35)), \
    to(point(15 + 35, 35 + 35))    \
  )
}
