canvas("test.png", height(1000), width(1000), color(0, 23, 42)) {
  # This is a comment
  y = 1.1 + 2.1
  x = 1 + 2 * 4 - 3 + y
  rect = rectangle(                                        \
                  height(10),                              \
                  thickness(1 * 15),                       \
                  width(10),                               \
                  point(500, 500) \
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
    from(rect), \
    to(rectangle(height(10), width(10), point(450, 500)))    \
  )
}
