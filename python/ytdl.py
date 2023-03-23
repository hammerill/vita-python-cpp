with open("ux0:data/sample.txt", "a") as log:
    log.write("[YouTubeDL importing...]\n")

try:
    import youtube_dl
except Exception, e:
    with open("ux0:data/sample.txt", "a") as log:
        log.write("[YouTubeDL Error: {0}]\n".format(str(e)))
    exit()

with open("ux0:data/sample.txt", "a") as log:
    log.write("[YouTubeDL imported]\n")

SAVE_PATH = "ux0:data"

ydl_opts = {"nocheckcertificate": True, "outtmpl":SAVE_PATH + "/%(title)s.%(ext)s"}
with youtube_dl.YoutubeDL(ydl_opts) as ydl:
    ydl.download(["https://www.youtube.com/watch?v=dQw4w9WgXcQ"])

with open("ux0:data/sample.txt", "a") as log:
    log.write("[File downloaded]\n")
