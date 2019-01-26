#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing universal aliases for various multimedia commands
#' @file multimedia_rc.sh
#' @version 2018.12.28
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# AUDIO #


#' Play an audio file
#' @param[in] $1 pathname to audio file to play
playmusic() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Play an audio file\nUsage: playmusic AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        if [ -x "$(command -v ffplay)" ]; then
            ffplay -hide_banner -loglevel panic -sn -vn -nodisp "${1}"
        elif [ -x "$(command -v play)" ]; then
            play -q -V1 "${1}"
        else
            printf 'ERROR: Unable to find a suitable audio player!\n' >&2
        fi
    else
        printf 'ERROR: A pathname to a readable file is required!\nPlay an audio file\nUsage: playmusic AUDIO_FILE\n' >&2
    fi
}


#' Play an audio file with visuals
#' @param[in] $1 pathname to audio file to play
#' @param[in] $2 specify visual by number
playmusicvisual() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Play an audio file with visuals\nUsage: playmusicvisual AUDIO_FILE [VISUAL]\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        if [ -x "$(command -v ffplay)" ]; then
            if [ -n "${2:-}" ]; then
                if [ "${2}" == 2 ]; then
                    ffplay -hide_banner -loglevel panic -sn -vn -showmode 2 "${1}"
                else
                    ffplay -hide_banner -loglevel panic -sn -vn -showmode 1 "${1}"
                fi
            else
                ffplay -hide_banner -loglevel panic -sn -vn -showmode 1 "${1}"
            fi
        else
            printf 'ERROR: Unable to find a suitable audio player!\n' >&2
        fi
    else
        printf 'ERROR: A pathname to a readable file is required!\nPlay an audio file with visuals\nUsage: playmusicvisual AUDIO_FILE [VISUAL]\n' >&2
    fi
}


# AUDIO CHARTS #


if [ -x "$(command -v ffmpeg)" ]; then


#' Generate a linear visualization of the audio wave (in the specified audio file) and save it as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate a linear visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        core_count=''
        outfile="${1##*/}"
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=lin:size=2560x1440 "${outfile%.*}.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\nGenerate a linear visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png AUDIO_FILE\n' >&2
    fi
}


#' Generate a squareroot visualization of the audio wave (in the specified audio file) and save it as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_sqrt() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate a squareroot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_sqrt AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        core_count=''
        outfile="${1##*/}"
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=sqrt:size=2560x1440 "${outfile%.*}_sqrt.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\nGenerate a squareroot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_sqrt AUDIO_FILE\n' >&2
    fi
}


#' Generate a cuberoot visualization of the audio wave (in the specified audio file) and save it as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_cbrt() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate a cuberoot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_cbrt AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        core_count=''
        outfile="${1##*/}"
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=cbrt:size=2560x1440 "${outfile%.*}_cbrt.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\nGenerate a cuberoot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_cbrt AUDIO_FILE\n' >&2
    fi
}


#' Generate a logarithmic visualization of the audio wave (in the specified audio file) and save it as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_log() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate a logarithmic visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_log AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        core_count=''
        outfile="${1##*/}"
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=log:size=2560x1440 "${outfile%.*}_log.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\nGenerate a logarithmic visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_log AUDIO_FILE\n' >&2
    fi
}


#' Generate multiple visualizations of the audio wave (in the specified audio file) and save them as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_all() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate multiple visualizations of the audio wave (in the specified audio file) and save them as a PNG\nUsage: audio2png_all AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        core_count=''
        outfile="${1##*/}"
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=lin:size=2560x1440 "${outfile%.*}.png" &
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=sqrt:size=2560x1440 "${outfile%.*}_sqrt.png" &
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=cbrt:size=2560x1440 "${outfile%.*}_cbrt.png" &
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=log:size=2560x1440 "${outfile%.*}_log.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\nGenerate multiple visualizations of the audio wave (in the specified audio file) and save them as a PNG\nUsage: audio2png_all AUDIO_FILE\n' >&2
    fi
}


fi


# AUDIO CONVERSIONS #


if [ -x "$(command -v ffmpeg)" ]; then


#' Convert an audio file to an AAC file
#' @param[in] $1 pathname to audio file to convert
convert_to_aac() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to AAC\nUsage: convert_to_aac AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libfaac -ar 44100 -f aac "${outfile%.*}.aac"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to AAC\nUsage: convert_to_aac AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an AC3 file
#' @param[in] $1 pathname to audio file to convert
convert_to_ac3() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to AC3\nUsage: convert_to_ac3 AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a ac3 -ar 44100 -f ac3 "${outfile%.*}.ac3"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to AC3\nUsage: convert_to_ac3 AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an AC3 (Fixed) file
#' @param[in] $1 pathname to audio file to convert
convert_to_ac3_fixed() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to AC3 (Fixed)\nUsage: convert_to_ac3_fixed AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a ac3_fixed -ar 44100 "${outfile%.*}.ac3"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to AC3 (Fixed)\nUsage: convert_to_ac3_fixed AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to a Flac file
#' @param[in] $1 pathname to audio file to convert
convert_to_flac() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to Flac\nUsage: convert_to_flac AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a flac -b:a 320000 -ar 44100 -compression_level 12 -f flac "${outfile%.*}.flac"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to Flac\nUsage: convert_to_flac AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an MP3 file
#' @param[in] $1 pathname to audio file to convert
convert_to_mp3() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to MP3\nUsage: convert_to_mp3 AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libmp3lame -b:a 320000 -ar 44100 -compression_level 0 -f mp3 "${outfile%.*}.mp3"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to MP3\nUsage: convert_to_mp3 AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an OGG file
#' @param[in] $1 pathname to audio file to convert
convert_to_ogg() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to OGG\nUsage: convert_to_ogg AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libvorbis -ar 44100 -f ogg "${outfile%.*}.ogg"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to OGG\nUsage: convert_to_ogg AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an OPUS file
#' @param[in] $1 pathname to audio file to convert
convert_to_opus() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to OPUS\nUsage: convert_to_opus AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libopus -compression_level 10 "${outfile%.*}.opus"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to OPUS\nUsage: convert_to_opus AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an WAV file
#' @param[in] $1 pathname to audio file to convert
convert_to_wav() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to WAV\nUsage: convert_to_wav AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="${1##*/}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a pcm_s16le -ar 44100 -f wav "${outfile%.*}.wav"
    else
        printf 'ERROR: A pathname to a readable file is required!\nConvert an audio file to WAV\nUsage: convert_to_wav AUDIO_FILE\n' >&2
    fi
}


fi


# IMAGES #


if [ -x "$(command -v convert)" ]; then


#' Convert image to BMP
#' @param[in] $1 pathname to the image file to convert
img2bmp() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to BMP\nUsage: img2bmp IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.bmp"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to Windows Cursor
#' @param[in] $1 pathname to the image file to convert
img2cur() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to a Windows Cursor\nUsage: img2cur IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.cur"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to GIF
#' @param[in] $1 pathname to the image file to convert
img2gif() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to GIF\nUsage: img2gif IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.gif"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to ICNS
#' @param[in] $1 pathname to the image file to convert
img2icns() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to ICNS\nUsage: img2icns IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.icns"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to ICO
#' @param[in] $1 pathname to the image file to convert
img2ico() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to ICO\nUsage: img2ico IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.ico"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to JPG
#' @param[in] $1 pathname to the image file to convert
img2jpg() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to JPG\nUsage: img2jpg IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.jpg"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to PDF
#' @param[in] $1 pathname to the image file to convert
img2pdf() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to PDF\nUsage: img2pdf IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.pdf"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to PNG
#' @param[in] $1 pathname to the image file to convert
img2png() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to PNG\nUsage: img2png IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.png"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to PostScript
#' @param[in] $1 pathname to the image file to convert
img2ps() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to PostScript\nUsage: img2ps IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.ps"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to TIFF
#' @param[in] $1 pathname to the image file to convert
img2tiff() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to TIFF\nUsage: img2tiff IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.tiff"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to Unicode Braille
#' @param[in] $1 pathname to the image file to convert
img2ubrl() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to Unicode Braille\nUsage: img2ubrl IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.ubrl"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Convert image to XPM
#' @param[in] $1 pathname to the image file to convert
img2xpm() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an image file to XPM\nUsage: img2xpm IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" "${1%.*}.xpm"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Rotate an image file 90-degrees clock-wise
#' @param[in] $1 pathname to the image file to rotate
rotate_img() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Rotate an image file 90-degrees clock-wise\nUsage: rotate_img IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" -rotate 90 "${1}"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Rotate an image file 90-degrees counter-clock-wise
#' @param[in] $1 pathname to the image file to rotate
rotate_img_ccw() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Rotate an image file 90-degrees counter-clock-wise\nUsage: rotate_img_ccw IMAGE_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        convert "${1}" -rotate -90 "${1}"
    else
        printf 'ERROR: A pathname to a readable image file is required!\n' >&2
    fi
}


#' Repair SVG Files
fixsvg() {
    find ./ -type f -name "*.svg" -exec minifyxml --svg --inplace --remove-all-metadata {} \; && find ./ -type f -name "*.svg" -exec xmllint --valid --nowarning --noout {} \;
}


fi


# VIDEO #


#' Play a video file
#' @param[in] $1 pathname to video file to play
playvideo() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Play a video file\nUsage: playvideo VIDEO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        if [ -x "$(command -v ffplay)" ]; then
            ffplay -hide_banner -loglevel panic "${1}"
        else
            printf 'ERROR: Unable to find a suitable audio player!\n' >&2
        fi
    else
        printf 'ERROR: A pathname to a readable file is required!\nPlay a video file\nUsage: playvideo VIDEO_FILE\n' >&2
    fi
}


if [ -x "$(command -v ffmpeg)" ]; then


#' Merge audio & video file
#' @param[in] $1 pathname to audio file
#' @param[in] $2 pathname to video file
mergeaudiovideo() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Play a video file\nUsage: mergeaudiovideo AUDIO_FILE VIDEO_FILE\n'
    elif { [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; } || { [ -n "${2:-}" ] && [ -r "${2}" ] && [ -f "${2}" ]; }; then
        core_count=''
        outfile="${1##*/}"
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -i "$1" -i "$2" "${outfile%.*}_merged.${outfile#.*}"
    else
        printf 'ERROR: Two pathnames to readable files is required!\nPlay a video file\nUsage: mergeaudiovideo AUDIO_FILE VIDEO_FILE\n' >&2
    fi
}


#' Create an MP4 video given an audio file & an image file
#' @param[in] $1 pathname to audio file
#' @param[in] $2 pathname to image file
audioimg2mp4() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Create an MP4 video given an audio file & an image file\nUsage: audioimg2mp4 AUDIO_FILE IMAGE_FILE\n'
    elif { [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; } || { [ -n "${2:-}" ] && [ -r "${2}" ] && [ -f "${2}" ]; }; then
        core_count=''
        outfile="${1##*/}"
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -y -hide_banner -loglevel panic ${hw_params} -thread_queue_size 4096 -probesize 20M -analyzeduration 20M -i "$2" -i "$1" -c:v libx264 -crf 15 -tune stillimage -vf scale=2560:1440 -c:a libmp3lame -b:a 320000 -ar 44100 -compression_level 0 "${outfile%.*}_merged.mp4"
    else
        printf 'ERROR: Two pathnames to readable files is required!\nCreate an MP4 video given an audio file & an image file\nUsage: audioimg2mp4 AUDIO_FILE IMAGE_FILE\n' >&2
    fi
}


fi
