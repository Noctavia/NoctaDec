import sys
import decompyle3

def decompile(pyc_file, output_file):
    try:
        with open(output_file, "w") as f:
            decompyle3.decompile_file(pyc_file, f)
        print(f"Décompilation réussie : {output_file}")
    except Exception as e:
        print(f"Erreur : {e}")

if __name__ == "__main__":
    decompile(sys.argv[1], sys.argv[2])
