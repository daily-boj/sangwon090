scale = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]

def foo(note):
    if note == "Ab":
        return "G#"
    elif note == "Bb":
        return "A#"
    elif note == "Db":
        return "C#"
    elif note == "Eb":
        return "D#"
    elif note == "Gb":
        return "F#"

    elif note == "B#":
        return "C"
    elif note == "E#":
        return "F"

    else:
        return note

while True:
    a = input()
    if a == "***":
        break

    b = list(map(foo, a.split(' ')))
    c = int(input())

    for (i, d) in enumerate(b):
        if scale.index(d) + c >= 12:
            b[i] = scale[scale.index(d) + c - 12]
        elif scale.index(d) + c < 0:
            b[i] = scale[scale.index(d) + c + 12]
        else:
            b[i] = scale[scale.index(d) + c]
    
    print(" ".join(b))