#!/bin/sh

FIRST_LINE=$(head -n 1 test.c)

TIER_CODE=$(echo "$FIRST_LINE" | awk '{print $2}')
PROB_NUM=$(echo "$FIRST_LINE" | awk '{print $3}' | tr -d ':')
TITLE=$(echo "$FIRST_LINE" | sed 's/.*: //; s/(.*//')
TAGS=$(echo "$FIRST_LINE" | sed 's/.*(//; s/).*//')

TIER_FIRST=$(echo "$TIER_CODE" | cut -c1)

case "$TIER_FIRST" in
    R) COLOR="#ff0062" ;;
    D) COLOR="#00b4fc" ;;
    P) COLOR="#27e2a4" ;;
    G) COLOR="#ec9a00" ;;
    S) COLOR="#435f7a" ;;
    B) COLOR="#ad5600" ;;
    N) COLOR="#96cc00" ;;
    *) COLOR="#000000" ;;
esac

mkdir -p ./OJ2026W
cp ./test.c "./OJ2026W/${PROB_NUM}.c"

CURRENT_DATE=$(date +%Y-%m-%d)
echo "|${PROB_NUM} |<span style=\"background-color:${COLOR}\">${TIER_CODE}</span>|C|${CURRENT_DATE}|${TITLE}|${TAGS}|" >> README.md

: > test.c
rm test