// Copyright 2021 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

use std::fs::File;
use std::io::prelude::*;

// Coordinates of a point in the plane.
type Point = (f64, f64);

// A cubic Bézier curve defined from four points.
// https://en.wikipedia.org/wiki/B%C3%A9zier_curve#Cubic_B%C3%A9zier_curves
type CubicBezier = (Point, Point, Point, Point);
fn coordinate(cubic_bezier: &CubicBezier, t: f64) -> Point {
    let ((x0, y0), (x1, y1), (x2, y2), (x3, y3)) = cubic_bezier;
    let u = 1. - t;
    (
        u*u*u * x0 + 3.*u*u*t * x1 + 3.*u*t*t * x2 + t*t*t * x3,
        u*u*u * y0 + 3.*u*u*t * y1 + 3.*u*t*t * y2 + t*t*t * y3,
    )
}

// A curve made of several cubic Bézier segments.
const POINTS_PER_BEZIER_SEGMENT: u64 = 100000;
fn approximate_length(curve: &[CubicBezier], points_per_bezier_segment: u64) -> f64 {
    let h = 1. / (points_per_bezier_segment as f64);
    let mut length = 0.;
    for cubic_bezier in curve {
        let mut previous_point = coordinate(cubic_bezier, 0.);
        for i in 0..points_per_bezier_segment {
            let (x0, y0) = previous_point;
            let (x1, y1) = coordinate(cubic_bezier, (i as f64 + 1.) * h);
            let dx = x1 - x0;
            let dy = y1 - y0;
            length += (dx * dx + dy * dy).sqrt();
            previous_point = (x1, y1);
        }
    }
    length
}
fn dump_to_svg(curve: &[CubicBezier], name: &str) -> std::io::Result<()> {
    let mut svg_file = File::create(name)?;

    svg_file.write(b"<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"
     width=\"500px\" height=\"500px\" viewBox=\"-250 -250 500 500\">
  <g transform=\"scale(10)\">
    <path stroke=\"black\" stroke-width=\".5px\" fill=\"lightblue\" d=\"\n")?;
    let mut previous_point = None;
    for ((x0, y0), (x1, y1), (x2, y2), (x3, y3)) in curve {
        match previous_point {
            Some((x, y)) => {
                if x != x0 || y != y0 {
                    writeln!(svg_file, "z M {},{} ", x0, y0)?;
                }
            },
            None => writeln!(svg_file, "M {},{} ", x0, y0)?,
        }
        writeln!(svg_file, "C{},{} {},{} {},{} ", x1, y1, x2, y2, x3, y3)?;
        previous_point = Some((x3, y3));
    }
    svg_file.write(b"z\"/>
  </g>
</svg>")?;
    Ok(())
}

fn main() {
    let curve = vec![
        ((-22.01,-8.05),(-24.84,-15.43),(-23.11,-17.24),(-20.71,-20.75)),
        ((-20.71,-20.75),(-18.32,-24.26),(-8.45,-17.72),(-5.67,-18.91)),
        ((-5.67,-18.91),(-2.88,-20.10),(-10.68,-25.00),(1.83,-22.42)),
        ((1.83,-22.42),(14.35,-19.85),(22.70,-14.34),(17.07,-13.81)),
        ((17.07,-13.81),(11.45,-13.28),(12.37,-18.78),(8.83,-15.45)),
        ((8.83,-15.45),(5.29,-12.13),(10.35,-12.72),(12.32,-8.00)),
        ((12.32,-8.00),(14.29,-3.29),(25.23,-0.67),(19.35,1.79)),
        ((19.35,1.79),(13.47,4.27),(20.97,11.09),(20.33,13.48)),
        ((20.33,13.48),(19.69,15.86),(11.09,13.62),(18.56,16.01)),
        ((18.56,16.01),(26.03,18.40),(22.00,23.47),(10.97,21.35)),
        ((10.97,21.35),(-0.06,19.24),(-17.58,29.42),(-7.69,20.11)),
        ((-7.69,20.11),(2.19,10.79),(10.68,5.24),(10.80,11.09)),
        ((10.80,11.09),(10.91,16.94),(10.48,22.44),(12.76,16.15)),
        ((12.76,16.15),(15.04,9.85),(17.51,7.47),(14.28,4.95)),
        ((14.28,4.95),(11.05,2.43),(7.49,-2.44),(5.54,2.47)),
        ((5.54,2.47),(3.59,7.39),(12.04,5.81),(3.07,7.86)),
        ((3.07,7.86),(-5.90,9.92),(-2.59,4.83),(-8.08,11.41)),
        ((-8.08,11.41),(-13.57,17.99),(-7.93,24.28),(-13.60,17.99)),
        ((-13.60,17.99),(-19.27,11.70),(-23.03,16.04),(-19.89,13.32)),
        ((-19.89,13.32),(-16.75,10.61),(-19.69,3.77),(-16.44,5.66)),
        ((-16.44,5.66),(-13.18,7.55),(-11.95,3.29),(-7.75,5.22)),
        ((-7.75,5.22),(-3.54,7.15),(-6.70,6.12),(-1.97,3.73)),
        ((-1.97,3.73),(2.76,1.35),(7.32,0.13),(2.48,-2.57)),
        ((2.48,-2.57),(-2.35,-5.27),(6.65,-10.85),(-1.68,-6.13)),
        ((-1.68,-6.13),(-10.03,-1.41),(3.85,-3.61),(-2.47,-0.23)),
        ((-2.47,-0.23),(-8.80,3.15),(-3.42,5.69),(-11.22,2.20)),
        ((-11.22,2.20),(-19.02,-1.28),(-22.84,1.82),(-15.48,-3.68)),
        ((-15.48,-3.68),(-8.11,-9.19),(-18.11,-8.53),(-7.49,-9.69)),
        ((-7.49,-9.69),(-4.03,-10.06),(-5.41,-7.09),(-3.81,-7.88)),
        ((-3.81,-7.88),(-0.51,-9.52),(3.28,-14.66),(3.21,-10.68)),
        ((3.21,-10.68),(3.10,-4.78),(11.27,2.48),(7.71,-7.24)),
        ((7.71,-7.24),(4.15,-16.97),(-3.33,-13.84),(-10.66,-14.88)),
        ((-10.66,-14.88),(-18.00,-15.93),(-19.18,-0.66),(-22.01,-8.05)),
    ];

    // Calculate length of the curve.
    println!("Longueur de la courbe: {}",
             approximate_length(&curve, POINTS_PER_BEZIER_SEGMENT));

    // Calculate lengths of curve chunks.
    // let thread_count = 8;
    // let segments_per_chunk = 1 + curve.len() / thread_count;
    // let curve_chunks: Vec<&[CubicBezier]> = curve.chunks(segments_per_chunk).collect();
    // crossbeam::scope(|spawner| {
    //     for curve_chunk in curve_chunks.into_iter() {
    //         spawner.spawn(move |_| {
    //             println!("{}", approximate_length(curve_chunk,
    //                                               POINTS_PER_BEZIER_SEGMENT));
    //         });
    //     }
    // }).unwrap();
}
