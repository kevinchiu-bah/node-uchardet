#!/bin/bash
SETTINGS=('NODE_NO_WARNINGS=1')
CXXFLAGS=('-fPIC')

CMDVARS=(
  ${SETTINGS[@]}
)

CMD="${CMDVARS[*]// /|} node-gyp rebuild"

export CXXFLAGS=\"${CXXFLAGS[*]// /|}\"

eval $CMD
