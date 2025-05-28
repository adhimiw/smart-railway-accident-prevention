#!/bin/bash

# Smart Railway Station Accident Prevention System
# GitHub Repository Setup Script
# Author: Adhithan Dev

echo "🚂 Smart Railway Station Accident Prevention System"
echo "=================================================="
echo "GitHub Repository Setup"
echo ""

# Repository details
REPO_NAME="smart-railway-accident-prevention"
GITHUB_USERNAME="adhimiw"
REPO_URL="https://github.com/$GITHUB_USERNAME/$REPO_NAME.git"

echo "📋 Repository Information:"
echo "   Name: $REPO_NAME"
echo "   Owner: $GITHUB_USERNAME"
echo "   URL: $REPO_URL"
echo ""

# Check if we're in a git repository
if [ ! -d ".git" ]; then
    echo "❌ Error: Not in a git repository"
    echo "Please run this script from the project root directory"
    exit 1
fi

echo "✅ Git repository detected"

# Check current git status
echo ""
echo "📊 Current Git Status:"
git status --short

echo ""
echo "📝 Git Log:"
git log --oneline -5

echo ""
echo "🔗 Setting up GitHub remote..."

# Check if remote already exists
if git remote get-url origin &> /dev/null; then
    echo "⚠️  Remote 'origin' already exists:"
    git remote -v
    echo ""
    read -p "Do you want to update the remote URL? (y/n): " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        git remote set-url origin "$REPO_URL"
        echo "✅ Remote URL updated"
    else
        echo "ℹ️  Keeping existing remote"
    fi
else
    git remote add origin "$REPO_URL"
    echo "✅ Remote 'origin' added"
fi

echo ""
echo "🌐 Remote configuration:"
git remote -v

echo ""
echo "📤 Instructions to create GitHub repository:"
echo ""
echo "1. Go to https://github.com/new"
echo "2. Repository name: $REPO_NAME"
echo "3. Description: Arduino-based Smart Railway Station Accident Prevention System using ultrasonic sensors and servo motors for automated safety barriers"
echo "4. Set as Public repository"
echo "5. DO NOT initialize with README, .gitignore, or license (we already have these)"
echo "6. Click 'Create repository'"
echo ""

echo "📋 Suggested repository topics (add these on GitHub):"
echo "   arduino, iot, railway-safety, ultrasonic-sensor, servo-motor,"
echo "   accident-prevention, smart-station, safety-system, embedded-systems, automation"
echo ""

echo "🚀 After creating the repository on GitHub, run:"
echo ""
echo "   # Push to GitHub"
echo "   git branch -M main"
echo "   git push -u origin main"
echo ""

echo "📁 Repository Contents:"
echo "   ✅ README.md - Complete project documentation"
echo "   ✅ Arduino source code in src/"
echo "   ✅ Demo video in videos/"
echo "   ✅ Technical documentation in docs/"
echo "   ✅ Installation guide"
echo "   ✅ Circuit diagrams"
echo "   ✅ MIT License"
echo "   ✅ Contributing guidelines"
echo ""

echo "🎯 Quick Commands:"
echo ""
echo "# Check repository status"
echo "git status"
echo ""
echo "# View commit history"
echo "git log --oneline"
echo ""
echo "# Push to GitHub (after creating repo)"
echo "git branch -M main"
echo "git push -u origin main"
echo ""
echo "# Play demo video"
echo "./play_demo.sh"
echo ""

echo "✨ Your Smart Railway Station Accident Prevention System is ready for GitHub!"
echo "   Project Date: March 22, 2023"
echo "   Total Cost: ~$33-63"
echo "   Components: Arduino UNO, HC-SR04, SG90 Servo"
echo ""
echo "🔗 After pushing, your repository will be available at:"
echo "   https://github.com/$GITHUB_USERNAME/$REPO_NAME"
echo ""
echo "Thank you for contributing to railway safety! 🚂🛡️"
