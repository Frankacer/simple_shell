#!/bin/bash
shell_input="hbtn_ls /var"
compare_with_sh=0
check_setup()
{
  cp "/bin/ls" "$PWD/hbtn_ls"
  OLDPATH="$PATH"
  export PATH="$PWD:$HOME/simple_shell"
  return 0
}
sh_setup()
{
  return 0
}
check_callback()
{
  status=$1
  export PATH="$OLDPATH"
  rm -f "$PWD/hbtn_ls"
  return $status
}
