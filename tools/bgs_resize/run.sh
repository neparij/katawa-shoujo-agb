#!/bin/sh
set -e

# Create or reuse virtual environment
if [ ! -d "venv-3.12" ]; then
    python -m venv venv-3.12
fi

# Activate the virtual environment
source venv-3.12/bin/activate

# Install the package in editable mode (if needed)
pip install -e . --verbose

ksre_bgs_resize
#ksre_drugs_gen
#ksre_random_fill
