#!/usr/bin/env bash
# Print the package version: the release tag without its "v" when TAG is set,
# otherwise BUBBLET_VERSION_STRING from bubblet_version.h.
set -euo pipefail
if [ -n "${TAG:-}" ]; then
  echo "${TAG#v}"
else
  sed -n 's/.*BUBBLET_VERSION_STRING "\(.*\)".*/\1/p' "$(dirname "$0")/../bubblet_version.h"
fi
