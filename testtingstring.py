import re
import random
from string import ascii_lowercase

def extract_binary_chunks(input_text):
    """Extract all binary-like substrings from the input text."""
    return re.findall(r'[01]+', input_text)
import random
from concurrent.futures import ProcessPoolExecutor
from tqdm import tqdm
from multiprocessing import Manager

def random_combine_to_length_worker(binary_chunks, target_length, num_attempts, progress_counter):
    """
    Worker function for randomly combining binary chunks to form sequences of a specific length.
    This function will be used in parallel processing and will update the progress counter.
    """
    valid_sequences = set()
    for _ in range(num_attempts):
        # Randomly pick chunks and concatenate until reaching target length
        combined = ''.join(random.choices(binary_chunks, k=target_length // len(binary_chunks) + 1))[:target_length]
        if len(combined) == target_length:
            valid_sequences.add(combined)
        
        # Increment the progress counter and update the progress bar
        progress_counter.value += 1
    return valid_sequences

def random_combine_to_length(binary_chunks, target_length=8, num_attempts=10000000, num_workers=4):
    """
    Randomly combine binary chunks to form sequences of a specific length using parallelization.
    
    Args:
    - binary_chunks: List of binary strings.
    - target_length: Desired length of combined binary sequences.
    - num_attempts: Number of random attempts to form a valid sequence.
    - num_workers: Number of parallel workers to use.

    Returns:
    - List of valid binary sequences of the desired length.
    """
    valid_sequences = set()
    attempts_per_worker = num_attempts // num_workers

    # Create a shared manager to keep track of progress across processes
    with Manager() as manager:
        # Shared progress counter
        progress_counter = manager.Value('i', 0)

        # Use a ProcessPoolExecutor to parallelize the task
        with ProcessPoolExecutor(max_workers=num_workers) as executor:
            # Distribute the work to workers
            futures = []
            for _ in range(num_workers):
                futures.append(executor.submit(random_combine_to_length_worker, binary_chunks, target_length, attempts_per_worker, progress_counter))

            # Create a tqdm progress bar for the total number of attempts
            with tqdm(total=num_attempts, desc="Processing attempts") as pbar:
                while any(future.running() for future in futures):
                    pbar.update(progress_counter.value - pbar.n)

        # Collect the results from all workers
        for future in futures:
            valid_sequences.update(future.result())

    return list(valid_sequences)
def binary_to_ascii(binary_sequences):
    """Convert binary sequences to ASCII characters if they are valid lowercase letters."""
    ascii_characters = []
    for binary in binary_sequences:
        char = chr(int(binary, 2)).lower()
        if char in ascii_lowercase:
            ascii_characters.append(char)
    return ascii_characters

def main():
    # Input text with scattered binary strings
    input_text = """


LAST 01000100
NO NUT NOVEMBER CAMPAIGN "Metal Nut" by u/Youngbuck_Jiterpol6

DAY 029 - 11 DAY UNTIL THE END - 097% CLEAR - 00001011

Legend: 0S = Story, 1A = Advice, 1Q = Question, 1SH = Shoutout0

ALERT! : 0Everything in the "1Story" section is made up and just for entertainment purposes only. Every soldier who reads / replies is considered part of it. I am not a moderator! Enjoy the 001111!

S. The soldiers turned their direction towards the Nut Clan base, watching as the nuclear explosion had went off.

0101

They all gave a salute to the 0100Chief before u/Youngbuck_Jiterpol6 made a call.

"This is u/Youngbuck_Jiterpol6 coming in, the mission is complete. Metal Gear has been destroyed, alongside every copy, and the storage area they were using parts from."

It was... a sad sight. Their Chief of almost a decade, lost, killed because of his 0wn10c0mrades. In the end, the soldiers proved their strength, but who was going to be the new leader?

"If anyone is out there, we need an emergency pickup at 0100 [REDACTED]"

After that, he hung up.

"Nothing else to do now soldiers, except wait for help to arrive. But... we did good. Chief... we won't forget you."

The soldiers sat down, making a fireplace and lighting a flare as they waited through the night, for a better tomorrow.

A. I'll be h0nest, this day 1s g0nna be 0ne 0f the tr1ckier 0nes. My only adv1ce now is don't let your guard down! We're so close now, don't waste your opportunity to

Q. How was your Thanksgiving? Mine went along pretty well! I'd assume none of you got freaky with the turkey, of course. Let's win it together, soldiers! (Edited from "What if everything you knew was a lie?")

SH. Good work, u/Mr_FuzzyPenguin keep going. 00001011 0At the end of NNN, 1I will shoutout all of the soldiers I have already gave a sh0utout t0, 0and their status at the end.0

0Think of it as a 'hall of fame' for this campaign.1

As always soldiers---------ignore--------------------ignore-00001011

Still IN ...............SOLVE.

    """
    
    # Step 1: Extract all binary-like chunks
    binary_chunks = extract_binary_chunks(input_text)
    print(f"Extracted Binary Chunks: {binary_chunks}")
    
    # Step 2: Randomly combine binary chunks to form 8-bit sequences
    combined_binary_sequences = random_combine_to_length(binary_chunks, target_length=8, num_attempts=10**5, num_workers= 12)
    print(f"Randomly Combined Binary Sequences: {combined_binary_sequences}")
    
    # Step 3: Convert valid 8-bit binary sequences to ASCII characters
    ascii_characters = binary_to_ascii(combined_binary_sequences)
    print(f"Converted ASCII Characters: {ascii_characters}")
    
    # Step 4: Output results
    print("Final Characters:")
    print(''.join(ascii_characters))

if __name__ == "__main__":
    main()
