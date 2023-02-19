# 2023/02/19
from PIL import Image, ImageFilter

before = Image.open("stadium.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out_edge.bmp")
