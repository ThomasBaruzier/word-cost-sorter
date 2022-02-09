import string
import random
def gen(size=6, chars=string.ascii_uppercase + string.ascii_lowercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))
for x in range(10000000):
    print(gen())
