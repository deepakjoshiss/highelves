# Light of the Trees: the generated art of the spell's light (data/ini/highelves/fxparticlesystem.inc, the LightOfTrees* systems).
#   art/w3d/ex/exlotfx_raywide.w3d            a wide soft ray of light: two crossed quads around one axis leaning TILT degrees from the vertical, its foot at
#                                             the origin on the ground, its top at the rain's height (Weather SnowBoxHeight 800); the particle's AngleZ turns
#                                             it (2.6: from the top right of the default camera, 0.55: from the top left)
#   art/compiledtextures/ex/exlotfx_raywidetex.tga   its texture: soft across the width, soft at the foot, fading to nothing toward the top (no quad edge shows)
#   art/compiledtextures/ex/exlotfx_dew.tga   a dew drop, art/compiledtextures/ex/exlotfx_leaf.tga  a leaf-flake (white: the particle colours them)
# The model mirrors retail's exlight01.w3d (one mesh, no hierarchy: header 3, vertices, normals, triangles, shade indices, material info, one vertex
# material with a white emissive, one additive shader (LEQUAL, no depth write, src ONE, dst ONE), one texture, one pass), with one texture stage.
# Textures are 32-bit uncompressed TGA, premultiplied (rgb = white x alpha). Python standard library only:  python3 -I -B openbfme/tools/lightoftrees_fx.py
import math, os, struct, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))  # the mod repo
H, TILT, W0, W1, SIGMA, STREAK, FOOT = 800.0, 35.0, 380.0, 620.0, 0.3, 0.06, 0.3


def tga(path, nx, ny, f):
    px = bytearray()
    for y in range(ny):
        for x in range(nx):
            c = int(round(max(0.0, min(1.0, f(x, y))) * 255))
            px += bytes((c, c, c, c))  # BGRA
    with open(path, "wb") as out:
        out.write(struct.pack("<BBBHHBHHHHBB", 0, 0, 2, 0, 0, 0, 0, 0, nx, ny, 32, 8 | 0x20) + px)  # top-left origin


def chunk(cid, body, wrap=False):
    return struct.pack("<II", cid, len(body) | (0x80000000 if wrap else 0)) + body


def ray(w3d_path, tex_name):
    t = math.radians(TILT)
    top = tuple(a * H / math.cos(t) for a in (-math.sin(t), 0.0, math.cos(t)))
    side_a, side_b = (0.0, 1.0, 0.0), (math.cos(t), 0.0, math.sin(t))
    verts, normals, uvs, tris = [], [], [], []
    for side, normal in ((side_a, side_b), (side_b, (0.0, -1.0, 0.0))):
        base = len(verts)
        for pt, w, v in (((0.0, 0.0, 0.0), W0, 0.0), (top, W1, 1.0)):
            for sgn, u in ((-1, 0.0), (1, 1.0)):
                verts.append(tuple(pt[i] + sgn * side[i] * w / 2 for i in range(3)))
                normals.append(normal)
                uvs.append((u, v))
        tris += [(base, base + 1, base + 3), (base, base + 3, base + 2)]
    xs, ys, zs = zip(*verts)
    lo, hi = (min(xs), min(ys), min(zs)), (max(xs), max(ys), max(zs))
    centre = tuple((lo[i] + hi[i]) / 2 for i in range(3))
    radius = max(math.dist(centre, p) for p in verts)
    name = os.path.splitext(os.path.basename(w3d_path))[0].upper().encode()[:15].ljust(16, b"\0")
    header = struct.pack("<II", 0x00040002, 0x00002000) + name + b"\0" * 16 + struct.pack("<IIIIiIIII", len(tris), len(verts), 1, 0, 1, 0, 0, 3, 1) \
        + struct.pack("<3f3f3ff", *lo, *hi, *centre, radius)

    def tri(a, b, c):
        p0, p1, p2 = verts[a], verts[b], verts[c]
        e1 = [p1[i] - p0[i] for i in range(3)]
        e2 = [p2[i] - p0[i] for i in range(3)]
        n = (e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0])
        ln = math.sqrt(sum(x * x for x in n)) or 1.0
        n = tuple(x / ln for x in n)
        return struct.pack("<4I4f", a, b, c, 13, *n, sum(n[i] * p0[i] for i in range(3)))

    vminfo = bytes.fromhex("00000000" "00000000" "00000000" "00000000" "ffffff00") + struct.pack("<3f", 0.0, 1.0, 0.0)  # no mapper, white emissive, opacity 1
    shader = bytes([3, 0, 0, 1, 2, 1, 0, 1, 1, 0, 0, 2, 0, 0, 0, 2])
    mesh = b"".join([
        chunk(0x1F, header),
        chunk(0x02, b"".join(struct.pack("<3f", *v) for v in verts)),
        chunk(0x03, b"".join(struct.pack("<3f", *n) for n in normals)),
        chunk(0x20, b"".join(tri(*t3) for t3 in tris)),
        chunk(0x22, b"".join(struct.pack("<I", i) for i in range(len(verts)))),
        chunk(0x28, struct.pack("<4I", 1, 1, 1, 1)),
        chunk(0x2A, chunk(0x2B, chunk(0x2C, b"LotFxRay\0") + chunk(0x2D, vminfo), True), True),
        chunk(0x29, shader),
        chunk(0x30, chunk(0x31, chunk(0x32, tex_name.encode() + b"\0"), True), True),
        chunk(0x38, chunk(0x39, struct.pack("<I", 0)) + chunk(0x3A, struct.pack("<I", 0))
              + chunk(0x48, chunk(0x49, struct.pack("<I", 0)) + chunk(0x4A, b"".join(struct.pack("<2f", u, v) for u, v in uvs)), True), True),
    ])
    with open(w3d_path, "wb") as out:
        out.write(chunk(0x00, mesh, True))


def main():
    w3d_dir, tex_dir = os.path.join(ROOT, "art/w3d/ex"), os.path.join(ROOT, "art/compiledtextures/ex")
    ray(os.path.join(w3d_dir, "exlotfx_raywide.w3d"), "exlotfx_raywidetex.tga")
    # the ray's texture: the image runs from the ray's top (row 0) to its foot (the UVs put v = 0 at the foot)
    nx, ny = 128, 256
    streak = [1.0 - STREAK + STREAK * math.sin(i * 0.37) * math.sin(i * 0.11 + 1.3) for i in range(nx)]

    def ray_tex(x, y):
        v = 1.0 - (y + 0.5) / ny
        along = min(1.0, (v + 0.02) / FOOT) ** 1.5 * (1.0 - max(0.0, (v - 0.35) / 0.65)) ** 1.6
        return math.exp(-(((x + 0.5) / nx - 0.5) / SIGMA) ** 2) * along * streak[x]
    tga(os.path.join(tex_dir, "exlotfx_raywidetex.tga"), nx, ny, ray_tex)
    n = 64
    cxy = lambda x, y: ((x + 0.5) / n * 2 - 1, (y + 0.5) / n * 2 - 1)

    def dew(x, y):
        u, v = cxy(x, y)
        return math.exp(-((u / 0.22) ** 2 + ((v - 0.1) / 0.45) ** 2)) + 0.35 * math.exp(-(math.hypot(u, v) / 0.6) ** 2)

    def leaf(x, y):  # a pointed leaf along the diagonal, a brighter vein
        a, b = cxy(x, y)
        u, v = (a + b) / math.sqrt(2), (a - b) / math.sqrt(2)
        w = 0.38 * max(0.0, 1 - u * u) ** 0.8
        return (1.0 if abs(v) < w else max(0.0, 1 - (abs(v) - w) / 0.05)) * (abs(u) < 1) * (0.75 + 0.25 * math.exp(-(v / 0.04) ** 2))
    tga(os.path.join(tex_dir, "exlotfx_dew.tga"), n, n, dew)
    tga(os.path.join(tex_dir, "exlotfx_leaf.tga"), n, n, leaf)
    print("wrote art/w3d/ex/exlotfx_raywide.w3d, art/compiledtextures/ex/exlotfx_raywidetex.tga, exlotfx_dew.tga, exlotfx_leaf.tga")


if __name__ == "__main__":
    sys.exit(main())
