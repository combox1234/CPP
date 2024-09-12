int main() {
    // create a new playlist object
    playlist playlist;

    // add three songs to the playlist
    playlist.addsong("song 1", "artist 1", 180); // add song 1
    playlist.addsong("song 2", "artist 2", 240); // add song 2
    playlist.addsong("song 3", "artist 3", 300); // add song 3

    // display the entire playlist
    playlist.displayplaylist(); // display the playlist with 3 songs

    // play a specific song
    playlist.playsong("song 2"); // play song 2

    // remove a song from the playlist
    playlist.removesong("song 2"); // remove song 2

    // display the updated playlist
    playlist.displayplaylist(); // display the playlist with 2 songs

    return 0;
}
