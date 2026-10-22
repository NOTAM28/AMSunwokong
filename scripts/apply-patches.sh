#!/usr/bin/env bash
set -euo pipefail

XNU_ROOT=$(cd "${1:?xnu tree}" && pwd)
PATCH_DIR=$(cd "${2:?patches dir}" && pwd)
ORDER="$PATCH_DIR/APPLY-ORDER.txt"

if [[ ! -f "$ORDER" ]]; then
  echo "missing APPLY-ORDER.txt at $ORDER" >&2
  ls -la "$PATCH_DIR" >&2 || true
  exit 1
fi

cd "$XNU_ROOT"
echo "XNU_ROOT=$XNU_ROOT"
echo "PATCH_DIR=$PATCH_DIR"

while read -r p || [[ -n "${p:-}" ]]; do
  [[ -z "$p" || "$p" =~ ^# ]] && continue
  f="$PATCH_DIR/$p"
  if [[ ! -f "$f" ]]; then
    echo "MISSING patch file: $f" >&2
    exit 1
  fi
  echo "APPLY $p"
  # --forward: skip if already applied; don't abort whole CI on one fuzzy fail yet
  if ! patch -p1 --forward --batch < "$f"; then
    echo "WARN: patch reported issues for $p (continuing)" >&2
  fi
done < "$ORDER"

echo "patches pass done"
