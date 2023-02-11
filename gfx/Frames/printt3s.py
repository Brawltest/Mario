import sys

print('This message will be displayed on the screen.')

original_stdout = sys.stdout # Save a reference to the original standard output

with open('mariospr.txt', 'w') as f:
    sys.stdout = f # Change the standard output to the file we created.
    print('--atlas -f rgba8888 -z auto')
    for i in range(137):
        print('Mario'+str(i+1))
    sys.stdout = original_stdout # Reset the standard output to its original value

input("Terminée")
