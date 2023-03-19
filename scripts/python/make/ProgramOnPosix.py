#!/usr/bin/env python3
# @file      ProgramOnPosix.py
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2023, Sergey Baigudin, Baigudin Software

from make.Program import Program
from common.Message import Message

class ProgramOnPosix(Program):
    """
    Program on POSIX.
    """

    def _do_build(self):
        if self._get_args().build is not True:    
            return
        
        Message.out(f'[BUILD] Generating CMake project...', Message.INF)
        args = ['cmake', f'-DCMAKE_BUILD_TYPE={self._get_args().config}', '..']
        self._run_subprocess_from_build_dir(args)

        args.clear()
        Message.out(f'[BUILD] Building Make project...', Message.INF)
        args = ['make', 'all']
        if self._get_args().jobs is not None:
            args.extend(['-j', str(self._get_args().jobs)]) 
        self._run_subprocess_from_build_dir(args)


    def _get_run_ut_executable_path_to(self):
        return './codebase/app-hello-world'
    

    def _get_run_ut_executable_path_back(self):
        return f'./../..'


    def _get_run_executable(self):
        return f'./EoosAppHelloWorld'
