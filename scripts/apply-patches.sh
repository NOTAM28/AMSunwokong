#!/usr/bin/env bash
set -euo pipefail
XNU_ROOT="${1:?xnu tree}"
PATCH_DIR="${2:?patches dir}"
ORDER="${PATCH_DIR}/APPLY-ORDER.txt"

cd "$XNU_ROOT"
while read -r p; do
  [[ -z "$p" || "$p" =~ ^# ]] && continue
  f="$PATCH_DIR/$p"
  if [[ ! -f "$f" ]]; then
    # prefer cuscoi name already in ORDER; fallback sweet
    echo "missing $f" >&2
    exit 1
  fi
  echo "APPLY $p"
  patch -p1 --forward --batch < "$f" || patch -p1 --forward --batch < "$f" || true
done < "$ORDER"
