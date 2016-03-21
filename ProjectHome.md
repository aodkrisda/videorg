Sometimes if you have a large number of movies in your computer could be very annoying to navigate throught, because the name of the file could be not the movie´s one or because nothing is organized in thematic folders.
The idea is quite simple, to get some snapshots of the movie, could be easy getting the last minutes where the ending titles used to be, then with an OCR software get the actual names of all people that participate in the movie, with this information is easy to search in google or imdb and get the actual name of the movie. Then:

- we can rename the file to something nice like Robocop[1987](1987.md).avi or something like that

- we can get metadata from imdb and organize all the movies in categories and folders

- we can get the movie poster, images or metada to generate a report that includes all your movies


some ideas to implement this:

1. get the snapshots with ffmpeg

2. use tessaract to process the OCR

3. use this output to search in google

i.e.

(generate a sample file with only the ending credits)

ffmpeg -ss 01:37:00 -t 01:43:00 -i Robocop\ 1987\ BDRip\[ResourceRG\].mp4 -async 1
-ac 1 robocop.mpeg

(get snapshots every second)

ffmpeg -i robocop.mpeg -r 0.25 -y bb%03d.png

(then use tessaract or other OCR software to recognize text)

(search in google to get the title and data)