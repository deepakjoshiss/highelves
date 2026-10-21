import sys, json
# usage: spots.py <review.json> <block name> [draft out] : prints the block's REVIEW spots raw (yours / v8.4 / 2.02); writes its merged text as a draft
r = [x for x in json.load(open(sys.argv[1])) if x['name'] == sys.argv[2] and 'spots' in x][0]
for i, s in enumerate(x for x in r['spots'] if x['how'].startswith('REVIEW')):
    for k in ('mod', 'base', 'theirs'): print(f'=== spot {i} {k}\n' + s[k].rstrip())
if len(sys.argv) > 3: open(sys.argv[3], 'w', encoding='latin-1').write(r['merged'])
