const fs = require('fs');
const path = require('path');
const outputPath = '../ini/mod/science/';

const decl =
  ';======================= Created by <D.J.> =========================\n' +
  ';=================== Generated from Sciencegen =====================\n\n'

export type FileType = {
  writeLine: (value: string) => void,
  nextLine: () => void,
  write: (value: string) => void,
  end: () => void
}

export const createWriteStream = (fileName: string): FileType => {
  if (!fs.existsSync(outputPath)) {
    fs.mkdirSync(outputPath, { recursive: true });
  }
  const file = fs.createWriteStream(outputPath + fileName);
  file.write(decl);
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