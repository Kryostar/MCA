import os
from pathlib import Path

dir_name = "C:/Users/1kryo/Documents/Github/MCA/MCA-Sem1/DS_lab/"
test = os.listdir(dir_name)

for item in test:
    if item.endswith(".exe"):
        os.remove(os.path.join(dir_name, item))
