# Abhijit S A
# Day 5 Assignment
import pandas as pd
import numpy as np
df=pd.DataFrame(np.random.randint(0,101,(4,5)),['A','B','C','D'],['1','2','3','4','5'])
print(df)
df['3']['B']=None # insults a NULL value at specified position
print(df)
print(df.isnull().sum())
