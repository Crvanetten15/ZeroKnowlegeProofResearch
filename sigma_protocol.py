'''
Disclaimer : 
This is a tutorial program for educational purposes and is not secure. Therefore it is 
not to be used in any actual application security or verification. It's design is merely to display
how this protocol type is to work within an mock application.

'''

from random import randrange

# Verifier, setting up public value

'''
g is a public parameter
p is a public parameter
'''
g = 5
p = 2000000579


# Secret Class to store actual birthday
class Secret:
    def __init__(self) -> None:
        self.x = 1101938

# Assuming this is a private machine


class Prover:
    def __init__(self) -> None:
        # private variables
        self.r = randrange(p)

        # sharing variables
        self.u = None
        self.z = None
        self.h = None
        self.c = None

        # secret - CHANGE THIS TO ATTEMPT NEW BIRTHDAY
        self.x = 1101938

# Assuming this is a private machine


class Verifier:
    def __init__(self) -> None:
        # sharing variables
        self.c = randrange(p)

        # prover returning variables
        self.u = None
        self.h = None
        self.z = None

    '''
    Verification Equation to check validity
    '''

    def Verify(self, g, p):
        correct = "Birthday is Known" if pow(g, self.z, p) \
            == (P.u * pow(self.h, self.c, p)) % p else \
            "Birthday is not Known"
        return correct


P = Prover()
V = Verifier()
S = Secret()
# =+=+=+=+=+=+=+=+=+=+=+= Establish Equation =+=+=+=+=+=+=+=+=+=+=+=
P.h = pow(g, S.x, p)
V.h = pow(g, S.x, p)

# =+=+=+=+=+=+=+=+=+=+=+= Commitment Phase =+=+=+=+=+=+=+=+=+=+=+=
# as r is randomly selected in Prover object, we are finding u, and sending it to the Verifier
P.u = pow(g, P.r, p)
V.u = P.u

# =+=+=+=+=+=+=+=+=+=+=+= Challenge Phase =+=+=+=+=+=+=+=+=+=+=+=
# Generate a random number for the challenge and give it to our prover
P.c = V.c

# =+=+=+=+=+=+=+=+=+=+=+= Response Phase =+=+=+=+=+=+=+=+=+=+=+=
# calculate our response and give it to the verifier
P.z = P.r + P.c * P.x
V.z = P.z


# =+=+=+=+=+=+=+=+=+=+=+= Verification Phase =+=+=+=+=+=+=+=+=+=+=+=
# Check if statement is valid and if our answer is correct
print(V.Verify(g, p))


"""
| P(x, h = g**x) | Transport  |    V(h = g**x)   | 
| ______________ | __________ | ________________ | 
| r -> R Zp      |            |                  | 
| u <- g**r      |   -> u     |                  | 
|                |   c <-     |    c -> R Zp     | 
| z <- r +cx     |            | g**z == u * h**c | 
"""
