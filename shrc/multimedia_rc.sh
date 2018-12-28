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
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Play an audio file\nUsage: playmusic AUDIO_FILE\n' >&2
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
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Play an audio file with visuals\nUsage: playmusicvisual AUDIO_FILE [VISUAL]\n' >&2
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
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        core_count=''
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=lin:size=2560x1440 "${outfile}.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Generate a linear visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png AUDIO_FILE\n' >&2
    fi
}


#' Generate a squareroot visualization of the audio wave (in the specified audio file) and save it as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_sqrt() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate a squareroot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_sqrt AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        core_count=''
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=sqrt:size=2560x1440 "${outfile}_sqrt.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Generate a squareroot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_sqrt AUDIO_FILE\n' >&2
    fi
}


#' Generate a cuberoot visualization of the audio wave (in the specified audio file) and save it as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_cbrt() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate a cuberoot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_cbrt AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        core_count=''
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=cbrt:size=2560x1440 "${outfile}_cbrt.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Generate a cuberoot visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_cbrt AUDIO_FILE\n' >&2
    fi
}


#' Generate a logarithmic visualization of the audio wave (in the specified audio file) and save it as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_log() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate a logarithmic visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_log AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        core_count=''
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=log:size=2560x1440 "${outfile}_log.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Generate a logarithmic visualization of the audio wave (in the specified audio file) and save it as a PNG\nUsage: audio2png_log AUDIO_FILE\n' >&2
    fi
}


#' Generate multiple visualizations of the audio wave (in the specified audio file) and save them as a PNG
#' @param[in] $1 pathname to audio file to visualize
audio2png_all() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Generate multiple visualizations of the audio wave (in the specified audio file) and save them as a PNG\nUsage: audio2png_all AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        core_count=''
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=lin:size=2560x1440 "${outfile}.png" &
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=sqrt:size=2560x1440 "${outfile}_sqrt.png" &
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=cbrt:size=2560x1440 "${outfile}_cbrt.png" &
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -sn -vn -i "${1}" -filter_complex showwavespic=scale=log:size=2560x1440 "${outfile}_log.png"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Generate multiple visualizations of the audio wave (in the specified audio file) and save them as a PNG\nUsage: audio2png_all AUDIO_FILE\n' >&2
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
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libfaac -ar 44100 -f aac "${outfile}.aac"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to AAC\nUsage: convert_to_aac AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an AC3 file
#' @param[in] $1 pathname to audio file to convert
convert_to_ac3() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to AC3\nUsage: convert_to_ac3 AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a ac3 -ar 44100 -f ac3 "${outfile}.ac3"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to AC3\nUsage: convert_to_ac3 AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an AC3 (Fixed) file
#' @param[in] $1 pathname to audio file to convert
convert_to_ac3_fixed() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to AC3 (Fixed)\nUsage: convert_to_ac3_fixed AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a ac3_fixed -ar 44100 "${outfile}.ac3"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to AC3 (Fixed)\nUsage: convert_to_ac3_fixed AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to a Flac file
#' @param[in] $1 pathname to audio file to convert
convert_to_flac() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to Flac\nUsage: convert_to_flac AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a flac -b:a 320000 -ar 44100 -compression_level 12 -f flac "${outfile}.flac"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to Flac\nUsage: convert_to_flac AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an MP3 file
#' @param[in] $1 pathname to audio file to convert
convert_to_mp3() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to MP3\nUsage: convert_to_mp3 AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libmp3lame -b:a 320000 -ar 44100 -compression_level 0 -f mp3 "${outfile}.mp3"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to MP3\nUsage: convert_to_mp3 AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an OGG file
#' @param[in] $1 pathname to audio file to convert
convert_to_ogg() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to OGG\nUsage: convert_to_ogg AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libvorbis -ar 44100 -f ogg "${outfile}.ogg"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to OGG\nUsage: convert_to_ogg AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an OPUS file
#' @param[in] $1 pathname to audio file to convert
convert_to_opus() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to OPUS\nUsage: convert_to_opus AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a libopus -compression_level 10 "${outfile}.opus"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to OPUS\nUsage: convert_to_opus AUDIO_FILE\n' >&2
    fi
}


#' Convert an audio file to an WAV file
#' @param[in] $1 pathname to audio file to convert
convert_to_wav() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Convert an audio file to WAV\nUsage: convert_to_wav AUDIO_FILE\n'
    elif [ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]; then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        ffmpeg -hide_banner -loglevel panic -sn -vn -i "${1}" -codec:a pcm_s16le -ar 44100 -f wav "${outfile}.wav"
    else
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Convert an audio file to WAV\nUsage: convert_to_wav AUDIO_FILE\n' >&2
    fi
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
        printf 'ERROR: A pathname to a readable file is required!\n' >&2
        printf 'Play a video file\nUsage: playvideo VIDEO_FILE\n' >&2
    fi
}


if [ -x "$(command -v ffmpeg)" ]; then


#' Merge audio & video file
#' @param[in] $1 pathname to audio file
#' @param[in] $2 pathname to video file
mergeaudiovideo() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Play a video file\nUsage: mergeaudiovideo AUDIO_FILE VIDEO_FILE\n'
    elif ([ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]) || ([ -n "${2:-}" ] && [ -r "${2}" ] && [ -f "${2}" ]); then
        outfile="$(basename "${2}")"
        file_ext="${outfile##*.}"
        outfile="${outfile%.*}"
        core_count=''
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -hide_banner -loglevel panic ${hw_params} -i "$1" -i "$2" "${outfile}_merged.${file_ext}"
    else
        printf 'ERROR: Two pathnames to readable files is required!\n' >&2
        printf 'Play a video file\nUsage: mergeaudiovideo AUDIO_FILE VIDEO_FILE\n' >&2
    fi
}


#' Create an MP4 video given an audio file & an image file
#' @param[in] $1 pathname to audio file
#' @param[in] $2 pathname to image file
audioimg2mp4() {
    if [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Create an MP4 video given an audio file & an image file\nUsage: audioimg2mp4 AUDIO_FILE IMAGE_FILE\n'
    elif ([ -n "${1:-}" ] && [ -r "${1}" ] && [ -f "${1}" ]) || ([ -n "${2:-}" ] && [ -r "${2}" ] && [ -f "${2}" ]); then
        outfile="$(basename "${1}")"
        outfile="${outfile%.*}"
        core_count=''
        [ -x "$(command -v nproc)" ] && core_count="-threads $(nproc)"
        hw_params='-hwaccel vaapi'
        [ -x "$(command -v nvidia-smi)" ] && hw_params="-hwaccel cuvid $core_count"
        # shellcheck disable=SC2086
        ffmpeg -y -hide_banner -loglevel panic ${hw_params} -thread_queue_size 4096 -probesize 20M -analyzeduration 20M -i "$2" -i "$1" -c:v libx264 -crf 15 -tune stillimage -vf scale=2560:1440 -c:a libmp3lame -b:a 320000 -ar 44100 -compression_level 0 "${outfile}_merged.mp4"
    else
        printf 'ERROR: Two pathnames to readable files is required!\n' >&2
        printf 'Create an MP4 video given an audio file & an image file\nUsage: audioimg2mp4 AUDIO_FILE IMAGE_FILE\n' >&2
    fi
}


fi
