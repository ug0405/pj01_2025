#!/usr/bin/env python3
import yaml
import subprocess
import sys

# YAMLファイルを読み込む
def load_commands():
    with open('commands.yaml', 'r') as file:
        return yaml.safe_load(file)

# コマンドを実行する関数
def run_command(command_name, commands):
    command = commands.get('commands', {}).get(command_name, None)
    if command:
        print(f"Executing: {command['description']}")
        subprocess.run(command['command'], shell=True)
    else:
        print(f"Command '{command_name}' not found in YAML.")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Please provide a command to run.")
        sys.exit(1)

    command_name = sys.argv[1]
    commands = load_commands()
    run_command(command_name, commands)
