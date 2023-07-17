canvas("test.png", height(1000), width(1000), color(0, 23, 42)) {
  # This is a comment
  y = 1.1 + 2.1
  x = 1 + 2 * 4 - 3 + y
  rect = rectangle(                  \
                  height(100),       \
                  thickness(1 * 15), \
                  width(100),        \
                  point(500, 500),   \
                  color(0, 255, 0)   \
                  )
  ell = ellipse(     \
    minor_axis(150), \
    major_axis(150), \
    point(600, 635), \
    thickness(15),   \
    color(255, 0, 0) \
  )
  the_line = line( \
    from(rect),    \
    to(ell)        \
  )
  write(rect)
  write(ell)
  write(the_line)
}
