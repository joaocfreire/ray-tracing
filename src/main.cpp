#include "rtweekend.h"

#include "camera.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main() {
    hittable_list world;

    auto metal_red    = make_shared<metal>(color(0.8, 0.2, 0.2), 0.2);
    auto metal_green  = make_shared<metal>(color(0.2, 0.8, 0.2), 0.2);
    auto metal_blue   = make_shared<metal>(color(0.2, 0.2, 0.8), 0.2);
    auto metal_gold   = make_shared<metal>(color(0.8, 0.6, 0.2), 0.1);

    double R = 0.5;
    double offset = 0.6;

    world.add(make_shared<sphere>(point3(-offset, offset, 0), R, metal_red));
    world.add(make_shared<sphere>(point3(offset, offset, 0), R, metal_green));
    world.add(make_shared<sphere>(point3(-offset, -offset, 0), R, metal_blue));
    world.add(make_shared<sphere>(point3(offset, -offset, 0), R, metal_gold));

    camera cam;

    cam.aspect_ratio = 1.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.vfov = 50;
    cam.lookfrom = point3(0, 0, 4);
    cam.lookat = point3(0, 0, 0);
    cam.vup = vec3(0, 1, 0);

    cam.render(world);
}