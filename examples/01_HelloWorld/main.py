import carrotlib as cl
import sys

class MyGame(cl.Game):
    def on_ready(self):
        super().on_ready()

        label = cl.controls.Label()
        label.text = "Hello, world"
        label.font_size = 100
        label.color = cl.Colors.Black
        label.position = cl.vec2(cl.g.viewport_width, cl.g.viewport_height) / 2
        print('label.position:', label.position)

        import box2d
        ver = box2d.b2GetVersion()
        print(ver.major, ver.minor, ver.revision)

    @property
    def title(self):
        return "Hello, World"

    @property
    def design_size(self):
        if sys.platform in ('ios', 'android'):
            return (0, 720)
        return (1280, 720)

