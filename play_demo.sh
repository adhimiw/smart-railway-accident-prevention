#!/bin/bash

# Smart Railway Station Accident Prevention System
# Demo Video Player Script
# Author: Adhithan Dev
# Date: March 22, 2023

echo "🚂 Smart Railway Station Accident Prevention System"
echo "=================================================="
echo ""
echo "Project Demo Video Player"
echo "Date: March 22, 2023"
echo ""

# Check if video file exists
VIDEO_FILE="videos/demo_video.mp4"

if [ ! -f "$VIDEO_FILE" ]; then
    echo "❌ Error: Demo video not found at $VIDEO_FILE"
    echo "Please ensure the video file is in the correct location."
    exit 1
fi

echo "📹 Found demo video: $VIDEO_FILE"
echo ""

# Try different video players
if command -v vlc &> /dev/null; then
    echo "🎬 Opening video with VLC Media Player..."
    vlc "$VIDEO_FILE" &
elif command -v mpv &> /dev/null; then
    echo "🎬 Opening video with MPV..."
    mpv "$VIDEO_FILE" &
elif command -v mplayer &> /dev/null; then
    echo "🎬 Opening video with MPlayer..."
    mplayer "$VIDEO_FILE" &
elif command -v totem &> /dev/null; then
    echo "🎬 Opening video with Totem..."
    totem "$VIDEO_FILE" &
elif command -v xdg-open &> /dev/null; then
    echo "🎬 Opening video with default application..."
    xdg-open "$VIDEO_FILE" &
else
    echo "❌ No suitable video player found."
    echo "Please install one of the following:"
    echo "  - VLC Media Player (vlc)"
    echo "  - MPV (mpv)"
    echo "  - MPlayer (mplayer)"
    echo "  - Totem (totem)"
    echo ""
    echo "Or open the video manually: $VIDEO_FILE"
    exit 1
fi

echo "✅ Video player launched successfully!"
echo ""
echo "📝 Project Information:"
echo "   - Arduino UNO based accident prevention system"
echo "   - Uses HC-SR04 ultrasonic sensor for detection"
echo "   - SG90 servo motor for barrier control"
echo "   - Real-time safety monitoring"
echo "   - Cost-effective solution (~$33-63)"
echo ""
echo "📚 For more information, see:"
echo "   - README.md - Complete project documentation"
echo "   - docs/INSTALLATION.md - Setup instructions"
echo "   - docs/TECHNICAL_SPECIFICATIONS.md - Technical details"
echo "   - src/railway_accident_prevention.ino - Arduino code"
echo ""
echo "🔗 GitHub Repository: https://github.com/adhimiw/smart-railway-accident-prevention"
echo ""
echo "Thank you for viewing the Smart Railway Station Accident Prevention System demo! 🚂✨"
