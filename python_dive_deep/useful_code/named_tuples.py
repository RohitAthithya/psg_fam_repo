

from collections import namedtuple



# Declaring namedtuple()
xyz = namedtuple('Student', ['name', 'age', 'DOB'])

# Adding values
S = xyz('Rohit', '23', '2541997')



print(f"{S.name=}")

