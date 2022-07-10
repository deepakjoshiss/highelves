const fs = require('fs');
const path = require('path');
const outputPath = 'C:/Data/BFME/highelves/data/ini/mod/science/';

export const getDecl = (fileName: string) => {
  return ';======================= Created by <D.J.> =========================\n' +
  `;=================== Generated from ${fileName} =====================\n\n`
}

export type FileType = {
  writeLine: (value: string) => void,
  nextLine: () => void,
  write: (value: string) => void,
  end: () => void
}

export const createWriteStream = (fileName: string, tag = 'code'): FileType => {
  if (!fs.existsSync(outputPath)) {
    fs.mkdirSync(outputPath, { recursive: true });
  }
  const file = fs.createWriteStream(outputPath + fileName);
  file.write(getDecl(tag));
  return {
    // writeLine: (value: string) => {},
    // write: (value: string) => {},
    // end: () => {},
    writeLine: (value: string) => {
      file.write(value);
      file.write('\n');
    },
    nextLine: () => {
      file.write('\n');
    },
    write: (value: string) => file.write(value),
    end: () => file.end(),
  }
}