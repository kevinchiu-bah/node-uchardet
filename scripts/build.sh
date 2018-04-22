#!/bin/bash
SETTINGS=('NODE_NO_WARNINGS=1')
CXXFLAGS=('-fPIC')

CMDVARS=(
  ${SETTINGS[@]}
  "CXXFLAGS=\"${CXXFLAGS[*]// /|}\""
)

CMD="${CMDVARS[*]// /|} node-gyp rebuild"
echo $CMD
eval $CMD
