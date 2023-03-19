#!/usr/bin/env python3
# @file      ProgramOnWin32.py
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2023, Sergey Baigudin, Baigudin Software

from make.Program import Program
from common.Message import Message

class ProgramOnWin32(Program):
    """
    Program on WIN32.
    """
   
    def _do_build(self):
        if self._get_args().build is not True:    
            return
        
        Message.out(f'[BUILD] Generating CMake project...', Message.INF)
        args = ['cmake', '..']
        self._run_subprocess_from_build_dir(args)

        args.clear()
        Message.out(f'[BUILD] Building CMake project...', Message.INF)
        args = ['cmake', '--build', '.', '--config', self._get_args().config]
        if self._get_args().jobs is not None:
            args.extend(['-j', str(self._get_args().jobs)]) 
        self._run_subprocess_from_build_dir(args)


    def _get_run_ut_executable_path_to(self):
        return f'./codebase/app-hello-world/{self._get_args().config}'
    

    def _get_run_ut_executable_path_back(self):
        return f'./../../..'


    def _get_run_executable(self):
        return f'EoosAppHelloWorld.exe'
