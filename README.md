# Raytracer

CPU powered raytracer written in C++

![image](screenshots/denoised_and_upscaled.png)

## Requirements

- [SFML](https://www.sfml-dev.org)
- [x86-64 Linux machine](https://wikipedia.org/wiki/Linux)
> The pre-compiled binaries won't work on anything else

## Usage

```bash
./raytracer [file.scene]
```
The program will create a ``output.ppm`` file.
To view the produced image, you can do so using the included viewer
```bash
./PPM_viewer [file.ppm]
```

## Presentation

### This is the first ever image I've ever gotten from my raytracer

![image](screenshots/first_result.png)

> Ladies and Gentlemen, behold the sphere!

This was supposed to be a raycasted sphere, well... Something definitely didn't go as planed.

### The first ever sphere, for real this time

![image](screenshots/ball.png)

As you can see by the shadow below the sphere, this is already raytraced and illuminated by the sky.

### Reflective surfaces

![image](screenshots/reflective_balls.png)

Here I had to implement a proper material class that handles rays differently depending on the choosen material.

### Planes

![image](screenshots/planes.png)

Spheres are cool, but what's cooler is being able to render any type of surface, so here's planes. I wish I had the time to implement triangles, This would've allowed me to support obj files and my raytracer would've been able to render actual 3D meshes.

### Cornell Box

![image](screenshots/cornell_box.png)

This scene introduces 2 new main things. First of all, an actual light material that illuminates its surroundings, it was limited to light from the sky before that. And also boxes, which is a simple mix of 6 planes. You can see some very nice penumbra shadows in the scene, as well as some subtle indirect lighting hitting the roof.

### Bonus render

![image](screenshots/reflections.png)

This image doesn't really introduces anything new, but I just think it looks cool and it deserves to be showcased :)