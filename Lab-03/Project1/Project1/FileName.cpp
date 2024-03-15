#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a song
struct Song {
    std::string name;
    std::string artist;
};

// Function to perform binary search on the playlist
int binarySearch(const std::vector<Song>& playlist, const std::string& target) {
    int low = 0;
    int high = playlist.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (playlist[mid].name == target) {
            return mid; // Song found at index mid
        }
        else if (playlist[mid].name < target) {
            low = mid + 1; // Search in the right half
        }
        else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Song not found
}

// Function to add a song to the playlist and maintain alphabetical order
void addSong(std::vector<Song>& playlist, const Song& newSong) {
    playlist.push_back(newSong);
    std::sort(playlist.begin(), playlist.end(), [](const Song& a, const Song& b) {
        return a.name < b.name;
        });
}

// Function to display the entire playlist
void displayPlaylist(const std::vector<Song>& playlist) {
    std::cout << "Playlist:\n";
    for (const auto& song : playlist) {
        std::cout << "Name: " << song.name << ", Artist: " << song.artist << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::vector<Song> playlist;

    // Adding some initial songs
    addSong(playlist, { "Song1", "Artist1" });
    addSong(playlist, { "Song3", "Artist3" });
    addSong(playlist, { "Song2", "Artist2" });

    displayPlaylist(playlist);

    // Searching for a song
    std::string searchSong;
    std::cout << "Enter the name of the song to search: ";
    std::cin >> searchSong;

    int index = binarySearch(playlist, searchSong);

    if (index != -1) {
        std::cout << "Song found at index " << index << ".\n";
    }
    else {
        std::cout << "Song not found.\n";
    }

    return 0;
}
