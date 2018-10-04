#!/usr/bin/env python3
import sys
import git

reviewers = []

print("Begin")

if len(sys.argv) < 2:
    print("Less than 2")
    sys.exit()

reviewers = sys.argv[1:]
config = []
for r in reviewers:
    config.append('r=' + r + '@fenbi.com')
print('%' + ','.join(config))
print("End")
