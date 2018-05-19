#!/bin/bash
settings=('NODE_NO_WARNINGS=1')
cxxflags=('-fPIC')

vars=(
  ${settings[@]}
  "CXXFLAGS=\"${cxxflags[*]// /|}\""
)

export CXXFLAGS=\"${cxxflags[*]// /|}\"

eval $cmd
