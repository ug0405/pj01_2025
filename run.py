import yaml
import subprocess
import os
import sys

def run_commands(commands):
    """コマンドリストを実行"""
    for command in commands:
        print(f"実行中: {command}")
        process = subprocess.Popen(command, shell=True)
        process.wait()
        if process.returncode != 0:
            print(f"コマンド {command} の実行に失敗しました。")
            return False
    return True

def main():
    # コマンドライン引数をチェック（ビルドかテストか両方かを指定）
    if len(sys.argv) < 2:
        print("使用法: python3 run_build_and_tests.py [build|test|all]")
        return

    action = sys.argv[1]

    # YAML ファイルを読み込む
    with open("cmake_config.yaml", "r") as file:
        config = yaml.safe_load(file)

    # ビルドディレクトリの作成
    build_dir = "build"
    if not os.path.exists(build_dir):
        os.makedirs(build_dir)

    # ビルドディレクトリに移動
    os.chdir(build_dir)

    # ビルドコマンドを実行（ビルド指定の場合）
    if action == "build" or action == "all":
        if not run_commands(config['build_commands']):
            print("ビルドコマンドが失敗しました。")
            return

    # カスタムコマンドがあれば実行（オプション）
    if 'custom_commands' in config:
        if not run_commands(config['custom_commands']):
            print("カスタムコマンドの実行に失敗しました。")
            return

    # テストコマンドを実行（テスト指定の場合）
    if action == "test" or action == "all":
        if not run_commands(config['test_commands']):
            print("テストコマンドが失敗しました。")
            return

    print("処理が完了しました。")

if __name__ == "__main__":
    main()
