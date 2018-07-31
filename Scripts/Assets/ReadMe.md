# Updating the project assets

Put some usefull links [here](./ReadMe.md)

## Description

We are sharing files between artists and programmer using a share on Google Drive.
We need a short script to copy new and changed files into the assets folder of the project.

## Workflow

- Run in folder of repository
- Take path/to/folder of Google Drive
- Copy newly created files and folder
- Copy modified files

## Using PowerShell

```
$AssetDest = "$env:userprofile/path/to/project/assets"
$AssetSrc = "$env:appdata/Google Drive/path/to/assets"

xcopy $AssetSrc\*.png $AssetDest /E /D /Y
```

## Requirements

Google Drive installed on workstation

