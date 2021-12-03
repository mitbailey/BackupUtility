# Directory Backup Utility
Recursively copies a directory, generating an identical directory whose name is appended with the date and time.

The utility is intended for use on Windows or Linux.

Uses C++'s filesystem header.

# Compilation
## ___Windows___
Open Command Prompt in the repository's directory and run the following:

`make`

To cleanup, run:

`cleanup`

## ___Linux___
Open Terminal in the repository's directory and run the following:

`make`

To cleanup, run:

`make clean`

# Usage

When invoked, the program copies a directory recursively and places it in another directory named as the original copied directory concatenated with the date and time in ISO8601 format.

For example, when run to backup `C:/Example/Folder` on 2021.12.02 at 09:55, the program will create `C:/Example/Folder_20211102T095500` whose contents will be identical to the source folder at the time of running.
___
## ___Windows___
1. Either compile the executable ___or___ download from the releases page.

2. Place the executable inside the directory to be copied.
  
The command line invocation includes two optional arguments, the absolute path to the output and absolute path to the input.

Note that command line arguments can be used by either opening Command Prompt and using the command line invocations as listed below, or by making a shortcut to the executable, right-clicking the shortcut, clicking `Properties`, and adding the arguments in the `Target:` field after `.exe`.

If the executable is downloaded and run directly, the program will use the default, no command line arguments invocation.

### Command Line Invocation
_via Command Prompt_
___
__No arguments__ will result in the program copying the executable's current directory and placing it one level above as a sibling of the current directory.

`backup`
___
__One argument__ allows specification of the absolute path of the desired output. The program will still copy the executable's current directory, but will now place it into the directory specified by the argument.

`backup C:/path/to/output/`
___
__Two arguments__ allows specification of the absolute path of the desired output and input. The program will copy the directory specified by the input path argument and place it in the directory specified by the output path argument.

`backup C:/path/to/output/ C:/path/to/input`
___
## ___Linux___
1. Compile the executable.

2. Place the executable inside the directory to be copied.
  
The command line invocation includes two optional arguments, the absolute path to the output and absolute path to the input.

### Command Line Invocation
_via Terminal_
___
__No arguments__ will result in the program copying the executable's current directory and placing it one level above as a sibling of the current directory.

`./backup.out`
___
__One argument__ allows specification of the absolute path of the desired output. The program will still copy the executable's current directory, but will now place it into the directory specified by the argument.

`./backup.out /path/to/output`
___
__Two arguments__ allows specification of the absolute path of the desired output and input. The program will copy the directory specified by the input path argument and place it in the directory specified by the output path argument.

`./backup.out /path/to/output /path/to/input`

